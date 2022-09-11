#include <stdio.h>
#include <stdlib.h>
// variables for the program
int check=1,num=0;
int result[8]={0};
int weekgross;
float weeksalary;
int main()
{
    while(check)    // to keep the program running until user input -1
    {

            printf("Enter Employee gross sale (-1 to end) :");
            scanf("%d",&weekgross);
            if(weekgross!=-1)
        {   num++;
            weeksalary=200+0.09*(float)weekgross;  // calculate the work Salary
            printf("Employee salary is:%0.2f\n",weeksalary);
            if(weeksalary>=200 && weeksalary<=299)   // determine the range of workSalary
            {
                result[0]++;
            }
            else if (weeksalary>=300 && weeksalary<=399)
            {
                result[1]++;
            }
             else if (weeksalary>=400 && weeksalary<=499)
             {
                 result[2]++;
             }
              else if (weeksalary>=500 && weeksalary<=599)
              {
                  result[3]++;
              }
               else if (weeksalary>=600 && weeksalary<=699)
               {
                   result[4]++;
               }
                else if (weeksalary>=700 && weeksalary<=799)
                {
                    result[5]++;
                }
                 else if (weeksalary>=800 && weeksalary<=899)
                 {
                     result[6]++;
                 }
                  else if (weeksalary>=900 && weeksalary<=1000)
                  {
                      result[7]++;
                  }
                  else
                  {
                      result[8]++;
                  }

                  weeksalary=0;   // initialize again for the next input
        }
        else
        {   check=0;
            printf("Total %d Employees Reported\n",num);
            printf("Employees in the range:\n");
            printf("200 299:%d\n",result[0]);
            printf("300 399:%d\n",result[1]);    // print the numbers of each range
            printf("400 499:%d\n",result[2]);
            printf("500 599:%d\n",result[3]);
            printf("600 699:%d\n",result[4]);
            printf("700 799:%d\n",result[5]);
            printf("800 899:%d\n",result[6]);
            printf("900 1000:%d\n",result[7]);
            printf("over 1000:%d\n",result[8]);
        }
    }


}
