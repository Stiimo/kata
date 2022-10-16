#pragma once
#include <stdexcept>

class CalculationError : public std::invalid_argument
{
public:
    CalculationError(const std::string &whatArg)
        : std::invalid_argument(whatArg)
    {}

    CalculationError(const char *whatArg)
        : std::invalid_argument(whatArg)
    {}

    ~CalculationError() noexcept override = default;

    CalculationError(const CalculationError &other) = default;
    CalculationError &operator=(const CalculationError &other) = default;
    CalculationError(CalculationError &&other) noexcept = default;
    CalculationError &operator=(CalculationError &&other) noexcept = default;
};
