#include "space.h"

unsigned char buffer[ELEMENT_SIZE * NUM_BYTE_BUF];
unsigned char byte_buf_mask = 0;

void print_buffer_status(void) {
    int i;

    printf("      byte_buf_mask: ");
    for (i = 0; i < NUM_BYTE_BUF; i++) {
        printf("%d ", (byte_buf_mask >> i) & 1); // 按低位到高位輸出
    }
    printf("\n");
}

void our_malloc(int type, void **target, int *mem_location) {
    int location;

    if (byte_buf_mask == FULL) {
        *target = NULL;
        return;
    } else if (type == TYPE_SMALL) {
        location = test_single_location(byte_buf_mask, NUM_BYTE_BUF);
        if (location >= 0) {
            set_single_bit(&byte_buf_mask, location);
            *target = &buffer[location * ELEMENT_SIZE];
            *mem_location = location;
        } else {
            *target = NULL;
        }
    } else // TYPE_LARGE
    {
        location = test_dual_location(byte_buf_mask, NUM_BYTE_BUF);
        if (location >= 0) {
            set_dual_bit(&byte_buf_mask, location);
            *target = &buffer[location * ELEMENT_SIZE];
            *mem_location = location;
        } else {
            *target = NULL;
        }
    }
}

int test_single_location(unsigned char mask, int mask_length) {
    int i;
    for (i = 0; i < mask_length; i++) {
        if ((mask & (1 << i)) == 0) // Adjusted to match new output order
        {
            return i;
        }
    }
    return -1;
}

void set_single_bit(unsigned char *mask, int location) {
    *mask |= (1 << location); // Adjusted for correct bit setting
}

int test_dual_location(unsigned char mask, int mask_length) {
    int i;
    for (i = 0; i < mask_length - 1; i++) {
        if (((mask & (3 << i)) == 0)) {
            return i;
        }
    }
    return -1;
}

void set_dual_bit(unsigned char *mask, int location) {
    *mask |= (3 << location); // Adjusted for correct bit setting
}

void clear_single_bit(unsigned char *mask, int location) {
    *mask &= ~(1 << location); // Adjusted for correct bit clearing
}

void clear_dual_bit(unsigned char *mask, int location) {
    *mask &= ~(3 << location); // Adjusted for correct bit clearing
}

void our_free(int type, int mem_location) {
    if (type == TYPE_SMALL) {
        clear_single_bit(&byte_buf_mask, mem_location);
    } else if (type == TYPE_LARGE) {
        clear_dual_bit(&byte_buf_mask, mem_location);
    }
}
