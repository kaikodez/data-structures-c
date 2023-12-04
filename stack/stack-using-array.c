/*
 *
 * Stack Data Structure
 *
 *    Uses:
 *      Array
 *
 *    Sample Operations:
 *      push, peek, pop, isEmpty, isFull
 *
 */

#include <stdio.h>

#define DEFAULT_VALUE (-1)
#define MAX_SIZE 10

typedef struct {
    int array[MAX_SIZE];
    int top;
    int size;
} stack;

int push(stack*, int);
int peek(stack*);
int pop(stack*);
int isEmpty(stack*);
int isFull(stack*);

int main() {
    // Not using dynamic memory allocation
    // (calloc or malloc) for this example.
    stack my_stack;
    my_stack.top = -1;
    my_stack.size = MAX_SIZE;

    // Stack is empty and should display 1.
    printf("isEmpty = %d\n", isEmpty(&my_stack));

    // Stack is not full and should display 0.
    printf("isFull = %d\n", isFull(&my_stack));

    // Peek and pop on empty stack displays
    // an error and DEFAULT_EMPTY_VALUE.
    printf("Peek: %d\n", peek(&my_stack));
    printf("Pop: %d\n", pop(&my_stack));

    // Push values on stack until it's full.
    int value = 200;

    while (!isFull(&my_stack)) {
        printf("Push: %d\n", push(&my_stack, value));
        value -= 10;
    }

    // Stack is not empty and should display 0.
    printf("isEmpty = %d\n", isEmpty(&my_stack));

    // Stack is full and should display 1.
    printf("isFull = %d\n", isFull(&my_stack));

    // Push on full stack displays
    // an error and DEFAULT_EMPTY_VALUE.
    printf("Push: %d\n", push(&my_stack, value-10));

    // Loop through the stack and display
    // all remaining values until empty.
    while (!isEmpty(&my_stack)) {
        printf("Peek: %d\n", peek(&my_stack));
        printf("Pop: %d\n", pop(&my_stack));
    }

    // Stack is empty and should display 1.
    printf("isEmpty = %d\n", isEmpty(&my_stack));

    // Stack is not full and should display 0.
    printf("isFull = %d\n", isFull(&my_stack));

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
    int return_value = value;

    if (isFull(stack)) {
        printf("Push error! Stack is full.\n");
        return_value = DEFAULT_VALUE;
    } else {
        stack->top++;
        stack->array[stack->top] = value;
    }

    return return_value;
}

/// Returns last value added to the stack.
/// \param stack
/// \return last added value if not empty,
/// otherwise DEFAULT_EMPTY_VALUE
int peek(stack* stack) {
    int return_value = DEFAULT_VALUE;

    if (isEmpty(stack)) {
        printf("Peek error! Stack is empty.\n");
    } else {
        return_value = stack->array[stack->top];
    }

    return return_value;
}

/// Returns and removes last value added to stack.
/// \param stack
/// \return last added value if not empty,
/// otherwise DEFAULT_EMPTY_VALUE
int pop(stack* stack) {
    int return_value = DEFAULT_VALUE;

    if (isEmpty(stack)) {
        printf("Pop error! Stack is empty.\n");
    } else {
        return_value = stack->array[stack->top];
        stack->top--;
    }

    return return_value;
}

/// Determines if the stack is empty.
/// \param stack
/// \return 1 if empty, otherwise 0
int isEmpty(stack* stack) {
    return stack->top == -1;
}

/// Determines if the stack is full.
/// \param stack
/// \return 1 if full, otherwise 0
int isFull(stack* stack) {
    return stack->top == stack->size - 1;
}
