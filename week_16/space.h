#ifndef __SPACE__
#define __SPACE__

#include "main.h"

#define NUM_SMALL_BYTE_BUF 8
#define NUM_LARGE_BYTE_BUF 8

#define SMALL_ELEMENT_SIZE 32
#define LARGE_ELEMENT_SIZE 64
#define LARGE_START (SMALL_ELEMENT_SIZE * NUM_SMALL_BYTE_BUF)

void print_buffer_status(void);

void our_malloc(int type, void **target, int *mem_location);
void our_free(int type, int mem_location);

int test_single_location(unsigned char mask, int mask_length);
void set_single_bit(unsigned char *mask, int location);

int test_dual_location(unsigned char mask, int mask_length);
void set_dual_bit(unsigned char *mask, int location);

void clear_single_bit(unsigned char *mask, int location);
void clear_dual_bit(unsigned char *mask, int location);

#endif