#pragma once
#include <string>
using namespace std;

class Product{
private:
    int id,amount,sourceAccount,destinationAccount;
    string date,hour;
public:
    Product(int _id, int _sourceAccount, int _destinationAccount, int _amount, string _date, string _hour);
    int getId();
    int setId(int _id);
    int getAmount();
    int setAmount(int _amount);
    int getSourceAccount();
    int setSourceAccount(int _sourceAccount);
    int getDestinationAccount();
    int setDestinationAccount(int _destinationAccount);
    string getDate();
    string setDate(string _date);
    string getHour();
    string setHour(string _hour);
};