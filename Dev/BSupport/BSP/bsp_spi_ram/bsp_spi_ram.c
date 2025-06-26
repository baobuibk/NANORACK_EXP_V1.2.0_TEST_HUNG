/*
 * bsp_spi_ram.c
 *
 *  Created on: Jun 25, 2025
 *      Author: Admin
 */
#include "bsp_spi_ram.h"
#include "IS66WVS4M8BLL.h"
// Byte dummy cho DMA TX



// Khởi tạo cấu hình SRAM
IS66_t IS66WV = {
    .spi = SPI6,
    .cs_port = GPIOD,
    .cs_pin = LL_GPIO_PIN_7, // Dùng PD7 làm CS
    .transfer_size = 0,
    .transfer_done = 0,
    .dma = DMA2, // Dùng DMA2
    .dma_stream_tx = LL_DMA_STREAM_5, // Stream 5 cho TX
    .dma_stream_rx = LL_DMA_STREAM_6, // Stream 6 cho RX
    .dma_channel = LL_DMA_CHANNEL_1 // Channel 1 chung
};

void bsp_spi_ram_init(void)
{
	SRAM_Initialize(&IS66WV);
}
void bsp_spi_ram_write_polling(uint32_t address, uint32_t size, uint8_t *buffer)
{
	SRAM_write_polling(&IS66WV, address, size, buffer);
}
void bsp_spi_ram_read_polling(uint32_t address, uint32_t size, uint8_t *buffer)
{
	SRAM_read_polling(&IS66WV, address, size, buffer);
}
void bsp_spi_ram_fast_read_polling(uint32_t address, uint32_t size, uint8_t *buffer)
{
	SRAM_fast_read_polling(&IS66WV, address, size, buffer);
}

void bsp_spi_ram_write_dma(uint32_t address, uint32_t size, uint8_t *buffer)
{
	SRAM_write_DMA(&IS66WV, address, size, buffer);
}

void bsp_spi_ram_read_dma(uint32_t address, uint32_t size, uint8_t *buffer)
{
	SRAM_read_DMA(&IS66WV, address, size, buffer);
}
void bsp_spi_ram_read_id(uint8_t * buffer)
{
	SRAM_read_id(&IS66WV,  buffer);
}
uint8_t bsp_spi_ram_is_transfer_done(void)
{
	return SRAM_IsTransferDone(&IS66WV);
}
