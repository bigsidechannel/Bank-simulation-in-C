#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "customer.h"
#include "input.h"

int main() {
    Customer customer;
    char temp[20];
    clear_customer(&customer);
    customer_set_name(&customer, input_get_string(temp,sizeof temp));
    customer_set_iban(&customer, "TR580006200000012345678901");
    list_customer_information(&customer);
    return 0;
}




