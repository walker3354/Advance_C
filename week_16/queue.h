#ifndef __QUEUE__
#define __QUEUE__

typedef struct type_small {
        int id;
        int location;
        int score;
} tQueueSmall;

typedef struct type_larg {
        int id;
        int location;
        int score[8];
} tQueueLarge;

typedef struct node_info {
        int type;
        void *content;
        struct node_info *next;
        struct node_info *prev;
} tQueueNode;

typedef struct {
        tQueueNode *front;
        tQueueNode *rear;
        int count;
} tQueue;

#endif