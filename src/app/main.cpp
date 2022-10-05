#include <calculator.h>
#include <iostream>

int main()
{
    std::string input;
    std::getline(std::cin, input);
    for (std::string line; std::getline(std::cin, line);) {
        input += "\n" + line;
    }

    try {
        std::cout << Calculator::add(input) << std::endl;
    } catch (const CalculationError &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
