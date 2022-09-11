#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// main stack
typedef struct sta
{
    int index;
    int operations[100];

}Stack;

void create_stack(Stack *ps)
{
    ps->index=0;
}

void push(int op,Stack*ps)
{
        ps->operations[ps->index]=op;
        ps->index++;
}

// pop
void dele(Stack*ps)
{
    ps->index--;
}





int main() {

    int num,value,max=0;

    scanf("%d",&max);
          Stack s;
          create_stack(&s);
    for(int i=0;i<max;i++)
    {
      scanf("%d",&num);

        if(num == 1)
        {  scanf("%d",&value);
            push(value,&s);

         }

        else if(num == 2)
            {  if(s.index!=0){dele(&s);}
            }

        else if (num==3)
        {
               if(s.index == 0){
                printf("Empty\n");}

            else
            {

              int temp = s.operations[s.index-1];
              for(int k=s.index -2 ; k>=0 ; k--)
              {

                  if(s.operations[k] < temp)
                  {
                      temp = s.operations[k];

                  }

              }

            printf("%d\n",temp);

            }

        }

    }



    return 0;
}
