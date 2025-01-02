#include <iostream>
#include <string>
using namespace std;

bool login() {
    string username, password;
    string correctUsername = "admin";  
    string correctPassword = "password";

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword) {
        return true; 
    } else {
        return false; 
    }
}

void homePage() {
    int choice;

    cout << "\nWelcome to the Flight Reservation System!\n";
    cout << "1. Book a Flight\n";
    cout << "2. View Available Flights\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\nYou can now proceed to book a flight.\n";
            break;
        case 2:
            cout << "\nHere are the available flights:\n";
            break;
        case 3:
            cout << "\nExiting the system. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid choice, please try again.\n";
    }
}

int main() {
    cout << "Flight Reservation System\n";

    while (true) {
        if (login()) {
            cout << "\nLogin successful!\n";
            break;
        } else {
            cout << "\nInvalid credentials. Please try again.\n";
        }
    }

    homePage();

    return 0;
}
