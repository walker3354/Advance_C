#include "stdio.h"
#include "stdlib.h"

void memory_protection(char** temp) {
    if (*temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

int get_input_len(char** str) {
    int size = 1;
    int len = 0;
    char temp;

    *str = (char*)malloc(size * sizeof(char));
    memory_protection(str);

    while ((temp = getchar()) != '\n' && temp != EOF) {
        (*str)[len++] = temp;
        if (len >= size) {
            size *= 2;
            *str = (char*)realloc(*str, size * sizeof(char));
            memory_protection(str);
        }
    }
    (*str)[len] = '\0';
    return len;
}

int inversions_char_counter(char* str, int len) {
    int counter = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                counter++;
            }
        }
    }
    return counter;
}

int main() {
    char* input_string = NULL;
    printf("Please input a character sequence: ");
    int len = get_input_len(&input_string);
    printf("The number of inversions in the character sequence is: %d\n",
           inversions_char_counter(input_string, len));
    return 0;
}