#ifndef CBANK_CUSTOMER_H
#define CBANK_CUSTOMER_H

#include <stdint.h>

// currency repository
typedef enum {
    TRY,
    USD,
    EUR,
    GBP,
    CHF,
    JPY
}Currency;

// Currency values in TRY terms
static constexpr double EXCHANGE_RATES[] = {
    [TRY] = 1.0,
    [USD] = 34.10,
    [EUR] = 38.05,
    [GBP] = 45.20,
    [CHF] = 40.15,
    [JPY] = 0.237
};

// a struct capable of storing account type
typedef enum {
    CHECKING,
    SAVINGS,
    INVESTMENT,
    ACCOUNT_NONE
} Account;

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
    Account account_type;           // customer's account type
    Birthday birthday;              // customer's birthday
    Phone phone;                    // customer's phone number and area code of phone number
    Currency currency;              // customer's account currency
}Customer;

typedef struct Node {
    Customer customer;
    struct Node* next;
}Node;

char* get_string(char* target,int size);
void clear_customer(Customer* customer);
void list_customer_information(Customer customer);





#endif //CBANK_CUSTOMER_H
