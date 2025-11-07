#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Author: Vladislav Skachkov
# Description:
#   Build system for the C1M2 assignment — supports building for both
#   the HOST environment (using native GCC) and the MSP432 platform
#   (using ARM cross-compiler). This Makefile compiles, assembles, links,
#   and cleans all project files.
#
# Use:
#   make [TARGET] [PLATFORM=<PLATFORM>]
#
# Example:
#   make build PLATFORM=HOST
#   make build PLATFORM=MSP432
#   make clean
#
# Build Targets:
#   build        - Builds and links all object files into final executable
#   compile-all  - Compiles all source files but does not link
#   preprocess   - Generates preprocessed (.i) files for each source
#   assembly     - Generates assembly (.asm) files for each source
#   assembly-all - Generates full assembly listing from final executable
#   clean        - Removes all build artifacts (.o, .i, .asm, .map, .out, .d)
#
# Platform Overrides:
#   PLATFORM=HOST   - Build for the native host machine using gcc
#   PLATFORM=MSP432 - Cross-compile for the MSP432 microcontroller
#
# Notes:
#   - The Makefile automatically sets default PLATFORM=HOST if not provided.
#   - The build system expects sources.mk to define SOURCES and INCLUDES.
#------------------------------------------------------------------------------

PLATFORM ?= HOST #getting rid of the problem with specifying the platform, if not specified the HOST would be set as default.
include sources.mk
 
# Output files
TARGET = c1m2.out
MAPFILE = c1m2.map

# Common Flags (Apply to both platforms)
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = 
LDFLAGS = 
SIZE = size

# Platform and Architectures Specifics
ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = gcc
	PLATFORM_DEFS =-DHOST
	CPPFLAGS += $(INCLUDES) $(PLATFORM_DEFS)

else ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-gcc
	SIZE = arm-none-eabi-size
	PLATFORM_DEFS = -DMSP432
	CPPFLAGS += $(INCLUDES) $(PLATFORM_DEFS)

	# Architecture and Linker Specifics
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	LINKER_FILE = ../ msp432p401r.lds

	CFLAGS += -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
	LDFLAGS += -T $(LINKER_FILE) -Wl,-Map=$(MAPFILE)
endif


# SOURCES AND OBJECTS

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

#DEFAULT TARGET

.PHONY: all
all: build

#BUILD TARGET

.PHONY: build
build: $(TARGET)
	$(SIZE) $(TARGET)

#LINKING

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) -o $@

#COMPILATION RULES

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -MMD -MP -o $@

%.i: %.c
	$(CC) -E $(CFLAGS) $(CPPFLAGS) $< -o $@

%.asm: %.c
	$(CC) -S $(CFLAGS) $(CPPFLAGS) $< -o $@

#-----------------------------------------------------------------

#	PREPROCESSOR, ASSEMBLY, OBJECT, COMPILE-ALL TARGETS

#-----------------------------------------------------------------


.PHONY: preprocess
	preprocess:
	$(foreach src,$(SOURCES),$(CC) -E $(CFLAGS) $(CPPFLAGS) $(src) -o $(basename $(src)).i;)

.PHONY: assembly
	assembly:
	$(foreach src,$(SOURCES),$(CC) -S $(CFLAGS) $(CPPFLAGS) $(src) -o $(basename $(src)).asm;)

.PHONY: assembly-all
	assembly-all: $(TARGET)
	@echo "Generating full assembly of $(TARGET)"
	arm-none-eabi-objdump -S $(TARGET) > $(basename $(TARGET)).asm

.PHONY: objects
	objects: $(OBJS)

.PHONY: compile-all
	compile-all: $(OBJS)

#------------------------------------------------------------------------------

# 	CLEAN TARGET

#------------------------------------------------------------------------------
.PHONY: clean
clean:
	@echo "Cleaning all build files..."
	rm -f $(OBJS) $(DEPS) $(TARGET) $(MAPFILE) *.i *.asm *.out *.map *.o *.d


-include $(DEPS)

