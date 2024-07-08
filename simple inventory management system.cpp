#include <iostream>
#include <string>
using namespace std;

// Define a class for Inventory Item
class InventoryItem {
public:
    string name;
    int id;
    int quantity;

    // Constructor
    InventoryItem(string n, int i, int q) : name(n), id(i), quantity(q) {}

    // Function to display item details
    void displayItem() const {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

// Define a class for Inventory Management
class InventoryManagement {
private:
    static const int MAX_ITEMS = 100; // Maximum number of items in the inventory
    InventoryItem* items[MAX_ITEMS]; // Array of pointers to InventoryItem objects
    int itemCount; // Current number of items in the inventory

public:
    // Constructor
    InventoryManagement() : itemCount(0) {}

    // Destructor
    ~InventoryManagement() {
        for (int i = 0; i < itemCount; ++i) {
            delete items[i]; // Deallocate memory for each item
        }
    }

    // Function to add an item to the inventory
    void addItem(const string& name, int id, int quantity) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount] = new InventoryItem(name, id, quantity);
            itemCount++;
            cout << "Item added successfully." << endl;
        } else {
            cout << "Cannot add more items. Inventory full." << endl;
        }
    }

    // Function to display all items in the inventory
    void displayInventory() const {
        cout << "Inventory List:" << endl;
        for (int i = 0; i < itemCount; ++i) {
            items[i]->displayItem();
        }
    }

    // Function to search for an item by name
    void searchByName(const string& name) const {
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (items[i]->name == name) {
                items[i]->displayItem();
                found = true;
            }
        }
        if (!found) {
            cout << "Item with name \"" << name << "\" not found." << endl;
        }
    }

    // Function to search for an item by ID
    void searchById(int id) const {
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (items[i]->id == id) {
                items[i]->displayItem();
                found = true;
            }
        }
        if (!found) {
            cout << "Item with ID " << id << " not found." << endl;
        }
    }
};

int main() {
    InventoryManagement inventory;

    // Menu-driven interface
    int choice;
    do {
        cout << "\nInventory Management System Menu:\n";
        cout << "1. Add Item\n";
        cout << "2. Display Inventory\n";
        cout << "3. Search by Name\n";
        cout << "4. Search by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int id, quantity;
                cout << "Enter item name: ";
                cin.ignore(); // Ignore newline character in buffer
                getline(cin, name);
                cout << "Enter item ID: ";
                cin >> id;
                cout << "Enter item quantity: ";
                cin >> quantity;
                inventory.addItem(name, id, quantity);
                break;
            }
            case 2:
                inventory.displayInventory();
                break;
            case 3: {
                string name;
                cout << "Enter item name to search: ";
                cin.ignore(); // Ignore newline character in buffer
                getline(cin, name);
                inventory.searchByName(name);
                break;
            }
            case 4: {
                int id;
                cout << "Enter item ID to search: ";
                cin >> id;
                inventory.searchById(id);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}

