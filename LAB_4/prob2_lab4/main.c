#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// main Queue
 int max_size=1000;
typedef struct queue
{
    int front;
    int rear;
    int size;
    int elements[1000];

}qu;
// initialize queue
void create_queue(qu *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
// Enter an element
void appand(int el,qu *pq)
{
        if(pq->rear == max_size-1)
        {
            pq->rear=0;
        }
        else{pq->rear++;}
        pq->elements[pq->rear]=el;
        pq->size++;
}

// read an element
void serve(qu * pq)
{
    if(pq->front == max_size-1)
        {
            pq->front=0;
        }
        else{pq->front++;}

        pq->size--;
}





int main() {

    int num,value,max,loc,k=0;

    scanf("%d",&max);
          qu q;
          create_queue(&q);
    for(int i=0;i<max;i++)
    {
      scanf("%d",&num);

        if(num == 1)
        {  scanf("%d",&value);
            appand(value,&q);

         }

        else if(num == 2)
            {  if(q.size!=0){serve(&q);}  //empty or not
            }

        else if (num==3)
        {
               if(q.size == 0){
                printf("Empty\n");}

            else
            {

              for(loc=q.front,k=0 ; k<q.size ; k++)
              {
                    if(k==q.size-1){printf("%d",q.elements[loc]);}else{ printf("%d,",q.elements[loc]);}

                   if(loc == max_size-1)
                         {
                            loc=0;
                          }
                     else{loc++;}

              }
                printf("\n");
            }

        }

    }



    return 0;
}
