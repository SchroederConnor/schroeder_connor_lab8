#ifndef ORDERBOX_H
#define ORDERBOX_H
#include <string>
using namespace std;

template <typename T>
class OrderBox
{
    string type;
    int num;
    T orders[20];
    public:
        OrderBox();
        OrderBox(string, int, T*);
        OrderBox(const OrderBox<T>&);

        string getType();
        int getNum();
        T* getOrders();

        void setType(string);

        void addOrder(T);

        OrderBox<T>& operator=(const OrderBox<T>&); 
        friend ostream& operator<<(ostream& out, const OrderBox<T>& other)
        {
            cout << "===================\n" << other.type << "\n===================\n";
            for(int i = 0; i < other.num; i++)
            {
                cout << i + 1 << ". " << other.orders[i] << endl;
            }
            return out;
        }
};
#include "orderBox.cpp"
#endif