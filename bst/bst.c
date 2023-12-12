/*
 *
 * Binary Search Tree
 *
 *    Sample Operations:
 *      add, find, contains, depth
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;

// BST Implementation
int add(node*, int);
node* find(node*, int);
int contains(node*, int);
int depth(node*, int);

// Helper Function(s)
node* createNode(int);

int main() {
    node* root = createNode(40);
    printf("Root = %d\n\n", root->value);

    // This order makes a height-balanced BST
    printf("Add %d\n", add(root, 20));
    printf("Add %d\n", add(root, 10));
    printf("Add %d\n", add(root, 30));
    printf("Add %d\n", add(root, 60));
    printf("Add %d\n", add(root, 50));
    printf("Add %d\n", add(root, 70));
    printf("\n");

    // Run Contains Function
    for (int i = 5; i < 80; i = i+5) {
        printf("Contains  %2d? %s\n", i, contains(root, i) ? "Yes" : "No");
    }

    printf("\n");

    // Run Depth Function
    for (int i = 10; i < 80; i = i+10) {
        printf("Depth  %2d? %d\n", i, depth(root, i));
    }

    return 0;
}

/*
 *
 * BST Implementation
 *
 */

/// Adds the value to the BST. If the value
/// is already present in the BST, it does
/// not add it again.
/// \param root
/// \param value
/// \return the value if added, otherwise -1
int add(node* root, int value) {
    node* current_node = root;

    while (current_node != NULL) {
        if (value < current_node->value) {
            if (current_node->left == NULL) {
                current_node->left = createNode(value);
                return value;
            } else
                current_node = current_node->left;
        } else if (value > current_node->value) {
            if (current_node->right == NULL) {
                current_node->right = createNode(value);
                return value;
            } else
                current_node = current_node->right;
        } else
            return -1;
    }

    return -1;
}

/// Returns the node with the value in
/// the BST using a tail recursive function
/// for kicks. Compiler should optimize it.
/// \param a_node
/// \param value
/// \return the node if found, otherwise NULL
node* find(node* a_node, int value) {
    // Base Tests
    if (a_node == NULL) return NULL;
    if (a_node->value == value) return a_node;

    if (value < a_node->value)
        a_node = a_node->left;
    else
        a_node = a_node->right;

    // Tail Recursion
    return find(a_node, value);
}

/// Determines if a value is in the BST.
/// \param a_node
/// \param value
/// \return 1 if found, otherwise 0
int contains(node* root, int value) {
    return find(root, value) != NULL;
}

/// Finds the depth of a node in the BST.
/// \param root
/// \param value
/// \return the node depth if found, otherwise -1
int depth(node* root, int value) {
    int depth = -1;
    node* current_node = root;

    while (current_node != NULL) {
        depth++;
        if (current_node->value == value)
            return depth;
        else if (value < current_node->value) {
            current_node = current_node->left;
        } else
            current_node = current_node->right;
    }

    return -1;
}

/*
* Helper Function(s)
*
*/

/// Creates a node containing the given value.
/// \param value
/// \return the node
node* createNode(int value) {
    node* new_node = calloc(1, sizeof(node));
    new_node->value = value;
    return new_node;
}
