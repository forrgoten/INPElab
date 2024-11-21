#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct Tour {
    std::string country;
    double price;
    int sales[6]; // Static array for sales

    Tour(const std::string& countryName, double tourPrice, const int salesArray[6]) {
        country = countryName;
        price = tourPrice;
        for (int i = 0; i < 6; i++) {
            sales[i] = salesArray[i];
        }
    }
};

int main() {
    std::ifstream inputFile("tours.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }

    std::ofstream binaryFile("tours.dat", std::ios::binary);
    if (!binaryFile.is_open()) {
        std::cerr << "Error opening binary file for writing!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string countryName;
        double tourPrice;
        int salesArray[6];

        // Read country name, price, and sales from the line
        std::getline(iss, countryName, ','); // Read country name
        iss >> tourPrice; // Read price
        iss.ignore(); // Ignore the comma
        for (int i = 0; i < 6; i++) {
            iss >> salesArray[i];
            if (i < 5) {
                iss.ignore(); // Ignore the comma after each sales number
            }
        }

        // Create a Tour object and write it to the binary file
        Tour tour(countryName, tourPrice, salesArray);
        size_t countryLength = tour.country.size();
        binaryFile.write(reinterpret_cast<char*>(&countryLength), sizeof(countryLength)); // Write length
        binaryFile.write(tour.country.c_str(), countryLength); // Write country name
        binaryFile.write(reinterpret_cast<const char*>(&tour.price), sizeof(tour.price)); // Write price
        binaryFile.write(reinterpret_cast<const char*>(tour.sales), sizeof(tour.sales)); // Write sales array
    }

    inputFile.close();
    binaryFile.close();
    return 0;
}