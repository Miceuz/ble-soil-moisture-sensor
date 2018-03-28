################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../platform/Device/SiliconLabs/EFR32BG1B/Source/system_efr32bg1b.c 

OBJS += \
./platform/Device/SiliconLabs/EFR32BG1B/Source/system_efr32bg1b.o 

C_DEPS += \
./platform/Device/SiliconLabs/EFR32BG1B/Source/system_efr32bg1b.d 


# Each subdirectory must supply rules for building sources it contributes
platform/Device/SiliconLabs/EFR32BG1B/Source/system_efr32bg1b.o: ../platform/Device/SiliconLabs/EFR32BG1B/Source/system_efr32bg1b.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-D__HEAP_SIZE=0xD00' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0x800' '-DEFR32BG1B232F256GM48=1' -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/CMSIS/Include" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/hardware/kit/common/halconfig" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/Device/SiliconLabs/EFR32BG1B/Include" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/protocol/bluetooth/ble_stack/inc/common" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/emdrv/common/inc" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/emlib/src" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/halconfig/inc/hal-config" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/emlib/inc" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/Device/SiliconLabs/EFR32BG1B/Source" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/emdrv/sleep/src" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/hardware/kit/EFR32BG1_BRD4300A/config" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/protocol/bluetooth/ble_stack/inc/soc" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/bootloader/api" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/hardware/kit/common/bsp" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/emdrv/tempdrv/src" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/emdrv/sleep/inc" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/emdrv/gpiointerrupt/inc" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/emdrv/uartdrv/inc" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/radio/rail_lib/common" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/hardware/kit/common/drivers" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/Device/SiliconLabs/EFR32BG1B/Source/GCC" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/app/bluetooth/common/stack_bridge" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/emdrv/tempdrv/inc" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/radio/rail_lib/chip/efr32" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3" -I"/home/miceuz/SimplicityStudio/v4_workspace/bleMoistureSensor3/platform/bootloader" -O2 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"platform/Device/SiliconLabs/EFR32BG1B/Source/system_efr32bg1b.d" -MT"platform/Device/SiliconLabs/EFR32BG1B/Source/system_efr32bg1b.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


