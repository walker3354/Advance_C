#ifndef __LIST_H__
#define __LIST_H__

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

tNumStorHead *initial_list();

void list_print(tNumStorHead *list);

void list_add_node(tNumStorHead *list, int add_number, int location,
                   int decision);

void list_del_node(tNumStorHead *list, int location);

#endif