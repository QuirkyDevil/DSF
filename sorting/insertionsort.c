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

void insertionSort(int *A, int n){
    int key, j;
    for (int i = 1; i <= n-1; i++)
    {
        key = A[i];
        j = i-1;
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        printf("\n Pass %d: ", i);
        for(int b = 0; b <n ; b++ ){
            printf("%d\t",A[b]);
        }
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
    insertionSort(A, n);
    FinalArray(A, n);
}