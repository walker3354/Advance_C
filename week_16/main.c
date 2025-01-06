#include "main.h"

#include "queue.h"
#include "space.h"

int main(void) {
    int operation, id, score, ret;
    tQueue *queue;
    tQueueNode *target_node;
    void *target_mem;
    int mem_location;

    queue = createQueue();

    while (1) {
        printf("\nWhich type you are going to operate? \n");
        printf("1. Add a type 1 (small) item\n");
        printf("2. Add a type 2 (big) item\n");
        printf("3. Remove a type 1 item with a specific Id\n");
        printf("4. Remove a type 2 item with a specific Id\n");
        printf("5. Exit\n");
        scanf("%d", &operation);

        if (operation == 5) {
            printf("Exiting...\n");
            break;
        }

        switch (operation) {
            case 1:
                printf("Enter id and score: ");
                scanf("%d %d", &id, &score);

                our_malloc(1, &target_mem, &mem_location);
                if (target_mem == NULL) {
                    printf("Allocation failed! No space available.\n");
                    continue;
                }

                ret = enqueue_node(queue, id, score, 1);
                if (ret == 0) {
                    printf("Enqueue Failed !!!\n");
                    our_free(1, mem_location);
                } else {
                    print_buffer_status();
                    print_queue(queue);
                }
                break;

            case 2:
                printf("Enter id and score: ");
                scanf("%d %d", &id, &score);

                our_malloc(2, &target_mem, &mem_location);
                if (target_mem == NULL) {
                    printf("Allocation failed! No space available.\n");
                    continue;
                }

                ret = enqueue_node(queue, id, score, 2);
                if (ret == 0) {
                    printf("Enqueue Failed !!!\n");
                    our_free(2, mem_location);
                } else {
                    print_buffer_status();
                    print_queue(queue);
                }
                break;

            case 3:
                printf("Enter an ID to remove: ");
                scanf("%d", &id);

                target_node = find_target_node(queue, id, 1);
                if (target_node == NULL) {
                    printf("Cannot find the target node\n");
                } else {
                    dequeue_node(queue, target_node, 1);
                    print_buffer_status();
                    print_queue(queue);
                }
                break;

            case 4:
                printf("Enter an ID to remove: ");
                scanf("%d", &id);

                target_node = find_target_node(queue, id, 2);
                if (target_node == NULL) {
                    printf("Cannot find the target node\n");
                } else {
                    dequeue_node(queue, target_node, 2);
                    print_buffer_status();
                    print_queue(queue);
                }
                break;

            default:
                printf("Invalid operation! Try again.\n");
                break;
        }
    }

    return 0;
}
