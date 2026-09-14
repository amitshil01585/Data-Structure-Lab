/* Task 14: Apply Binary Search to find the first occurrence, last occurrence,
   and total count of a given element in an array (array must be sorted) */
#include <stdio.h>
 
int findFirst(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;   /* keep searching left for an earlier occurrence */
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}
 
int findLast(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;   /* keep searching right for a later occurrence */
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}
 
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
            }
}
 
int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
 
    bubbleSort(arr, n);   /* ensure array is sorted before binary search */
 
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    printf("Enter element to search: ");
    scanf("%d", &key);
 
    int first = findFirst(arr, n, key);
    int last = findLast(arr, n, key);
 
    if (first == -1) {
        printf("Element not found.\n");
    } else {
        printf("First occurrence index = %d\n", first);
        printf("Last occurrence index = %d\n", last);
        printf("Total count = %d\n", last - first + 1);
    }
 
    return 0;
}
