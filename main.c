#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef enum {
    TRY,
    USD,
    EUR,
    GBP,
    CHF,
    JPY
}Currency;

const double EXCHANGE_RATES[] = {
    [TRY] = 1.0,
    [USD] = 34.10,
    [EUR] = 38.05
};

typedef enum {
    CHECKING,
    SAVINGS,
    INVESTMENT,
    ACCOUNT_NONE
} Account;

typedef struct {
    uint8_t day;
    uint8_t month;
    uint16_t year;
}Birthday;

typedef struct {
    char area_code[4];
    char number[11];
}Phone;

typedef struct {
    char name[30];
    char iban[27];
    char tc[12];
    uint32_t customer_id;
    uint64_t balance;
    uint64_t debt;
    Account account_type;
    Birthday birthday;
    Phone phone;
    Currency currency;
}Customer;


char* get_string(char* target,int size);
void clear_customer(Customer* customer);

int main() {

    return 0;
}

char* get_string(char* target,int size) {
    if (target == NULL || size == 0) return;
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
        return NULL;
    }
    return target;
}

void clear_customer(Customer* customer) {
    if (customer == NULL) return;

    memset(customer, 0, sizeof(Customer));

    customer->account_type = ACCOUNT_NONE;
    customer->currency = TRY;
}




