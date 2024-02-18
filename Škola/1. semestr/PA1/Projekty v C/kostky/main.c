#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *cisla; // Changed to a single char* to hold concatenated numbers
    int delka;   // Length of the string
} Kostka;

void removeTrailingNewline(char *str) {
    int len = strlen(str); // Get the length of the string
    if (len > 0 && str[len - 1] == '\n') { // Check if the last character is a newline
        str[len - 1] = '\0'; // Replace the newline with a null terminator
    }
}


bool isSubString(char * big, char * small){
    char * doubleBig = malloc(strlen(big) + 1);
    strcpy(doubleBig, big);
    strcat(doubleBig, big);

    char * val = strstr(doubleBig, small);
    free(doubleBig);
    if(val){
        return true;
    }
    return false;
}

int main() {
    Kostka *kostky = NULL;
    char *line = NULL;
    char *delims = "[], ";
    size_t linecap = 0;
    ssize_t linelen;
    int unikaty = 0;

    int kostkaIndex = 0;

    while ((linelen = getline(&line, &linecap, stdin)) > 0) {
        kostky = realloc(kostky, (kostkaIndex + 1) * sizeof(Kostka));
        kostky[kostkaIndex].cisla = malloc(1); // Start with an empty string
        kostky[kostkaIndex].cisla[0] = '\0';   // Null-terminate the empty string
        kostky[kostkaIndex].delka = 0;

        char *token = strtok(line, delims);
        while (token) {
            // Resize the cisla to accommodate the new token plus the null terminator
           removeTrailingNewline(token);
            kostky[kostkaIndex].cisla = realloc(kostky[kostkaIndex].cisla, kostky[kostkaIndex].delka + strlen(token) + 1);
            // Concatenate the token to the end of cisla
            strcat(kostky[kostkaIndex].cisla, token);
            // Update the length of cisla
            kostky[kostkaIndex].delka += strlen(token);

            token = strtok(NULL, delims);
        }
        kostkaIndex++;
    }

    int start = 0;

    // Are they equal?
    for (int i = 0; i <= kostkaIndex; ++i) {
        for (int j = start; j < kostkaIndex; ++j) {
            if (i != j && kostky[i].delka == kostky[j].delka){
                if (!isSubString(kostky[i].cisla, kostky[j].cisla)){
                    unikaty++;
                    printf("%s:%s\n", kostky[i].cisla, kostky[j].cisla);
                }
            }
        }
        start++;
    }

    // tisk
        printf("%d\n", isSubString(kostky[1].cisla, kostky[4].cisla));
    printf("%d\n", unikaty);

    // Free the allocated memory
    free(line);
    for (int i = 0; i < kostkaIndex; ++i) {
        free(kostky[i].cisla);
    }
    free(kostky);

    return 0;
}
