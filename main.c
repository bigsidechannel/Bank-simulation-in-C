#include <stdio.h>
#include <stdint.h>

typedef enum {
    CHECKING,
    SAVINGS,
    INVESTMENT
} Account;

typedef struct {
    uint8_t day;
    uint8_t month;
    uint16_t year;
}Birthday;

typedef struct {
    char name[30];
    char iban[27];
    char tc[12];
    uint32_t customer_id;
    uint64_t balance;
    uint64_t debt;
    Account account_type;
    Birthday birthday;
        
}Customer;




int main() {
    printf("");
    return 0;
}
