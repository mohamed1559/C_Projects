#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// main Queue
 int max_size=10000;
typedef struct queue
{
    int front;
    int rear;
    int size;
    int courses[10000];
    int duration[10000];

}qu;
// initialize queue
void create_queue(qu *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
// Enter an element
void appand(int cou,int dur,qu *pq)
{
        if(pq->rear == max_size-1)
        {
            pq->rear=0;
        }
        else{pq->rear++;}
        pq->courses[pq->rear]=cou;
        pq->duration[pq->rear]=dur;
        pq->size++;
}
// Swap the two values
void swap(int * course1,int * course2,int*duration1,int * duration2)
{
    int cou_temp,dur_temp;
    cou_temp=*course1;
    *course1=*course2;
    *course2=cou_temp;

    dur_temp=*duration1;
    *duration1=*duration2;
    *duration2=dur_temp;
}
int main() {
     int num_of_courses,course,duration,sum_of_cou,c=0;
     qu q;
     create_queue(&q);
    scanf("%d",&num_of_courses);
    if(num_of_courses<=0 || num_of_courses>=10000 ){printf("%d",c); return 0;}
    for(int i=0;i<num_of_courses;i++)
    {
        scanf("%d%d",&course,&duration);
        if(course > duration || course <=0 || duration <=0 || course>10000 || duration>10000){continue;}
       else
       {
            appand(course,duration,&q);

        }
    }
// order the queue by the minimum duration in front
    for(int j=0;j<q.size;j++)
            {  for (int k = j + 1; k < q.size;k++)
                  {
                if(q.duration[j]>q.duration[k])
                {
                    swap(&q.courses[j],&q.courses[k],&q.duration[j],&q.duration[k]);
                }
                  }
            }



    if(q.size != 0){
    for(int i=0;i<q.size;i++)
    {
        if(i==0)
        {    c++;
            sum_of_cou=q.courses[i];
        }else
        {
            if(sum_of_cou+q.courses[i] <= q.duration[i])
            {
                c++;
             sum_of_cou+=q.courses[i];
            }
        }
      }


    }
    else{c=0;}

    printf("%d",c);


    return 0;
}
