#ifndef __STACK_H__ 
#define __STACK_H__

#include "space.h"

typedef struct node
{
    tTypeScore *data_ptr;
    struct node *next;
}tNode;

typedef struct nodeInfo
{
    int count;
    tNode *head;
}tStack;

tStack *create_stack(void);  //Create a stack
void handle_push_operation (tStack *stack_ptr); //push a data_ptr to a specific stack
void handle_pop_operation (tStack *stack_ptr); //pop a specific stack and return a void* data_ptr
void print_stack_content(tStack *stack_ptr); //print all content in stack

#endif