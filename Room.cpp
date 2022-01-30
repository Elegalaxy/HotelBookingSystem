#include "Room.h"

Room::Room(){
    room_number = 0;
    room_type = "";
    cost = 0.0;
}

int Room::get_roomNum(){
    return room_number;
}

std::string Room::get_roomType(){
    return room_type;
}

std::map<std::string, int> Room::get_bedType(){
    return bed_type;
}

float Room::get_cost(){
    return cost;
}

void Room::set_roomNum(int n){
    room_number = n;
}

void Room::set_roomType(std::string t){
    room_type = t;
}

void Room::set_bedType(std::map<std::string, int> b){
    bed_type = b;
}

void Room::set_cost(float c){
    cost = c;
}
