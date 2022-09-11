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


struct node* previous = NULL;

int max_dup_preorder(struct node* root)
{  static int arr[100];
     static int current = 1, max = 0, n,i;
    if (root == NULL) {
        return 0;
    }
    if (previous != NULL) {
        if (root->entry == previous->entry) {
            current++;
            arr[i]=root->entry;
            arr[i+1]=current;
            i++;
        }
        else {
            current = 1;
        }
    }

    if (current > max ) {
        max = current;
      //  n = root->entry;
    }
    previous = root;
    max_dup_preorder(root->l);
    max_dup_preorder(root->r);


    for(int l=0;l<100;l++)
    {
        if(arr[i]%2 ==1 && arr[i]==max)
        {
            printf("%d",arr[i-1]);
        }
    }
    return n;
}




int main()
{       int size;
        scanf("%d",&size);
        if(size<=0){return 0;}
        int numbers[size];
        struct node* root =NULL;
        for(int i=0;i<size;i++)
        {
              scanf("%d",&numbers[i]);

        }
        root = insert(numbers, root, 0, size);
       // printf("%d",max_dup_preorder(root),size);
       max_dup_preorder(root);
    return 0;
}
