#include "input.h"
#include <string.h>
#include <stdio.h>

char* input_get_string(char* target, int size) {
    if (target == nullptr || size <= 0) return nullptr;
    if (fgets(target, size, stdin) != nullptr) {
        char* p = strchr(target, '\n');
        if (p != nullptr) {
            *p = '\0';
        }
        else {
            int c;
            while ((c = getchar()) != EOF && c != '\n');
        }
    }
    else {
        return nullptr;
    }
    return target;
}