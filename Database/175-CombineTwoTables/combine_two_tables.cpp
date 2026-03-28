// LeetCode 175 - Combine Two Tables
// Approach: LEFT JOIN Simulation using structs + map
// Time: O(n + m) | Space: O(n + m)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <iomanip>
using namespace std;

struct Person {
    int    personId;
    string lastName;
    string firstName;
};

struct Address {
    int    addressId;
    int    personId;
    string city;
    string state;
};

struct Row {
    string firstName;
    string lastName;
    string city;
    string state;
};

vector<Row> combineTwoTables(vector<Person>& persons, vector<Address>& addresses) {
    unordered_map<int, Address> addressMap;
    for (auto& a : addresses) {
        addressMap[a.personId] = a;
    }

    vector<Row> result;
    for (auto& p : persons) {
        if (addressMap.count(p.personId)) {
            result.push_back({p.firstName, p.lastName,
                              addressMap[p.personId].city,
                              addressMap[p.personId].state});
        } else {
            result.push_back({p.firstName, p.lastName, "Null", "Null"});
        }
    }
    return result;
}

int main() {
    vector<Person> persons = {
        {1, "Wang",  "Allen"},
        {2, "Alice", "Bob"}
    };

    vector<Address> addresses = {
        {1, 2, "New York City", "New York"},
        {2, 3, "Leetcode",     "California"}
    };

    auto result = combineTwoTables(persons, addresses);

    cout << left
         << setw(12) << "firstName"
         << setw(12) << "lastName"
         << setw(16) << "city"
         << setw(12) << "state" << "\n";
    cout << string(52, '-') << "\n";

    for (auto& r : result) {
        cout << left
             << setw(12) << r.firstName
             << setw(12) << r.lastName
             << setw(16) << r.city
             << setw(12) << r.state << "\n";
    }

    return 0;
}