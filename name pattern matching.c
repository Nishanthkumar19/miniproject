#include <stdio.h>
#include <regex.h>

int main() {
    regex_t regex;
    char name[50];

    printf("Enter a name: ");
    scanf("%s", name);

    // Compile the regular expression
    int ret = regcomp(&regex, "[A-Za-z]+", REG_EXTENDED);
    if (ret) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    // Execute the regular expression
    ret = regexec(&regex, name, 0, NULL, 0);
    if (!ret) {
        printf("Name matched the pattern\n");
    } else if (ret == REG_NOMATCH) {
        printf("Name did not match the pattern\n");
    } else {
        char error_message[100];
        regerror(ret, &regex, error_message, sizeof(error_message));
        fprintf(stderr, "Regex match failed: %s\n", error_message);
        return 1;
    }

    // Free the memory allocated for the regex
    regfree(&regex);

    return 0;
}
