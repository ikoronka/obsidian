#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int * poleCisel;
    int delka;
} Kostka;

void rotateArray(int **source, int len) {
    int smallestIntIdx = 0;
    int min = (*source)[0];
    int *tmp = malloc(len * sizeof(int));

    // Find the smallest number in the array
    for (int i = 1; i < len; ++i) {
        if (min > (*source)[i]) {
            min = (*source)[i];
            smallestIntIdx = i;
        }
    }

    // Rotate the array and store the result in tmp
    for (int i = 0; i < len; ++i) {
        tmp[i] = (*source)[(smallestIntIdx + i) % len];
    }

    //copy
    for (int i = 0; i < len; ++i) {
        (*source)[i] = tmp[i];
    }

    free(tmp);
}


bool areDiceEqual (int *arr1, int *arr2, int len){
    for (int i = 0; i < len; ++i) {
        if (arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}


int main(){
    Kostka * kostky = NULL;
    char * line = NULL;
    char * delims = "[],\n";
    size_t linecap = 0;
    ssize_t linelen;

    int pocetKostek = 0;
    int unikaty = 0;

    while ((linelen = getline(&line, &linecap, stdin)) != -1) {
        char * token = strtok(line, delims);
        int pocetCisel = 0;
        kostky = realloc(kostky, (pocetKostek+1) * sizeof(Kostka));
        kostky[pocetKostek].poleCisel = NULL;

        while (token){
            kostky[pocetKostek].poleCisel = realloc(kostky[pocetKostek].poleCisel, (pocetCisel+1)*sizeof(int));
            kostky[pocetKostek].poleCisel[pocetCisel] = strtol(token, NULL, 10);
            kostky[pocetKostek].delka++;

            pocetCisel++;
            token = strtok(NULL, delims);
        }

        rotateArray(&kostky[pocetKostek].poleCisel, pocetCisel);
        pocetKostek++;
    }

    bool *isDuplicate = calloc(pocetKostek, sizeof(bool)); // Array to track duplicates

    for (int i = 0; i < pocetKostek; ++i) {
        if (isDuplicate[i]) continue; // Skip if already marked as a duplicate

        Kostka kostkai = kostky[i];
        int delkai = kostkai.delka;

        for (int j = i + 1; j < pocetKostek; ++j) {
            Kostka kostkaj = kostky[j];

            if (delkai == kostkaj.delka && areDiceEqual(kostkai.poleCisel, kostkaj.poleCisel, delkai)) {
                isDuplicate[j] = true; // Mark the duplicate entry
                break; // No need to check further if a duplicate is found
            }
        }
        unikaty++; // Increment unique count
    }


    printf("--%d--", unikaty);

//    int len = 4;
//    int * res = NULL;
//    int arr[] = {3, 4, 1, 2};
//    int * src = arr;
//
//    rotateArray(&src, len);
//
//    if (src){
//        for (int i = 0; i < len; ++i) {
//            printf("%d--", src[i]);
//        }
//    }

    for (int i = 0; i < pocetKostek; ++i) {
        free(kostky[i].poleCisel);
    }

    free(kostky);

    free(isDuplicate);

    free(line);
    return 0;
}