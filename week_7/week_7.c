#include <stdio.h>
#include <stdlib.h>

typedef struct num_storage {
        int number;
        struct num_storage *next;
        struct num_storage *pre;
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
void delete_last(tNumStorHead *list);

int main() {
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
    int input = 0;
    while (input != -1) {
        printf("\nInput a number (-1 to exit, -2 to delete last): ");
        scanf("%d", &input);
        if (input == -2) {
            delete_last(list);
        } else if (input != -1) {
            sort_list(list, input);
        }
    }
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
    node->pre = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else if (input <= temp_node->number) {
        node->next = temp_node;
        temp_node->pre = node;
        list->head = node;
    } else {
        while (temp_node->next != NULL && temp_node->next->number < input) {
            temp_node = temp_node->next;
        }
        node->next = temp_node->next;
        if (temp_node->next != NULL) {
            temp_node->next->pre = node;
        }
        temp_node->next = node;
        node->pre = temp_node;
        if (node->next == NULL) {
            list->tail = node;
        }
    }
    list->counts++;
    print_list(list);
}

void delete_last(tNumStorHead *list) {
    if (list->counts == 1) {
        list->counts--;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else if (list->counts != 0) {
        list->counts--;
        tNumStorage *temp = list->tail;
        list->tail = list->tail->pre;
        list->tail->next = NULL;
        free(temp);
    }
    print_list(list);
}