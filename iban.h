#ifndef CBANK_IBAN_H
#define CBANK_IBAN_H

#include "error.h"

CbankResult iban_validate(const char* iban);

#endif //CBANK_IBAN_H