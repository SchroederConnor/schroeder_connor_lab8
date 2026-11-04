#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "menuItem.h"
#include "orderBox.h"

class Customer
{
    string name, ID;
    int partySize;
    OrderBox<MenuItem> menuItems;
    OrderBox<string> notes;
    double bill;

    public:
        //constructors
        Customer();
        Customer(string, string, int, OrderBox<MenuItem>, OrderBox<string>);
        Customer(const Customer&);

        //destructor
        ~Customer();

        //getters
        string getName();
        string getID();
        int getSize();
        OrderBox<MenuItem> getMenuItemOrderbox();
        OrderBox<string> getNoteOrderbox();
        double getBill();

        //setters
        void setName(string);
        void setID(string);
        void setSize(int);
        void addNote(string);
        void addMenuItem(MenuItem);

        void calculateBill();

        //operator overloads
        friend ostream& operator<<(ostream&, const Customer&);
        Customer& operator=(const Customer&);
};
#endif