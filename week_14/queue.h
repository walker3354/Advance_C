#ifndef __QUEUE__
#define __QUEUE__

typedef struct queue_node {
        int id;
        int location;
        int data_type;
        struct queue_node *next;
        struct queue_node *prev;
} tQueueNode;

typedef struct {
        tQueueNode *front;
        tQueueNode *rear;
        int count;
} tQueue;

tQueue *createQueue(void);
int enqueue_node(tQueue *queue, int id, int data_type);
void dequeue_node(tQueue *queue, tQueueNode *target);
tQueueNode *find_target_node(tQueue *queue, int id);
void print_queue(tQueue *queue);

#endif
