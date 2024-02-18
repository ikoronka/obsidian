#include <stdio.h>
#include <ctype.h> // For isspace()
#include <stdbool.h>

void squeezeSpaces(char *str) {
    char *src = str, *dst = str;
    bool inSpaceFlag = false;
    while (*src != '\0') {
        if (isspace(*src)) {
            if (!inSpaceFlag) {
                *dst++ = ' ';
                inSpaceFlag = true;
            }
        } else {
            *dst++ = *src;
            inSpaceFlag = false;
        }
        src++;
    }
    *dst = '\0'; // Null-terminate the modified string
}

int main() {
    char str[] = "ahoj.   jak       je?";
    squeezeSpaces(str);
    printf("Without whitespaces: '%s'\n", str);
    return 0;
}
