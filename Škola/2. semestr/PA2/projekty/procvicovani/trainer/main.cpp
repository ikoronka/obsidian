#include <iostream>
#include <cstdlib>

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut

    // return arg1 - arg2; // erroneous shortcut: undefined behavior in case of
    // integer overflow, such as with INT_MIN here
}

int main() {
    int cisla[10];
    int size = sizeof cisla / sizeof *cisla;
    printf("Zadejte 10 cisel:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d",
          &cisla[0], &cisla[1], &cisla[2], &cisla[3], &cisla[4], &cisla[5], &cisla[6], &cisla[7], &cisla[8], &cisla[9]);
    qsort(cisla, size, sizeof(int), compare_ints);

    for (int i = 0; i < size; i++)
        printf("%d ", cisla[i]);

    printf("\n");

    return 0;
}
