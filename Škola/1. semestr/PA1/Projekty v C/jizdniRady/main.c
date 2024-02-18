#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int casOdjezd;
    int casPrijezd;
    char dopravce[4097];
} Entry;

typedef struct {
    int h;
    int m;
    int s;
} FormatovanyCas;

typedef struct {
    FormatovanyCas casOdjezd;
    FormatovanyCas casPrijezd;
    char dopravce[4097];
} FormatovanyEntry;

typedef struct {
    FormatovanyEntry odpovedA;
    FormatovanyEntry odpovedB;
    bool found;
} Odpoved;

int naSekundy (int h, int m, int s){
    return h*3600+m*60+s;
}

FormatovanyCas naformatovatCas (int s){
    FormatovanyCas format = {0, 0, 0};
    int tmp = s;
    format.h = floor((double)s/3600);
    tmp = s - format.h*3600;
    s = tmp;
    format.m = floor((double)s/60);
    tmp = s - format.m*60;
    s = tmp;
    format.s = s;

    return format;
}

Odpoved vyhodnotit(Entry * Acko, Entry * Bcko, int otazka, int pocetA, int pocetB){
    Odpoved odpoved;
    int maxTime = 9999999;

    odpoved.found = false;

    for (int i = 0; i < pocetA; ++i) {
        for (int j = 0; j < pocetB; ++j) {
            if (Acko[i].casOdjezd >= otazka && Acko[i].casPrijezd <= Bcko[j].casOdjezd && Bcko[j].casPrijezd - Acko[i].casOdjezd < maxTime) {
                maxTime = Bcko[j].casPrijezd - Acko[i].casOdjezd;

                odpoved.odpovedA.casOdjezd = naformatovatCas(Acko[i].casOdjezd);
                odpoved.odpovedA.casPrijezd = naformatovatCas(Acko[i].casPrijezd);
                strcpy(odpoved.odpovedA.dopravce, Acko[i].dopravce);

                odpoved.odpovedB.casOdjezd = naformatovatCas(Bcko[j].casOdjezd);
                odpoved.odpovedB.casPrijezd = naformatovatCas(Bcko[j].casPrijezd);
                strcpy(odpoved.odpovedB.dopravce, Bcko[j].dopravce);

                odpoved.found = true;
            }
        }
    }

    return odpoved;
}


int main() {
    Entry * Acko = NULL, * Bcko = NULL;
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    Odpoved odpoved;

    int pocetA = 0, pocetB = 0;

    printf("Jizdni rad:\n");

    while ((linelen = getline(&line, &linecap, stdin)) > 0){
        int h1,m1,s1,h2,m2,s2,h3,m3,s3;
        char dopravce[4097];

        if (sscanf(line, "A %d:%d:%d %d:%d:%d %[^\n]", &h1, &m1, &s1, &h2, &m2, &s2, dopravce) == 7){
            Acko = realloc(Acko, (pocetA+1) * sizeof(*Acko));

            strcpy(Acko[pocetA].dopravce, dopravce);
            Acko[pocetA].casOdjezd = naSekundy(h1, m1, s1);
            Acko[pocetA].casPrijezd = naSekundy(h2, m2, s2);

            pocetA++;
        } else if (sscanf(line, "B %d:%d:%d %d:%d:%d %[^\n]", &h1, &m1, &s1, &h2, &m2, &s2, dopravce) == 7){
            Bcko = realloc(Bcko, (pocetB+1) * sizeof(*Bcko));

            strcpy(Bcko[pocetB].dopravce, dopravce);
            Bcko[pocetB].casOdjezd = naSekundy(h1, m1, s1);
            Bcko[pocetB].casPrijezd = naSekundy(h2, m2, s2);

            pocetB++;
        } else if (sscanf(line, "? %d:%d:%d", &h3, &m3, &s3) == 3){

            odpoved = vyhodnotit(Acko, Bcko, naSekundy(h3, m3, s3), pocetA, pocetB);

            if(odpoved.found){
                printf("A %d:%d:%d %d:%d:%d %s\n", odpoved.odpovedA.casOdjezd.h, odpoved.odpovedA.casOdjezd.m, odpoved.odpovedA.casOdjezd.s,
                       odpoved.odpovedA.casPrijezd.h, odpoved.odpovedA.casPrijezd.m, odpoved.odpovedA.casPrijezd.s, odpoved.odpovedA.dopravce);
                printf("B %d:%d:%d %d:%d:%d %s\n", odpoved.odpovedB.casOdjezd.h, odpoved.odpovedB.casOdjezd.m, odpoved.odpovedB.casOdjezd.s,
                       odpoved.odpovedB.casPrijezd.h, odpoved.odpovedB.casPrijezd.m, odpoved.odpovedB.casPrijezd.s, odpoved.odpovedB.dopravce);
            }
            else {
                printf("Spojeni neexistuje.\n");
            }
        } else {
            printf("Nespravny vstup.\n");
        }
    }

    free(line);
    free(Acko);
    free(Bcko);

    return 0;
}
