#include <stdio.h>
#include <string.h>

int countAlternates(char *cfg) {
    int count = 0;
    char *token = strtok(cfg, ";");
    while (token != NULL) {
        char *arrow = strstr(token, "->");
        if (arrow) {
            for (char *p = arrow; *p != '\0'; p++) {
                if (*p == '|') {
                    count++;
                }
            }
            count++; // Add 1 for the first alternate
        }
        token = strtok(NULL, ";");
    }
    return count;
}

int main() {
    char cfg[500];
    printf("Enter CFG: ");
    fgets(cfg, 500, stdin);

    int alternates = countAlternates(cfg);
    printf("Number of alternates: %d\n", alternates);

    return 0;
}
