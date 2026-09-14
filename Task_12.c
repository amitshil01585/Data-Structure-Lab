/* Task 12: Apply Linear Search to find a given element in an array */
#include <stdio.h>
 
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;   /* return index of first match */
    }
    return -1;
}
 
int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
 
    printf("Enter element to search: ");
    scanf("%d", &key);
 
    int result = linearSearch(arr, n, key);
 
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found.\n");
 
    return 0;
}
