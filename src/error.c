#include "error.h"

static const char* const CBANK_ERRORS[] = {
    [CBANK_OK] = "CBANK_OK",
    [CBANK_ERR_NULL] = "CBANK_ERR_NULL",
    [CBANK_ERR_EMPTY] = "CBANK_ERR_EMPTY",
    [CBANK_ERR_LENGTH] = "CBANK_ERR_LENGTH",
    [CBANK_ERR_FORMAT] = "CBANK_ERR_FORMAT",
    [CBANK_ERR_DUPLICATE] = "CBANK_ERR_DUPLICATE",
    [CBANK_ERR_NOT_FOUND] = "CBANK_ERR_NOT_FOUND",
    [CBANK_ERR_FULL] = "CBANK_ERR_FULL",
    [CBANK_ERR_BANK_COUNTRY] = "CBANK_ERR_BANK_COUNTRY",
    [CBANK_ERR_BANK_CODE] = "CBANK_ERR_BANK_CODE",
    [CBANK_ERR_NAME] = "CBANK_ERR_NAME",
    [CBANK_ERR_RESERVE_DIGIT] = "CBANK_ERR_RESERVE_DIGIT",
};

const char* cbank_errors(CbankResult error) {
    if (error < CBANK_OK || error >= CBANK_ERR_COUNT) return "Error number unspecified";

    return CBANK_ERRORS[error];
}

