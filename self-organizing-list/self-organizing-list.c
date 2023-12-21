/*
 * Self-Organizing List
 *
 * I like the idea of a self-organizing
 * list that adjusts itself to improve
 * the average lookup times. An unordered
 * linked list will search in linear time.
 * However, depending on the application,
 * one might be able to improve the avg
 * times by moving the frequently accessed
 * items to the front of the list.
 *
 * This example uses a Move-To-Front Strategy
 * to move a recently searched for item
 * to the head of the list.
 *
 * It also adds any new items to the head of
 * the list as they may be accessed shortly
 * after being added to the list.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[10];
    int age;
    struct node* next;
} node;

typedef struct list {
    node* head;
} list;

void add(list*, char*, int);
int findAge(list*, char*);
void moveToFront(list*, node*, node*);
void printList(list*);
void clear(list*);

node* createNode(char*, int);

int main() {
    list* family = calloc(1, sizeof(list));

    add(family, "John", 42);
    add(family, "Martha", 38);
    add(family, "Rosco", 12);
    add(family, "Cal", 10);
    add(family, "Trish", 7);

    printList(family);

    findAge(family, "Trish");
    findAge(family, "Cal");
    findAge(family, "Rosco");
    findAge(family, "Martha");
    findAge(family, "John");

    printList(family);

    clear(family);

    free(family);
    family = NULL;

    return 0;
}

/// Adds a new item to the head of the list.
/// \param list
/// \param name
/// \param age
void add(list* list, char* name, int age) {
    node* new_node = createNode(name, age);
    new_node->next = list->head;
    list->head = new_node;
}

/// Finds the age of the family member.
/// \param list
/// \param name
/// \return age, or -1 if not found
int findAge(list* list, char* name) {
    // Keep track of the previous node,
    // so we can use it in moveToFront
    // call to simplify re-organizing
    // the list.
    int age_found = -1;
    node* previous_node = NULL;
    node* current_node = list->head;

    // Search for name in the list.
    while (current_node != NULL) {
        if (strcmp(current_node->name, name) == 0)
            break;
        previous_node = current_node;
        current_node = current_node->next;
    }

    // The name is found. Move the node
    // associated with the name to the
    // head of the list.
    if (current_node != NULL) {
        moveToFront(list, previous_node, current_node);
        age_found = current_node->age;
    }

    return age_found;
}

/// Moves node to the head of the list.
/// \param list
/// \param previous_node
/// \param node
void moveToFront(list* list, node* previous_node, node* node) {
    // It's at the front of the list.
    // Do nothing.
    if (previous_node == NULL)
        return;

    previous_node->next = node->next;
    node->next = list->head;
    list->head = node;
}

/// Clears the list of any items.
/// \param list
void clear(list* list) {
    node* current_node = list->head;
    node* next_node;

    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    list->head = NULL;
}

/// Prints the names of all people in the list.
void printList(list* list) {
    node* current_node = list->head;
    while (current_node != NULL) {
        printf("%10s", current_node->name);
        current_node = current_node->next;
    }
    printf("\n\n");
}

/// Creates and returns a new node with
/// the proper name and age.
/// \param name
/// \param age
/// \return a new node
node* createNode(char* name, int age) {
    node* new_node = calloc(1, sizeof(node));
    strcpy(new_node->name, name);
    new_node->age = age;
    return new_node;
}
