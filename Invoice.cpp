#include "Invoice.hpp"

/* Constant variable for the invoice number starting value */
int INVOICENUMBER = 1000;

/* Invoice constructor*/
Invoice::Invoice(Customer* customer, std::string date)
{
    this->invoiceNumber = INVOICENUMBER;
    this->customer = customer;
    this->date = date;

    INVOICENUMBER++;
};

/* Getter function for invoice customer number */
int Invoice::getCustomerNumber()
{
    return customer->getCustomerNumber();
}
/* Getter function for invoice number */
int Invoice::getInvoiceNumber()
{
    return invoiceNumber;
}
/* Getter function for invoice total quantity */
int Invoice::getQuantity()
{
    return customer->getOrderTotalQuantity();
}
/* Getter function for invoice date */
std::string Invoice::getDate()
{
    return date;
}
/* Getter function for invoice customer */	
Customer* Invoice::getCustomer()
{
    return customer;
}
