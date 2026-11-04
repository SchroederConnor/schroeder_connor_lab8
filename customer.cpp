#include "customer.h"

//constructors
Customer::Customer()
{
    name = "N/A";
    ID = "N/A";
    partySize = 0;
    calculateBill();
}
Customer::Customer(string n, string i, int s, OrderBox<MenuItem> mI, OrderBox<string> no)
{
    name = n;
    ID = i;
    partySize = s;
    menuItems = mI;
    notes = no;
    calculateBill();
}
Customer::Customer(const Customer& rh)
{
    name = rh.name;
    ID = rh.ID;
    partySize = rh.partySize;
    menuItems = rh.menuItems;
    notes = rh.notes;
    calculateBill();
}

//destructor
Customer::~Customer(){}

//getters
string Customer::getName() {return name;}
string Customer::getID() {return ID;}
int Customer::getSize() {return partySize;}
OrderBox<MenuItem> Customer::getMenuItemOrderbox() {return menuItems;}
OrderBox<string> Customer::getNoteOrderbox() {return notes;}
double Customer::getBill() {return bill;}

//setters
void Customer::setName(string n) {name = n;}
void Customer::setID(string i) {ID = i;}
void Customer::setSize(int i) {partySize = i;}
void Customer::addNote(string n) {notes.addOrder(n);}
void Customer::addMenuItem(MenuItem mi) {menuItems.addOrder(mi); calculateBill();}

void Customer::calculateBill()
{
    bill = 0;
    int lim = menuItems.getNum();
    for(int i = 0; i < lim; i++)
    {
        bill += menuItems.getOrders()[i].getPrice();
    }
}

//overloaded Operators
ostream& operator<<(ostream& os, const Customer& rh)
{
    cout << "Name: " << rh.name << "(ID:" << rh.ID << ") - " << rh.partySize << " People." << endl;
    cout << rh.menuItems << endl;
    cout << rh.notes << endl;
    cout << "Total Bill: $" << rh.bill << endl;
    return os;
}
Customer& Customer::operator=(const Customer& rh)
{
    name = rh.name;
    ID = rh.ID;
    partySize = rh.partySize;
    menuItems = rh.menuItems;
    notes = rh.notes;
    calculateBill();
    return *this;
}