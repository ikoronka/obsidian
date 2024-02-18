#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    char **slovnik = NULL;
    char **text = NULL;
    int pocetSlovSlovnik = 0, pocetSlovText = 0;
    char *line = NULL;
    bool nacitamSlovnik = true;
    size_t linecap = 0;
    ssize_t linelen;

    while ((linelen = getline(&line, &linecap, stdin)) > 0){
        char *token = strtok(line, " ");
        if (strcmp(line, "*****\n") == 0){
            nacitamSlovnik = false;
        } else if (nacitamSlovnik){
            while(token) {
                slovnik = (char **) realloc(slovnik, (pocetSlovSlovnik + 1) * sizeof(char *));
                slovnik[pocetSlovSlovnik] = (char *) malloc(strlen(token) * sizeof(char));
                for (int j = 0; j < strlen(token); ++j) {
                    if (token[j] == '\n'){
                        token[j] = '\0';
                    }
                }
                strcpy(slovnik[pocetSlovSlovnik], token);

                token = strtok(NULL, " ");
                pocetSlovSlovnik++;
            }
        } else {
            while(token){
                text = (char **)realloc(text, (pocetSlovText + 1) * sizeof(char*));
                text[pocetSlovText] = (char *)malloc((strlen(token) + 1));
                strcpy(text[pocetSlovText], token);

                token = strtok(NULL, " ");
                pocetSlovText++;
            }
        }
    }
    if (nacitamSlovnik){
        printf("Nespravny vstup\n");
        return 0;
    }

    bool match = false;
    char * tmp = NULL;
    int amtOfChars = 0;

    for (int i = 0; i < pocetSlovText; ++i) {
        for (int j = 0; j < strlen(text[i]); ++j) {
            if (text[i][j] == '\n'){
                text[i][j] = '\0';
            }
        }
        for (int j = 0; j < pocetSlovSlovnik; ++j) {
            if (strcasecmp(slovnik[j], text[i]) == 0){
                match = true;
                break;
            }
        }
        //printf("\n\n%lu\n\n", amtOfChars + strlen(text[i]) + 12);
        if (!match){
            if (amtOfChars + strlen(text[i]) + 12 > 80){
                printf("\n");
                amtOfChars = strlen(text[i]) + 12;
            } else if (i != 0){
                printf(" ");
                amtOfChars += strlen(text[i]) + 12;
                //printf("\n%d\n", amtOfChars);
            }
            printf("<err>%s</err>", text[i]);
        } else {
            if (amtOfChars + strlen(text[i]) > 80){
                printf("\n");
                amtOfChars = strlen(text[i]) + 1;
            } else if (i != 0){
                printf(" ");
                amtOfChars += strlen(text[i]) + 1;
                //printf("\n%d\n", amtOfChars);
            }
            printf("%s", text[i]);
            match = false;
        }
    }

    // FREEING SECTION
    free(line);

    for (int i = 0; i < pocetSlovSlovnik; i++) {
        free(slovnik[i]);
    }
    free(slovnik);

    for (int i = 0; i < pocetSlovText; i++) {
        free(text[i]);
    }
    free(text);

    free(tmp);

    return 0;
}
