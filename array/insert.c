#include <stdio.h>
 
int main()
{
   int array[100], pos, a, n, value;
   printf("Enter number of elements in array\n");
   scanf("%d", &n);
 
   printf("Enter %d elements\n", n);
 
   for (a = 0; a < n; a++)
      scanf("%d", &array[a]);
   
   printf("The original array is: ");
   for (a = 0; a < n; a++)
      printf("%d ", array[a]);
    printf("\n");
 
   printf("Enter the location where you wish to insert an element\n");
   scanf("%d", &pos);
 
   printf("Enter the value to insert\n");
   scanf("%d", &value);
 
   for (a = n - 1; a >= pos - 1; a--)
      array[a+1] = array[a];
 
   array[pos-1] = value;
 
   printf("Resultant array is\n");
 
   for (a = 0; a <= n; a++)
      printf("%d", array[a]);
 
   return 0;
}