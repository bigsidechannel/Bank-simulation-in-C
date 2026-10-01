#include <stdint.h>
#include "currency.h"

static const char* const CURRENCY_NAME[] = {
    [CURRENCY_TRY] = "TRY",
    [CURRENCY_USD] = "USD",
    [CURRENCY_EUR] = "EUR",
    [CURRENCY_GBP] = "GBP",
    [CURRENCY_CHF] = "CHF",
    [CURRENCY_JPY] = "JPY"
};

const char* currency_name(Currency currency) {
    if (currency < CURRENCY_COUNT && CURRENCY_NAME[currency] != nullptr) {
        return CURRENCY_NAME[currency];
    }
    return "Unknown";
}

// Currency values in TRY terms
static const uint64_t EXCHANGE_RATES[] = {
    [CURRENCY_TRY] = 100,
    [CURRENCY_USD] = 3410,
    [CURRENCY_EUR] = 3805,
    [CURRENCY_GBP] = 4520,
    [CURRENCY_CHF] = 4015,
    [CURRENCY_JPY] = 24
};