#include "orderBox.h"

template <typename T>
OrderBox<T>::OrderBox()
{
    type = "N/A";
    num = 0;
    
}
template <typename T>
OrderBox<T>::OrderBox(string n, int x, T* t)
{
    type = t;
    num = x;
    for(int i = 0; i < 20; i++)
    {
        orders[i] = t.orders[i];
    }
}
template <typename T>
OrderBox<T>::OrderBox(const OrderBox<T>& rh)
{
    type = rh.type;
    num = rh.num;
    for(int i = 0; i < 20; i++)
    {
        orders[i] = rh.orders[i];
    }
}

template <typename T>
string OrderBox<T>::getType() {return type;}
template <typename T>
int OrderBox<T>::getNum() {return num;}
template <typename T>
T* OrderBox<T>::getOrders() {return orders;}

template <typename T>
void OrderBox<T>::setType(string t) {type = t;}

template <typename T>
void OrderBox<T>::addOrder(T t)
{
    if(int num < 20)
    {
        orders[num] = t;
        num++;
    }
    else
    {
        cout << "ERROR: orders full" << endl;
    }
}

template <typename T>
OrderBox<T>& OrderBox<T>::operator=(const OrderBox<T>& rh)
{
    type = rh.type;
    num = rh.num;
    for(int i = 0; i < 20; i++)
    {
        orders[i] = rh.orders[i];
    }
    return *this;
}