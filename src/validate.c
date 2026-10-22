#include "validate.h"
#include "error.h"
#include "bank.h"
#include "customer.h"
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


static int iban_mod97_push(int rem, int digit) {
    return (rem * 10 + digit) % 97;
}

static int iban_mod97_push_letter(int rem, char letter) {
    int value = (letter - 'A') + 10; // A=10 .. Z=35
    rem = iban_mod97_push(rem, value / 10);
    rem = iban_mod97_push(rem, value % 10);
    return rem;
}

CbankResult iban_validate(const char* iban) {
    if (iban == nullptr) {
        return CBANK_ERR_NULL;
    }
    if (iban[0] == '\0') {
        return CBANK_ERR_EMPTY;
    }
    if (strlen(iban) != IBAN_TR_LEN) {
        return CBANK_ERR_LENGTH;
    }

    if (iban[0] != BANK_COUNTRY[0] || iban[1] != BANK_COUNTRY[1]) {
        return CBANK_ERR_BANK_COUNTRY;
    }

    for (int i = 0; i < BANK_CODE_LEN; ++i) {
        if (iban[IBAN_BBAN_START + i] != BANK_CODE[i]) {
            return CBANK_ERR_BANK_CODE;
        }
    }

    if (iban[IBAN_RESERVE_INDEX] != BANK_RESERVE_DIGIT) {
        return CBANK_ERR_RESERVE_DIGIT;
    }

    for (int i = IBAN_CHECK_HI; i < IBAN_TR_LEN; ++i) {
        if (iban[i] < '0' || iban[i] > '9') {
            return CBANK_ERR_FORMAT;
        }
    }

    int rem = 0;
    for (int i = IBAN_BBAN_START; i < IBAN_TR_LEN; ++i) {
        rem = iban_mod97_push(rem, iban[i] - '0');
    }
    rem = iban_mod97_push_letter(rem, BANK_COUNTRY[0]);
    rem = iban_mod97_push_letter(rem, BANK_COUNTRY[1]);
    rem = iban_mod97_push(rem, 0);
    rem = iban_mod97_push(rem, 0);

    int expected = 98 - rem;
    int written = (iban[IBAN_CHECK_HI] - '0') * 10
        + (iban[IBAN_CHECK_LO] - '0');
    if (written != expected) {
        return CBANK_ERR_FORMAT;
    }

    return CBANK_OK;
}

CbankResult  name_validate(const char* name) {
    if (name == nullptr) return CBANK_ERR_NULL;
    if (name[0] == '\0') return CBANK_ERR_EMPTY;

    size_t len = strlen(name);

    if (len >= CUSTOMER_NAME_LEN) return CBANK_ERR_LENGTH;

    for (size_t i = 0;i < len;i++) {
        if(isdigit(name[i])) return CBANK_ERR_NAME;
    }

    return CBANK_OK;
}

CbankResult tc_validate(const char* tc) {
    if (tc == nullptr) return CBANK_ERR_NULL;
    if (tc[0] == '\0') return CBANK_ERR_EMPTY;

    size_t len = strlen(tc);

    if(len != 11) return CBANK_ERR_LENGTH;

    for (size_t i = 0;i < len;i++) {
        if(!isdigit(tc[i])) return CBANK_ERR_TC;
    }
    
    #define tc_digit(x) (tc[x] - '0')

    
    if (tc_digit(0) == 0) return CBANK_ERR_TC_FIRST_DIGIT;


    uint8_t singles = 0;
    uint8_t doubles = 0;
    uint8_t tc_algorithms_tenth_digit = 0;
    uint8_t tc_algorithms_eleventh_digit = 0;
    for (size_t i = 0; i < len - 2; i++) {
        if (i % 2 == 0) {
            singles+=tc_digit(i);
        }
        else {
            doubles+=tc_digit(i);
        }
    }
    tc_algorithms_tenth_digit = ((((singles * 7) - (doubles)) % 10) + 10) % 10;
    tc_algorithms_eleventh_digit = (singles + doubles + tc_digit(9)) % 10;
    printf("10. hane = %"PRIu8"\n",tc_algorithms_tenth_digit);
    printf("11. hane = %"PRIu8"\n",tc_algorithms_eleventh_digit);
    
    return CBANK_OK;
}