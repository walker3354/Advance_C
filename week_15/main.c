#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4
typedef char my_int[MAX];

void my_add(const char* input_1, const char* input_2);
void my_number_print(const char* result);
int validate_input(const char* input);

int main(void) {
    my_int input_1;
    my_int input_2;

    printf("Enter up to 3 digits: ");
    scanf("%3s", input_1);
    if (!validate_input(input_1)) {
        printf("Invalid input.\n");
        system("pause");
        return 1;
    }

    printf("Enter up to 3 digits: ");
    scanf("%3s", input_2);
    if (!validate_input(input_2)) {
        printf("Invalid input.\n");
        system("pause");
        return 1;
    }

    my_add(input_1, input_2);
    system("pause");
    return 0;
}

void my_add(const char* input_1, const char* input_2) {
    my_int result = {'0', '0', '0', '\0'};
    int carry = 0;
    int len1 = strlen(input_1);
    int len2 = strlen(input_2);

    for (int i = 1; i < MAX; i++) {
        int pos1 = len1 - i;
        int pos2 = len2 - i;
        int digit1 = (pos1 >= 0) ? (input_1[pos1] - '0') : 0;
        int digit2 = (pos2 >= 0) ? (input_2[pos2] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[MAX - 1 - i] = (sum % 10) + '0';
    }

    if (carry > 0) {
        printf("Overflow!\n");
        return;
    }
    my_number_print(result);
}

void my_number_print(const char* result) {
    printf("Result: ");
    {
        int leading_zero = 1;
        for (int i = 0; i < MAX - 1; i++) {
            if (result[i] != '0' || !leading_zero) {
                printf("%c", result[i]);
                leading_zero = 0;
            }
        }
        if (leading_zero) {
            printf("0");
        }
    }
    printf("\n");
}

int validate_input(const char* input) {
    if (strlen(input) > 3 || strspn(input, "0123456789") != strlen(input)) {
        return 0;
    }
    return 1;
}
