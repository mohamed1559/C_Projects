#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

// stack node
struct Stack {
    int index;
    int numbers[MAXSIZE];
} st;


void initialize() {
 st.index = -1;
}


int isEmpty() {
 if(st.index == -1)
     return 1;
 else
     return 0;
}


void push(int num) {
        st.numbers[st.index + 1] = num;
        st.index++;
}

int pop() {
     st.index = st.index - 1;
     return st.numbers[st.index+1];
}

 // for using it in the reverse function
void insert_at_end(int item) {
    if (isEmpty()) {
        push(item);
    } else {
        int index = pop();
        insert_at_end(item);
        push(index);
    }
}

 // to reverse the stack ( Queue FIFO    Stack LIFO   ===> reverse (Stack) = Queue <====)
void reverse() {
    if (!isEmpty()) {
        int index = pop();
        reverse();
        insert_at_end(index);
    }
}

int check_Bipartite(int n,int graph[][n], int info, int color[])
{
    color[info] = 1;  // the first color


     initialize(st);
     push(info);

    while (!(isEmpty())) {  // empty or not

        int u = pop();
        if (graph[u][n] == 1)
            return 0;

               // Find all non-colored  Av
        for (int v = 0; v < n; ++v) {
            if (graph [u][v]&& color[v] == -1) {
                color[v] = 1 - color[u];
                push(v);
                reverse();  // reverse the stack to get the first element one the top on the stack
            }
            else if (graph [u][v]&& color[v] == color[u])
                return 0;
        }
    }

    return 1;
}


int isBipartite(int n,int graph[][n])
{
    int color[n];
    for (int i = 0; i < n; ++i)
        color[i] = -1;

    for (int i = 0; i < n; i++)   // for handle disconnected graph
        if (color[i] == -1)
            if (check_Bipartite(n,graph, i, color) == 0)
                return 0;

    return 1;
}

int main()
{

    int n,e,x,y;
    scanf("%d%d",&n,&e);
    int graph[n][n];
    // initialize the 2D array
     for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
        {
             graph[i][j]=0;
        }
        }

    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&y,&x);
       graph[(y-1)][x-1]=1;// assign the adjacent vertices for the each V
    }


   if(isBipartite(n,graph))
        printf("Yes");
    else
        printf("No") ;
    return 0;
}
