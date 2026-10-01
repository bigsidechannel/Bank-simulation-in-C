#pragma once
#include <stdint.h>

// currency repository
typedef enum {
    CURRENCY_TRY,
    CURRENCY_USD,
    CURRENCY_EUR,
    CURRENCY_GBP,
    CURRENCY_CHF,
    CURRENCY_JPY,
    CURRENCY_COUNT
}Currency;

const char* currency_name(Currency currency);