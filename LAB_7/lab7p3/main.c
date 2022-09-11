#include <stdio.h>
#include <stdlib.h>

// sorting
void shell_sort(int numbers[], int n)
{
    for (int i = n / 2; i > 0; i = i / 2)
    {
        for (int j = i; j < n; j++)
        {        // gap between the elements
            for(int gap = j - i; gap >= 0; gap = gap - i)
            {
                if (numbers[gap+i] >= numbers[gap])
                    break;
                else
                {    // swap the values by bitwise XOR
                     numbers[gap]=numbers[gap]^numbers[gap+i];
                    numbers[gap+i] =numbers[gap]^numbers[gap+i];
                    numbers[gap]=numbers[gap]^numbers[gap+i];
                }
            }
        }
    }
}
int main()
{
    int numbers[100];
    int gap,num_of_element,index;
    scanf("%d%d", &num_of_element,&index);

    for (gap =0 ; gap < num_of_element; gap++)
    {
        scanf("%d", &numbers[gap]);
    }
    shell_sort(numbers, num_of_element);
        printf("%d", numbers[num_of_element-index]);
    return 0;
}
