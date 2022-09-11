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
    int size;
    scanf("%d",&size);
    if(size<=0){ printf("Not Exist"); return 0;}
      int numbers[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&numbers[i]);
    }

    heapSort(numbers, size);


        if(size%2 ==1)
        {
        printf("%d",numbers[size/2]);
        }else
          {

                float mid=((float)numbers[size/2-1]+(float)numbers[size/2])/2.0;
              if((mid-(int)mid)==0.0)
              {
                  printf("%d",(int)mid);
              }else{printf("%0.1f",mid);}
          }




    return 0;
}








