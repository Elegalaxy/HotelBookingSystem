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

        int get_id();
        std::vector<Customer*> get_cust();
        Room* get_room();
        Billing* get_bill();
        
        void set_id(int data);
        void set_cust(std::vector<Customer*> data);
        void set_room(Room* data);
        void set_bill(Billing* data);
};

#endif