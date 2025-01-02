#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  

using namespace std;


struct Flight {
    int flightNumber;
    string destination;
    string departureTime;
    float price;
    bool isAvailable;
};


struct Booking {
    string passengerName;
    int flightNumber;
};

void displayFlights(const vector<Flight>& flights) {
    cout << "------ Available Flights ------\n";
    for (const auto& flight : flights) {
        if (flight.isAvailable) {
            cout << "Flight No: " << flight.flightNumber << ", Destination: " << flight.destination
                 << ", Departure Time: " << flight.departureTime << ", Price: $" << fixed << setprecision(2) << flight.price << endl;
        }
    }

void bookFlight(vector<Flight>& flights, vector<Booking>& bookings) {
    int flightNumber;
    string name;

    cout << "Enter your name: ";
    cin.ignore();  
    getline(cin, name);

    cout << "Enter the flight number you want to book: ";
    cin >> flightNumber;

    bool found = false;
    for (auto& flight : flights) {
        if (flight.flightNumber == flightNumber && flight.isAvailable) {
            found = true;
            
            flight.isAvailable = false;  
            bookings.push_back({name, flightNumber});
            cout << "Flight booked successfully for " << name << ".\n";
            break;
        }
    }

    if (!found) {
        cout << "Flight not available or incorrect flight number.\n";
    }
}


void cancelBooking(vector<Flight>& flights, vector<Booking>& bookings) {
    int flightNumber;
    string name;
    bool found = false;

    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter the flight number you want to cancel: ";
    cin >> flightNumber;

    for (auto it = bookings.begin(); it != bookings.end(); ++it) {
        if (it->passengerName == name && it->flightNumber == flightNumber) {
            
            bookings.erase(it);
            
            for (auto& flight : flights) {
                if (flight.flightNumber == flightNumber) {
                    flight.isAvailable = true;
                    cout << "Booking canceled successfully.\n";
                    found = true;
                    break;
                }
            }
            break;
        }
    }

    if (!found) {
        cout << "No booking found with the given details.\n";
    }
}


void viewBookings(const vector<Booking>& bookings) {
    if (bookings.empty()) {
        cout << "No bookings found.\n";
        return;
    }

    cout << "------ Your Bookings ------\n";
    for (const auto& booking : bookings) {
        cout << "Passenger: " << booking.passengerName << ", Flight No: " << booking.flightNumber << endl;
    }
}


void generateInvoice(const vector<Flight>& flights, const vector<Booking>& bookings) {
    string name;
    cout << "Enter your name to generate the invoice: ";
    cin.ignore();  
    getline(cin, name);

    float total = 0;
    cout << "------ Invoice ------\n";
    for (const auto& booking : bookings) {
        if (booking.passengerName == name) {
            for (const auto& flight : flights) {
                if (flight.flightNumber == booking.flightNumber) {
                    cout << "Flight No: " << flight.flightNumber << ", Destination: " << flight.destination
                         << ", Price: $" << fixed << setprecision(2) << flight.price << endl;
                    total += flight.price;
                }
            }
        }
    }

    if (total > 0) {
        cout << "Total Amount: $" << fixed << setprecision(2) << total << endl;
    } else {
        cout << "No bookings found for " << name << ".\n";
    }
}

int main() {

    vector<Flight> flights = {
        {101, "New York", "2024-12-30 08:00", 300.50, true},
        {102, "Los Angeles", "2024-12-30 09:30", 250.75, true},
        {103, "Chicago", "2024-12-30 10:00", 200.00, true},
        {104, "Miami", "2024-12-30 11:30", 150.20, true}
    };

    vector<Booking> bookings;  

    int choice;
    do {
        cout << "\n------ Flight Reservation System ------\n";
        cout << "1. View Available Flights\n";
        cout << "2. Book a Flight\n";
        cout << "3. Cancel a Flight\n";
        cout << "4. View My Bookings\n";
        cout << "5. Generate Invoice\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayFlights(flights);
                break;
            case 2:
                bookFlight(flights, bookings);
                break;
            case 3:
                cancelBooking(flights, bookings);
                break;
            case 4:
                viewBookings(bookings);
                break;
            case 5:
                generateInvoice(flights, bookings);
                break;
            case 6:
                cout << "Thank you for using the Flight Reservation System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
