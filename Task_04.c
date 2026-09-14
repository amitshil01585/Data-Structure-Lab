/* Task 4: Implement string-handling functions
   GETCHAR, PUTCHAR, LENGTH, POS, CONCAT, SUBSTRING, DELETE, INSERT, COMPARE
   All string operations are implemented manually without <string.h>. */

#include <stdio.h>

char GETCHAR(char str[], int n) {
    int i = 0;
    while (str[i] != '\0') {
        if (i + 1 == n) return str[i];
        i++;
    }
    return '\0';
}

void PUTCHAR(char str[], int n, char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (i + 1 == n) { str[i] = c; return; }
        i++;
    }
}

int LENGTH(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int POS(char str1[], char str2[]) {
    int i, j, len1 = LENGTH(str1), len2 = LENGTH(str2);
    if (len2 == 0) return 1;
    for (i = 0; i <= len1 - len2; i++) {
        j = 0;
        while (j < len2 && str1[i + j] == str2[j]) j++;
        if (j == len2) return i + 1;
    }
    return 0;
}

void CONCAT(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') result[i] = str1[i++];
    while (str2[j] != '\0') result[i++] = str2[j++];
    result[i] = '\0';
}

void SUBSTRING(char str1[], int i, int m, char result[]) {
    int k = 0, len = LENGTH(str1);
    if (i < 1 || i > len || m < 0) { result[0] = '\0'; return; }
    while (k < m && str1[i - 1 + k] != '\0') {
        result[k] = str1[i - 1 + k]; k++;
    }
    result[k] = '\0';
}

void DELETE(char str[], int i, int m) {
    int len = LENGTH(str), k;
    if (i < 1 || i > len || m <= 0) return;
    for (k = i - 1; k + m <= len; k++) str[k] = str[k + m];
}

void INSERT(char str1[], char str2[], int i, char result[]) {
    int k = 0, j = 0, p = 0, len1 = LENGTH(str1);
    if (i < 1 || i > len1 + 1) { result[0] = '\0'; return; }
    while (k < i - 1) result[p++] = str1[k++];
    while (str2[j] != '\0') result[p++] = str2[j++];
    while (str1[k] != '\0') result[p++] = str1[k++];
    result[p] = '\0';
}

int COMPARE(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) return (unsigned char)str1[i] - (unsigned char)str2[i];
        i++;
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}

int main() {
    char s1[100], s2[100], result[200];
    int n, i, m; char c;
    printf("Enter string 1: "); scanf("%99s", s1);
    printf("Enter string 2: "); scanf("%99s", s2);
    printf("\n--- Demonstrating all functions ---\n");
    printf("LENGTH(s1) = %d\n", LENGTH(s1));
    printf("Enter position n for GETCHAR: "); scanf("%d", &n);
    printf("GETCHAR(s1, %d) = %c\n", n, GETCHAR(s1, n));
    printf("Enter position n and character c for PUTCHAR: "); scanf("%d %c", &n, &c);
    PUTCHAR(s1, n, c); printf("After PUTCHAR: s1 = %s\n", s1);
    printf("POS(s1, s2) = %d\n", POS(s1, s2));
    CONCAT(s1, s2, result); printf("CONCAT(s1, s2) = %s\n", result);
    printf("Enter i and m for SUBSTRING: "); scanf("%d %d", &i, &m);
    SUBSTRING(s1, i, m, result); printf("SUBSTRING(s1, %d, %d) = %s\n", i, m, result);
    printf("Enter i and m for DELETE: "); scanf("%d %d", &i, &m);
    DELETE(s1, i, m); printf("After DELETE: s1 = %s\n", s1);
    printf("Enter position i for INSERT (insert s2 into s1): "); scanf("%d", &i);
    INSERT(s1, s2, i, result); printf("INSERT(s1, s2, %d) = %s\n", i, result);
    printf("COMPARE(s1, s2) = %d\n", COMPARE(s1, s2));
    return 0;
}

