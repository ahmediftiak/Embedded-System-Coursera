# Makefile for Platform-specific (Host or MSP432) build system
#
# Use: make [TARGET] PLATFORM=[HOST|MSP432]
#
# Build Targets:
#    <File>.i      - Builds <File>.i preprocessed file
#    <File>.o      - Builds <File>.o object file
#    <File>.asm    - Builds <File>.asm assembly file
#    <File>.d      - Builds <File>.o dependency file
#    <File>.map    - Builds <File>.map map output file
#    <File>.out    - Builds <File>.out executable file
#
# Platform Overrides:
#    PLATFORM=HOST  - Builds for the host (native environment, e.g., Ubuntu).
#    PLATFORM=MSP432 - Builds for the MSP432 platform using the cross-compiler.
#
# Example usage:
#    make build PLATFORM=HOST
#    make build PLATFORM=MSP432
#
# The PLATFORM override controls the following:
#   - Compiler to use (gcc for HOST, arm-none-eabi-gcc for MSP432)
#   - Compiler flags (CFLAGS, CPPFLAGS, etc.)
#   - Linker flags (LDFLAGS)
#   - Source files and includes (specific to the platform)
#   - Architecture flags (e.g., ARM specific flags for MSP432)
#
# Platform-specific configuration will be done using the PLATFORM variable.
#
# Note:
#   You must specify the platform to build for (either HOST or MSP432).
#   For example, to build for the MSP432 platform, use the command:
#       make build PLATFORM=MSP432
#
# This file supports the following platforms:
#   HOST (for native builds on your computer)
#   MSP432 (for embedded builds using cross-compilers)

# Makefile for Platform-specific (Host or MSP432) build system

include sources.mk

PLATFORM ?= HOST

# Files and directories
OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.asm)
PREPROCESSED = $(SOURCES:.c=.i)
MAP_FILE = c1m2.map
EXEC_FILE = c1m2.out

# Platform-specific flags
ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Tmsp432p401r.lds --specs=nosys.specs
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 -MMD -MP
	CPPFLAGS = -DMSP432
else
	CC = gcc
	LD = gcc
	LDFLAGS = -Wl,-Map=$(MAP_FILE)
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -MMD -MP
	CPPFLAGS = -DHOST
endif

# Default target
.PHONY: all
all: build

# Rule for generating preprocessed files
%.i: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -E $< -o $@

# Rule for generating assembly files
%.asm: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -S $< -o $@

# Rule for generating object files
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

# Rule to compile all object files without linking
.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $(EXEC_FILE) $(LDFLAGS) $(OBJS)


# Rule to clean all build artifacts
.PHONY: clean
clean:
	rm -f *.o *.i *.asm $(MAP_FILE) $(EXEC_FILE) *.d

# Include dependency files if available
-include $(SOURCES:.c=.d)
