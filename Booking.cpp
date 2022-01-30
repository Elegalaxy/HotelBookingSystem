#include "Booking.h"
using namespace std;

int Booking::id = 0;

Booking::Booking(){
    ++id;
}

Booking::Booking(Room* r, Billing* b, vector<Customer*> c){
    ++id;
}