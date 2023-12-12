/*
 *
 * Queue
 *
 *    Uses:
 *      Linked List
 *
 *    Sample Operations:
 *      enqueue, dequeue, isEmpty
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_EMPTY_VALUE (-1)

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct queue {
    node* head;
    node* tail;
} queue;

// Queue Implementation
void enqueue(queue*, int);
int dequeue(queue*);
int isEmpty(queue*);

// Helper Function(s)
node* createNode(int value);

int main() {
    queue nodes;
    nodes.head = NULL;
    nodes.tail = NULL;

    printf("Empty: %s\n\n", isEmpty(&nodes) ? "Yes" : "No");

    for(int i = 0; i < 10; i++) {
        printf("Enqueue %d\n", i);
        enqueue(&nodes, i);
    }

    printf("\n");

    printf("Empty: %s\n\n", isEmpty(&nodes) ? "Yes" : "No");

    while (!isEmpty(&nodes)) {
        printf("Dequeue %d\n", dequeue(&nodes));
    }

    return 0;
}

/*
 *
 * Queue Implementation
 *
 */

/// Adds the value to the queue.
/// \param que
/// \param value
void enqueue(queue* que, int value) {
    node* new_node = createNode(value);

    if (que->tail != NULL)
        que->tail->next = new_node;

    que->tail = new_node;

    if (que->head == NULL)
        que->head = new_node;
}

/// Returns the next value from the queue.
/// \param que
/// \return value from queue, otherwise
/// DEFAULT_EMPTY_VALUE if empty
int dequeue(queue* que) {
    if (isEmpty(que))
        return DEFAULT_EMPTY_VALUE;

    // Save the node and value to
    // free and return respectively
    node* node = que->head;
    int value = node->value;

    // Move head to next node
    que->head = que->head->next;

    // Free the memory allocated by calloc
    free(node);

    // Deleted the only item in queue
    if (que->head == NULL)
        que->tail = NULL;

    return value;
}

/// Checks if no values are on the queue.
/// \param que
/// \return 1 if empty, otherwise 0
int isEmpty(queue* que) {
    return que->head == NULL;
}

/*
* Helper Function(s)
*
*/

/// Creates a node containing the given value.
/// \param value
/// \return the node
node* createNode(int value) {
    node* node = calloc(1, sizeof(node));
    node->value = value;
    return node;
}
