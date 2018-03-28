################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include protocol/bluetooth/lib/EFR32BG1B/GCC/subdir.mk
-include platform/emlib/src/subdir.mk
-include platform/emdrv/tempdrv/src/subdir.mk
-include platform/emdrv/sleep/src/subdir.mk
-include platform/Device/SiliconLabs/EFR32BG1B/Source/GCC/subdir.mk
-include platform/Device/SiliconLabs/EFR32BG1B/Source/subdir.mk
-include hardware/kit/common/bsp/subdir.mk
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
all: bleMoistureSensor3.axf

# Tool invocations
bleMoistureSensor3.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/efr32bg1b232f256gm48.ld" -Xlinker --gc-sections -Xlinker -Map="bleMoistureSensor3.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o bleMoistureSensor3.axf -Wl,--start-group "./InitDevice.o" "./application_properties.o" "./gatt_db.o" "./init_app.o" "./init_board.o" "./init_mcu.o" "./main.o" "./pti.o" "./thermistor.o" "./hardware/kit/common/bsp/bsp_stk.o" "./platform/Device/SiliconLabs/EFR32BG1B/Source/GCC/startup_efr32bg1b.o" "./platform/Device/SiliconLabs/EFR32BG1B/Source/system_efr32bg1b.o" "./platform/emdrv/sleep/src/sleep.o" "./platform/emdrv/tempdrv/src/tempdrv.o" "./platform/emlib/src/em_adc.o" "./platform/emlib/src/em_cmu.o" "./platform/emlib/src/em_core.o" "./platform/emlib/src/em_cryotimer.o" "./platform/emlib/src/em_crypto.o" "./platform/emlib/src/em_emu.o" "./platform/emlib/src/em_gpio.o" "./platform/emlib/src/em_i2c.o" "./platform/emlib/src/em_int.o" "./platform/emlib/src/em_ldma.o" "./platform/emlib/src/em_msc.o" "./platform/emlib/src/em_rmu.o" "./platform/emlib/src/em_rtcc.o" "./platform/emlib/src/em_system.o" "./platform/emlib/src/em_timer.o" "./platform/emlib/src/em_usart.o" "/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/radio/rail_lib/autogen/librail_release/librail_efr32xg1_gcc_release.a" "/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/protocol/bluetooth/lib/EFR32BG1B/GCC/binapploader.o" "/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/protocol/bluetooth/lib/EFR32BG1B/GCC/libpsstore.a" "/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/protocol/bluetooth/lib/EFR32BG1B/GCC/libmbedtls.a" "/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/protocol/bluetooth/lib/EFR32BG1B/GCC/libbluetooth.a" -lm -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: bleMoistureSensor3.hex'
	arm-none-eabi-objcopy -O ihex "bleMoistureSensor3.axf" "bleMoistureSensor3.hex"
	@echo ' '

	@echo 'Building bin file: bleMoistureSensor3.bin'
	arm-none-eabi-objcopy -O binary "bleMoistureSensor3.axf" "bleMoistureSensor3.bin"
	@echo ' '

	@echo 'Building s37 file: bleMoistureSensor3.s37'
	arm-none-eabi-objcopy -O srec "bleMoistureSensor3.axf" "bleMoistureSensor3.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "bleMoistureSensor3.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) bleMoistureSensor3.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
