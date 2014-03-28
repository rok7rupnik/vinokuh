
BASE_DIR=../../../../..
CMSIS_DIR=$(BASE_DIR)/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS
LIB_DIR=$(BASE_DIR)/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver
BOARD_DIR=$(BASE_DIR)/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery
CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
LDSCRIPT=stm32f4xx_flash.ld
ETAGS=/cygdrive/c/emacs/emacs-23.4/bin/etags.exe

LINKER_FLAGS=-mthumb -nostartfiles -Xlinker -oLibdemo.elf -Xlinker -M -Xlinker -Map=libdemo.map
LIBS=

DEBUG=-g
OPTIM=-O3


CFLAGS= $(DEBUG) \
		$(OPTIM) \
		-T$(LDSCRIPT) \
		-I . \
		-I .. \
		-I $(CMSIS_DIR)/ST/STM32F4xx/Include \
		-I $(CMSIS_DIR)/Include \
		-I $(LIB_DIR)/inc \
		-I $(BOARD_DIR) \
		-D GCC_ARMCM4F \
		-D STM32F4 \
		-D THUMB \
		-D GCC_MAKE \
		-D USE_FULL_ASSERT \
		-mcpu=cortex-m4 \
		-D PACK_STRUCT_END=__attribute\(\(packed\)\) \
		-D ALIGN_STRUCT_END=__attribute\(\(aligned\(4\)\)\) \
		-fomit-frame-pointer \
		-mthumb \
		-mfloat-abi=softfp \
		-fno-strict-aliasing \
		-fno-dwarf2-cfi-asm

THUMB_SOURCE= \
		../main.c \
		../stm32f4xx_it.c \
		../system_stm32f4xx.c \
		$(BOARD_DIR)/stm32f4_discovery.c \
		$(LIB_DIR)/src/misc.c \
		$(LIB_DIR)/src/stm32f4xx_dcmi.c \
		$(LIB_DIR)/src/stm32f4xx_dma.c \
		$(LIB_DIR)/src/stm32f4xx_exti.c \
		$(LIB_DIR)/src/stm32f4xx_flash.c \
		$(LIB_DIR)/src/stm32f4xx_fsmc.c \
		$(LIB_DIR)/src/stm32f4xx_gpio.c \
		$(LIB_DIR)/src/stm32f4xx_rcc.c \
		$(LIB_DIR)/src/stm32f4xx_rtc.c \
		$(LIB_DIR)/src/stm32f4xx_spi.c \
		$(LIB_DIR)/src/stm32f4xx_syscfg.c \
		$(LIB_DIR)/src/stm32f4xx_tim.c \
		$(LIB_DIR)/src/stm32f4xx_usart.c \
		$(LIB_DIR)/src/stm32f4xx_wwdg.c \


ARM_SOURCE=

THUMB_OBJS = $(THUMB_SOURCE:.c=.o)
ARM_OBJS = $(ARM_SOURCE:.c=.o)


all: Libdemo.bin

Libdemo.bin : Libdemo.hex
	$(OBJCOPY) Libdemo.elf -O binary Libdemo.bin

Libdemo.hex : Libdemo.elf
	$(OBJCOPY) Libdemo.elf -O ihex Libdemo.hex

#Libdemo.elf : $(THUMB_OBJS) $(ARM_OBJS) boot.s Makefile
#	$(CC) $(CFLAGS) $(ARM_OBJS) $(THUMB_OBJS) $(LIBS) boot.s $(LINKER_FLAGS)
#
Libdemo.elf : $(THUMB_OBJS) $(ARM_OBJS) startup_stm32f4xx.s Makefile
	$(CC) $(CFLAGS) $(ARM_OBJS) $(THUMB_OBJS) $(LIBS) startup_stm32f4xx.s $(LINKER_FLAGS)


$(THUMB_OBJS) : %.o : %.c Makefile
	$(CC) -c $(CFLAGS) -mthumb $< -o $@

$(ARM_OBJS) : %.o : %.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm $(THUMB_OBJS)
	touch Makefile

tags:
	rm -f TAGS
	echo $(THUMB_SOURCE) $(ARM_SOURCE) | xargs $(ETAGS) -a -o TAGS
	ls $(CMSIS_DIR)/ST/STM32F4xx/Include/*.h | xargs $(ETAGS) -a -o TAGS
	ls $(CMSIS_DIR)/Include/*.h | xargs $(ETAGS) -a -o TAGS
	ls $(LIB_DIR)/inc/*.h | xargs $(ETAGS) -a -o TAGS
	ls $(BOARD_DIR)/*.h | xargs $(ETAGS) -a -o TAGS
