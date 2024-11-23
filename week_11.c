#include <stdio.h>
typedef unsigned int Int32;

int check_range_loop(Int32 input, Int32 high, Int32 low);
int check_range_no_loop(Int32 input, Int32 high, Int32 low);

int main() {
    Int32 input, high, low; // I think high and low should be unsigned Int8
    int decision = 1;
    while (decision) {
        printf("Please specifiy the input: ");
        sacnf("%x", &input);
        printf("\tPlease specify the high: ");
        scanf("%u", &high);
        printf("\tPlease specify the low:");
        scanf("%u", &low);
        printf("check_range_loop: %d\n", check_range_loop(input, high, low));
        printf("check_range_no_loop: %d\n",
               check_range_no_loop(input, high, low));
        printf("Input 1 to keep trying the next round: ");
        scanf("%d", &decision);
    }
}

int check_range_loop(Int32 input, Int32 high, Int32 low) {
    for (Int32 i = low; i <= high; i++) { // same
        if ((input & (1 << i)) == 1) return 1;
    }
    return 0;
}

int check_range_no_loop(Int32 input, Int32 high, Int32 low) {
    Int32 mask = ((1 << (high - low + 1)) - 1) << low;
    return (input & mask) != 0;
}