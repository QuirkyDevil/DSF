#include <stdio.h>
int main()
{
 int array[100]={ 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 }, a,n=10, value;
 printf("The original array is: ");
 for (a = 0; a < n; a++)
 printf("%d ", array[a]);
 printf("\n");
 printf("Enter the value to insert\n");
 scanf("%d", &value);
 for (a = n - 1; a >= 4 - 1; a--)
 array[a+1] = array[a];
 array[4-1] = value;
 printf("Resultant array is\n");
 for (a = 0; a <= n; a++)
 printf("%d ", array[a]);
 return 0;
  }