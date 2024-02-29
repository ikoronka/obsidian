#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int cisla[10];
    int size = sizeof cisla / sizeof *cisla;
    int amtEntered;
    printf("Zadejte 10 cisel:\n");
    while (scanf("%d"))

    printf("Serazene:\n");
    for (int i = 0; i < size; i++){
        if (i != 9){
            printf("%d, ", cisla[i]);
        } else {
            printf("%d", cisla[i]);
        }
    }

    printf("\n");

    return 0;
}
