#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_ascending(char a, char b) { return a > b; }

int compare_descending(char a, char b) { return a < b; }

void bubble_sort(char *array, int length, int (*compare)(char, char)) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (compare(array[j], array[j + 1])) {
                char temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int choice;
    char *input = NULL;
    size_t buffer_size = 0; // 用於 getline 的緩衝大小
    int (*compare_funcs[2])(char, char) = {compare_ascending,
                                           compare_descending};
    printf("Please enter (0) increasing or (1) descending sort: ");
    scanf("%d", &choice);
    getchar();
    if (choice < 0 || choice > 1) {
        printf("Invalid choice!\n");
        return 1;
    }
    printf("Please enter a string: ");
    getline(&input, &buffer_size, stdin);
    size_t length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
        char *array = (char *)malloc(length + 1);
        if (array == NULL) {
            printf("Memory allocation failed!\n");
            free(input);
            return 1;
        }
        strcpy(array, input);
        bubble_sort(array, length, compare_funcs[choice]);
        printf("Result: %s\n", array);
        return 0;
    }
}