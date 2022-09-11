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
struct node *Newnode(int val)
{
   struct node *Newnode =(struct node*) malloc(sizeof(struct node));
    if(val==-1)
    {
         Newnode = NULL;

    }else
    {
     Newnode->entry = val;

     }
      Newnode->l  = NULL;
     Newnode->r = NULL;



    return Newnode;
}
struct node *insert(int numbers[],struct node* root,int i, int n)
{
    //  recursion base case
    if (i < n)
    {  if(numbers[i]==-1)
    {
        root=NULL;
    }else
    {
         root = Newnode(numbers[i]);
        //  left child
        root->l = insert(numbers,root->l, 2 * i + 1, n);

        // right child
        root->r = insert(numbers,root->r, 2 * i + 2, n);

    }

    }
    return root;
}


int check_full (struct node* root)
{

    if (root == NULL) // empty
        return 1;

    // If left & right child are null
    if (root->l == NULL && root->r == NULL)
        return 1;


    if ((root->l) && (root->r))
        return (check_full(root->l) && check_full(root->r));
    return 0;
}



int main()
{   int size;
        scanf("%d",&size);
        if(size<=0){return 0;}
        int numbers[size];
        struct node* root =NULL;
        for(int i=0;i<size;i++)
        {
              scanf("%d",&numbers[i]);

        }
        root = insert(numbers, root, 0, size);

if(check_full(root))
{
    printf("YES");
}else{printf("NO");}



    return 0;
}
