#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 int size[2];
 int n,m,num,next,fill,min,temp=0;
int main() {
    // entering the values
    for(int i=0;i<2;i++)
    {
        scanf("%d",&size[i]);
    }
     int developers[size[0]];
     int tasks[size[1]];
    for(int i=0;i<size[0];i++)
    {
        scanf("%d",&developers[i]);
    }
    for(int i=0;i<size[1];i++)
    {
        scanf("%d",&tasks[i]);
    }

// sorting
    for(int fill=0;fill<size[1]-1;fill++)
    {
        min=fill;
        for(next=fill+1;next<size[1];next++)
        {
            if(tasks[next]< tasks[min])
            {    temp=tasks[min];
                tasks[min]=tasks[next];
                tasks[next]=temp;
            }
        }
    }

    for(int fill=0;fill<size[0]-1;fill++)
    {
        min=fill;
        for(next=fill+1;next<size[0];next++)
        {
            if(developers[next]< developers[min])
            {    temp=developers[min];
                developers[min]=developers[next];
                developers[next]=temp;
            }
        }
    }
// dividing tasks
    while(n<size[1])
    {  for(m=n;m<size[0];m++)
        {
        if(tasks[n]<=developers[m])
         {
            num++;
            break;
         }else{continue;}
        }
        n++;
    }
    printf("%d",num);

    return 0;
}
