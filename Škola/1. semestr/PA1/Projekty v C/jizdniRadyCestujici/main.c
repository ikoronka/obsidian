#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VLAKY 100  // Maximum number of trains
#define MAX_STRING_LEN 256

typedef struct {
    int hodiny, minuty, sekundy;
} Cas;

typedef struct {
    Cas odjezd, prijezd;
    int kapacita;
    char dopravce[4096];
} Vlak;

// Funkce pro porovnání časů
int casPorovnani(Cas *cas1, Cas *cas2) {
    if (cas1->hodiny != cas2->hodiny) return cas1->hodiny - cas2->hodiny;
    if (cas1->minuty != cas2->minuty) return cas1->minuty - cas2->minuty;
    return cas1->sekundy - cas2->sekundy;
}

// Funkce pro převod času na sekundy
int casNaSekundy(Cas *cas) {
    return cas->hodiny * 3600 + cas->minuty * 60 + cas->sekundy;
}

// Pomocná funkce pro porovnání dvou vlaků podle času příjezdu
int porovnaniVlaku(const void *a, const void *b) {
    Vlak *vlakA = (Vlak *)a;
    Vlak *vlakB = (Vlak *)b;
    return casPorovnani(&vlakA->prijezd, &vlakB->prijezd);
}

// Funkce pro výpočet času v sekundách mezi dvěma časy
int casRozdil(Cas *start, Cas *konec) {
    return casNaSekundy(konec) - casNaSekundy(start);
}

// Funkce pro vyhledávání spojení
void najdiSpojeni(Vlak vlaky[], int pocetVlaku, Cas *zacatek, int potrebnyPocetCestujicich) {
    int cestujiciZbyva = potrebnyPocetCestujicich;
    int prvniIndex = -1, posledniIndex = -1;
    int storedStrings = 0;

    char outputStrings[pocetVlaku][MAX_STRING_LEN];

    for (int i = 0; i < pocetVlaku && cestujiciZbyva > 0; i++) {
        if (casPorovnani(&vlaky[i].odjezd, zacatek) >= 0) {  // Vlak odjíždí po požadovaném čase
            int moznostPrepravy = vlaky[i].kapacita < cestujiciZbyva ? vlaky[i].kapacita : cestujiciZbyva;
            cestujiciZbyva -= moznostPrepravy;
            if (prvniIndex == -1) prvniIndex = i;
            posledniIndex = i;
            sprintf(outputStrings[storedStrings], "%d: %02d:%02d:%02d %02d:%02d:%02d %d %s\n",
                       i + 1,
                       vlaky[i].odjezd.hodiny, vlaky[i].odjezd.minuty, vlaky[i].odjezd.sekundy,
                       vlaky[i].prijezd.hodiny, vlaky[i].prijezd.minuty, vlaky[i].prijezd.sekundy,
                       moznostPrepravy, vlaky[i].dopravce);
            storedStrings++;
        }
    }

    if (cestujiciZbyva > 0) {
        printf("Spojeni neexistuje.\n");
    } else {
        printf("%s", outputStrings[0]);
        printf("%s", outputStrings[storedStrings-1]);
    };
}

int main() {
    Vlak vlaky[100];  // Maximální počet vlaků
    int pocetVlaku = 0;
    char line[4096];

    // Načítání vlaků
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '+') {
            if (sscanf(line + 1, "%d:%d:%d %d:%d:%d %d %4095s",
                       &vlaky[pocetVlaku].odjezd.hodiny, &vlaky[pocetVlaku].odjezd.minuty, &vlaky[pocetVlaku].odjezd.sekundy,
                       &vlaky[pocetVlaku].prijezd.hodiny, &vlaky[pocetVlaku].prijezd.minuty, &vlaky[pocetVlaku].prijezd.sekundy,
                       &vlaky[pocetVlaku].kapacita, vlaky[pocetVlaku].dopravce) == 8) {
                pocetVlaku++;
            } else {
                printf("Nespravny vstup\n");
                return 1;
            }
        } else if (line[0] == '?') {
            qsort(vlaky, pocetVlaku, sizeof(Vlak), porovnaniVlaku);
            Cas zacatek;
            int potrebnyPocetCestujicich;
            if (sscanf(line + 1, "%d:%d:%d %d",
                       &zacatek.hodiny, &zacatek.minuty, &zacatek.sekundy,
                       &potrebnyPocetCestujicich) == 4) {
                najdiSpojeni(vlaky, pocetVlaku, &zacatek, potrebnyPocetCestujicich);
            } else {
                printf("Nespravny vstup\n");
                return 1;
            }
        }
    }

    return 0;
}
