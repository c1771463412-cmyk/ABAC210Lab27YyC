// COMSC-210-5293 | Lab 27 | Yuyi Chen

#include <iostream>
#include <map>
#include <tuple>
#include <string>
#include <limits>
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
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Check for invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        // Check for extra characters after the number
        if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            // Add villager
            case 1: {
                string name;
                int friendship;
                string species;
                string catchphrase;

                // Get the new villager's information
                cout << "Enter villager name: ";
                cin >> name;

                // Check if the villager already exists
                auto it = villagers.find(name);

                if (it != villagers.end()) {
                    cout << "Villager already exists." << endl;
                    break;
                }

                cout << "Enter friendship level (0-10): ";
                cin >> friendship;

                // Check if friendship level is a valid number
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid friendship level." << endl;
                    break;
                }

                // Check for extra characters after the number
                if (cin.peek() != '\n') {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid friendship level." << endl;
                    break;
                }

                // Check if friendship level is between 0 and 10
                if (friendship < 0 || friendship > 10) {
                    cout << "Invalid friendship level." << endl;
                    break;
                }

                cout << "Enter species: ";
                cin >> species;

                cout << "Enter catchphrase: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, catchphrase);

                // Add the new villager to the map
                villagers[name] = {friendship, species, catchphrase};
                cout << name << " added successfully." << endl;

                break;
            }

            // Delete villager
            case 2: {
                string name;

                cout << "Enter villager name: ";
                cin >> name;

                // Search for the villager
                auto it = villagers.find(name);

                if (it != villagers.end()) {
                    // Delete the villager from the map
                    villagers.erase(name);
                    cout << name << " deleted successfully." << endl;
                }
                else {
                    cout << "Villager not found." << endl;
                }

                break;
            }

            // Increase Friendship
            case 3: {
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

            // Decrease Friendship
            case 4: {
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

            // Search for Villager
            case 5: {
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

            // Exit
            case 6:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        // Display the updated villager list after each operation
        if (choice != 6) {
            printVillagers(villagers);
        }

    } while (choice != 6);

    return 0;
}

// printVillagers() displays all villagers and their information
// arguments: reference to a map containing villager information
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