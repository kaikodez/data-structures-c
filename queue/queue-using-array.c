/*
 *
 * Queue
 *
 *   Uses:
 *      Array
 *
 *   Sample Operations:
 *      enqueue, dequeue, isEmpty, isFull
 *
 * Notes:
 *
 * The array is circular. Therefore, tail index can be
 * less than the head index. The head and tail indexes
 * will wrap around, if possible, when they come to the
 * last index of the array. The code handles this
 * wrapping using the modulus operator.
 *
 * The queue is empty when the head index equals -1.
 * If the head index equals -1, the tail index better
 * equal -1, too. When you set the head index to -1,
 * set the tail index to -1.
 *
 * The queue is full when the tail index is one less
 * than the head index. Since the array is circular,
 * the code takes this into consideration using the
 * modulus operator.
 *
 * There is only one item in the queue when head == tail,
 * and they are not equal to -1. On a dequeue, it checks
 * to see if they are equal, and if they are, it means the
 * queue will be empty after the dequeue, so it sets both
 * the head and tail indexes equal to -1 (empty).
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR_RETURN_VALUE (-1)

typedef struct queue {
    int* arr;
    int capacity; // Maximum size of array
    int head; // Index pointing to the head of queue.
    int tail; // Index pointing to the tail of queue.
} queue;

// Queue Implementation
int enqueue(queue*, int);
int dequeue(queue*);
int isEmpty(queue*);
int isFull(queue*);

// Helper Function(s)
queue* createQueue(int);
void freeQueue(queue*);

int main() {
    queue* que = createQueue(10);

    // Fill the queue.
    int i = 0;
    while(!isFull(que)) {
        printf("Enqueue: %d\n", enqueue(que, i));
        i++;
    }

    printf("\n");

    // Empty the queue.
    while (!isEmpty(que)) {
        printf("Dequeue: %d\n", dequeue(que));
    }

    // Free the memory and eliminate
    // dangling pointer.
    freeQueue(que);
    que = NULL;

    return 0;
}

/*
 *
 * Queue Implementation
 *
 */

/// Adds a value to the back of the queue. If the
/// queue is full it displays an error message and
/// returns ERROR_RETURN_VALUE, otherwise it returns
/// the value added to the queue.
/// \param que
/// \param value
/// \return ERROR_RETURN_VALUE if full, otherwise value
int enqueue(queue* que, int value) {
    if (isFull(que)) {
        printf("Error: Queue is full.\n");
        return ERROR_RETURN_VALUE;
    }

    // Increase tail index and wrap to the
    // beginning of the array if necessary.
    que->tail++;
    que->tail = que->tail % que->capacity;

    // If this is the first item in the queue,
    // set the head index to this first item.
    if (que->head == -1)
        que->head = 0;

    que->arr[que->tail] = value;

    return value;
}

/// Returns and removes the value at the front of the
/// queue. If the queue is empty it displays an error
/// message and returns ERROR_RETURN_VALUE.
/// \param que
/// \return ERROR_RETURN_VALUE if empty, otherwise value
int dequeue(queue* que) {
    if (isEmpty(que)) {
        printf("Error: Queue is empty.\n");
        return ERROR_RETURN_VALUE;
    }

    // Save the return value because we
    // will be changing the head index
    // before returning from the function.
    int value = que->arr[que->head];

    // If head == tail, and they don't
    // equal -1, this is the last item
    // in the queue, set it to empty.
    if (que->head == que->tail) {
        que->head = -1;
        que->tail = -1;
    } else {
        // Increase head index and wrap to the
        // beginning of the array if necessary.
        que->head++;
        que->head = que->head % que->capacity;
    }

    return value;
}

/// Checks if the queue is empty.
/// \param que
/// \return 1 if empty, otherwise 0
int isEmpty(queue* que) {
    return que->head == -1;
}

/// Checks if the queue is full.
/// \param que
/// \return 1 if full, otherwise 0
int isFull(queue* que) {
    // A queue is full when the tail index is
    // one less than the head index.
    return (que->tail + 1) % que->capacity == que->head;
}

/*
 * Helper Function(s)
 *
 */

/// Creates a queue.
/// \param capacity the maximum number of items in queue
/// \return the queue
queue* createQueue(int capacity) {
    queue* que = calloc(1, sizeof(queue));
    que->arr = calloc(capacity, sizeof(int));

    // Save the maximum size of the array.
    que->capacity = capacity;

    // Set both indexes to -1 when empty.
    que->head = -1;
    que->tail = -1;

    return que;
}

/// Frees all memory used by que.
/// \param que
void freeQueue(queue* que) {
    free(que->arr);
    free(que);
}
