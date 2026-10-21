#pragma once

#include "error.h"
#include "stdint.h"
#include "customer.h"

enum {
    IBAN_TR_LEN = 26,          // TR IBAN visible length
    IBAN_BBAN_START = 4,       // first index of bank+reserve+account
    IBAN_CHECK_HI = 2,         // tens digit of the check number
    IBAN_CHECK_LO = 3,         // ones digit of the check number
    IBAN_RESERVE_INDEX = 9     // TR reserved digit, always '0'
};


CbankResult iban_validate(const char* iban);
CbankResult name_validate(const char* name);
CbankResult tc_validate(const char* tc);
CbankResult password_validate(const char* password);
CbankResult customer_id_validate(const uint32_t customer_id);
CbankResult account_number_validate(const uint64_t account_number);
CbankResult balance_validate(const uint64_t balance);
CbankResult debt_validate(const uint64_t debt);
CbankResult account_type_validate(const AccountType account_type);
CbankResult birthday_validate(const Birthday birthday);
CbankResult phone_validate(const Phone phone);
CbankResult currency_validate(const Currency currency);