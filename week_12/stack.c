#include "stack.h"

tStack *create_stack(void) {
    tStack *stack_ptr = (tStack *)malloc(sizeof(tStack));
    stack_ptr->count = 0;
    stack_ptr->head = NULL;
    return stack_ptr;
}

void handle_push_operation(tStack *stack_ptr) {
    if (stack_ptr->count >= N)
        printf("[Error]  handle_push_operation(): space full \n");
    else {
        int score;
        tNode *new_node = (tNode *)malloc(sizeof(tNode));
        printf("  handle_push_operation(): enter score value: ");
        scanf("%d", &score);
        get_score_space(&(new_node->data_ptr));
        new_node->next = stack_ptr->head;
        new_node->data_ptr->score = score;
        stack_ptr->head = new_node;
        stack_ptr->count++;
    }
}

void handle_pop_operation(tStack *stack_ptr) {
    if (stack_ptr->count == 0)
        printf("[Error]  handle_pop_operation(): nothing in stack = \n");
    else {
        tNode *temp_p = stack_ptr->head;
        printf("  handle_pop_operation(): poped value: %d\n",
               temp_p->data_ptr->score);
        return_score_space(temp_p->data_ptr->loc);
        stack_ptr->head = temp_p->next;
        stack_ptr->count--;
        free(temp_p);
    }
}

void print_stack_content(tStack *stack_ptr) {
    printf("   print_stack_content(): stack items -> ");
    tNode *temp_p = stack_ptr->head;
    for (int i = 0; i < stack_ptr->count; i++) {
        printf(" %d(%d)", temp_p->data_ptr->score, temp_p->data_ptr->loc);
        temp_p = temp_p->next;
    }
    printf("\n");
}
