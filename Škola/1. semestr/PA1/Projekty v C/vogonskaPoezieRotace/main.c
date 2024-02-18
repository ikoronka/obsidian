#ifndef __PROGTEST__

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define VERSE_MAX 128
typedef struct TVerse {
    struct TVerse *m_Next;
    char m_Str[VERSE_MAX];
} TVERSE;

void freeList(TVERSE *l) {
    while (l) {
        TVERSE *tmp = l->m_Next;
        free(l);
        l = tmp;
    }
}

TVERSE *createVerse(const char *verse, TVERSE *next) {
    TVERSE *n = (TVERSE *) malloc(sizeof(*n));
    strcpy(n->m_Str, verse);
    n->m_Next = next;
    return n;
}

#endif /* __PROGTEST__ */


TVERSE *vogonPoetry(const TVERSE *src) {
}

#ifndef __PROGTEST__

int main(int argc, char *argv[]) {
    TVERSE *x, *y;

    x = createVerse("Oh freddled gruntbuggly",
                    createVerse("Thy micturations are to",
                                createVerse("dled gruntbugglyOh fred",
                                            createVerse("As plurdled gabbleblotchits",
                                                        createVerse("on a lurgid bee",
                                                                    createVerse("reddled gruntbugglyOh f",
                                                                                createVerse("cturations are toThy mi",
                                                                                            createVerse(
                                                                                                    "untbugglyOh freddled gr",
                                                                                                    NULL))))))));
    y = vogonPoetry(x);
    assert (!strcmp(y->m_Str, "Oh freddled gruntbuggly"));
    assert (!strcmp(y->m_Next->m_Str, "dled gruntbugglyOh fred"));
    assert (!strcmp(y->m_Next->m_Next->m_Str, "reddled gruntbugglyOh f"));
    assert (!strcmp(y->m_Next->m_Next->m_Next->m_Str, "untbugglyOh freddled gr"));
    assert (y->m_Next->m_Next->m_Next->m_Next == NULL);
    freeList(y);
    freeList(x);

    x = createVerse("First Verse",
                    createVerse("ndVerseSeco",
                                createVerse("st VerseFir",
                                            createVerse("rseSecondVe",
                                                        createVerse("ndVerseSeco",
                                                                    createVerse("seFirst Ver",
                                                                                createVerse("rseSecondVe",
                                                                                            createVerse("st VerseFir",
                                                                                                        createVerse(
                                                                                                                "VerseSecond",
                                                                                                                createVerse(
                                                                                                                        "t VerseFirs",
                                                                                                                        NULL))))))))));
    y = vogonPoetry(x);
    assert (!strcmp(y->m_Str, "First Verse"));
    assert (!strcmp(y->m_Next->m_Str, "st VerseFir"));
    assert (!strcmp(y->m_Next->m_Next->m_Str, "seFirst Ver"));
    assert (!strcmp(y->m_Next->m_Next->m_Next->m_Str, "st VerseFir"));
    assert (!strcmp(y->m_Next->m_Next->m_Next->m_Next->m_Str, "t VerseFirs"));
    assert (y->m_Next->m_Next->m_Next->m_Next->m_Next == NULL);
    freeList(y);
    freeList(x);

    return EXIT_SUCCESS;
}

#endif /* __PROGTEST__ */