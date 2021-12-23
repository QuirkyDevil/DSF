#include<stdio.h>

void printArray(int* A, int n){
    printf("\n Initial array is: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n");
}
void FinalArray(int* A, int n){
    printf("\n\n\n Final sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t ", A[i]);
    }
    printf("\n");
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int *A, int n){
int i, j, min_idx;
     for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (A[j] < A[min_idx])
            min_idx = j;
        swap(&A[min_idx], &A[i]);
    }
}
int main(){
    int A[] = {12, 54, 65, 7, 23, 9};
    int n, i;
    printf("\nEnter no. of elements :");
    scanf("%d", &n);
    printf("\nEnter array elements :");
    for (i = 0; i < n; i++)
      scanf("%d", &A[i]);
    printArray(A, n);
    selectionSort(A, n);
    FinalArray(A, n);
}