CROSS_COMPILE ?= arm-linux-gnueabihf-
TARGET		  ?= clkc

CC 			  := $(CROSS_COMPILE)gcc
LD 			  := $(CROSS_COMPILE)ld
OBJCOPY 	  := $(CROSS_COMPILE)objcopy
OBJDUMP       := $(CROSS_COMPILE)objdump

INCLUDIRS	  := imx6u \
				 bsp/clk \
				 bsp/led \
				 bsp/delay \
				 bsp/beep \
				 bsp/key \
				 bsp/gpio

SRCDIRS		  := project \
				 bsp/clk \
				 bsp/led \
				 bsp/delay \
				 bsp/beep \
				 bsp/key \
				 bsp/gpio

INCLUDE 	  := $(patsubst %, -I %, $(INCLUDIRS))
SFILES     	  := $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
CFILES     	  := $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

SFILESNODIR   := $(notdir $(SFILES))
CFILESNODIR   := $(notdir $(CFILES))
SOBJS   	  := $(patsubst %, obj/%, $(SFILESNODIR:.S=.o))
COBJS   	  := $(patsubst %, obj/%, $(CFILESNODIR:.c=.o))
OBJS 		  := $(SOBJS)$(COBJS)

VPATH 		  := $(SRCDIRS)

.PHONY:clean

$(TARGET).bin: $(OBJS)
	$(LD) -Timx6u.lds -o $(TARGET).elf $^
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf >$(TARGET).dis

$(SOBJS): obj/%.o: %.S
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

$(COBJS): obj/%.o: %.c
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

clean:
	rm -rf $(TARGET).elf $(TARGET).bin $(TARGET).dis $(OBJS)

print:
	@echo INCLUDE = $(INCLUDE)
	@echo SFILES  = $(SFILES)
	@echo CFILES  = $(CFILES)
	@echo SFILESNODIR  = $(SFILESNODIR)
	@echo CFILESNODIR  = $(CFILESNODIR)
	@echo SOBJS  = $(SOBJS)
	@echo COBJS  = $(COBJS)

