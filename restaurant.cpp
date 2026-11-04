#include "restaurant.h"

//implement all 3 constructors
Restaurant::Restaurant()
{
    name = "N/A";
    numItem = 0;
    maxItem = 5;
    items = new MenuItem[maxItem];
}
Restaurant::Restaurant(string n, int num, int max, MenuItem* arr)
{
    name = n;
    numItem = num;
    maxItem = max;
    items = new MenuItem[maxItem];
    for(int i = 0; i < maxItem; i++)
    {
        items[i] = arr[i];
    }
}
Restaurant::Restaurant(const Restaurant& rh)
{
    name = rh.name;
    numItem = rh.numItem;
    maxItem = rh.maxItem;
    items = new MenuItem[maxItem];
    for(int i = 0; i < maxItem; i++)
    {
        items[i] = rh.items[i];
    }
}

//implement all the getters/setters
string Restaurant::getName() {return name;}
int Restaurant::getNumItem() {return numItem;}
int Restaurant::getMaxItem() {return maxItem;}
MenuItem* Restaurant::getItems() {return items;}
void Restaurant::setName(string n) {name = n;}

//implement addItem method
void Restaurant::addItem(MenuItem mI){

    //add MenuItem at the end of your list and resize if it's necessary. 
    //Follow the resize rules from the lab document
    if(items[maxItem - 1].getName() != "N/A")
    {
        maxItem += 5;
        MenuItem *temp = new MenuItem[maxItem];
        for(int i = 0; i < numItem; i++)
        {
            temp[i] = items[i];
        }
        delete [] items;
        items = temp;
    }
    items[numItem] = mI;
    numItem++;
}

//Do not modify this
void Restaurant::operator+(const MenuItem& rhs){
    addItem(rhs);
}

//implement assignment operator overload
Restaurant& Restaurant::operator=(const Restaurant& rh)
{
    delete [] items;
    name = rh.name;
    numItem = rh.numItem;
    maxItem = rh.maxItem;
    items = new MenuItem[maxItem];
    for(int i = 0; i < maxItem; i++)
    {
        items[i] = rh.items[i];
    }
    return *this;
}

//implement << operator overload
ostream& operator<<(ostream& os, const Restaurant& rh)
{
    cout << "Welcome to " << rh.name << endl;
    cout << "===================" << endl;
    cout << "Max Slot: " << rh.maxItem << endl;
    cout << "Menu" << endl << "===================" << endl;
    for(int i = 0; i < rh.numItem; i++)
    {
        cout << i + 1 << ". " << rh.items[i];
    }
    return os;
}

//implement destructor
Restaurant::~Restaurant()
{
    delete [] items;
}