#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

class Payment{ // Payment type
    private:
        std::string type, number, cvc, month, year;
        
    public:
        Payment();
        Payment(std::string t): type{t} {};
        Payment(std::string t, std::string n, std::string c, std::string m, std::string y): type{t}, number{n}, cvc{c}, month{m}, year{y} {};

        std::string get_type();
};

#endif