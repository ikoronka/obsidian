#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 5

// Funkce pro porovnání dvou kostek
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Funkce pro normalizaci kostky
void normalize(int *domino, int size) {
    int minIndex = 0, min = domino[0];
    for (int i = 1; i < size; ++i) {
        if (domino[i] < min) {
            min = domino[i];
            minIndex = i;
        }
    }

    int normalized[MAX_LEN];
    for (int i = 0; i < size; ++i) {
        normalized[i] = domino[(minIndex + i) % size];
    }

    memcpy(domino, normalized, size * sizeof(int));
}

int main() {
    int domino[MAX_LEN];
    int uniqueCount = 0;
    char input[256];
    int dominoes[1000][MAX_LEN] = {0}; // Předpokládáme maximálně 1000 unikátních kostek
    int dominoCount = 0;

    while (fgets(input, sizeof(input), stdin)) {
        int size = sscanf(input, "[%d,%d,%d,%d,%d]", &domino[0], &domino[1], &domino[2], &domino[3], &domino[4]);

        // Normalizace kostky
        normalize(domino, size);

        // Kontrola unikátnosti
        int found = 0;
        for (int i = 0; i < dominoCount && !found; ++i) {
            if (memcmp(dominoes[i], domino, size * sizeof(int)) == 0) {
                found = 1;
            }
        }

        if (!found) {
            memcpy(dominoes[dominoCount++], domino, size * sizeof(int));
            uniqueCount++;
        }
    }

    printf("Unikátní: %d\n", uniqueCount);

    return 0;
}
