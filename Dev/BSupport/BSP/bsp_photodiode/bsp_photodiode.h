/*
 * bsp_photodiode.h
 *
 *  Created on: Jun 24, 2025
 *      Author: Admin
 */

#ifndef BSUPPORT_BSP_BSP_PHOTODIODE_BSP_PHOTODIODE_H_
#define BSUPPORT_BSP_BSP_PHOTODIODE_BSP_PHOTODIODE_H_

#include "board.h"
#include "ads8327.h"

typedef enum{SPI_MODE_0, SPI_MODE_1, SPI_MODE_2, SPI_MODE_3} bsp_photo_spi_mode_t;

void bsp_photodiode_timer1_init(uint32_t period) ;
void bsp_photodiode_sample_start(uint32_t init_num_sample);

void bsp_photo_sw_spi_change_mode(void);
void bsp_photo_adc_spi_change_mode(void);

void bsp_photo_set_spi_mode(bsp_photo_spi_mode_t spi_mode);
void bsp_photo_set_spi_data_len(uint32_t DataWidth);
void bsp_photo_set_spi_prescaler(uint32_t Prescaler);


extern ADS8327_Device_t photo_adc;

#endif /* BSUPPORT_BSP_BSP_PHOTODIODE_BSP_PHOTODIODE_H_ */
