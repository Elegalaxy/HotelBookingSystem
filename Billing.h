#ifndef BILLING_H
#define BILLING_H

#include "Payment.h"

class Billing{
    private:
        Payment* payment;
        std::string name;
        float amount;

    public:
        Billing();
        Billing(std::string n, float a, Payment* p): name{n}, amount{a}, payment{p} {};
};

#endif