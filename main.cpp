#include "functions.hpp"

int main() {
    requestData();

    std::cout.precision(4);
    std::cout << "\nThe converted amount is: " << convertCurrency(currentPrice, currencyAmountOne) << " " << currencyNameTwo << "\n";

    std::cout << "\nPress ENTER to exit...\n";
    std::getchar();
    return 0;
}