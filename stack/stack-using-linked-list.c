/*
 *
 * Stack Data Structure
 *
 *    Uses:
 *      Linked List
 *
 *    Sample Operations:
 *      push, peek, pop, isEmpty
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_EMPTY_VALUE (-1)

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct stack {
    node* top;
} stack;

int push(stack* stack, int value);
int peek(stack* stack);
int pop(stack* stack);
int isEmpty(stack* stack);

int main() {
    stack* my_stack = calloc(1, sizeof(stack));

    // Stack is empty and should display 1.
    printf("isEmpty = %d\n", isEmpty(my_stack));

    // Peek and pop on empty stack displays
    // an error and DEFAULT_EMPTY_VALUE.
    printf("Peek: %d\n", peek(my_stack));
    printf("Pop: %d\n", pop(my_stack));

    // Push returns the value added to it
    // for the convenience of this sample.
    printf("Push: %d\n", push(my_stack, 99));
    printf("Push: %d\n", push(my_stack, 88));
    printf("Push: %d\n", push(my_stack, 77));

    printf("Pop: %d\n", pop(my_stack));
    printf("Push: %d\n", push(my_stack, 66));

    // Loop through the stack and display
    // all remaining values until empty.
    while (!isEmpty(my_stack)) {
        printf("Peek: %d\n", peek(my_stack));
        printf("Pop: %d\n", pop(my_stack));
    }

    // Free the memory allocated for the stack.
    free(my_stack);
    my_stack = NULL;

    return 0;
}

/*
 *
 * Stack Implementation
 *
 */

/// Adds a value to the stack.
/// \param stack
/// \param value
/// \return value added to stack
int push(stack* stack, int value) {
    node* new_node = calloc(1, sizeof(node));
    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;

    return value;
}

/// Returns last value added to the stack.
/// \param stack
/// \return last added value if not empty,
/// otherwise DEFAULT_EMPTY_VALUE
int peek(stack* stack) {
    int value = DEFAULT_EMPTY_VALUE;

    if (stack->top == NULL) {
        printf("Peek error! Stack is empty.\n");
    } else {
        value = stack->top->data;
    }

    return value;
}

/// Returns and removes last value added to stack.
/// \param stack
/// \return last added value if not empty,
/// otherwise DEFAULT_EMPTY_VALUE
int pop(stack* stack) {
    int value = DEFAULT_EMPTY_VALUE;

    if (stack->top == NULL) {
        printf("Pop error! Stack is empty.\n");
    } else {
        value = stack->top->data;

        node* previous_top = stack->top;
        stack->top = previous_top->next;
        free(previous_top);
    }

    return value;
}

/// Determines if the stack is empty.
/// \param stack
/// \return 1 if empty, otherwise 0
int isEmpty(stack *stack) {
    return stack->top == NULL;
}
