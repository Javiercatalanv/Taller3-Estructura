#include "Product.h"
using namespace std;

Product :: Product(int _id, int _sourceAccount, int _destinationAccount, int _amount, string _date, string _hour){
    this -> id = _id;
    this -> sourceAccount = _sourceAccount;
    this -> destinationAccount = _destinationAccount;
    this -> amount = _amount;
    this -> date = _date;
    this -> hour = _hour;
}

int Product :: getId(){
    return id;
}
int Product :: getAmount(){
    return amount;
}
int Product :: getSourceAccount(){
    return sourceAccount;
}
int Product :: getDestinationAccount(){
    return destinationAccount;
}
string Product :: getDate(){
    return date;
}
string Product :: getHour(){
    return hour;
}

int Product :: setId(int _id){
    id = _id;
}
int Product :: setAmount(int _amount){
    amount = _amount;
}
int Product :: setSourceAccount(int _sourceAccount){
    sourceAccount = _sourceAccount;
}
int Product :: setDestinationAccount(int _destinationAccount){
    destinationAccount = _destinationAccount;
}
string Product :: setDate(string _date){
    date = _date;
}
string Product :: setHour(string _hour){
    hour = _hour;
}