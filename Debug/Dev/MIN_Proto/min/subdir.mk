################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dev/MIN_Proto/min/min.c 

OBJS += \
./Dev/MIN_Proto/min/min.o 

C_DEPS += \
./Dev/MIN_Proto/min/min.d 


# Each subdirectory must supply rules for building sources it contributes
Dev/MIN_Proto/min/%.o Dev/MIN_Proto/min/%.su Dev/MIN_Proto/min/%.cyclo: ../Dev/MIN_Proto/min/%.c Dev/MIN_Proto/min/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32F765xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Common" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Devices" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/LED" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Sensor_I2C" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/BSupport/UART" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/BSupport/SysTick" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/BSupport/I2C" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Devices/ADG1414" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Devices/DateTime" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Devices/IR_LED" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Devices/MB85RS2MT" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Sensor_I2C/LSM6DSOX" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Sensor_I2C/BME280" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Sensor_I2C/BMP390" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Sensor_I2C/H250" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Sensor_I2C/H3LIS331DL" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Sensor_I2C/K33" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MIN_Proto/min" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MIN_Proto/min_app" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MIN_Proto" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MiddleWare/sst0_c/ports/arm-cm" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MiddleWare/container" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MiddleWare/Utils/ports/stm32f4xx" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MiddleWare/Utils" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MiddleWare/sst0_c/src" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MiddleWare/FSM" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MiddleWare/STDIO" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/App/Signals" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/App/shell/CLI_Command" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/App/app_main" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/App/shell" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/BSupport/BSP/Board" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MiddleWare/CLI_Terminal" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/MiddleWare/CLI_Terminal/CLI_Src" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/App/temperature_monitor" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/App/temperature_control" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/BSupport/BSP/bsp_tec" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/BSupport/BSP/bsp_ntc" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/BSupport/BSP/bsp_heater" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Devices/ADS8327" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Devices/MCP4902" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/BSupport/BSP/bsp_photodiode" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Devices/IS66WVS4M8BLL" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Devices/LT8722" -I"D:/PROJECT/BOOK_EXAMPLE/EXP_V120/Dev/Devices/NTC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Dev-2f-MIN_Proto-2f-min

clean-Dev-2f-MIN_Proto-2f-min:
	-$(RM) ./Dev/MIN_Proto/min/min.cyclo ./Dev/MIN_Proto/min/min.d ./Dev/MIN_Proto/min/min.o ./Dev/MIN_Proto/min/min.su

.PHONY: clean-Dev-2f-MIN_Proto-2f-min

