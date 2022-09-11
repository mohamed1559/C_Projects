#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int zero,number,k=0;
int check,sum=0;
int dim_x[2],dim_y[2]={0};

int check_sparse_matrix (int row,int colum,int matrix[row][colum])
{
    for(int i=0;i<row;i++)
   {
       for(int j=0;j<colum;j++)
       {
           if(matrix[i][j]==0){zero ++;}else{number++;}

       }
   }
   if(zero >= number)
   {
       return 1;
   }else {return -1;}

}
int main() {
    // entering x
   for(int i=0;i<2;i++)
   {
       scanf("%d",&dim_x[i]);
   }

   int x[dim_x[0]][dim_x[1]];
   for(int i=0;i<dim_x[0];i++)
   {
       for(int j=0;j<dim_x[1];j++)
       {
           scanf("%d",&x[i][j]);
       }
   }
    check= check_sparse_matrix (dim_x[0],dim_x[1],x);
    if(check==-1)
        {
            printf("Not Valid");
             return 0;}

   // entering y

   for(int i=0;i<2;i++)
   {
       scanf("%d",&dim_y[i]);
   }

   // check the multiplication validation
   if( dim_x[1] != dim_y[0])
        {
            printf("Not Valid");
             return 0;
             }

   int y[dim_y[0]][dim_y[1]];
   for(int i=0;i<dim_y[0];i++)
   {
       for(int j=0;j<dim_y[1];j++)
       {
           scanf("%d",&y[i][j]);
       }
   }

   check= check_sparse_matrix (dim_y[0],dim_y[1],y);
    if(check==-1)
        {
            printf("Not Valid");
             return 0;
             }



 // optimize the time by expected the zero sum
int result[dim_x[0]][dim_y[1]];

  for(int i=0;i<dim_x[0];i++)   // the row of the first matrix
  {
      for(k=0;k<dim_y[1];k++)    // the column of the second matrix
      {
              for(int l=0;l<dim_y[0];l++)     // the row of the second matrix
           {
              if(x[i][l]==0 || y[l][k]==0)    // remove thee expected zero sum
                {
                 continue;
               }
             else
               {
              sum+=x[i][l]*y[l][k];
               }
           }
           result[i][k]= sum;
           sum=0;
      }

  }

 // printing the result
  for(int i=0;i<dim_x[0];i++)
  {
      for(k=0;k<dim_y[1];k++)
      {

          printf("%d ",result[i][k]);
      }
      printf("\n");

  }









    return 0;
}


