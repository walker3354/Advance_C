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
void print_list(tNumStorHead *list);
void parser(tNumStorHead *list);
void insert_element(tNumStorHead *list);
void inserter(tNumStorHead *list, int decision, int location, int add_number);
void delete_element(tNumStorHead *list);

int main() {
    tNumStorHead *list = (tNumStorHead *)malloc(sizeof(tNumStorHead));
    initial_list(list);
    parser(list);
}

void initial_list(tNumStorHead *list) {
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

void print_list(tNumStorHead *list) {
    tNumStorage *node_ptr = list->head;
    printf("\ncounts: %d\n", list->counts);
    printf("\t From head --> ");
    while (node_ptr != NULL) {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }
    printf("\n\t From tail --> ");
    node_ptr = list->tail;
    while (node_ptr != NULL) {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->pre;
    }
    printf("\n");
}

void parser(tNumStorHead *list) {
    int input = 0;
    while (1) {
        printf("1. Add a number or 2. Delete a number :");
        scanf("%d", &input);
        if (input == -1) {
            break;
        } else if (input == 1) {
            insert_element(list);
        } else if (input == 2) {
            delete_element(list);
        } else {
            printf("\tNo such choice!\n");
        }
    }
}

void insert_element(tNumStorHead *list) {
    int add_number = 0;
    printf("\tAdd a number : ");
    scanf("%d", &add_number);
    if (list->counts == 0) {
        tNumStorage *node = (tNumStorage *)malloc(sizeof(tNumStorage));
        node->number = add_number;
        node->next = NULL;
        node->pre = NULL;
        list->head = node;
        list->tail = node;
        list->counts++;
    } else {
        int location = 0, decision = 0;
        printf("\t Specify a target location: ");
        scanf("%d", &location);
        if (location > list->counts || location < 0) {
            printf("\t out of list\n");
            return;
        }
        printf("\t 1. Before or 2. After the location %d: ", location);
        scanf("%d", &decision);
        inserter(list, decision, location, add_number);
    }
    print_list(list);
}

void inserter(tNumStorHead *list, int decision, int location, int add_number) {
    if (decision == 1 || decision == 2) {
        tNumStorage *node = (tNumStorage *)malloc(sizeof(tNumStorage));
        node->number = add_number;
        tNumStorage *temp_node = list->head;
        for (int i = 0; i < (decision == 1 ? location - 1 : location); i++) {
            if (temp_node->next == NULL) break;
            temp_node = temp_node->next;
        }
        if (decision == 1) {
            node->pre = temp_node->pre;
            node->next = temp_node;
            if (temp_node->pre != NULL) {
                temp_node->pre->next = node;
            } else {
                list->head = node;
            }
            temp_node->pre = node;
        } else {
            node->next = temp_node->next;
            node->pre = temp_node;
            if (temp_node->next != NULL) {
                temp_node->next->pre = node;
            } else {
                list->tail = node;
            }
            temp_node->next = node;
        }
        list->counts++;
    } else {
        printf("unexpected decision\n");
    }
}

void delete_element(tNumStorHead *list) {
    int location = 0;
    printf("\tSpecify a target location: ");
    scanf("%d", &location);
    if (location < 0 || location >= list->counts) {
        printf("\tUnexpected location\n");
        return;
    }
    tNumStorage *temp_node = list->head;
    for (int i = 0; i < location; i++) {
        temp_node = temp_node->next;
    }
    if (temp_node->pre != NULL) {
        temp_node->pre->next = temp_node->next;
    } else {
        list->head = temp_node->next;
    }
    if (temp_node->next != NULL) {
        temp_node->next->pre = temp_node->pre;
    } else {
        list->tail = temp_node->pre;
    }
    free(temp_node);
    list->counts--;
    print_list(list);
}
