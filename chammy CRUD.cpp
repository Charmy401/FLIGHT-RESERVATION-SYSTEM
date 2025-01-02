#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;


struct Flight {
    int flightID;
    string flightName;
    string origin;
    string destination;
    int availableSeats;
};


void displayFlights(const vector<Flight>& flights) {
    cout << "\n===== Available Flights =====\n";
    for (const auto& flight : flights) {
        cout << "Flight ID: " << flight.flightID << " | "
             << "Flight Name: " << flight.flightName << " | "
             << "Origin: " << flight.origin << " | "
             << "Destination: " << flight.destination << " | "
             << "Available Seats: " << flight.availableSeats << endl;
    }
    cout << "============================\n";
}


void addFlight(vector<Flight>& flights) {
    Flight newFlight;
    cout << "Enter Flight ID: ";
    cin >> newFlight.flightID;
    cin.ignore();  
    cout << "Enter Flight Name: ";
    getline(cin, newFlight.flightName);
    cout << "Enter Origin: ";
    getline(cin, newFlight.origin);
    cout << "Enter Destination: ";
    getline(cin, newFlight.destination);
    cout << "Enter Available Seats: ";
    cin >> newFlight.availableSeats;
    
    flights.push_back(newFlight);
    cout << "Flight added successfully!\n";
}


void updateFlight(vector<Flight>& flights) {
    int flightID;
    cout << "Enter Flight ID to update: ";
    cin >> flightID;
    
    for (auto& flight : flights) {
        if (flight.flightID == flightID) {
            cin.ignore();  
            cout << "Enter new Flight Name: ";
            getline(cin, flight.flightName);
            cout << "Enter new Origin: ";
            getline(cin, flight.origin);
            cout << "Enter new Destination: ";
            getline(cin, flight.destination);
            cout << "Enter new Available Seats: ";
            cin >> flight.availableSeats;
            cout << "Flight details updated successfully!\n";
            return;
        }
    }
    cout << "Flight not found.\n";
}

void deleteFlight(vector<Flight>& flights) {
    int flightID;
    cout << "Enter Flight ID to delete: ";
    cin >> flightID;
    
    for (auto it = flights.begin(); it != flights.end(); ++it) {
        if (it->flightID == flightID) {
            flights.erase(it);
            cout << "Flight deleted successfully.\n";
            return;
        }
    }
    cout << "Flight not found.\n";
}


void bookFlight(vector<Flight>& flights) {
    int flightID, seatsToBook;
    cout << "Enter Flight ID to book: ";
    cin >> flightID;
    
    for (auto& flight : flights) {
        if (flight.flightID == flightID) {
            cout << "Enter number of seats to book: ";
            cin >> seatsToBook;
            
            if (seatsToBook > flight.availableSeats) {
                cout << "Not enough available seats.\n";
            } else {
                flight.availableSeats -= seatsToBook;
                cout << "Booking successful! " << seatsToBook << " seats booked.\n";
            }
            return;
        }
    }
    cout << "Flight not found.\n";

void displayBookedFlights(const vector<Flight>& flights) {
    cout << "\n===== Booked Flights =====\n";
    for (const auto& flight : flights) {
        if (flight.availableSeats < 100) {  
            cout << "Flight ID: " << flight.flightID << " | "
                 << "Flight Name: " << flight.flightName << " | "
                 << "Origin: " << flight.origin << " | "
                 << "Destination: " << flight.destination << " | "
                 << "Available Seats: " << flight.availableSeats << endl;
        }
    }
    cout << "===========================\n";
}

int main() {
    vector<Flight> flights;  // Stores the flight data
    int choice;

    while (true) {
        cout << "\n===== Flight Reservation System =====\n";
        cout << "1. Add Flight\n";
        cout << "2. Update Flight\n";
        cout << "3. Delete Flight\n";
        cout << "4. Display All Flights\n";
        cout << "5. Book Flight\n";
        cout << "6. Display Booked Flights\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFlight(flights);
                break;
            case 2:
                updateFlight(flights);
                break;
            case 3:
                deleteFlight(flights);
                break;
            case 4:
                displayFlights(flights);
                break;
            case 5:
                bookFlight(flights);
                break;
            case 6:
                displayBookedFlights(flights);
                break;
            case 7:
                cout << "Exiting the system...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
