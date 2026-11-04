#include "restaurant.h"
#include "orderBox.h"
#include "customer.h"
#include <fstream>

int main()
{
    Restaurant restaurant;
    restaurant.setName("Hello World");

    // Create an input file stream and open "menuItems.txt".
    // Read one menu item at a time from the file.
    // For each menu item:
    //   - Read the item name and price.
    //   - Create a MenuItem object.
    //   - Add the MenuItem to the restaurant using the addItem() method.
    // Continue reading until the end of the file, then close the file.

    ifstream fin("menuItems.txt");
    //write your implementation here
    if(fin.is_open())
    {
        string name, price;
        while(fin)
        {
            getline(fin, name, ':');
            getline(fin, price, '$');    //destroy
            getline(fin, price);
            MenuItem mi(name, stod(price));
            restaurant.addItem(mi);

            if(fin.eof()) break;
        }
        fin.close();
    }

    // Display the restaurant using the overloaded insertion (<<) operator.
    cout << restaurant;

    OrderBox<MenuItem> order;
    //use the setter method for order to set type as "Order"
    order.setType("Order");
    int select;

    // Prompt the user to select menu items.
    // The user should enter the menu item number shown in the menu.
    // Continue accepting menu selections until the user enters 0.
    // For each valid selection, add the corresponding MenuItem to the
    // OrderBox<MenuItem> object using the addOrder() method.

    cout << "Choose your order" << endl;
    cout << "Press 0 to stop" << endl;
    //write your implementation here
    cin >> select;
    while(select != 0)
    {
        if(select > restaurant.getNumItem())
        {
            cout << "ERROR: selection out of menu bounds" << endl;
            cin >> select;
        }
        else
        {
            order.addOrder(restaurant.getItems()[select - 1]);
            cin >> select;
        }
    }

    OrderBox<string> note;
    //use the setter method for note to set type as "Note"
    note.setType("Note");
    string notes[5];

    // Create another input file stream fin2 and open "notes.txt".
    // Read each line from the file and store it in the notes array.
    // Keep track of the total number of notes read using an index variable.
    // Continue until the end of the file, then close the file.

    ifstream fin2("notes.txt");
    //write your implementation here
    int total = 0;
    if(fin2.is_open())
    {
        string n;
        while(fin2)
        {
            getline(fin2, n);
            notes[total] = n;
            total++;
            if(fin2.eof()) break;
        }
        fin2.close();
    }

    // Display all available kitchen notes saved in notes array.
    // Number each note beginning with 1.
    for(int i = 0; i < total; i++)
    {
        cout << i + 1 << ": " << notes[i] << endl;
    }
    
    // Prompt the user to select one or more kitchen notes.
    // Continue accepting selections until the user enters 0.
    // For each valid selection, add the chosen note to the
    // OrderBox<string> object using the addOrder() method.

    cout << "Select specific notes" << endl;
    cout << "Press 0 to stop" << endl;

    //write your implementation here
    cin >> select;
    while(select != 0)
    {
        if(select > total)
        {
            cout << "ERROR: selection out of menu bounds" << endl;
            cin >> select;
        }
        else
        {
            note.addOrder(notes[select - 1]);
            cin >> select;
        }
    }

    // Create a Customer object using the following information:
    //   Name: Annie
    //   ID: An4
    //   Party Size: 4
    //   Menu Items: order
    //   Notes: note
    Customer cust("Annie", "An4", 4, order, note);
    
    // Add a new kitchen note ("No Ranch") to Annie's order
    // by calling the addNote() method in Customer class.
    cust.addNote("No Ranch");
    
    MenuItem m("Wings",10.5);
    // Add this new menu item m to Annie's order
    // by calling the addMenuItem() method in Customer class.
    cust.addMenuItem(m);

    // Display the customer's information using the overloaded insertion (<<) operator.
    cout << cust;

    // Your output must match Output.txt exactly.
    // Pay close attention to spelling, capitalization, spaces, punctuation, end lines
    // and blank lines.

    return 0;
}