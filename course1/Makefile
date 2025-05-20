# Simplified Makefile
# Usage: make PLATFORM=HOST or make PLATFORM=MSP432
#        make VERBOSE=1 to show commands

include sources.mk

PLATFORM ?= HOST
TARGET = course1
OBJS = $(SOURCES:.c=.o)
DEPS = $(OBJS:.o=.d)

# Verbosity control
VERBOSE ?= 0
ifeq ($(VERBOSE),1)
  Q =
else
  Q = @
endif

ifeq ($(PLATFORM),MSP432)
  CC = arm-none-eabi-gcc
  LDFLAGS = -Wl,-Tmsp432p401r.lds, --specs=nosys.specs
  CFLAGS = -Wall -Werror -O0 -g -std=c99 -mcpu=cortex-m4 -mthumb \
           -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 -MMD -MP
  CPPFLAGS = -DMSP432 $(INCLUDES)
else
  CC = gcc
  LDFLAGS = -Wl,-Map=$(TARGET).map
  CFLAGS = -Wall -Werror -O0 -g -std=c99 -MMD -MP
  CPPFLAGS = -DHOST -DCOURSE1 $(INCLUDES)
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(Q)$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(Q)$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	$(Q)rm -f src/*.o src/*.d $(TARGET) *.map *.out

