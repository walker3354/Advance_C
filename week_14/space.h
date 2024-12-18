#ifndef __SPACE__
#define __SPACE__

#include "main.h"

#define NUM_BYTE_BUF 3
#define ELEMENT_SIZE 32
#define FULL_MASK ((1 << 23) - 1)
#define TOTAL_MEMORY_UNITS 23

void print_buffer_status(void);
int calculate_remaining_space(void);

void our_malloc(int type, void **target, int *mem_location);
void our_free(int type, int mem_location);

int test_single_location(unsigned int mask, int mask_length);
void set_single_bit(unsigned int *mask, int location);
void clear_single_bit(unsigned int *mask, int location);

#endif
