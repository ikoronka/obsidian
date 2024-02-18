```c
#include <stdio.h>
#include <stdbool.h> // For bool type

void squeezeSpaces(const char *src, char *dest) {
    bool inSpace = false; // Track whether we're in a sequence of spaces

    while (*src != '\0') { // Loop until the end of the string
        if (*src == ' ') {
            if (!inSpace) { // If this is the first space in a sequence
                *dest++ = ' '; // Copy a single space to dest
                inSpace = true; // Now we're in a sequence of spaces
            }
        } else {
            *dest++ = *src; // Copy the non-space character to dest
            inSpace = false; // No longer in a sequence of spaces
        }
        src++; // Move to the next character
    }

    *dest = '\0'; // Null-terminate the dest string
}

```