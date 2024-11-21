#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

struct Tour
{
    string country;
    double price;
    int *sales; // Pointer to dynamic array
    int salesCount;
    double average_sales;

    Tour(int count) : salesCount(count)
    {
        sales = new int[salesCount]; // Dynamic memory allocation for array
    }

    ~Tour()
    {
        delete[] sales; // Free allocated memory
    }

    void calculate_average_sales()
    {
        average_sales = accumulate(sales, sales + salesCount, 0) / static_cast<double>(salesCount);
    }
};

bool compare(const Tour *a, const Tour *b)
{
    double total_a = a->price * accumulate(a->sales, a->sales + a->salesCount, 0);
    double total_b = b->price * accumulate(b->sales, b->sales + b->salesCount, 0);
    return total_a > total_b;
}

int main()
{
    ifstream binaryFile("tours.dat", ios::binary);
    ofstream resultFile("result.txt");

    if (!binaryFile.is_open() || !resultFile.is_open())
    {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    vector<Tour *> tours;

    while (true)
    {
        Tour *tour = new Tour(6); // Create new Tour object with dynamic array
        // Read country name length first
        size_t countryLength;
        binaryFile.read(reinterpret_cast<char *>(&countryLength), sizeof(countryLength));
        if (binaryFile.eof())
        {
            delete tour; // Free memory if end of file is reached
            break;
        }

        // Read country name
        tour->country.resize(countryLength);
        binaryFile.read(&tour->country[0], countryLength);

        binaryFile.read(reinterpret_cast<char *>(&tour->price), sizeof(tour->price));
        binaryFile.read(reinterpret_cast<char *>(tour->sales), sizeof(int) * 6); // Read array
        tour->calculate_average_sales();
        tours.push_back(tour); // Add pointer to vector
    }

    // Sort by descending order
    sort(tours.begin(), tours.end(), compare);

    // Write results to text file
    for (const auto &t : tours)
    {
        resultFile << "Country: " << t->country << ", Price: " << t->price
                   << ", Average Sales: " << t->average_sales << "\n";
    }

    binaryFile.close();
    resultFile.close();

    // Free allocated memory
    for (auto tour : tours)
    {
        delete tour;
    }

    return 0;
}