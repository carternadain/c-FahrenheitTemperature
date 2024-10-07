#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// function for converting 
double fahrenheitToCelsius(int fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    // Input file stream for fahrenheit
    ifstream inputFile("FahrenheitTemperature.txt");
    
    // Output file stream for celsius
    ofstream outputFile("CelsiusTemperature.txt");
    
    // Check if the input file opens 
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open FahrenheitTemperature.txt" << endl;
        return 1;  // Exit with error code
    }

    // Check if the output file opens
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open CelsiusTemperature.txt" << endl;
        return 1;  // Exit with error code
    }

    // Variables to store the city name and temperature
    string city;
    int fahrenheitTemp;
    
    // Reads from the input file and write to the output file
    while (inputFile >> city >> fahrenheitTemp) {
        double celsiusTemp = fahrenheitToCelsius(fahrenheitTemp);  // Convert to Celsius
        outputFile << city << " " << celsiusTemp << endl;  // Write to output file
    }

    // Closes the files
    inputFile.close();
    outputFile.close();

    cout << "Conversion complete. Data written to CelsiusTemperature.txt" << endl;
    
    return 0;
}
