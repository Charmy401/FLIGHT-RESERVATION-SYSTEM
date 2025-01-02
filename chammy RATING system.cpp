#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class FlightRatingSystem {
private:
    struct Rating {
        std::string customerName;
        int rating; // Rating on a scale of 1 to 5
    };
    
    std::vector<Rating> ratingList;

public:
    // Method for a customer to provide a rating
    void submitRating() {
        std::string name;
        int rating;

        std::cout << "Enter your name: ";
        std::cin.ignore();  // Clear the input buffer
        std::getline(std::cin, name);
        
        // Ensuring the rating is between 1 and 5
        do {
            std::cout << "Enter your rating (1-5): ";
            std::cin >> rating;
        } while (rating < 1 || rating > 5);
        
        Rating newRating = {name, rating};
        ratingList.push_back(newRating);
        
        std::cout << "Thank you for your rating!\n" << std::endl;
    }

    // Method to view all ratings
    void viewRatings() {
        if (ratingList.empty()) {
            std::cout << "No ratings have been submitted yet.\n" << std::endl;
        } else {
            std::cout << "\nAll Customer Ratings:\n";
            std::cout << "--------------------------------------\n";
            for (const auto& rating : ratingList) {
                std::cout << "Customer: " << rating.customerName << "\n";
                std::cout << "Rating: " << rating.rating << " stars\n";
                std::cout << "--------------------------------------\n";
            }
        }
    }

    // Method to calculate and display the average rating
    void displayAverageRating() {
        if (ratingList.empty()) {
            std::cout << "No ratings available to calculate average.\n" << std::endl;
            return;
        }

        int sum = 0;
        for (const auto& rating : ratingList) {
            sum += rating.rating;
        }

        double average = static_cast<double>(sum) / ratingList.size();
        std::cout << "Average Customer Rating: " << average << " stars\n" << std::endl;
    }

    // Method to save ratings to a file
    void saveRatingsToFile() {
        std::ofstream outFile("flight_ratings.txt", std::ios::app);

        if (!outFile) {
            std::cout << "Error opening file to save ratings.\n" << std::endl;
            return;
        }

        for (const auto& rating : ratingList) {
            outFile << "Customer: " << rating.customerName << "\n";
            outFile << "Rating: " << rating.rating << " stars\n";
            outFile << "--------------------------------------\n";
        }

        std::cout << "Ratings have been saved!\n" << std::endl;
    }

    // Method to load ratings from a file
    void loadRatingsFromFile() {
        std::ifstream inFile("flight_ratings.txt");

        if (!inFile) {
            std::cout << "No previous ratings found.\n" << std::endl;
            return;
        }

        std::string name;
        int rating;
        while (std::getline(inFile, name)) {
            inFile >> rating;
            inFile.ignore();  // Ignore the newline character after the rating
            inFile.ignore();  // Ignore the "--------------------------------------" line
            
            Rating newRating = {name.substr(10), rating};  // Remove "Customer: " from the name
            ratingList.push_back(newRating);
        }

        std::cout << "Ratings loaded from file.\n" << std::endl;
    }
};

int main() {
    FlightRatingSystem system;
    int choice;

    // Load previous ratings from the file
    system.loadRatingsFromFile();

    while (true) {
        std::cout << "Flight Reservation System\n";
        std::cout << "1. Submit Rating\n";
        std::cout << "2. View All Ratings\n";
        std::cout << "3. Display Average Rating\n";
        std::cout << "4. Save Ratings to File\n";
        std::cout << "5. Exit\n";
        std::cout << "Please select an option (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system.submitRating();
                break;
            case 2:
                system.viewRatings();
                break;
            case 3:
                system.displayAverageRating();
                break;
            case 4:
                system.saveRatingsToFile();
                break;
            case 5:
                std::cout << "Exiting the rating system. Thank you!\n";
                return 0;
            default:
                std::cout << "Invalid option, please try again.\n";
                break;
        }
    }
}
