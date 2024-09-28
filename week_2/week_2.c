#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_array_first(int square_w, int len, char** num_list);
char** display_array_second(int square_w, int len, char** num_list);
void display_array_third(int square_w, int len, char** num_list);

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    int square_w = (int)sqrt(len);

    display_array_first(square_w, len, argv + 2);
    char** temp = display_array_second(square_w, len, argv + 2);
    display_array_third(square_w, len, temp);
}

void display_array_first(int square_w, int len, char** num_list) {
    printf("The first array is:\n");
    for (int i = 0; i < len; i++) {
        printf("%s\t", *(num_list + i));
        if (i != 0 && (i + 1) % square_w == 0) {
            printf("\n");
        }
    }
}

char** display_array_second(int square_w, int len, char** num_list) {
    printf("The second array is:\n");
    char** temp = (char**)malloc(len * sizeof(char*));
    for (int i = 0; i < len; i++) {
        temp[i] = (char*)malloc(10 * sizeof(char));
    }
    for (int i = 0; i < len; i++) {
        if (i < square_w) {
            printf("%s\t", *(num_list + 2 * square_w + i));
            strcpy(*(temp + i), *(num_list + 2 * square_w + i));
        } else if (i >= square_w * 2 && i < square_w * 3) {
            printf("%s\t", *(num_list + i - 2 * square_w));
            strcpy(*(temp + i), *(num_list + i - 2 * square_w));
        } else {
            printf("%s\t", *(num_list + i));
            strcpy(*(temp + i), *(num_list + i));
        }
        if (i != 0 && (i + 1) % square_w == 0) {
            printf("\n");
        }
    }
    return temp;
}

void display_array_third(int square_w, int len, char** num_list) {
    printf("The third array is:\n");
    for (int i = 0; i < square_w; i++) {
        char* temp = *(num_list + i * square_w);
        *(num_list + i * square_w) = *(num_list + i * square_w + 2);
        *(num_list + i * square_w + 2) = temp;
    }

    for (int i = 0; i < len; i++) {
        printf("%s\t", *(num_list + i));
        if (i != 0 && (i + 1) % square_w == 0) {
            printf("\n");
        }
    }
}