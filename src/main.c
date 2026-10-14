#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "customer.h"
#include "input.h"
#include "error.h"

int main() {
    Customer customer;
    char temp[CUSTOMER_NAME_LEN];
    // Bellekteki sabit metnin adresini bir pointer'a atıyoruz.
    const char* my_iban = "TR419900100000012345678901";
    
    clear_customer(&customer);
    CbankResult customer_set_name_err = customer_set_name(&customer, (char*)input_get_string(temp,sizeof temp));
    CbankResult customer_set_iban_err = customer_set_iban(&customer, my_iban);
    list_customer_information(&customer);
    return 0;
}




