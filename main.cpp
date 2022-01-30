#include <iostream>
#include "Booking.h"
using namespace std;

// Room
void room_menu(map<int, Room*> &rooms){
    
}


// Customers
void customer_menu(map<string, Customer*> &customers){
    int choice = 1;

    while(choice){
        cout << "Create Customer(1)" << endl;
        cout << "View Customer(2)" << endl;
        cout << "Edit Customer(3)" << endl;
        cout << "Delete Customer(4)" << endl;
        cout << "Return(0)" << endl;
        cin >> choice;

        switch(choice){
            case 1:
                create_cust(customers);
                break;
            case 2:
                view_cust(customers);
                break;
            case 3:
                edit_cust(customers);
                break;
            case 4:
                delete_cust(customers);
                break;
            default:
                cout << "Invalid input!" << endl;
        }
    }

}

void create_cust(map<string, Customer*> &customers, Booking* booking = nullptr){
    string name = "", contact = "", ic = "";

    cout << "Enter customer's name: ";
    cin >> name;
    cout << "Enter customer's contact: ";
    cin >> contact;
    cout << "Enter customer's ic: ";
    cin >> ic;

    customers[ic] = new Customer(name, contact, ic, booking);
}

// Bookings
void book_menu(map<int, Booking*> &bookings){

}


bool menu(map<int, Room*> &rooms, map<string, Customer*> &customers, map<int, Booking*> &bookings){
    int choice;

    cout << "Booking menu(1)" << endl;
    cout << "Customer menu(2)" << endl;
    cout << "Room menu(3)" << endl;
    cout << "Exit(0)" << endl;
    cout << "Choose your action: ";
    cin >> choice;

    switch(choice){
        case 1:
            book_menu(bookings);
            break;
        case 2:
            customer_menu(customers);
            break;
        case 3:
            room_menu(rooms);
            break;
        case 0:
            return false;
        default:
            cout << "Invalid input!" << endl;
    }

    return true;
}

int main(){
    // Rooms
    map<int, Room*> rooms; // Room number as key

    // Customers
    map<string, Customer*> customers; // IC as key

    // Bookings
    map<int, Booking*> bookings; // id as key

    
    // Menu
    cout << "Welcome to Hotel Management System!" << endl;

    bool choice = true;

    while(choice)
        choice = menu(rooms, customers, bookings);

    return 0;
}