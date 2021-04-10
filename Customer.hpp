#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <string>

/* Customer object */

class Customer
{
    /* Private variables */
    std::string name;
    int customerNumber;
    int orderTotalQuantity;

public:
    /* Constructor declaration */
    Customer(int customerNumber, std::string name);

    /* Getters and Setters */
    std::string getName();
    int getCustomerNumber();

    void addToOrderTotal(int);
    void resetOrderQuantity();

    int getOrderTotalQuantity();
};

#endif
