#include "queue.h"

#include "space.h"

tQueue *createQueue(void) {
    tQueue *queue;
    queue = (tQueue *)malloc(sizeof(tQueue));

    if (queue) {
        queue->front = NULL;
        queue->rear = NULL;
        queue->count = 0;
    }

    return queue;
}

int enqueue_node(tQueue *queue, int id, int score, int data_type) {
    tQueueNode *newptr = NULL;
    int mem_location;

    // Memory allocation
    our_malloc(data_type, (void **)&newptr, &mem_location);

    if (newptr == NULL) {
        printf("    Enqueue False!!! \n");
        return 0;
    }

    // Initialize the new node
    newptr->id = id;
    newptr->score = score;
    newptr->location = mem_location;
    newptr->data_type =
        data_type + 1; // Adjust data_type for correct output format
    newptr->next = NULL;
    newptr->prev = NULL; // Ensure previous pointer is initialized

    // Add to the queue
    if (queue->rear == NULL) // Empty queue
    {
        queue->front = queue->rear = newptr;
    } else // Non-empty queue
    {
        queue->rear->next = newptr;
        newptr->prev = queue->rear;
        queue->rear = newptr;
    }

    queue->count++;
    return 1;
}

void dequeue_node(tQueue *queue, tQueueNode *target, int data_type) {
    if (target == NULL) return;

    // Unlink the target node
    if (target->prev)
        target->prev->next = target->next;
    else
        queue->front = target->next; // Update front if first node is removed

    if (target->next)
        target->next->prev = target->prev;
    else
        queue->rear = target->prev; // Update rear if last node is removed

    // Free memory
    our_free(data_type, target->location);
    free(target);
    queue->count--;
}

tQueueNode *find_target_node(tQueue *queue, int id, int data_type) {
    tQueueNode *current = queue->front;

    // Traverse to find the target node
    while (current != NULL) {
        if (current->id == id &&
            current->data_type == data_type + 1) // Match adjusted data_type
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void print_queue(tQueue *queue) {
    tQueueNode *current = queue->front;

    printf("      queue content: ");
    while (current != NULL) {
        printf("%d(%d) ", current->id,
               current->data_type); // Output adjusted data_type
        current = current->next;
    }
    printf("\n");
}
