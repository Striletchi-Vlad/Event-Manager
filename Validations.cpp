#include <string>
#include "Validations.h"
using namespace std;

    void EventValidator::validate_date(string date) {
        // has to be dd/mm/yyyy
        //just a basic check for max 31 days, max 12 months, does not take into account for ex that february only has 28 sometimes
        if (date.size() != 10) //correct length
            throw ValidException();
        if (date[2] != '/' || date[5] != '/') //correct format
            throw ValidException();
        //sequence is numeric
        if ((date[0] < '0' || date[0]>'9') || (date[1] < '0' || date[1]>'9') || (date[3] < '0' || date[3]>'9') || (date[4] < '0' || date[4]>'9') || (date[6] < '0' || date[6]>'9') || (date[7] < '0' || date[7]>'9') || (date[8] < '0' || date[8]>'9') || (date[9] < '0' || date[9]>'9'))
            throw ValidException();
        string day = date.substr(0, 2);
        string month = date.substr(3, 2);
        if (stoi(day) > 31)
            throw ValidException();
        if (stoi(month) > 12)
            throw ValidException();
    }

    void EventValidator::validate_month(string month) {
        //has to be mm
        if (month.size() != 2)
            throw ValidException();
        if (month[0] != '0' && month[0] != '1')
            throw ValidException();
        if (month[1] < '0' || month[1]>'9')
            throw ValidException();
        if (month[0] == '1' && month[1] > '2')
            throw ValidException();
    }

    void EventValidator::validate_time(string time) {
        //has to be hh:mm
        if (time.size() != 5)
            throw ValidException();
        if (time[2] != ':')
            throw ValidException();
        if ((time[0] < '0' || time[0]>'9') || (time[1] < '0' || time[1]>'9') || (time[3] < '0' || time[3]>'9') || (time[4] < '0' || time[4]>'9'))
            throw ValidException();
        string hour = time.substr(0, 2);
        string minutes = time.substr(3, 2);
        if (stoi(hour) > 24)
            throw ValidException();
        if (stoi(minutes) > 60)
            throw ValidException();
    }

