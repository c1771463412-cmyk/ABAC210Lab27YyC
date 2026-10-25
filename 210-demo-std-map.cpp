// COMSC-210-5293 | Lab 27 | Yuyi Chen

#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;


    // Insert villagers into the map
    // Each villager has a friendship level, species, and catchphrase
    villagers["Audie"] = {5, "Wolf", "Foxtrot"};
    villagers["Raymond"] = {8, "Cat", "Nice fit"};
    villagers["Marshal"] = {6, "Squirrel", "Sulky"};


    // Access the map using a range-based for loop
    cout << "Villager details (for loop):" << endl;

    for (auto pair : villagers) {
        cout << pair.first << " ["
             << get<0>(pair.second) << ", "
             << get<1>(pair.second) << ", "
             << get<2>(pair.second) << "]" << endl;
    }


    // Access the map using iterators
    cout << "\nVillager details (iterators):" << endl;

    for (map<string, tuple<int, string, string>>::iterator it = villagers.begin(); 
    it != villagers.end(); ++it) {

        cout << it->first << " ["
             << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << "]" << endl;
    }


    //-----------------------------------------------------
    // Display the menu and let the user choose an option
    int choice;

    do {
        cout << "\nVillager Menu" << endl;
        cout << "1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search for Villager" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;

                cout << "Enter villager name: ";
                cin >> name;

                // Search for the villager
                auto it = villagers.find(name);

                if (it != villagers.end()) {
                    // Increase friendship without going above 10
                    if (get<0>(it->second) < 10) {
                        get<0>(it->second)++;
                        cout << name << "'s friendship increased to "
                             << get<0>(it->second) << endl;
                    }
                    else {
                        cout << name << "'s friendship is already at 10." << endl;
                    }
                }
                else {
                    cout << "Villager not found." << endl;
                }

                break;
            }

            case 2:
                cout << "Decrease Friendship selected." << endl;
                break;

            case 3:
                cout << "Search for Villager selected." << endl;
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);


    return 0;
}
