#include "input.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <stdio.h>

#define UINT_DIGITS(type) (((sizeof(type) * 8 * 30103) / 100000 + 1) + 1)


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

uint8_t input_get_uint8_t() {
    char temp[UINT_DIGITS(uint8_t)];
    uint8_t uin = 0;
    if(fgets(temp, sizeof(temp), stdin) != nullptr) {
        char* p = strchr(temp, '\n');

        if(p != nullptr) {
            *p = '\0';
        }
        else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
    else {
        return 0;
    }
    int adet = sscanf(temp, "%" SCNu8, &uin);
    if(adet == 1) {
        return uin;
    }
    else {
        return 0;
    }
}