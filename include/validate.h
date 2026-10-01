#pragma once

#include "error.h"

enum {
    IBAN_TR_LEN = 26,          // TR IBAN visible length
    IBAN_BBAN_START = 4,       // first index of bank+reserve+account
    IBAN_CHECK_HI = 2,         // tens digit of the check number
    IBAN_CHECK_LO = 3,         // ones digit of the check number
    IBAN_RESERVE_INDEX = 9     // TR reserved digit, always '0'
};


CbankResult iban_validate(const char* iban);
CbankResult name_validate(const char* name);