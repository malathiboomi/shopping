
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> shoppingList;
    int choice;
    string item;

    do {
        cout << "\n===== SHOPPING LIST =====\n";
        cout << "1. Add an item\n";
        cout << "2. Remove an item\n";
        cout << "3. Search for an item\n";
        cout << "4. Display all items\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to add: ";
                getline(cin >> ws, item);
                shoppingList.push_back(item);
                cout << "Item added successfully!\n";
                break;

            case 2: {
                cout << "Enter item to remove: ";
                getline(cin >> ws, item);

                auto it = find(shoppingList.begin(),
                               shoppingList.end(), item);

                if (it != shoppingList.end()) {
                    shoppingList.erase(it);
                    cout << "Item removed successfully!\n";
                } else {
                    cout << "Item not found!\n";
                }
                break;
            }

            case 3: {
                cout << "Enter item to search: ";
                getline(cin >> ws, item);

                auto it = find(shoppingList.begin(),
                               shoppingList.end(), item);

                if (it != shoppingList.end()) {
                    cout << "Item found in the list!\n";
                } else {
                    cout << "Item not found!\n";
                }
                break;
            }

            case 4:
                if (shoppingList.empty()) {
                    cout << "Shopping list is empty!\n";
                } else {
                    cout << "\nShopping List:\n";
                    for (int i = 0; i < shoppingList.size(); i++) {
                        cout << i + 1 << ". "
                             << shoppingList[i] << "\n";
                    }
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
