/* Task 8: Insert a given text into a string at a specified position */
#include <stdio.h>
#include <string.h>
 
void insertString(char original[], char toInsert[], int pos, char result[]) {
    int i = 0, k = 0;
 
    /* copy part before insertion point */
    for (i = 0; i < pos; i++)
        result[k++] = original[i];
 
    /* copy the string to insert */
    for (i = 0; toInsert[i] != '\0'; i++)
        result[k++] = toInsert[i];
 
    /* copy the remaining part of original string */
    for (i = pos; original[i] != '\0'; i++)
        result[k++] = original[i];
 
    result[k] = '\0';
}
 
int main() {
    char original[200], toInsert[100], result[300];
    int pos;
 
    printf("Enter the original string: ");
    scanf("%s", original);
    printf("Enter the text to insert: ");
    scanf("%s", toInsert);
    printf("Enter position (0-based index) to insert at: ");
    scanf("%d", &pos);
 
    if (pos < 0 || pos > (int)strlen(original)) {
        printf("Invalid position.\n");
        return 0;
    }
 
    insertString(original, toInsert, pos, result);
    printf("Resulting string = %s\n", result);
 
    return 0;
}
