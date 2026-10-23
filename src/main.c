#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "customer.h"
#include "input.h"
#include "error.h"
#include "validate.h"

int main() {
    Customer customer;
    char temp_name[CUSTOMER_NAME_LEN];
    char temp_tc[CUSTOMER_TC_LEN];
    char temp_password[CUSTOMER_PASSWORD_LEN];
    const char* my_iban = "TR419900100000012345678901";
    clear_customer(&customer);
    customer_set_name(&customer, input_get_string(temp_name,sizeof temp_name));
    customer_set_iban(&customer, my_iban);
    customer_set_tc(&customer, input_get_string(temp_tc,sizeof temp_tc), sizeof(temp_tc));
    customer_set_password(&customer, input_get_string(temp_password, sizeof(temp_password)));
    list_customer_information(&customer);
    return 0;
}




