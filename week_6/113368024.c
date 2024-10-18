#include <stdio.h>
#include <stdlib.h>

typedef struct num_storage {
        int number;
        struct num_storage *next;
} tNumStorage;

typedef struct num_stor_head {
        int counts;
        struct num_storage *head;
        struct num_storage *tail;
} tNumStorHead;

void initial_list(tNumStorHead *list);
void get_input(tNumStorHead *list);
void print_list(tNumStorHead *list);
void sort_list(tNumStorHead *list, int input);

int main() {
    int i;
    tNumStorHead *list = (tNumStorHead *)malloc(sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
}

void initial_list(tNumStorHead *list) {
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

void get_input(tNumStorHead *list) {
    int input;
    printf("Input a number: ");
    scanf("%d", &input);
    while (input != -1) {
        list->counts++;
        printf("\tlist->counts: %d", list->counts);
        sort_list(list, input);
        print_list(list);
        printf("\nInput a number: ");
        scanf("%d", &input);
    }
    print_list(list);
}

void print_list(tNumStorHead *list) {
    tNumStorage *node_ptr = list->head;
    printf("\n\tThe sorted list: ");
    while (node_ptr != NULL) {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }
}

void sort_list(tNumStorHead *list, int input) {
    tNumStorage *node = (tNumStorage *)malloc(sizeof(tNumStorage));
    tNumStorage *temp_node = list->head;
    node->number = input;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else if (input <= temp_node->number) {
        node->next = temp_node;
        list->head = node;
    } else {
        while (temp_node->next != NULL && temp_node->next->number < input) {
            temp_node = temp_node->next;
        }
        node->next = temp_node->next;
        temp_node->next = node;
        if (node->next == NULL) {
            list->tail = node;
        }
    }
}