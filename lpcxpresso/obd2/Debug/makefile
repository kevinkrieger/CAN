################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: obd2.axf

# Tool invocations
obd2.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -L"/home/kevin/Projects/CAN/lpcxpresso/lpc_chip_11cxx_lib/Debug" -L"/home/kevin/Projects/CAN/lpcxpresso/lpc_chip_11cxx_lib" -L"/home/kevin/Projects/CAN/lpcxpresso/lpc_chip_11cxx_lib/Release" -Xlinker -Map="obd2.map" -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T "obd2_Debug.ld" -o "obd2.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) obd2.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "obd2.axf"; # arm-none-eabi-objcopy -v -O binary "obd2.axf" "obd2.bin" ; # checksum -p LPC11C14_301 -d "obd2.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
