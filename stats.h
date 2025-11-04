/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief functions implementation
 *
 * The task is to write a couple of functions that can analyze an array of unsigned char data 
 * items and report analytics on the maximum, minimum, mean, and median of the data set.
 *
 * @author Vladislav Skachkov
 * @date 04.11.2025
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/** A function that prints the statistics of an array including minimum, maximum, mean, and median.*/ 
void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median);

/** Given an array of data and a length, prints the array to the screen */ 
void print_array(unsigned char *array, unsigned int length);

/** Given an array of data and a length, returns the median value */ 
unsigned char find_median(unsigned char *array, unsigned int length);

/**  Given an array of data and a length, returns the mean */ 
unsigned char find_mean(unsigned char *array, unsigned int length);

/** Given an array of data and a length, returns the maximum */ 
unsigned char find_maximum(unsigned char *array, unsigned int length);

/** Given an array of data and a length, returns the minimum */ 
unsigned char find_minimum(unsigned char *array, unsigned int length);


/**  Given an array of data and a length, sorts the array from largest to smallest.  (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. ) */
void sort_array(unsigned char *array, unsigned int length);




#endif /* __STATS_H__ */
