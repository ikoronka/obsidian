### Kdy musíme použít for loop na uvolnění paměti
```c
#include <stdlib.h>

typedef struct {
    int* dynamicArray;
    int size;
} ExampleStruct;

int main() {
    int n = 10; // Předpokládejme, že máme 10 struktur
    ExampleStruct* array = malloc(n * sizeof(ExampleStruct));

    // Předpokládejme inicializaci každé struktury a alokaci dynamicArray zde

    // Uvolnění paměti
    for (int i = 0; i < n; i++) {
        free(array[i].dynamicArray); // Uvolnění dynamicky alokovaného pole uvnitř struktury
    }
    free(array); // Nakonec uvolnění celého pole struktur

    return 0;
}

```