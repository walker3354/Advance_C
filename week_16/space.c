#include "space.h"

unsigned char buffer[SMALL_ELEMENT_SIZE * NUM_SMALL_BYTE_BUF +
                     LARGE_ELEMENT_SIZE * NUM_LARGE_BYTE_BUF];

unsigned char byte_large_buf_mask = 0;
unsigned char byte_small_buf_mask = 0;

void print_buffer_status(void) {
    printf("\n\tbyte_small_buf_mask: ");
    for (int i = NUM_SMALL_BYTE_BUF - 1; i >= 0; i--) {
        printf("%d", (byte_small_buf_mask >> i) & 1);
    }
    printf("\n\tbyte_large_buf_mask: ");
    for (int i = NUM_LARGE_BYTE_BUF - 1; i >= 0; i--) {
        printf("%d", (byte_large_buf_mask >> i) & 1);
    }
}

void our_malloc(int type, void **target, int *mem_location) {
    int location;
    if (type == 1) {
        location =
            test_single_location(byte_small_buf_mask, NUM_SMALL_BYTE_BUF);
        if (location == -1) {
            *target = NULL;
            *mem_location = -1;
            return;
        }
        set_single_bit(&byte_small_buf_mask, location);
        *target = (void *)(buffer + location * SMALL_ELEMENT_SIZE);
        *mem_location = location;
    } else if (type == 2) {
        location = test_dual_location(byte_large_buf_mask, NUM_LARGE_BYTE_BUF);
        if (location == -1) {
            *target = NULL;
            *mem_location = -1;
            return;
        }
        set_dual_bit(&byte_large_buf_mask, location);
        *target =
            (void *)(buffer + LARGE_START + location * LARGE_ELEMENT_SIZE);
        *mem_location = location;
    } else {
        *target = NULL;
        *mem_location = -1;
    }
}

void our_free(int type, int mem_location) {
    if (type == 1) { // 釋放小型記憶體區塊
        if (mem_location < 0 || mem_location >= NUM_SMALL_BYTE_BUF) {
            printf("Error: Invalid memory location for small block.\n");
            return;
        }
        clear_single_bit(&byte_small_buf_mask, mem_location); // 清除單個位
    } else if (type == 2) { // 釋放大型記憶體區塊
        if (mem_location < 0 || mem_location >= NUM_LARGE_BYTE_BUF) {
            printf("Error: Invalid memory location for large block.\n");
            return;
        }
        clear_dual_bit(&byte_large_buf_mask, mem_location); // 清除連續兩個位
    } else {
        printf("Error: Invalid memory type.\n");
    }
}

int test_single_location(unsigned char mask, int mask_length) {
    for (int i = 0; i < mask_length; i++) {
        if (((mask >> i) & 1) == 0) return i;
    }
    return -1;
}

void set_single_bit(unsigned char *mask, int location) {
    *mask = *mask | 1 << location;
}

int test_dual_location(unsigned char mask, int mask_length) {
    for (int i = 0; i < mask_length - 1; i++) {
        if (((mask >> i) & 3) == 0) return i;
    }
    return -1;
}

void set_dual_bit(unsigned char *mask, int location) {
    *mask = *mask | 3 << location;
}

void clear_single_bit(unsigned char *mask, int location) {
    *mask = *mask & ~(1 << location);
}

void clear_dual_bit(unsigned char *mask, int location) {
    *mask = *mask & ~(3 << location);
}