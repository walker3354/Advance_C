#include <stdio.h>
#include <stdlib.h>

typedef struct num_list {
        int counts;
        int* p_lis;
} tNumList;

int list_counter = 1;

void fill_list(tNumList* list);
void bubble_sort(tNumList* list);
void merge(tNumList* list1, tNumList* list2);
void print_list(tNumList* list);

int main() {
    tNumList* list1 = (tNumList*)malloc(sizeof(tNumList));
    tNumList* list2 = (tNumList*)malloc(sizeof(tNumList));
    fill_list(list1);
    fill_list(list2);
    bubble_sort(list1);
    bubble_sort(list2);
    print_list(list1);
    print_list(list2);
    merge(list1, list2);
}

void fill_list(tNumList* list) {
    printf("please enter how many numbers in list%d: ", list_counter++);
    scanf("%d", &(list->counts));
    list->p_lis = (int*)malloc(sizeof(int) * list->counts);
    printf("\tPlease input %d numbers: ", list->counts);
    for (int i = 0; i < list->counts; i++) {
        scanf("%d", list->p_lis + i);
    }
}

void bubble_sort(tNumList* list) {
    for (int i = 0; i < list->counts - 1; i++) {
        for (int j = 0; j < list->counts - 1 - i; j++) {
            if (*(list->p_lis + j) > *(list->p_lis + j + 1)) {
                int temp = *(list->p_lis + j);
                *(list->p_lis + j) = *(list->p_lis + j + 1);
                *(list->p_lis + j + 1) = temp;
            }
        }
    }
}

void merge(tNumList* list1, tNumList* list2) {
    int list1_p = 0;
    int list2_p = 0;
    printf("\nmerged list: ");
    while (list1_p < list1->counts && list2_p < list2->counts) {
        if (*(list1->p_lis + list1_p) <= *(list2->p_lis + list2_p)) {
            printf("%d ", *(list1->p_lis + list1_p++));
        } else {
            printf("%d ", *(list2->p_lis + list2_p++));
        }
    }

    if (list1_p >= list1->counts) {
        for (int i = list2_p; i < list2->counts; i++) {
            printf("%d ", *(list2->p_lis + i));
        }
    } else {
        for (int i = list1_p; i < list1->counts; i++) {
            printf("%d ", *(list1->p_lis + i));
        }
    }
}

void print_list(tNumList* list) {
    printf("\nsorted list%d: ", list_counter / 2);
    for (int i = 0; i < list->counts; i++) {
        printf("%d ", *(list->p_lis + i));
    }
}