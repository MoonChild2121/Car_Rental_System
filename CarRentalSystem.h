#ifndef CARRENTALSYSTEM_H
#define CARRENTALSYSTEM_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Cars
{
    public:
    string model;
    string name;
    string colour;
    string num;
    string bookmodel;
    string bookname;
    string bookcolour;
    string booknum;
    long int price;
    int num_of_days;
    vector <long int> prices;
    bool days;
    virtual void lessgo() = 0;
    void displayinfo(long int a);
    void calcPrice(long int a, long int b);
    void setPrice();
};

class Admin : public Cars
{
    void displayData();
    void display();
    bool pwd();
    public:
    Admin();
    void lessgo();
};

class User : public Cars
{
    string mobilenum;
    string CNIC;
    string address;
    string my_name;
    void display();
    void displayData();
    public:
    User();
    void lessgo();
};

#endif
