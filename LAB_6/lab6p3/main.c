#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// building tree
struct node
{
    int entry;
    struct node *l;
    struct node *r;
};

// creating node
struct node *NewNode(int val)
{
    struct node *NewNode =(struct node*) malloc(sizeof(struct node));
    NewNode->entry = val;
    NewNode->l  = NULL;
    NewNode->r = NULL;

    return NewNode;
}
// binary sorted tree
struct node* binary_sorted_tree(int numbers[], int left, int right)
{

    if (left > right)
      return NULL;

  // for the middle number
    int mid = (left + right)/2;
    struct node *root = NewNode(numbers[mid]);


    root->l =  binary_sorted_tree(numbers, left, mid-1);


    root->r = binary_sorted_tree(numbers, mid+1, right);

    return root;
}


// print preorder
void preorder(struct node* node)
{   static int n=0;
    if (node == NULL)
        return;
    if(n==0)
    {
         printf("%d", node->entry);
         n++;
    }else { printf(",%d", node->entry);}

    preorder(node->l);
    preorder(node->r);
}


int main()
{   int size;
        scanf("%d",&size);
        if(size<=0 || size > pow(10,4));
        int numbers[size];
        for(int i=0;i<size;i++)
        {
            scanf("%d",&numbers[i]);
        }

    struct node *root = binary_sorted_tree(numbers, 0, size-1);
    preorder(root);

    return 0;
}
