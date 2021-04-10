#include "Order.hpp"


/* Initialising the construtor */
Order::Order(int quantity, int customerNumber, std::string date)
{
    this->quantity = quantity;
    this->customerNumber = customerNumber;
    this->date = date;
};

/* Getter function for order date */
std::string Order::getDate()
{
    return date;
}

/* Getter function for order quantity */
int Order::getQuantity()
{
    return quantity;
}

/* Getter function for order customer number */
int Order::getCustomerNumber()
{
    return customerNumber;
}

