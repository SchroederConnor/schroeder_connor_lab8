#include "restaurant.h"
#include "orderbox.h"
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
    fin.close();

    // Display the restaurant using the overloaded insertion (<<) operator.
    

    OrderBox<MenuItem> order;
    //use the setter method for order to set type as "Order"
    int select;

    // Prompt the user to select menu items.
    // The user should enter the menu item number shown in the menu.
    // Continue accepting menu selections until the user enters 0.
    // For each valid selection, add the corresponding MenuItem to the
    // OrderBox<MenuItem> object using the addOrder() method.

    cout << "Choose your order" << endl;
    cout << "Press 0 to stop" << endl;

    //write your implementation here

    OrderBox<string> note;
    //use the setter method for note to set type as "Note"
    string notes[5];

    // Create another input file stream fin2 and open "notes.txt".
    // Read each line from the file and store it in the notes array.
    // Keep track of the total number of notes read using an index variable.
    // Continue until the end of the file, then close the file.

    ifstream fin2("notes.txt");
    //write your implementation here
    fin2.close();

    // Display all available kitchen notes saved in notes array.
    // Number each note beginning with 1.

    


    // Prompt the user to select one or more kitchen notes.
    // Continue accepting selections until the user enters 0.
    // For each valid selection, add the chosen note to the
    // OrderBox<string> object using the addOrder() method.

    cout << "Select specific notes" << endl;
    cout << "Press 0 to stop" << endl;

    //write your implementation here

    // Create a Customer object using the following information:
    //   Name: Annie
    //   ID: An4
    //   Party Size: 4
    //   Menu Items: order
    //   Notes: note

    

    

    // Add a new kitchen note ("No Ranch") to Annie's order
    // by calling the addNote() method in Customer class.

    
    MenuItem m("Wings",10.5);
    // Add this new menu item m to Annie's order
    // by calling the addMenuItem() method in Customer class.

    // Display the customer's information using the overloaded insertion (<<) operator.
    

    // Your output must match Output.txt exactly.
    // Pay close attention to spelling, capitalization, spaces, punctuation, end lines
    // and blank lines.

    return 0;
}