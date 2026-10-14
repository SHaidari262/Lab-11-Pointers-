
#include <iostream>
#include <string>
using namespace std;

// This struct stores information about one pet.
// Each pet can have a different number of grooming services.
struct Pet {
    string name;
    string owner;
    int age;

    // Dynamic array to store grooming services
    string* services;
    int serviceCount;
};

int main() {
    int petCount;

    cout << "PET GROOMING APPOINTMENT MANAGER\n";
    cout << "How many pets have appointments? ";
    cin >> petCount;

    // Make sure the number of pets is valid
    if (petCount <= 0) {
        cout << "Please enter a positive number.\n";
        return 1;
    }

    // Create a dynamic array of Pet structs
    Pet* pets = new Pet[petCount];

    // Collect information about each pet
    for (int i = 0; i < petCount; i++) {
        cout << "\nEnter information for pet "
             << i + 1 << endl;

        cout << "Pet name: ";
        cin >> pets[i].name;

        cout << "Owner name: ";
        cin >> pets[i].owner;

        cout << "Pet age: ";
        cin >> pets[i].age;

        cout << "Number of grooming services: ";
        cin >> pets[i].serviceCount;

        // Make sure the service count is not negative
        while (pets[i].serviceCount < 0) {
            cout << "Enter 0 or more services: ";
            cin >> pets[i].serviceCount;
        }

        // Each pet gets its own dynamic array
        pets[i].services =
            new string[pets[i].serviceCount];

        // Fill the dynamic array with service names
        for (int j = 0; j < pets[i].serviceCount; j++) {
            cout << "Service " << j + 1 << ": ";
            cin >> pets[i].services[j];
        }
    }

    // Display all appointments
    cout << "\n===== APPOINTMENT SUMMARY =====\n";

    for (int i = 0; i < petCount; i++) {
        cout << "\nPet: " << pets[i].name << endl;
        cout << "Owner: " << pets[i].owner << endl;
        cout << "Age: " << pets[i].age << endl;

        cout << "Grooming services: ";

        if (pets[i].serviceCount == 0) {
            cout << "None";
        } else {
            for (int j = 0; j < pets[i].serviceCount; j++) {
                cout << pets[i].services[j];

                if (j < pets[i].serviceCount - 1) {
                    cout << ", ";
                }
            }
        }

        cout << endl;
    }

    // Release each pet's dynamic service array
    for (int i = 0; i < petCount; i++) {
        delete[] pets[i].services;
    }

    // Release the dynamic array of Pet structs
    delete[] pets;

    return 0;
}
