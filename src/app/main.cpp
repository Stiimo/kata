#include <calculator.h>
#include <iostream>

int main()
{
    std::string input;
    std::getline(std::cin, input);

    try {
        std::cout << Calculator::add(input) << std::endl;
    } catch (const CalculationError &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
