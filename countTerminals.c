#include <stdio.h>
#include <ctype.h>
#include <string.h>

int countTerminals(char *cfg) {
    int count = 0;
    for (int i = 0; cfg[i] != '\0'; i++) {
        if (islower(cfg[i]) || strchr("+-*/=(){}[]<>|", cfg[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    char cfg[500];
    printf("Enter CFG: ");
    fgets(cfg, 500, stdin);

    int terminals = countTerminals(cfg);
    printf("Number of terminals: %d\n", terminals);

    return 0;
}
