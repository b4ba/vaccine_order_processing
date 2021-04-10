#ifndef __ORDER_H
#define __ORDER_H

#include "Customer.hpp"
#include <string>


/* Order object */
class Order
{

    /* Private variables */
    std::string date;
    int quantity;
    int customerNumber;
public:
    /* Constructor declaration */
    Order(int, int, std::string);
    /* Getter methods */
    std::string getDate();
    int getQuantity();
    int getCustomerNumber();

};

#endif
