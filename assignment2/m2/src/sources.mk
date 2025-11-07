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




ifeq ($(PLATFORM),HOST)

#-------------------------------------

#	 Host Platform (Native GCC)

#-------------------------------------

SOURCES =  main.c \
	memory.c

INCLUDES = -I../include \
	   -I../include/common 


else ifeq ($(PLATFORM),MSP432)

#----------------------------------------------

#	 MSP432 Platform (Cross-Compile)

#----------------------------------------------

SOURCES =  main.c \
	memory.c \
	startup_msp432p401r_gcc.c \
	system_msp432p401r.c \
	interrupts_msp432p401r_gcc.c

INCLUDES = -I../include/common \
	-I../include/msp432 \
	-I../include/CMSIS/

#else
#$(error PLATFORM not defined! Use 'make build PLATFORM=HOST' or 'make build PLATFORM=MSP432')
endif








