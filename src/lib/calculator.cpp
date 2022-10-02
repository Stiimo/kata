#include "calculator.h"

int Calculator::add(const std::string &numbers)
{
    auto pos = numbers.find(',');
    if (pos == std::string::npos) {
        return getInt(numbers);
    }
    return getInt(numbers.substr(0, pos)) + getInt(numbers.substr(pos + 1));
}

int Calculator::getInt(const std::string &number)
{
    if (number.empty()) {
        return 0;
    }
    try {
        std::size_t processed = 0;
        int result = std::stoi(number, &processed, 10);
        if (processed != number.size()) {
            throw CalculationError("number contains non-digit characters");
        }
        return result;
    } catch (const std::invalid_argument &e) {
        throw CalculationError(e.what());
    } catch (const std::out_of_range &e) {
        throw CalculationError(e.what());
    }
}
