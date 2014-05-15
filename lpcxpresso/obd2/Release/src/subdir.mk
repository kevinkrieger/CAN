################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/board.c \
../src/board_sysinit.c \
../src/ccan_rom.c \
../src/cr_startup_lpc11xx.c \
../src/crp.c \
../src/ff.c \
../src/main.c \
../src/mmc.c \
../src/rtc.c \
../src/sysinit.c \
../src/systick.c 

OBJS += \
./src/board.o \
./src/board_sysinit.o \
./src/ccan_rom.o \
./src/cr_startup_lpc11xx.o \
./src/crp.o \
./src/ff.o \
./src/main.o \
./src/mmc.o \
./src/rtc.o \
./src/sysinit.o \
./src/systick.o 

C_DEPS += \
./src/board.d \
./src/board_sysinit.d \
./src/ccan_rom.d \
./src/cr_startup_lpc11xx.d \
./src/crp.d \
./src/ff.d \
./src/main.d \
./src/mmc.d \
./src/rtc.d \
./src/sysinit.d \
./src/systick.d 


# Each subdirectory must supply rules for building sources it contributes
src/board.o: ../src/board.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DNDEBUG -D__CODE_RED -DCORE_M0 -D__USE_LPCOPEN -DNO_BOARD_LIB -DCR_INTEGER_PRINTF -D__LPC11XX__ -I"/home/kevin/lpcxpresso/lpc_chip_11cxx_lib/inc" -I"/home/kevin/lpcxpresso/lpc_chip_11cxx_lib/src" -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/board.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DNDEBUG -D__CODE_RED -DCORE_M0 -D__USE_LPCOPEN -DNO_BOARD_LIB -DCR_INTEGER_PRINTF -D__LPC11XX__ -I"/home/kevin/lpcxpresso/lpc_chip_11cxx_lib/inc" -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


