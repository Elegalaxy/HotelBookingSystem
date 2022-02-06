#include "Customer.h"
using namespace std;

Customer::Customer(){
    ic = "";
    name = "";
    contact = "";
}

string Customer::get_str(string type){
    if(type == "name")
        return name;
    else if(type == "ic")
        return ic;
    else if(type == "contact")
        return contact;
    
    return "";
}

void Customer::set_str(string type, string data){
    if(type == "name")
        name = data;
    else if(type == "ic")
        ic = data;
    else if(type == "contact")
        contact = data;
    
}