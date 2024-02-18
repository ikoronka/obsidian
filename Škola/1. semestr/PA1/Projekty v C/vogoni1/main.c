#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define VERSE_MAX 100
#define DEBUG true

typedef struct TVerse {
    struct TVerse * m_Next;
    char            m_Str [VERSE_MAX];
} TVERSE;

TVERSE * createItem(TVERSE * next, const char * verse) {
    TVERSE * newItem = (TVERSE *) malloc(sizeof(TVERSE));
    newItem->m_Next = next;
    strcpy(newItem->m_Str, verse);
    return newItem;
}

void freeList(TVERSE * list) {
    while (list) {
        TVERSE * tmp = list->m_Next;
        free(list);
        list = tmp;
    }
}



int main() {
    TVERSE * first = createItem(createItem(createItem(createItem(createItem(createItem(createItem(createItem(NULL,
                                                                                                             "untbugglyOh freddled gr"),
                                                                                                  "cturations are toThy mi"),
                                                                                       "reddled gruntbugglyOh f"),
                                                                            "on a lurgid bee"),
                                                                 "As plurdled gabbleblotchits"),
                                                      "dled gruntbugglyOh fred"),
                                           "Thy micturations are to"),
                                "Oh freddled gruntbuggly");

#if DEBUG == true
    for (TVERSE * tmp = first; tmp; tmp = tmp->m_Next)
        printf("%s\n", tmp->m_Str);
    printf("---\n");
#endif

    freeList(first); // Note: You need to either keep the freeList function or handle memory deallocation here.
    return 0;
}
