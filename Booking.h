#ifndef BOOKING_H
#define BOOKING_H

#include <vector>
#include "Customer.h"
#include "Room.h"
#include "Billing.h"

class Booking{
    private:
        static int id;
        std::vector<Customer*> customers;
        Room* room;
        Billing* bill;

    public:
        Booking();
        Booking(Room* r, Billing* b, std::vector<Customer*> c): room{r}, bill{b}, customers{c} {};

};

#endif