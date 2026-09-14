/* Task 1: Generate all permutations of a given set of elements */
#include <stdio.h>
 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
/* Recursive function using Heap's-style swapping approach:
   fix one element at a time and permute the rest */
void permute(int arr[], int start, int n) {
    if (start == n - 1) {
        printArray(arr, n);
        return;
    }
    for (int i = start; i < n; i++) {
        swap(&arr[start], &arr[i]);
        permute(arr, start + 1, n);
        swap(&arr[start], &arr[i]);   /* backtrack */
    }
}
 
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
 
    printf("\nAll permutations:\n");
    permute(arr, 0, n);
 
    return 0;
}
