#include <stdio.h>
#include <string.h>
#include "customer.h"

char* get_string(char* target,int size) {
    if (target == NULL || size == 0) return nullptr;
    if (fgets(target,size,stdin) != NULL) {
        char *p = strchr(target,'\n');
        if (p != NULL) {
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

void clear_customer(Customer* customer) {
    if (customer == NULL) return;

    memset(customer, 0, sizeof(Customer));

    customer->account_type = ACCOUNT_NONE;
    customer->currency = TRY;
}

void list_customer_information(Customer customer) {
    printf("-------------------------------------");
    printf("%s",customer.name);
    printf("Iban: %s",customer.iban);
    printf("Tc: %s",customer.iban);
    printf("Password: %s",customer.password);
    printf("Tc: %u",customer.customer_id);
    printf("Tc: %lu",customer.balance);
    printf("Tc: %lu",customer.debt);
    switch(customer.account_type) {
        case(CHECKING):
            printf("Account Type: CHECKING");
            break;
        case(SAVINGS):
            printf("Account Type: SAVINGS");
            break;
        case(INVESTMENT):
            printf("Account Type: INVESTMENT");
            break;
        case(ACCOUNT_NONE):
            printf("Account Type: ACCOUNT_NONE");
            break;
        default:
            printf("Account Type: Unknown");
    }
    printf("Tc: %s",customer.iban);
    printf("Tc: %s",customer.iban);
}