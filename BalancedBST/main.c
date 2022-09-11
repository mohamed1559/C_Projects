#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create sub trees
struct node* newSubTree(int data){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct node* buildBST(int element[], int lowerBound, int upperBound){
    // Condition to stop recursion
    if (lowerBound > upperBound){
        return NULL;
    }

    // Getting the middle element of the array
    int mid;
    mid = (lowerBound + upperBound)/2;

    // Root of the tree is the mid element
    struct node* root = newSubTree(element[mid]);

    // Recursion to add left and right children to the BST
    root->left = buildBST(element, lowerBound, mid-1);  // Traversing left part of array
    root->right = buildBST(element, mid+1, upperBound); // Traversing right part of array

    return root;
}

// Function to print the pre-order traversal of the tree
void preOrder(struct node* subtree){
    // If the leaves are not reached
    if(subtree == NULL){
        return;
    }
    printf("%d,", subtree->data); // print data of the current node
    preOrder(subtree->left);      // call the function again to print left children
    preOrder(subtree->right);     // call the function again to print right children
}

int main()
{
    int N = 0; // The number of sorted elements in the array
    scanf("%d", &N);

    int elements[N];
    for(int i=0; i<N; i++){ // Reading elements into the array
        scanf("%d", &elements[i]);
    }

    struct node* root;
    root = buildBST(elements, 0, N-1); // Function call to build the BST

    preOrder(root);

    return 0;
}
