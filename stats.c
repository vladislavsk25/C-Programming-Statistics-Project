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
 * @brief fucntions implementation
 *
 * The task is to write a couple of functions that can analyze an array of unsigned char data 
 * items and report analytics on the maximum, minimum, mean, and median of the data set.
 *
 * @author Vladislav Skachkov
 * @date 04.11.2025
 *
 */



#include <stdio.h>
#include "stats.h"
/* Size of the Data Set */
#define SIZE (40)

void sort_array(unsigned char *array, unsigned int length){
	for (unsigned int i = 0; i < SIZE - 1; i++){
	  for(unsigned int j = i+1; j < SIZE; j++){
	    if(array[i] < array[j]){
		unsigned char temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	    }
	  }
	}
}


void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median){
	printf("Statistics:\n");
	printf("Minimum: %u\n", min);
	printf("Maximum: %u\n", max);
	printf("Mean: %u\n", mean);
	printf("Median: %u\n", median);
}

void print_array(unsigned char *array, unsigned int length){
	printf("Array elements:\n");

	for(unsigned int i = 0; i < SIZE; i++){
	printf("%3u ", array[i]);
	  if((i+1) % 8 == 0){
		printf("\n");
	  }
	}
}

unsigned char find_median(unsigned char *array, unsigned int length){
	unsigned char sorted[SIZE];
	for ( int i = 0; i < SIZE; i++){
	   sorted[i] = array[i];
	}

	sort_array(sorted, SIZE);

	if(SIZE % 2 == 0){
	return (sorted[SIZE/2-1] + sorted[SIZE/2])/2;
	} else 
	return sorted[SIZE/2];
	
}

unsigned char find_mean(unsigned char *array, unsigned int length){
	unsigned int sum = 0;
	for(unsigned int i = 0; i  < SIZE; i++){
	sum += array[i];
	}
	return sum/SIZE;
}

unsigned char find_maximum(unsigned char *array, unsigned int length){
	unsigned char max = array[0];
	for (unsigned int i = 0; i < SIZE; i++){
	  if(array[i] > max){
	  max = array[i];
	  }
	}
	return max; 
}

unsigned char find_minimum(unsigned char *array, unsigned int length){
	unsigned char min = array[0];
	for (unsigned int i = 0; i < SIZE; i++){
	  if(array[i] < min){
	  min = array[i];
	  }
	}
	return min; 
}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  unsigned char min = find_minimum(test, SIZE);
  unsigned char max = find_maximum(test, SIZE);	
  unsigned char mean = find_mean(test, SIZE);	
  unsigned char median = find_median(test, SIZE);

  print_statistics(min, max, mean, median);

  printf("Original Array:\n");
  print_array(test, SIZE);

  printf("Sorted Array:\n");
  sort_array(test, SIZE);
  print_array(test, SIZE);		
}

/* Add other Implementation File Code Here */


