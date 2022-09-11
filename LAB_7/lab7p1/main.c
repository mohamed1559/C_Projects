#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef char *str;
typedef int U16;
U16 compare_string(str first_string, str second_string) // comparing strings
{
  U16 i = 0;
  for(;;)
  {
    if (first_string[i] == '\0')
      return second_string[i] > second_string[0];

    if (second_string[i] == '\0')
      return first_string[i] < first_string[0];

    if (first_string[i] != second_string[i])
      return first_string[i] < second_string[i];
    i++;
  }
}
U16 partition(str *numbers, U16 start, U16 end, U16 N)
{
  //  the pivot to be the last element
  str pivot = numbers[end];
  U16 j = start - 1;

  for (U16 i = start; i < end; i++)
  {

    if (compare_string(numbers[i], pivot))
    {

      j++;

      str temp = numbers[j];
      numbers[j] = numbers[i];
      numbers[i] = temp;
    }
  }

  str temp = numbers[j + 1];
  numbers[j + 1] = numbers[end];
  numbers[end] = temp;
  return j + 1;
}
void quick_Sort(str *numbers, U16 start, U16 end, U16 N)
{
  if (start < end)
  {
    U16 pivot_index = partition(numbers, start, end, N);
    quick_Sort(numbers, start, pivot_index - 1, N);
    quick_Sort(numbers, pivot_index + 1, end, N);
  }
}


U16 main()
{
  U16 N;
  printf("%d", sizeof(long long int));
  scanf("%d ", &N);

  str *numbers = (str *)malloc(N * sizeof(str));

  for (U16 i = 0; i < N; i++)
  {
    str num = (str)malloc(MAX_SIZE * sizeof(char));
    scanf("%s", num);
    numbers[i] = num;
  }
  quick_Sort(numbers, 0, N - 1, N);

  for (U16 i = 0; i < N; i++)
  {
    printf("%s", numbers[N - i - 1]);
  }

  return 0;
}

