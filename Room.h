#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <map>

class Room{
    private:
        int room_number;
        std::string room_type;
        std::map<std::string, int> bed_type;
        float cost;

    public:
        Room();
        Room(int n, std::string t, float c, std::map<std::string, int> b): room_number{n}, room_type{t}, cost{c}, bed_type{b} {};

        int get_roomNum();
        std::string get_roomType();
        std::map<std::string, int> get_bedType();
        float get_cost();

        void set_roomNum(int n);
        void set_roomType(std::string t);
        void set_bedType(std::map<std::string, int> b);
        void set_cost(float c);
};

#endif