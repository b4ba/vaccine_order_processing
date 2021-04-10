#include "ordering.hpp"

// Initialising data structures
std::vector<Customer*> customers;

/* MAIN METHOD */
int main(int argc, char* argv[])
{
    /* Confirm number of arguments */
    if(argc == 2)
    {
        readFile(argv[1]);
        return EXIT_SUCCESS;
    }else
    {
       std::cout << "Invalid number of arguments!" << std::endl;
       return EXIT_FAILURE;
    }
}

/* Function for creating and displaying an invoice */
void createInvoice(Invoice* invoice)
{
    /* Print out information of invoice */
    std::cout << "OP: customer " << std::setfill('0') << std::setw(4) << invoice->getCustomerNumber() 
              << ": shipped quantity " << invoice->getCustomer()->getOrderTotalQuantity() << std::endl;
    std::cout << "SC: customer " << std::setfill('0') << std::setw(4) << invoice->getCustomerNumber() 
              << ": invoice " << invoice->getInvoiceNumber() << ": date " 
              << invoice->getDate() << ": quantity " << invoice->getQuantity() << std::endl;
    delete invoice;
}

/* Find customer who's number equals given parameter */
Customer* locateCustomer(int customerNumber)
{
    /* Check for all customers whether their 
     * number is equal to the argument inputted */
    for(Customer* customer : customers)
    {
        if(customerNumber == customer->getCustomerNumber())
        {
            return customer;
        }
    }
    return NULL;
}

/* Function for adding new customers and displaying message */
inline void manageCustomer(std::string info)
{
    /* Extract necessary fields from buffer */
    int customerNumber = std::stoi(info.substr(1, 4));
    std::string customerName = info.substr(5, info.length());
 
    customers.push_back(new Customer(customerNumber, customerName));
    std::cout << "OP: customer " << std::setfill('0') << std::setw(4) 
              << customerNumber << " added" << std::endl;
}


/* Function for handling either normal or express orders and displaying message */
inline void manageSaleOrder(std::string info)
{
    /* Extract necessary fields from buffer */
    std::string orderDate = info.substr(1, 8);
    int customerNumber = std::stoi(info.substr(10, 4));
    int quantity = std::stoi(info.substr(14, 3));

    Order* O = new Order(quantity, customerNumber, orderDate);
    /* Find customer who placed this order */
    Customer* customer = locateCustomer(customerNumber);
    
    try{
           if(customer == nullptr)
           {
               throw -1;
           }
           customer->addToOrderTotal(O->getQuantity());

            /* Normal order */
            if(info[9] == 'N')
            {

                std::cout << "OP: customer " << std::setfill('0') << std::setw(4) 
                          << customer->getCustomerNumber() << ": normal order: quantity " << O->getQuantity() << std::endl;

            }else
            {
                /* Express Order */
        
                Invoice* invoice = new Invoice(customer, O->getDate());

                std::cout << "OP: customer " << std::setfill('0') << std::setw(4)
                          << customer->getCustomerNumber() << ": EXPRESS order: quantity " 
                          << O->getQuantity() << std::endl;

                std::cout << "OP: customer " << std::setfill('0') << std::setw(4) 
                          << invoice->getCustomerNumber() << ": shipped quantity " 
                          << invoice->getCustomer()->getOrderTotalQuantity() << std::endl;
 
                std::cout << "SC: customer " << std::setfill('0') << std::setw(4) 
                          << invoice->getCustomerNumber() << ": invoice " << invoice->getInvoiceNumber() 
                          << ": date " << invoice->getDate() << ": quantity " 
                          << invoice->getQuantity() << std::endl;

                customer->resetOrderQuantity();

                delete invoice;

            }
        }catch(int e)
        {
            /* Catch runtime error if customer doesn't exist */
            std::cout << "---------- " << "customer " << customerNumber << " was not found " << e << " ----------" << std::endl;
        }
    delete O;
}

/* Function for handeling end of day orders */
inline void manageEndOfDayOrder(std::string info)
{
    /* Extract necessary field from buffer */
    std::string orderDate = info.substr(1, info.length());
    std::cout << "OP: end of day " << orderDate << std::endl;

    for(Customer* customer : customers)
    {
        /* For every customer with order quantity greater than zero
         * send invoice and reset order quantity */
        if(customer->getOrderTotalQuantity() > 0)
        {
            Invoice* invoice = new Invoice(customer, orderDate);
            createInvoice(invoice);
        }
        customer->resetOrderQuantity();
    }
}

/* Function for reading input file and deciding
 * action depending on the first character of each line */
void readFile(std::string fileName)
{    
    std::fstream inputFile;
    /* Opening file */
    inputFile.open(fileName, std::ios::in);

    if(!inputFile)
    {
        std::cout << fileName << " was not found" << std::endl;
        exit(-1);
    }
    else
    {
        std::string buffer;
        /* Options depending on first character of each line read */
        while(std::getline(inputFile, buffer))
        {
            if(buffer[0] == 'C')
            {
                manageCustomer(buffer);
            }
            else if(buffer[0] == 'S')
            {
                manageSaleOrder(buffer);
            }
            else if(buffer[0] == 'E')
            {
                manageEndOfDayOrder(buffer);
            }
        }
    }

    inputFile.close();

    /* Free memory from customer vector */
    for(Customer* customer : customers)
    {
        delete customer;
    }
}

