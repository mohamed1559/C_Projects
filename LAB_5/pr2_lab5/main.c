#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10000

struct node
{
    char entry;
    struct node *l;
    struct node *r;
};

struct node *NewNode(char val)
{
    struct node *NewNode = malloc(sizeof(struct node));
    NewNode->entry = val;
    NewNode->l  = NULL;
    NewNode->r = NULL;

    return NewNode;
}

struct node *insert(struct node *root, char val)
{
    if(root == NULL)
    return NewNode(val);

    if(root->l == NULL)
        root->r = insert(root->r,val);

    else if(root->r == NULL)
        root->l = insert(root->l,val);


    return root;
}


void postorder(struct node *root)
{
    if(root == NULL)
        return;


   if(root->entry != '\0') printf("%c",root->entry);
    postorder(root->l);
    postorder(root->r);


}


typedef struct sta
{
    int index;
    char elements[10000];

}Stack;


//initialization stack
void create_stack(Stack *ps)
{
    ps->index=0;
}

// push
void push(char el,Stack*ps)
{
		ps->elements[ps->index] = el;
		ps->index ++;

}


//pop
char pop(Stack*ps)
{
	char ch ;
	    ps->index--;
		ch = ps->elements[ps->index];
		return(ch);

}


int isoperator(char sign)
{
	if(sign == '%' || sign == '*' || sign == '/' || sign == '+' || sign =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}



int precedence(char sign)
{
	if(sign == '%' || sign == '*' || sign == '/')
	{
		return(2);
	}
	else if(sign == '+' || sign == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
int isDigit(char ch)
{
    if(ch>='0' && ch<='9')
    {
        return 1;
    }else{return 0;}
}



void convert_to_postfix(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char charcter;
   Stack s;
    create_stack(&s);
	push('(',&s);
	strcat(infix_exp,")");
	i=0;
	j=0;
	item=infix_exp[i];

	while(item != '\0')
	{
		if(item == '(')
		{
			push(item,&s);
		}
		else if( isDigit(item))
		{
			postfix_exp[j] = item;
			j++;
		}
		else if(isoperator(item) == 1)
		{
			charcter=pop(&s);
			while(isoperator(charcter) == 1 && precedence(charcter)>= precedence(item))
			{
				postfix_exp[j] = charcter;
				j++;
				charcter = pop(&s);
			}
			push(charcter,&s);


			push(item,&s);
		}
		else if(item == ')')
		{
			charcter = pop(&s);
			while(charcter != '(')
			{
				postfix_exp[j] = charcter;
				j++;
				charcter = pop(&s);
			}
		}
		i++;


		item = infix_exp[i];
	}


	postfix_exp[j] = '\0';

}


int main()
{
	char infix[SIZE], postfix[SIZE];
    struct node *root = NULL;
     int s=0;
	scanf("%s",infix);

	convert_to_postfix(infix,postfix);
       for(int i=0;i<sizeof(postfix);i++)
    {
        if(postfix[i] != '\0'){s++;}
    }
	 for(int i=0;i<s;i++)
    {
        root = insert(root,postfix[i]);
    }
    postorder(root);

	return 0;
}
