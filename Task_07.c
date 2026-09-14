/* Task 7: Concatenate two strings (without using strcat, to show the logic) */
#include <stdio.h>
#include <string.h>
 
void myConcat(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;
 
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0';
}
 
int main() {
    char str1[100], str2[100], result[200];
 
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
 
    myConcat(str1, str2, result);
 
    printf("Concatenated string = %s\n", result);
 
    return 0;
}
