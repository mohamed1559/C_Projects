#include <stdio.h>
#include <stdlib.h>
void swap(int*a,int*b)
{
    int t=*a;
    *a=*b;
    *b=t;

}
// assure that it's max heap ( the elements are descending}
void heapify(int elements[],int size,int i)
{

int l=2*i+1;  //left child
int r=2*i+2;  // right child
int max=i;    // assume the current is the maximum

    if(l<size && elements[l]<elements[max])
    max=l;
    if(r<size &&elements[r]<elements[max])
    max=r;

    if(max != i)
        {
    swap(&elements[i],&elements[max]);
    heapify(elements,size,max);   // recursion
       }
}
// for the two branches (left and right child)
void creatingheap(int elements[],int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(elements, size, i);  // recursion
}

 // sorting heap
void heapSort(int elements[], int n)
{

    creatingheap(elements, n);
    for (int i = n-1; i >=0; i--)
    {
        swap(&elements[0], &elements[i]);
        heapify(elements, i, 0);
    }

}
int main()
{
    int size,max;
    scanf("%d",&size);
    if(size<=1){printf("0"); return 0;}
      int numbers[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&numbers[i]);
    }

      heapSort(numbers, size);

    int interval=numbers[0]-numbers[1]; // between the first two elements
    for(int i=0;i<size-1;i++)
    {  max=numbers[i]-numbers[i+1];
        if(abs(max)>abs(interval))
        {
            interval=max;
        }else{continue;}


    }
    printf("%d",abs(interval));



    return 0;
}
