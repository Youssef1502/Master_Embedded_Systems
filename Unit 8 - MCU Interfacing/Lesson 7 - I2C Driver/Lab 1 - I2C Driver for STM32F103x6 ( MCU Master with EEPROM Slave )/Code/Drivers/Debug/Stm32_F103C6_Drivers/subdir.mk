################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.c \
../Stm32_F103C6_Drivers/Stm32_F103C6_GPIO_driver.c \
../Stm32_F103C6_Drivers/Stm32_F103C6_I2C_driver.c \
../Stm32_F103C6_Drivers/Stm32_F103C6_RCC_driver.c \
../Stm32_F103C6_Drivers/Stm32_F103C6_SPI_driver.c \
../Stm32_F103C6_Drivers/Stm32_F103C6_USART_driver.c 

OBJS += \
./Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.o \
./Stm32_F103C6_Drivers/Stm32_F103C6_GPIO_driver.o \
./Stm32_F103C6_Drivers/Stm32_F103C6_I2C_driver.o \
./Stm32_F103C6_Drivers/Stm32_F103C6_RCC_driver.o \
./Stm32_F103C6_Drivers/Stm32_F103C6_SPI_driver.o \
./Stm32_F103C6_Drivers/Stm32_F103C6_USART_driver.o 

C_DEPS += \
./Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.d \
./Stm32_F103C6_Drivers/Stm32_F103C6_GPIO_driver.d \
./Stm32_F103C6_Drivers/Stm32_F103C6_I2C_driver.d \
./Stm32_F103C6_Drivers/Stm32_F103C6_RCC_driver.d \
./Stm32_F103C6_Drivers/Stm32_F103C6_SPI_driver.d \
./Stm32_F103C6_Drivers/Stm32_F103C6_USART_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.o: ../Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/HAL/includes" -I../Inc -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/Stm32_F103C6_GPIO_driver.o: ../Stm32_F103C6_Drivers/Stm32_F103C6_GPIO_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/HAL/includes" -I../Inc -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Stm32_F103C6_GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/Stm32_F103C6_I2C_driver.o: ../Stm32_F103C6_Drivers/Stm32_F103C6_I2C_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/HAL/includes" -I../Inc -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Stm32_F103C6_I2C_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/Stm32_F103C6_RCC_driver.o: ../Stm32_F103C6_Drivers/Stm32_F103C6_RCC_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/HAL/includes" -I../Inc -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Stm32_F103C6_RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/Stm32_F103C6_SPI_driver.o: ../Stm32_F103C6_Drivers/Stm32_F103C6_SPI_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/HAL/includes" -I../Inc -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Stm32_F103C6_SPI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/Stm32_F103C6_USART_driver.o: ../Stm32_F103C6_Drivers/Stm32_F103C6_USART_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/HAL/includes" -I../Inc -I"C:/Users/J000/Desktop/I2C Master with EEPROM Slave/Code/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Stm32_F103C6_USART_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

