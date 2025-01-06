#include "queue.h"

#include "space.h"

tQueue *createQueue(void) {
    tQueue *queue = (tQueue *)malloc(sizeof(tQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
}

int enqueue_node(tQueue *queue, int id, int score, int data_type) {
    tQueueNode *new_node = (tQueueNode *)malloc(sizeof(tQueueNode));
    new_node->type = data_type;
    if (data_type == 1) {
        tQueueSmall *new_small_node =
            (tQueueSmall *)malloc(sizeof(tQueueSmall));
        new_small_node->id = id;
        new_small_node->score = score;
        new_node->content = new_small_node;
    } else {
        tQueueLarge *new_large_node =
            (tQueueLarge *)malloc(sizeof(tQueueLarge));
        new_large_node->id = id;
        new_large_node->score[0] = score;
        new_node->content = new_large_node;
    }
    new_node->next = NULL;
    new_node->prev = NULL;
    if (queue->count == 0) {
        queue->front = queue->rear = new_node;
    } else {
        new_node->prev = queue->rear;
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->count++;
    return 1;
}

void dequeue_node(tQueue *queue, tQueueNode *target, int data_type) {
    if (queue == NULL || target == NULL) {
        printf("No such file!\n");
        return;
    }
    if (target == queue->front) {
        queue->front = target->next;
        if (queue->front != NULL) {
            queue->front->prev = NULL;
        }
    } else {
        target->prev->next = target->next;
    }
    if (target == queue->rear) {
        queue->rear = target->prev;
        if (queue->rear != NULL) {
            queue->rear->next = NULL;
        }
    } else {
        target->next->prev = target->prev;
    }
    if (data_type == 1) {
        free((tQueueSmall *)target->content);
    } else if (data_type == 2) {
        free((tQueueLarge *)target->content);
    }
    free(target);
    queue->count--;
}

tQueueNode *find_target_node(tQueue *queue, int id, int data_type) {
    tQueueNode *temp = queue->front;
    while (temp != NULL) {
        if (temp->type == data_type) {
            if (data_type == 1) {
                tQueueSmall *small_node = (tQueueSmall *)temp->content;
                if (small_node->id == id) {
                    return temp;
                }
            } else if (data_type == 2) {
                tQueueLarge *large_node = (tQueueLarge *)temp->content;
                if (large_node->id == id) {
                    return temp;
                }
            }
        }
        temp = temp->next;
    }
    return NULL;
}

void print_queue(tQueue *queue) {
    int small_counter = 0;
    int large_counter = 8;
    tQueueNode *temp = queue->front;
    printf("\n\ttype mixed queue: ");
    while (temp != NULL) {
        if (temp->type == 1) {
            printf("%d,%d(1,%d) ", ((tQueueSmall *)temp->content)->id,
                   ((tQueueSmall *)temp->content)->score, small_counter++);
        } else {
            printf("%d,%d(2,%d) ", ((tQueueLarge *)temp->content)->id,
                   ((tQueueLarge *)temp->content)->score, large_counter++);
        }
        temp = temp->next;
    }
    printf("\n");
}
