#include <stdio.h>
#include <stdlib.h>
// the program variables
int matrix_1[3][3],matrix_2[3][3],result[3][3];

int main()
{
 printf("Enter Matrix A of size 3x3 :\n");
 for(int i=0;i<3;i++)
 {
     for(int j=0;j<3;j++)
     {
         scanf("%d",&matrix_1[i][j]);  // Enter the first Matrix
     }
 }
  printf("Enter Matrix B of size 3x3:\n");
 for(int i=0;i<3;i++)
 {
     for(int j=0;j<3;j++)
     {
         scanf("%d",&matrix_2[i][j]);  // Enter the second Matrix
     }
 }

 int*pm1,*pm2;
 pm1=matrix_1;  // pointer to the first matrix
 pm2=matrix_2;  // pointer to the second matrix
 for(int i=0;i<3;i++)
 {
     for(int j=0;j<3;j++)
     {
         result[i][j]= *(pm1+i*3+j)+ *(pm2+i*3+j);  // calculate the sum of the two matrices
     }
 }
 printf("Sum of both matrices:\n");
 for(int i=0;i<3;i++)
 {
     for(int j=0;j<3;j++)
     {
         printf("%d ",result[i][j]);  // print the sum
     }
          printf("\n");
 }



}
