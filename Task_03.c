/* Task 3: Find prime numbers using the Sieve of Eratosthenes method */
#include <stdio.h>
#include <stdbool.h>
 
int main() {
    int n;
    printf("Enter the upper limit: ");
    scanf("%d", &n);
 
    bool isComposite[n + 1];
    for (int i = 0; i <= n; i++)
        isComposite[i] = false;
 
    for (int p = 2; p * p <= n; p++) {
        if (!isComposite[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p)
                isComposite[multiple] = true;
        }
    }
 
    printf("Prime numbers up to %d are:\n", n);
    for (int i = 2; i <= n; i++) {
        if (!isComposite[i])
            printf("%d ", i);
    }
    printf("\n");
 
    return 0;
}
