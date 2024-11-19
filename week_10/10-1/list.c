#include "list.h"

tNumStorHead *initial_list() {
    tNumStorHead *list = (tNumStorHead *)malloc(sizeof(tNumStorHead));
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void list_print(tNumStorHead *list) {
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

void list_add_node(tNumStorHead *list, int add_number, int location,
                   int decision) {
    if (list->counts == 0) {
        tNumStorage *node = (tNumStorage *)malloc(sizeof(tNumStorage));
        node->number = add_number;
        node->next = NULL;
        node->pre = NULL;
        list->head = node;
        list->tail = node;
        list->counts++;
    } else {
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
    }
    list_print(list);
}

void list_del_node(tNumStorHead *list, int location) {
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
    list_print(list);
}
