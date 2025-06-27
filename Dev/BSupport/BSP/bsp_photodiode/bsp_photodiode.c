/*
 * bsp_photodiode.c
 *
 *  Created on: Jun 24, 2025
 *      Author: Admin
 */

#include "bsp_photodiode.h"
#include "main.h"

ADS8327_Device_t photo_adc;
ADG1414_Device_t photo_sw;
static uint32_t num_sample;


void bsp_photo_set_spi_data_len(uint32_t DataWidth)
{
    LL_SPI_Disable(SPI2);
    LL_SPI_SetDataWidth(SPI2, DataWidth);
    LL_SPI_Enable(SPI2);
}

void bsp_photo_set_spi_prescaler(uint32_t Prescaler)
{
    LL_SPI_Disable(SPI2);
    LL_SPI_SetBaudRatePrescaler(SPI2, Prescaler);
    LL_SPI_Enable(SPI2);
}

void bsp_photo_set_spi_mode(bsp_photo_spi_mode_t spi_mode)
{
	LL_SPI_Disable(SPI2);
	switch(spi_mode)
	{
		case SPI_MODE_0:
			LL_SPI_SetClockPolarity(SPI2, LL_SPI_POLARITY_LOW);
			LL_SPI_SetClockPhase(SPI2, LL_SPI_PHASE_1EDGE);
		break;

		case SPI_MODE_1:
			LL_SPI_SetClockPolarity(SPI2, LL_SPI_POLARITY_LOW);
			LL_SPI_SetClockPhase(SPI2, LL_SPI_PHASE_2EDGE);
		break;

		case SPI_MODE_2:
			LL_SPI_SetClockPolarity(SPI2, LL_SPI_POLARITY_HIGH);
			LL_SPI_SetClockPhase(SPI2, LL_SPI_PHASE_1EDGE);
		break;

		case SPI_MODE_3:
			LL_SPI_SetClockPolarity(SPI2, LL_SPI_POLARITY_HIGH);
			LL_SPI_SetClockPhase(SPI2, LL_SPI_PHASE_2EDGE);
		break;
	}
	LL_SPI_Enable(SPI2);
}


void bsp_photo_sw_init(void)
{
	struct_init_typedef init_param =
	{
		.spi = SPI2,              // Peripheral SPI (SPI1, SPI2, v.v.)
		.cs_port = PHOTO_ADC_CS_GPIO_Port,         // Port của chân CS
		.cs_pin = PHOTO_ADC_CS_Pin,               // Chân CS
		.convst_port = PHOTO_ADC_CONV_GPIO_Port,     // Port của chân convst
		.convst_pin = PHOTO_ADC_CONV_Pin,           // Chân convst
		.EOC_port = PHOTO_ADC_EOC_GPIO_Port,
		.EOC_pin = PHOTO_ADC_EOC_Pin
	};

	bsp_photo_adc_spi_change_mode();
	ADS8327_Device_Init(&photo_adc, &init_param);

	bsp_photo_sw_spi_change_mode();
	ADG1414_Chain_Init(&photo_sw, SPI2, PHOTO_SW_CS_GPIO_Port, PHOTO_SW_CS_Pin, INTERNAL_CHAIN_SWITCH_NUM);
}

void bsp_photo_sw_spi_change_mode(void)
{
	bsp_photo_set_spi_data_len(LL_SPI_DATAWIDTH_8BIT);
	bsp_photo_set_spi_mode(SPI_MODE_1);
	bsp_photo_set_spi_prescaler(LL_SPI_BAUDRATEPRESCALER_DIV32);
}


void bsp_photo_adc_spi_change_mode(void)
{
	bsp_photo_set_spi_data_len(LL_SPI_DATAWIDTH_16BIT);
	bsp_photo_set_spi_mode(SPI_MODE_0);
	bsp_photo_set_spi_prescaler(LL_SPI_BAUDRATEPRESCALER_DIV2);
}


/*
 *timer interrupt->start Conv
 *EXTI (EOC) falling edge
 *EXTI Pull CSADC low
 *EXTI SPI send 2 byte to get 2 byte
 */
void bsp_photodiode_timer1_init(uint32_t period)
{
    uint32_t ticks = period / 5;
    uint16_t prescaler = 0;
    uint16_t arr = ticks - 1;
    if (ticks > 0xFFFF) {
        prescaler = (ticks / 0xFFFF) + 1;
        arr = (ticks / prescaler) - 1;
    }

    TIM1->CR1 = 0; // Xóa thanh ghi điều khiển
    TIM1->ARR = arr; // Cài đặt giá trị auto-reload
    TIM1->PSC = prescaler; // Cài đặt prescaler
    TIM1->EGR = TIM_EGR_UG; // Tạo sự kiện update để áp dụng ngay
    TIM1->DIER |= TIM_DIER_UIE; // Kích hoạt ngắt update
    TIM1->CNT = 0;
    NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 0); // Ưu tiên ngắt cao nhất
}

void bsp_photodiode_sample_start(uint32_t init_num_sample)
{
	num_sample = init_num_sample;
    NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);		// Timer 1 enable IRQ

    TIM1->CR1 |= TIM_CR1_CEN;				// Timer 1 enable counter
}

/*
 * start the pre-sampling phase
 */
void bsp_photodiode_start_pre_sampling(uint32_t num_sample)
{
//	Photodiode_DMA_config(num_sample);
//	Photodiode_timer_start(num_sample);
}

// Hàm xử lý ngắt Timer 1
void TIM1_UP_TIM10_IRQHandler(void)
{
	GPIOD->BSRR = GPIO_BSRR_BS_9; // Đặt CS lên 1
	GPIOD->BSRR = GPIO_BSRR_BR_10; // Đặt PD10 xuống 0
	GPIOD->BSRR = GPIO_BSRR_BR_9; // CS=0
	LL_SPI_TransmitData16(SPI2, 0xAAAA);
	GPIOD->BSRR = GPIO_BSRR_BS_10; // Đặt PD10 lên 1
	TIM1->SR &= ~TIM_SR_UIF; // Xóa cờ ngắt
}

