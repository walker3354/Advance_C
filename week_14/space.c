#include "space.h"

unsigned char buffer[ELEMENT_SIZE * NUM_BYTE_BUF]; // 3 bytes (24位元)記憶體池
unsigned int byte_buf_mask = 0;                    // 位元遮罩 (23位有效位元)

void print_buffer_status(void) {
    printf("      buffer_mask: ");
    for (int i = 0; i < TOTAL_MEMORY_UNITS; i++) {
        printf("%d ", (byte_buf_mask & (1 << i)) ? 1 : 0);
        if ((i + 1) % 7 == 0 &&
            i != TOTAL_MEMORY_UNITS - 1) { // 每7位元後加逗號
            printf(", ");
        }
    }
    printf("\n");
}

int calculate_remaining_space(void) {
    int count = 0;
    for (int i = 0; i < TOTAL_MEMORY_UNITS; i++) {
        if ((byte_buf_mask & (1 << i)) == 0) {
            count++;
        }
    }
    return count;
}

void our_malloc(int type, void **target, int *mem_location) {
    int location;

    if (byte_buf_mask == FULL_MASK) {
        *target = NULL;
        *mem_location = -1;
        return;
    }

    location = test_single_location(byte_buf_mask, TOTAL_MEMORY_UNITS);
    if (location >= 0) {
        set_single_bit(&byte_buf_mask, location);
        *target = &buffer[location * ELEMENT_SIZE];
        *mem_location = location;
    } else {
        *target = NULL;
        *mem_location = -1;
    }
}

void our_free(int type, int mem_location) {
    clear_single_bit(&byte_buf_mask, mem_location);
}

int test_single_location(unsigned int mask, int mask_length) {
    for (int i = 0; i < mask_length; i++) {
        if ((mask & (1 << i)) == 0) {
            return i;
        }
    }
    return -1;
}

void set_single_bit(unsigned int *mask, int location) {
    *mask |= (1 << location);
}

void clear_single_bit(unsigned int *mask, int location) {
    *mask &= ~(1 << location);
}
