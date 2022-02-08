#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Booking.h"

class Customer{
    private:
        std::string name, contact, ic;
        Booking* booking;

    public:
        Customer();
        // Customer(std::string n, std::string c, std::string i): name{n}, contact{c}, ic{i} {};
        Customer(std::string n, std::string c, std::string i, Booking* b): name{n}, contact{c}, ic{i}, booking{b} {};

        std::string get_str(std::string type);
        Booking* get_book();
        void set_str(std::string type, std::string data);
        void set_book(Booking* data);

};

#endif