// COMSC-210-5293 | Lab 27 | Yuyi Chen

#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

// Prototype
void printVillagers(const map<string, tuple<int, string, string>> &villagers);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // Insert villagers into the map
    // Each villager has a friendship level, species, and catchphrase
    villagers["Audie"] = {5, "Wolf", "Foxtrot"};
    villagers["Raymond"] = {8, "Cat", "Nice fit"};
    villagers["Marshal"] = {6, "Squirrel", "Sulky"};

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

            case 2: {
                string name;

                cout << "Enter villager name: ";
                cin >> name;

                // Search for the villager
                auto it = villagers.find(name);

                if (it != villagers.end()) {
                    // Decrease friendship without going below 0
                    if (get<0>(it->second) > 0) {
                        get<0>(it->second)--;
                        cout << name << "'s friendship decreased to "
                             << get<0>(it->second) << endl;
                    }
                    else {
                        cout << name << "'s friendship is already at 0." << endl;
                    }
                }
                else {
                    cout << "Villager not found." << endl;
                }

                break;
            }

            case 3: {
                string name;

                cout << "Enter villager name: ";
                cin >> name;

                // Search for the villager
                auto it = villagers.find(name);

                if (it != villagers.end()) {
                    // Display the villager's information
                    cout << "\nVillager: " << it->first << endl;
                    cout << "Friendship Level: " << get<0>(it->second) << endl;
                    cout << "Species: " << get<1>(it->second) << endl;
                    cout << "Catchphrase: " << get<2>(it->second) << endl;
                }
                else {
                    cout << "Villager not found." << endl;
                }

                break;
            }

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        // Display the updated villager list after each operation
        if (choice != 4) {
            printVillagers(villagers);
        }

    } while (choice != 4);


    return 0;
}

// printVillagers() prints all villagers and their information
// arguments: const map<string, tuple<int, string, string>> &villagers
//            - the map containing all villager information
// returns: none
void printVillagers(const map<string, tuple<int, string, string>> &villagers) {
    cout << "\nVillager List:" << endl;

    if (villagers.empty()) {
        cout << "No villagers found." << endl;
    }
    else {
        for (auto pair : villagers) {
            cout << pair.first << " ["
                 << get<0>(pair.second) << ", "
                 << get<1>(pair.second) << ", "
                 << get<2>(pair.second) << "]" << endl;
        }
    }
}