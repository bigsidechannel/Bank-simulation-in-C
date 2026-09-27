#ifndef CBANK_CUSTOMER_H
#define CBANK_CUSTOMER_H

#include <stdint.h>
#include "currency.h"

// a struct capable of storing account type
typedef enum {
    ACCOUNT_NONE,
    CHECKING,
    SAVINGS,
    INVESTMENT,
    ACCOUNT_TYPE_COUNT
} AccountType;


// a struct capable of storing birthday
typedef struct {
    uint8_t day;
    uint8_t month;
    uint16_t year;
}Birthday;

// a struct capable of storing phone information
typedef struct {
    char area_code[4];
    char number[11];
}Phone;

// A struct capable of storing customer information.
typedef struct {
    char name[30];                  // customer's name
    char iban[27];                  // customer's iban
    char tc[12];                    // customer's Republic of Turkey identity number
    char password[30];              // customer's password
    uint32_t customer_id;           // customer's accessible ID
    uint64_t balance;               // customer's account balance
    uint64_t debt;                  // customer's account balance due
    AccountType account_type;           // customer's account type
    Birthday birthday;              // customer's birthday
    Phone phone;                    // customer's phone number and area code of phone number
    Currency currency;              // customer's account currency
}Customer;

typedef struct Node {
    Customer customer;
    struct Node* next;
}Node;

void clear_customer(Customer* customer);
const char* account_type_name(AccountType type);
void list_customer_information(const Customer* customer);
bool customer_set_name(Customer* customer, const char* name);




#endif //CBANK_CUSTOMER_H
