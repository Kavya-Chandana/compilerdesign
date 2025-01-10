#include <stdio.h>
#include <ctype.h>
#include <string.h>

void countTerminalsAndNonTerminals(char *cfg, int *terminals, int *nonTerminals) {
    *terminals = *nonTerminals = 0;
    for (int i = 0; cfg[i] != '\0'; i++) {
        if (islower(cfg[i]) || strchr("+-*/=(){}[]<>|", cfg[i])) {
            (*terminals)++;
        } else if (isupper(cfg[i])) {
            (*nonTerminals)++;
        }
    }
}

int main() {
    char cfg[500];
    printf("Enter CFG: ");
    fgets(cfg, 500, stdin);

    int terminals, nonTerminals;
    countTerminalsAndNonTerminals(cfg, &terminals, &nonTerminals);
    printf("Number of terminals: %d\n", terminals);
    printf("Number of non-terminals: %d\n", nonTerminals);

    return 0;
}
