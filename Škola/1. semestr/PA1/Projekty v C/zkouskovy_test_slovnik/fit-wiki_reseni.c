#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * cstring;
typedef cstring * StringArray;

// essential for releasing individual string pointers
void freeStringArray(StringArray array, size_t len) {
    for (size_t i = 0; i < len; i ++)
        free(array[i]);
    free(array);
}

// reads strings from stdin, writes their count to p_numStrings and returns a pointer to the data
// if endOnStars is a logical true, the function should end when a string consisting of 5 stars is detected, or fail if not found
// if the function fails, it also releases all resources and returns NULL
StringArray readStringArray(size_t *p_numStrings, int endOnStars) {
    size_t limit = 10, current = 0;
    StringArray data = (StringArray) malloc(limit * sizeof(*data));
    while (1) {
        cstring s = (cstring) malloc(31 * sizeof(*s));
        if (scanf(" %30s", s) != 1) { // EOF
            if (endOnStars) { // FAIL, no dictionary separator detected
                freeStringArray(data, current);
                free(s);
                return NULL;
            }
            // OK (no separator needed)
            free(s);
            *p_numStrings = current;
            return data;
        }
        if (endOnStars && strcmp(s, "*****") == 0) { // string loaded, but might be dictionary separator
            free(s);
            *p_numStrings = current;
            return data;
        }

        if (current == limit) { // maybe realloc
            limit = limit * 3 / 2 + 10;
            data = (StringArray) realloc(data, limit * sizeof(*data));
        }
        data[current ++] = s;
    }
}

// reads both dictionary and text to be checked, returns 1 on success, 0 on failure (and releases allocated resources)
int readInput(size_t *p_dictSize, size_t *p_wordsSize, StringArray *p_dict, StringArray *p_words) {
    printf("Slovnik:\n");
    if (!(*p_dict = readStringArray(p_dictSize, 1)))
        return 0;

    printf("Text:\n");
    if (!(*p_words = readStringArray(p_wordsSize, 0))) {
        freeStringArray(*p_dict, *p_dictSize);
        return 0;
    }
    return 1;
}

// needed to keep correct types (the dict and words are arrays of strings (double char pointers)
int strCaseCmp(const char **s1, const char **s2) {
    return strcasecmp(*s1, *s2);
}

#define LINE_LIMIT 80
#define ERROR_LEN 11 // <err></err>

// tries to find all given words in a given dictionary, prints out formatted results:
// %s if found, <err>%s</err> if not found
// if > 80 letters (including spaces and markup, excluding CRLF) should be present, start writing on a new line instead
// also insert spaces between individual words
void findAll(StringArray dict, StringArray words, size_t dictLen, size_t wordsLen) {
    // sort the dictionary in order to use binary search
    qsort(dict, dictLen, sizeof(*dict), (int (*)(const void *, const void *)) strCaseCmp);

    size_t rowLength = 0;

    for (size_t i = 0; i < wordsLen; i ++) {
        size_t strLen = strlen(words[i]);

        // if found, something else than NULL is returned (and hence the condition is truthy)
        if (bsearch(words + i, dict, dictLen, sizeof(*dict), (int (*)(const void *, const void *)) strCaseCmp)) {
            if (rowLength + strLen + (i != 0) > LINE_LIMIT) { // new line
                rowLength = strLen + (i != 0);
                printf("\n%s", words[i]);
            } else { // same line
                rowLength += strLen + (i != 0);
                printf("%s%s", i == 0 ? "" : " ", words[i]);
            }
        } else { // not found
            if (rowLength + strLen + (i != 0) + ERROR_LEN > LINE_LIMIT) { // new line
                rowLength = strLen + (i != 0) + ERROR_LEN;
                printf("\n<err>%s</err>", words[i]);
            } else { // same line
                rowLength += strLen + (i != 0) + ERROR_LEN;
                printf("%s<err>%s</err>", i == 0 ? "" : " ", words[i]);
            }
        }
    }
    printf("\n"); // ProgTest requires it
}

int main(int argc, char **argv) {
    size_t dictSize, wordsSize;
    StringArray dict, words;
    if (readInput(&dictSize, &wordsSize, &dict, &words) == 0) {
        printf("Nespravny vstup.\n");
        return 1;
    }

    findAll(dict, words, dictSize, wordsSize);

    freeStringArray(dict, dictSize);
    freeStringArray(words, wordsSize);

    return 0;
}