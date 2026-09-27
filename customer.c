#include <stdio.h>
#include <string.h>
#include "customer.h"

void clear_customer(Customer* customer) {
    if (customer == NULL) return;

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
    printf("balance: %llu\n",customer->balance);
    printf("debt: %llu\n",customer->debt);
    printf("Account Type: %s\n", account_type_name(customer->account_type));
    printf("Phone: +%s %s",customer->phone.area_code, customer->phone.number);
    printf("Currency: %s", currency_name(customer->currency));
}

bool customer_set_name(Customer* customer, const char* name) {
    if (customer != nullptr && name != nullptr && name[0] != '\0') {
        snprintf(customer->name, sizeof customer->name, "%s", name);
        return true;
    }
    return false;
}