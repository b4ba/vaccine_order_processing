#include "Customer.hpp"

/* Constructor */
Customer::Customer(int customerNumber, std::string name)
{
    this->customerNumber = customerNumber;
    this->name = name;
    this->orderTotalQuantity = 0;

};

/* Getter function for customer number */
int Customer::getCustomerNumber()
{
    return customerNumber;
}

/* Getter function for the customer name */
std::string Customer::getName()
{
    return name;
}
/* Function that adds the current quantity to the total quantity*/
void Customer::addToOrderTotal(int quantity)
{
   orderTotalQuantity += quantity; 
}
/* Function that resets the order quantity */
void Customer::resetOrderQuantity()
{
    orderTotalQuantity = 0;
}
/* Getter function for customer total order quantity */
int Customer::getOrderTotalQuantity()
{
    return orderTotalQuantity;
}
