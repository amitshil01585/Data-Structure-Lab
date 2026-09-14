/* Task 9: Delete a given text (m characters) from a string at a specified position */
#include <stdio.h>
#include <string.h>
 
void deleteFromString(char str[], int pos, int count) {
    int len = strlen(str);
 
    if (pos < 0 || pos >= len) {
        printf("Invalid position.\n");
        return;
    }
    if (pos + count > len)
        count = len - pos;   /* clamp so we don't go out of bounds */
 
    for (int i = pos; i + count <= len; i++)
        str[i] = str[i + count];
}
 
int main() {
    char str[200];
    int pos, count;
 
    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter position (0-based index) to start deleting from: ");
    scanf("%d", &pos);
    printf("Enter number of characters to delete: ");
    scanf("%d", &count);
 
    deleteFromString(str, pos, count);
 
    printf("Resulting string = %s\n", str);
 
    return 0;
}
