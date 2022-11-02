#pragma once
#include <string>
using namespace std;

class ValidException:public exception{
};

class EventValidator {
    friend ValidException;
public:
    static void validate_date(string date);

    static void validate_time(string time);

    static void validate_month(string month);
};