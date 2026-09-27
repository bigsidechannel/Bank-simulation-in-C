#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "customer.h"

int main() {
    Customer customer;
    clear_customer(&customer);
    customer_set_name(&customer, "melih");
    list_customer_information(&customer);
    return 0;
}




