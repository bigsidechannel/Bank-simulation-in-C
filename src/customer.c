#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "customer.h"
#include "error.h"
#include "validate.h"

void clear_customer(Customer* customer) {
    if (customer == nullptr) return;

    memset(customer, 0, sizeof(Customer));

    customer->account_type = ACCOUNT_NONE;
    customer->currency = CURRENCY_TRY;
}

static const char* const ACCOUNT_TYPE_NAME[] = {
    [ACCOUNT_NONE] = "ACCOUNT_NONE",
    [CHECKING] = "CHECKING",
    [SAVINGS] = "SAVINGS",
    [INVESTMENT] = "INVESTMENT",
};

const char* account_type_name(AccountType type) {
    if (type < ACCOUNT_TYPE_COUNT && ACCOUNT_TYPE_NAME[type] != nullptr) {
        return ACCOUNT_TYPE_NAME[type];
    }
    return "Unknown";
}

void list_customer_information(const Customer* customer) {
    printf("-------------------------------------\n");
    printf("%s\n",customer->name);
    printf("Iban: %s\n",customer->iban);
    printf("Tc: %s\n",customer->tc);
    printf("Password: %s\n",customer->password);
    printf("Id: %u\n",customer->customer_id);
    printf("Account Number: %" PRIu64 "\n", customer->account_number);
    printf("balance: %lu\n",customer->balance);
    printf("debt: %lu\n",customer->debt);
    printf("Account Type: %s\n", account_type_name(customer->account_type));
    printf("Phone: +%s %s\n",customer->phone.area_code, customer->phone.number);
    printf("Currency: %s\n", currency_name(customer->currency));
}

CbankResult customer_set_name(Customer* customer, const char* name) {
    if (customer == nullptr) return CBANK_ERR_NULL;

    CbankResult is_valid = name_validate(name);
    if (is_valid != CBANK_OK) {
        printf("name_validate_err: %s\n",cbank_errors(is_valid));
        return is_valid;
    } 

    strncpy(customer->name, name, CUSTOMER_NAME_LEN - 1);
    customer->name[CUSTOMER_NAME_LEN - 1] = '\0'; 
    return CBANK_OK;
}

CbankResult customer_set_iban(Customer* customer,const char* iban) {
    CbankResult is_valid = iban_validate(iban);
    if (customer == nullptr) return CBANK_ERR_NULL;

    if(is_valid != CBANK_OK) {
        printf("iban_validate_error: %s\n",cbank_errors(is_valid));
        return is_valid;
    }

    strncpy(customer->iban, iban, CUSTOMER_İBAN_LEN - 1);
    customer->iban[CUSTOMER_NAME_LEN - 1] = '\0';

    return CBANK_OK;
}