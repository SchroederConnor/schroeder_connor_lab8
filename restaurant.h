#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "menuItem.h"


class Restaurant{
    string name;
    int numItem;
    int maxItem;
    MenuItem* items;

    public:
        //3 constructors
        Restaurant();
        Restaurant(string, int, int, MenuItem*);
        Restaurant(const Restaurant&);

        //getters and setters
        string getName();
        int getNumItem();
        int getMaxItem();
        MenuItem* getItems();
        void setName(string);

        //adder
        void addItem(MenuItem);
        
        void operator + (const MenuItem&);
        //assignment(=) operator overload
        Restaurant& operator = (const Restaurant&);
        //insertion (<<) operator overload
        friend ostream& operator<<(ostream&, const Restaurant&);
        //Destructor
        ~Restaurant();

};

#endif