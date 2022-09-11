#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// main stack
 int check=1;
typedef struct sta
{
    int index;
    int entry[100];

}Stack;

void initalize_stack(Stack *ps)
{
    ps->index=0;
}
// to check it empty or not
int stack_empty(Stack *ps)
{
    return ps->index;
}
// push
void push(int op,Stack*ps)
{
        ps->entry[ps->index]=op;
        ps->index++;
}

// pop
void pop(int *p,Stack*ps)
{
    ps->index--;
   *p=ps->entry[ps->index];
}

int isDigit(char ch)
{
    if(ch>='0' && ch<='9')
    {
        return 1;
    }else{return 0;}
}



// math operations
int m_oper(char ch,int op_1,int op_2)
{
    switch(ch)
    {
        case '*': return (op_1*op_2);
        case '/': return (op_1/op_2);
        case '%': return (op_1%op_2);
        case '+': return (op_1+op_2);
        case '-': return (op_1-op_2);
        default: return -1;
    }

}

int evaluate(char postfix[])
{
    char ch;
    int n1,n2,result;
    Stack s;
    initalize_stack(&s);
    for(int i=0;(ch=postfix[i]) != '\0';i++)
    {
        if(isDigit(ch))
        {   int ch_num=(int)(ch-'0');
            push(ch_num,&s);
        }else
        {
            if(s.index ==1){check=-1; printf("Not Valid"); break;}
            pop(&n2,&s);
            pop(&n1,&s);
           if(ch=='/' && n2==0){check=-1; printf("Not Valid"); break;}
            result=m_oper(ch,n1,n2);
            push(result,&s);


        }
    }

    pop(&result,&s);
    if(s.index>0 || s.index <0){
    printf("Not Valid");
    check=-1;
     }
    return result;

}


int main()
{   char input[100];
    int value;
              scanf("%s",input);
              value=evaluate(input);
              if(check==1){ printf("%d",value);}




    return 0;
}
