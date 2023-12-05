/*
 *
 * Linked List
 *
 *    Sample Operations:
 *      add, delete, contains, isEmpty, clear
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
} linked_list;

// Linked List Implementation
int add(linked_list*, int);
int delete(linked_list*, int);
int contains(linked_list*, int);
int isEmpty(linked_list*);
int clear(linked_list*);

// Helper Function(s)
void printList(linked_list*);

int main() {
    linked_list list;
    list.head = NULL;
    list.tail = NULL;

    printf("IsEmpty? %s\n\n",
           isEmpty(&list) ? "Yes" : "No" );

    printf("Add: %d\n", add(&list, 1));
    printf("Add: %d\n", add(&list, 2));
    printf("Add: %d\n", add(&list, 3));
    printf("Add: %d\n", add(&list, 4));
    printf("Add: %d\n", add(&list, 5));
    printf("Add: %d\n\n", add(&list, 6));

    printList(&list);

    printf("IsEmpty? %s\n\n",
           isEmpty(&list) ? "Yes" : "No" );

    printf("Contains 5? %s\n",
           contains(&list, 5) ? "Yes" : "No");

    printf("Contains 7? %s\n\n",
           contains(&list, 7) ? "Yes" : "No");

    printf("Delete: 5 => %s\n",
           delete(&list, 5) ? "Ok" : "Not Found");

    printf("Delete: 7 => %s\n\n",
           delete(&list, 5) ? "Ok" : "Not Found");

    printList(&list);

    printf("Add: %d\n\n", add(&list, 7));

    printList(&list);

    printf("Delete: 1 => %s\n",
           delete(&list, 1) ? "Ok" : "Not Found");

    printf("Delete: 7 => %s\n\n",
           delete(&list, 7) ? "Ok" : "Not Found");

    printList(&list);

    printf("Clear List. Records Deleted: %d\n\n", clear(&list));

    printf("IsEmpty? %s\n\n",
           isEmpty(&list) ? "Yes" : "No" );

    return 0;
}

/*
 *
 * Linked List Implementation
 *
 */

/// Adds the value to the end of the list.
/// \param list
/// \param value
int add(linked_list* list, int value) {
    node* node = calloc(1, sizeof(node));
    node->value = value;
    node->next = NULL;

    if (isEmpty(list)) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    return value;
}

/// Removes the value from the list if found.
/// \param list
/// \param value
/// \return 1 if node deleted, otherwise 0
int delete(linked_list* list, int value) {
    int return_value = 0;

    node* previous_node = NULL;
    node* current_node = list->head;

    while (current_node != NULL) {
        if (current_node->value == value)
            break;

        previous_node = current_node;
        current_node = current_node->next;
    }

    if (current_node != NULL) {

        // Deleting the only node in list.
        if (current_node == list->head && current_node == list->tail) {
            list->head = NULL;
            list->tail = NULL;
        }

        // Deleting the head of the list.
        else if (current_node == list->head) {
            list->head = current_node->next;
        }

        // Deleting the tail of the list.
        else if (current_node == list->tail) {
            list->tail = previous_node;
            list->tail->next = NULL;
        }

        // Deleting a node in the middle of the list.
        else {
            previous_node->next = current_node->next;
        }

        free (current_node);
        return_value = 1;
    }

    return return_value;
}

/// Checks if the value is in the list.
/// \param list
/// \param value
/// \return 1 if value found in list, otherwise 0
int contains(linked_list* list, int value) {
    node* current_node = list->head;

    while(current_node != NULL) {
        if (current_node->value == value)
            break;

        current_node = current_node->next;
    }

    return current_node == NULL ? 0 : 1;
}

/// Checks if the list is empty.
/// \param list
/// \return 1 if empty, otherwise 0
int isEmpty(linked_list* list) {
    return list->head == NULL;
}

/// Removes all nodes from the linked list.
/// \param list
/// \return number of nodes removed from list
int clear(linked_list* list) {
    int count_nodes_deleted = 0;

    node* current_node = list->head;
    node* next_node = NULL;

    while (current_node != NULL) {
        next_node = current_node->next;

        free(current_node);
        count_nodes_deleted++;

        current_node = next_node;
    }

    list->head = NULL;
    list->tail = NULL;

    return count_nodes_deleted;
}

/*
* Helper Function(s)
*
*/

/// Prints the linked list.
/// \param list
void printList(linked_list* list) {
    node* current_node = list->head;

    printf("List: ");
    while (current_node != NULL) {
        printf("%d  ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n\n");
}
