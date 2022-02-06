#include <iostream>
#include <cctype>
#include "Booking.h"
using namespace std;

// Menu, create, search, view, edit, delete

// Room
// Room type: Single, Double, Family, Luxury
// Bed size: Single, Double, Queen, King
void room_menu(map<int, Room*> &rooms){
    int choice = 1;

    while(choice){
        cout << "Create Room(1)" << endl;
        cout << "View Room(2)" << endl;
        cout << "Edit Room(3)" << endl;
        cout << "Delete Room(4)" << endl;
        cout << "Return(0)" << endl;
        cin >> choice;

        switch(choice){
            case 1:
                create_room(rooms);
                break;
            case 2:
                view_room(rooms);
                break;
            case 3:
                edit_room(rooms);
                break;
            case 4:
                delete_room(rooms);
                break;
            case 0:
                return;
            default:
                cout << "Invalid input!" << endl;
        }
    }

}

void create_room(map<int, Room*> &rooms){
    string room_type;
    int room_number = 0, room_choice = -1;
    map<string, int> bed_type;
    int sing, doub, queen, king;
    float cost;

    do{
        cout << "Enter room_number: ";
        cin >> room_number;

        if(rooms.find(room_number) == rooms.end())
            break;

        cout << "Room exist!" << endl;
    }while(1);

    do{
        cout << "Room type:" << endl;
        cout << "Single(1)" << endl;
        cout << "Double(2)" << endl;
        cout << "Family(3)" << endl;
        cout << "Luxury(4)" << endl;
        cout << "Enter room_type(1-4): ";
        cin >> room_choice;

        switch(room_choice){
            case 1:
                room_type = "single";
                break;
            case 2:
                room_type = "double";
                break;
            case 3:
                room_type = "family";
                break;
            case 4:
                room_type = "luxury";
                break;

            default:
                cout << "Invalid Input!" << endl;
        }

    }while(room_choice <= 0 || room_choice >= 5);


    cout << "Enter number of bed(0 if non)" << endl;
    cout << "Single: ";
    cin >> sing;
    cout << "Double: ";
    cin >> doub;
    cout << "Queen: ";
    cin >> queen;
    cout << "King: ";
    cin >> king;

    bed_type["single"] = sing;
    bed_type["double"] = doub;
    bed_type["queen"] = queen;
    bed_type["king"] = king;

    cout << "Cost of the room per night: ";
    cin >> cost;

    rooms[room_number] = new Room(room_number, room_type, cost, bed_type);
}

Room* search_room(map<int, Room*> &rooms){
    int data;
    Room* cur;

    cout << "Enter room number: ";
    cin >> data;

    auto res = rooms.find(data);

    if(res != rooms.end())
        cur = res->second;
    else
        cout << "Room not found!" << endl;

    return cur;
}

void view_room(map<int, Room*> &rooms){
    Room* cur = search_room(rooms);

    if(cur){
        string nul;
        cout << "Room Info" << endl;
        cout << "Room Number: " << cur->get_roomNum() << endl;
        cout << "Room type: " << cur->get_roomType() << endl;
        cout << "Room Bed Types:" << endl;
        map<string, int> cur_bed = cur->get_bedType();
        for(auto i:cur_bed){
            cout << (char)toupper(i.first[0])+i.first.substr(1) << " room: " << i.second << endl;
        }

        cout << "Room Cost: " << cur->get_cost() << endl;
        cout << "Press any key to continue" << endl;
        cin >> nul;
    }
}

void edit_room(map<int, Room*> &rooms){
    Room* cur = search_room(rooms);

    if(cur){
        int choice = -1;

        do{
            cout << "Select one type of room info to change";
            cout << "Room number(1)" << endl;
            cout << "Room type(2)" << endl;
            cout << "Room bed type(3)" << endl;
            cout << "Cost(4)" << endl;
            cout << "Exit(0)" << endl;

            string data_str;
            int data_int, sing, doub, queen, king;
            float data_flt;
            map<string, int> data_map;

            switch(choice){
                case 1:
                    cout << "Enter new room number: " << endl;
                    cin >> data_int;
                    cur->set_roomNum(data_int);
                case 2:
                    cout << "Enter new room type: " << endl;
                    cin >> data_str;
                    cur->set_roomType(data_str);
                case 3:
                    cout << "Enter new number of beds(0 if non)" << endl;
                    cout << "Single: ";
                    cin >> sing;
                    cout << "Double: ";
                    cin >> doub;
                    cout << "Queen: ";
                    cin >> queen;
                    cout << "King: ";
                    cin >> king;

                    data_map["single"] = sing;
                    data_map["double"] = doub;
                    data_map["queen"] = queen;
                    data_map["king"] = king;
                    cur->set_bedType(data_map);
                case 4:
                    cout << "Enter new cost: " << endl;
                    cin >> data_flt;
                    cur->set_cost(data_flt);
                case 0:
                    return;
                default:
                    cout << "Invalid Input!" << endl;
            }
        }while(choice >= 0 && choice <= 3);
    }
}

void delete_room(map<int, Room*> &rooms){
    Room* cur = search_room(rooms);

    if(cur)
        rooms.erase(cur->get_roomNum());
    
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
            case 0:
                return;
            default:
                cout << "Invalid input!" << endl;
        }
    }

}

void create_cust(map<string, Customer*> &customers, Booking* booking = nullptr){
    string name = "", contact = "", ic = "", book;

    cout << "Enter customer's name: ";
    cin >> name;
    cout << "Enter customer's contact: ";
    cin >> contact;
    cout << "Enter customer's ic: ";
    cin >> ic;
    cout << "Does this customer have a booking?(y/n): ";
    cin >> book;

    if(book == "y" || book == "Y"){
        int book_id = 0;
        pair<bool, Booking*> cus_book; // Bool to check if cancel searching

        cout << "Enter booking number: ";
        cin >> book_id;
        

        do{
            cus_book = search_book(book_id);

            if(!cus_book.first) return;
        }while(cus_book.second == nullptr);

        booking = cus_book.second;
    }

    customers[ic] = new Customer(name, contact, ic, booking);
}

Customer* search_cust(map<string, Customer*> &customers){
    string type = "", data = "";
    Customer* cur;
    int choice = -1;

    do{
        cout << "Select one type of customer info for searching";
        cout << "Name(1)" << endl;
        cout << "IC(2)" << endl;
        cout << "Contact(3)" << endl;
        cout << "Exit(0)" << endl;

        switch(choice){
            case 1:
                type = "name";
                cout << "Enter name: " << endl;
                cin >> data;
            case 2:
                type = "ic";
                cout << "Enter IC: " << endl;
                cin >> data;
            case 3:
                type = "contact";
                cout << "Enter contact: " << endl;
                cin >> data;
            case 0:
                return nullptr;
            default:
                cout << "Invalid Input!" << endl;
        }
    }while(choice >= 0 && choice <= 3);


    for(auto i:customers){
        Customer* cur = i.second;
        string res = cur->get_str(type);
        
        if(res == data)
            return cur;
    }

    cout << "Customer not found!" << endl;

    return nullptr;
}

void view_cust(map<string, Customer*> &customers){
    Customer* cur = search_cust(customers);

    if(cur){
        string nul;
        cout << "Customer Info" << endl;
        cout << "Name: " << cur->get_str("name") << endl;
        cout << "IC: " << cur->get_str("ic") << endl;
        cout << "Contact: " << cur->get_str("contact") << endl;
        cout << "Press any key to continue" << endl;
        cin >> nul;
    }
}

void edit_cust(map<string, Customer*> &customers){
    Customer* cur = search_cust(customers);
    string type, data;

    if(cur){
        int choice = -1;

        do{
            cout << "Select one type of customer info to change";
            cout << "Name(1)" << endl;
            cout << "IC(2)" << endl;
            cout << "Contact(3)" << endl;
            cout << "Exit(0)" << endl;

            switch(choice){
                case 1:
                    type = "name";
                    cout << "Enter new name: " << endl;
                    cin >> data;
                case 2:
                    type = "ic";
                    cout << "Enter new IC: " << endl;
                    cin >> data;
                case 3:
                    type = "contact";
                    cout << "Enter new contact: " << endl;
                    cin >> data;
                case 0:
                    return;
                default:
                    cout << "Invalid Input!" << endl;
            }
        }while(choice >= 0 && choice <= 3);

        cur->set_str(type, data);
    }
}

void delete_cust(map<string, Customer*> &customers){
    Customer* cur = search_cust(customers);

    if(cur)
        customers.erase(cur->get_str("ic"));
    
}

// Bookings
void book_menu(map<int, Booking*> &bookings){

}


void menu(map<int, Room*> &rooms, map<string, Customer*> &customers, map<int, Booking*> &bookings){
    int choice = -1;

    while(choice){
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
                return;
            default:
                cout << "Invalid input!" << endl;
        }
    }

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

    menu(rooms, customers, bookings);
    return 0;
}