#include "stack.h"

int main(void) {

    tStack *stack_ptr = create_stack();
    int choose;

    while (1)
    {
        //menu 
        printf("\n(1) push or (2) pop a item to/from stack: ");
        scanf("%d", &choose);

        if (choose == 1)
        {
            handle_push_operation(stack_ptr);
        }
        else if (choose == 2)
        {
            handle_pop_operation(stack_ptr);
        }
        print_stack_content(stack_ptr);
    }
    
    return 0;
}
