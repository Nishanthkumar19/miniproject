#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100

int main() {
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];
    int flames_count[6] = {0};
    char *flames[] = {"Friends", "Lovers", "Attraction", "Marriage", "Enemies", "Siblings"};
    int i, j, len1, len2, remaining, index;

    printf("Enter the first name: ");
    fgets(name1, sizeof(name1), stdin);
    name1[strcspn(name1, "\n")] = '\0'; // Remove newline character

    printf("Enter the second name: ");
    fgets(name2, sizeof(name2), stdin);
    name2[strcspn(name2, "\n")] = '\0'; // Remove newline character

    // Convert names to lowercase
    for (i = 0; name1[i] != '\0'; i++) {
        name1[i] = tolower(name1[i]);
    }
    for (i = 0; name2[i] != '\0'; i++) {
        name2[i] = tolower(name2[i]);
    }

    // Calculate the number of occurrences of each letter in both names
    len1 = strlen(name1);
    len2 = strlen(name2);
    for (i = 0; i < len1; i++) {
        if (name1[i] != ' ') {
            for (j = 0; j < len2; j++) {
                if (name1[i] == name2[j]) {
                    name2[j] = ' '; // Mark letter as used
                    break;
                }
            }
            if (j == len2) // Letter not found in name2
                flames_count[0]++;
        }
    }

    // Calculate remaining letters in name2
    remaining = 0;
    for (i = 0; i < len2; i++) {
        if (name2[i] != ' ')
            remaining++;
    }

    // Calculate total count of letters in both names
    remaining += flames_count[0];

    // Calculate index of flames_count to remove letters
    while (remaining > 6) {
        remaining %= 6;
        if (remaining == 0)
            remaining = 6;
    }
    index = remaining;

    printf("Relationship between %s and %s: %s\n", name1, name2, flames[index - 1]);

    return 0;
}
