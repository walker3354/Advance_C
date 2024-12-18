#include "main.h"

#include "queue.h"
#include "space.h"

int main(void) {
    int operation;
    int id, ret;
    tQueue *queue;
    tQueueNode *target_node;

    // 創建佇列
    queue = createQueue();

    while (1) {
        printf("Remaining memory space: %d\n", calculate_remaining_space());
        printf("\nWhich type you are going to operate? \n");
        printf("1. Add a type 1 (small) item\n");
        printf("2. Add a type 2 (big) item\n");
        printf("3. Remove a type 1 item with a specific Id\n");
        printf("4. Remove a type 2 item with a specific Id\n");
        scanf("%d", &operation);

        if (operation == 1 || operation == 2) {
            printf("  Enter id: ");
            scanf("%d", &id);

            ret = enqueue_node(queue, id,
                               (operation == 1 ? TYPE_SMALL : TYPE_LARGE));
            if (ret == 0) {
                printf("    Cannot enter to the queue\n");
            }
            print_buffer_status();
            printf("Remaining memory space: %d\n", calculate_remaining_space());
        } else if (operation == 3 || operation == 4) {
            printf("  Enter an ID to remove: ");
            scanf("%d", &id);

            target_node = find_target_node(queue, id);
            if (target_node == NULL) {
                printf("    Cannot find the target node\n");
            } else {
                dequeue_node(queue, target_node);
            }
            print_buffer_status();
        } else {
            printf("    No such operation\n");
        }

        print_queue(queue); // 顯示當前佇列內容
    }

    return 0;
}
