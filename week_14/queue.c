#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

#include "space.h"

tQueue *createQueue(void) {
    tQueue *queue = (tQueue *)malloc(sizeof(tQueue));
    if (queue) {
        queue->front = queue->rear = NULL;
        queue->count = 0;
    }
    return queue;
}

int enqueue_node(tQueue *queue, int id, int data_type) {
    tQueueNode *newptr = (tQueueNode *)malloc(sizeof(tQueueNode));
    int mem_location;
    void *buffer_location;

    our_malloc(data_type, &buffer_location, &mem_location);
    if (mem_location == -1 || newptr == NULL) {
        printf("    Enqueue False!!!\n");
        free(newptr);
        return 0;
    }

    newptr->id = id;
    newptr->location = mem_location;
    newptr->data_type = data_type;
    newptr->next = newptr->prev = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newptr;
    } else {
        queue->rear->next = newptr;
        newptr->prev = queue->rear;
        queue->rear = newptr;
    }
    queue->count++;
    return 1;
}

void dequeue_node(tQueue *queue, tQueueNode *target) {
    if (!target) return;

    if (target->prev) target->prev->next = target->next;
    if (target->next) target->next->prev = target->prev;

    if (queue->front == target) queue->front = target->next;
    if (queue->rear == target) queue->rear = target->prev;

    our_free(target->data_type, target->location);
    free(target);
    queue->count--;
}

tQueueNode *find_target_node(tQueue *queue, int id) {
    tQueueNode *current = queue->front;
    while (current) {
        if (current->id == id) return current;
        current = current->next;
    }
    return NULL;
}

void print_queue(tQueue *queue) {
    tQueueNode *current = queue->front;
    printf("      queue content: ");
    while (current) {
        printf("%d(%d, %d) ", current->id, current->location,
               current->data_type);
        current = current->next;
    }
    printf("\n");
}
