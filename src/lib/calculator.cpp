#include "calculator.h"

int Calculator::add(const std::string &numbers)
{
    if (numbers.empty()) {
        return 0;
    }
    int result = 0;
    std::size_t start = 0;
    for (auto pos = numbers.find(','); pos != std::string::npos;
         start = pos + 1, pos = numbers.find(',', start)) {
        result += getInt(numbers.substr(start, pos - start));
    }
    result += getInt(numbers.substr(start));
    return result;
}

int Calculator::getInt(const std::string &number)
{
    if (number.empty()) {
        throw CalculationError("no number between subsequent commas");
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
