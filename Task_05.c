/* Task 5: Find a substring within a string and display its starting position */
#include <stdio.h>
#include <string.h>
 
int findSubstring(char str[], char sub[]) {
    int lenStr = strlen(str);
    int lenSub = strlen(sub);
 
    for (int i = 0; i <= lenStr - lenSub; i++) {
        int j;
        for (j = 0; j < lenSub; j++) {
            if (str[i + j] != sub[j])
                break;
        }
        if (j == lenSub)
            return i + 1;   /* 1-based position */
    }
    return -1;
}
 
int main() {
    char str[200], sub[100];
 
    printf("Enter the main string: ");
    scanf("%s", str);
    printf("Enter the substring to find: ");
    scanf("%s", sub);
 
    int pos = findSubstring(str, sub);
 
    if (pos != -1)
        printf("Substring found at position %d\n", pos);
    else
        printf("Substring not found.\n");
 
    return 0;
}
