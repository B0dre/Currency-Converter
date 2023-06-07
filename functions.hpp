/*
Project: CURRENCY-CONVERTER
Code By: Wilson Lora (@wlb.do)
*/
#include <iostream>

// Function declarations
void requestData();
double convertCurrency(double currentPrice, double currencyAmountOne);
double replaceCommasAndConvert(const char* input);

// Global variables
char currencyNameOne[20];
double currentPrice;
char currencyNameTwo[20];
double currencyAmountOne;

// Function to replace commas with periods and convert to double
double replaceCommasAndConvert(const char* input) {
    char modifiedInput[20];
    int i = 0;

    for (; input[i] != '\0'; i++) {
        if (input[i] == ',') {
            modifiedInput[i] = '.';
        }
        else {
            modifiedInput[i] = input[i];
        }
    }
    modifiedInput[i] = '\0';

    double result = 0.0;
    bool decimalFound = false;
    double decimalPlace = 0.1;

    for (i = 0; modifiedInput[i] != '\0'; i++) {
        if (modifiedInput[i] == '.') {
            decimalFound = true;
        }
        else if (modifiedInput[i] >= '0' && modifiedInput[i] <= '9') {
            if (decimalFound) {
                result += (modifiedInput[i] - '0') * decimalPlace;
                decimalPlace *= 0.1;
            }
            else {
                result = result * 10 + (modifiedInput[i] - '0');
            }
        }
    }

    return result;
}

void requestData() {
    std::cout << "\nEnter the name of the base currency to convert from (e.g., USD): ";
    std::cin.getline(currencyNameOne, 20);
    std::cout << "Enter the name of the currency to convert to (e.g., EUR): ";
    std::cin.getline(currencyNameTwo, 20);

    std::cout << "Enter the exchange rate from " << currencyNameOne << " to " << currencyNameTwo << " (e.g., 0.94): ";

    char input[20];
    std::cin.getline(input, 20);
    currentPrice = replaceCommasAndConvert(input);

    std::cout << "Enter the amount of " << currencyNameOne << " (e.g., 100): ";

    std::cin.getline(input, 20);
    currencyAmountOne = replaceCommasAndConvert(input);
}

double convertCurrency(double currentPrice, double currencyAmountOne) {
    double currencyAmountTwo = 0;
    currencyAmountTwo = currencyAmountOne * currentPrice;
    return currencyAmountTwo;
}