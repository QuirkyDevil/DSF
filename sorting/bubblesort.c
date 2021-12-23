#include<stdio.h>
//function declaration 
void bubble_sort(int[], int);
 
void main() {
    //normal array input and declaration
   int arr[100], no, i;
 
   printf("\nEnter no. of elements :");
   scanf("%d", &no);
 
   printf("\nEnter array elements :");
   for (i = 0; i < no; i++)
      scanf("%d", &arr[i]);
 
   bubble_sort(arr, no);
}
 
void bubble_sort(int iarr[], int no) {
   int i, j, k, temp;
 
   printf("\nOriginal array:");
   for (k = 0; k < no; k++) {
      printf("%5d", iarr[k]);
   }
//instead of (no-1) I used (i=1) cuz it felt easier for me 
   for (i = 1; i < no; i++) {
      for (j = 0; j < no - 1; j++) {
         if (iarr[j] > iarr[j + 1]) {
            //checking the array elements and sawp
            //temp is taken to swap elements
            temp = iarr[j];
            iarr[j] = iarr[j + 1];
            iarr[j + 1] = temp;
         }
      }
 
      printf("\nAfter pass %d : ", i);
      for (k = 0; k < no; k++) {
         printf("%5d", iarr[k]);
      }
   }
}
