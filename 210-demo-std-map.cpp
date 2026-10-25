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


    // Delete a villager from the map
    villagers.erase("Raymond");


    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);

    if (it != villagers.end()) {
        cout << "\nFound " << searchKey << ": "
             << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << endl;
    }
    else {
        cout << endl << searchKey << " not found." << endl;
    }


    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}
