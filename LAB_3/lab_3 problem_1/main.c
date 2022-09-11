#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};


int in_num,original,size,ch,org_num=0;
int check=1;
int main()
{
    // count the number
   scanf("%d",&org_num);
   in_num=abs(org_num);
   if(in_num==0){return 0;}
   original=in_num;
   while(check)
   {
       if(in_num != 0)
       {
           size++;
        in_num=in_num/10;
       }
       else{check=0;}
   }
   if(size == 0 || size==1){return 0;}
   int numbers[size];
   in_num=original;
   for(int i=0;i<size;i++)
    {

        numbers[i]= in_num%10;
        in_num=in_num/10;


   }

   // create the linked list 1

   struct node *head=malloc(sizeof(struct node));
   head->data=numbers[0];
   head->link=NULL;

   struct node *previous=head;
   for(int i=1;i<size/2;i++){
   struct node *current=malloc(sizeof(struct node));
   current->data=numbers[i];
   current->link=NULL;
   previous->link=current;
   previous=current;
   }

   // create the linked list 2

   struct node *head_2=malloc(sizeof(struct node));
   head_2->data=numbers[size-1];
   head_2->link=NULL;

   struct node *previous_2=head_2;

   if(size%2 ==0){
   for(int i=size-1;i>size/2;i--){
   struct node *current_2=malloc(sizeof(struct node));
   current_2->data=numbers[i-1];
   current_2->link=NULL;
   previous_2->link=current_2;
   previous_2=current_2;
        }
      }else
      {
          for(int i=size-2;i>size/2;i--)
            {
        struct node *current_2=malloc(sizeof(struct node));
        current_2->data=numbers[i];
        current_2->link=NULL;
        previous_2->link=current_2;
        previous_2=current_2;
           }
      }


    //print
    struct node *m1=NULL;
    struct node *m2=NULL;
    m1=head;
    m2=head_2;
    while(m1 != NULL || m2 != NULL)
    {
       if(m1->data == m2->data)
       {
           ch++;
       }else
       {
           printf("NO");
           break;
       }

        m1=m1->link;
        m2=m2->link;
    }

   if(ch==size/2)
   {
       printf("YES");
   }


    return 0;
}
