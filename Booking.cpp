#include "Booking.h"
using namespace std;

int Booking::id = 0;

Booking::Booking(){
    ++id;
}

Booking::Booking(Room* r, Billing* b, vector<Customer*> c){
    ++id;
}

int Booking::get_id(){
    return id;
}

vector<Customer*> Booking::get_cust(){
    return customers;
}

Room* Booking::get_room(){
    return room;
}

Billing* Booking::get_bill(){
    return bill;
}


void Booking::set_id(int data){
    id = data;
}

void Booking::set_cust(std::vector<Customer*> data){
    customers = data;
}

void Booking::set_room(Room* data){
    room = data;
}

void Booking::set_bill(Billing* data){
    bill = data;
}
