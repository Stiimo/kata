#pragma once
#include <calculationerror.h>
#include <string>

class Calculator
{
public:
    static int add(const std::string &numbers);

private:
    static int getInt(const std::string &number);
    static bool getDelimeters(const std::string &string, std::string &delimeters);
};
