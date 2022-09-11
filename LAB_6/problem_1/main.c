#include <stdio.h>
#include <stdlib.h>
//the variables in this program
float numbers[5],negarr[5],posarr[5]={};
int neg,pos=0;
float sumneg,sumpos,avgneg,avgpos=0.0;

int main()
{
    printf("Enter the five numbers :");

    for(int i=0;i<5;i++)
    {
        scanf("%f",&numbers[i]);   // Entering the five numbers
    }

    for(int i=0;i<5;i++)
    {
        if (numbers[i]<0)
        {
            negarr[neg]=numbers[i];     // detect the negative and positive numbers
            neg++;

        }
        else if (numbers[i]>0)
        {
            posarr[pos]=numbers[i];
            pos++;


        }
    }

    for(int i=0;i<neg;i++)
    {

        sumneg=sumneg+negarr[i];                  // sum of negative
    }

    for (int i=0;i<pos;i++)
    {
        sumpos=sumpos+posarr[i];                 // sum of positive
    }

    avgneg=sumneg/(float)neg;            // determine the average
    avgpos=sumpos/(float)pos;

    // print the Results
  printf("Number of positive numbers:%d\n",pos);
  printf("Number of Negative numbers:%d\n",neg);
  printf("Average of positive numbers:%f\n",avgpos);
  printf("Average of Negative numbers:%f\n",avgneg);

}
