################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
04-KeyPad.lss \

FLASH_IMAGE += \
04-KeyPad.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 04-KeyPad.elf secondary-outputs

# Tool invocations
04-KeyPad.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,04-KeyPad.map -mmcu=atmega32 -o "04-KeyPad.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

04-KeyPad.lss: 04-KeyPad.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 04-KeyPad.elf  >"04-KeyPad.lss"
	@echo 'Finished building: $@'
	@echo ' '

04-KeyPad.hex: 04-KeyPad.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 04-KeyPad.elf  "04-KeyPad.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 04-KeyPad.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 04-KeyPad.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 04-KeyPad.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
