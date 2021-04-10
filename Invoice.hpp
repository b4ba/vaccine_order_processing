#ifndef __INVOICE_H
#define __INVOICE_H

#include "Customer.hpp"
#include "Order.hpp"
#include <string>

/* Invoice class */
class Invoice
{
    /* An invoice consists of the following information: 
     * customer number, customer name, invoice number, 
     * shipment date, shipment quantity. */

    Customer* customer;
    int invoiceNumber;
    std::string date;

public:
    /* Constructor declaration */
    Invoice(Customer*, std::string);

    /* Getter methods */
    int getCustomerNumber();
    int getInvoiceNumber();
    int getQuantity();
    std::string getDate();
    Customer* getCustomer();

};

#endif
