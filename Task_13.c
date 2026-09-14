/* Task 13: Apply Binary Search to find a given element in an array
   NOTE: Binary search requires the array to be sorted first. */
#include <stdio.h>
 
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
 
    while (low <= high) {
        int mid = low + (high - low) / 2;
 
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
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
 
    int result = binarySearch(arr, n, key);
 
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found.\n");
 
    return 0;
}
