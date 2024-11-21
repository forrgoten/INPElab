#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Tour
{
    string country;
    double price;
    int sales[6]; // Static array for sales

    Tour(const string &countryName, double tourPrice, const int salesArray[6]) {
        country = countryName;
        price = tourPrice;
        for (int i = 0; i < 6; i++)
        {
            sales[i] = salesArray[i];
        }
    }
};

int main()
{
    ifstream inputFile("tours.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    ofstream binaryFile("tours.dat", ios::binary);
    if (!binaryFile.is_open())
    {
        cerr << "Error opening binary file for writing!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        string countryName;
        double tourPrice;
        int salesArray[6];

        // Read country name, price, and sales from the line
        getline(iss, countryName, ','); // Read country name
        iss >> tourPrice; // Read price
        iss.ignore(); // Ignore the comma
        for (int i = 0; i < 6; i++)
        {
            iss >> salesArray[i];
            if (i < 5)
            {
                iss.ignore(); // Ignore the comma after each sales number
            }
        }

        // Create a Tour object and write it to the binary file
        Tour tour(countryName, tourPrice, salesArray);
        size_t countryLength = tour.country.size();
        binaryFile.write(reinterpret_cast<char *>(&countryLength), sizeof(countryLength)); // Write length
        binaryFile.write(tour.country.c_str(), countryLength); // Write country name
        binaryFile.write(reinterpret_cast<const char *>(&tour.price), sizeof(tour.price)); // Write price
        binaryFile.write(reinterpret_cast<const char *>(tour.sales), sizeof(tour.sales)); // Write sales array
    }

    inputFile.close();
    binaryFile.close();
    return 0;
}