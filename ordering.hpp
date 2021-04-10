#ifndef __ORDERING_H
#define __ORDERING_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <iomanip>
#include "Invoice.hpp"

/* Defining function prototypes */
void createInvoice(Invoice*);
Customer* locateCustomer(int);
void manageCustomer(std::string);
void manageSaleOrder(std::string);
void manageEndOfDayOrder(std::string);
void readFile(std::string);

#endif
