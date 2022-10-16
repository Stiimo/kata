#include "calculator.h"
#include <algorithm>
#include <vector>

constexpr auto DefaultDelimeters = ",\n";

int Calculator::add(const std::string &numbers)
{
    if (numbers.empty()) {
        return 0;
    }
    std::size_t start = 0;
    std::string delimeters;
    if (getDelimeters(numbers, delimeters)) {
        start = 4;
    }
    int result = 0;
    std::vector<int> negatives;
    for (auto pos = numbers.find_first_of(delimeters, start); pos != std::string::npos;
         start = pos + 1, pos = numbers.find_first_of(delimeters, start)) {
        auto value = getInt(numbers.substr(start, pos - start));
        if (value < 0) {
            negatives.push_back(value);
        } else if (value < 1001) {
            result += value;
        }
    }
    auto value = getInt(numbers.substr(start));
    if (value < 0) {
        negatives.push_back(value);
    } else if (value < 1001) {
        result += value;
    }
    if (negatives.empty()) {
        return result;
    } else {
        auto error = std::to_string(negatives[0]);
        for (size_t i = 1; i < negatives.size(); ++i) {
            error += ", " + std::to_string(negatives[i]);
        }
        throw CalculationError("negatives not allowed: " + error);
    }
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

bool Calculator::getDelimeters(const std::string &string, std::string &delimeters)
{
    if (string.size() < 4 || !string.starts_with("//") || string[3] != '\n') {
        delimeters = DefaultDelimeters;
        return false;
    }
    delimeters = string[2];
    return true;
}
