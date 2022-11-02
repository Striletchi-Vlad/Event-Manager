#include "Event.h"
#include <fstream>
//std::ostream& operator<<(std::ostream& os, const Event& e) {
//	os <<"\n\t===================" << "\n\tTitle: " << e.title << "\n\tDescription: " << e.description << "\n\tDate: " << e.date << "\n\tTime: " << e.time << "\n\tNo. of people: " << e.nr_people << "\n\tLink: " << e.link << "\n\t===================";
//	return os;
//}
std::ostream& operator<<(std::ostream& os, const Event& e) {
    os << e.title << "\n" << e.description << "\n" << e.date << "\n" << e.time << "\n" << e.nr_people << "\n" << e.link << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Event& e) {
    //is >> e.title >> e.description >> e.date >> e.time >> e.nr_people >> e.link;
    std::string title, description, date, time, link, nr_people;
    int nr_people_numeric;
    std::getline(is, title);
    //try to stop if invalid entry
    if(title.empty()){
        return is;
    }

    std::getline(is, description);
    std::getline(is, date);
    std::getline(is, time);
    std::getline(is, nr_people);
    std::getline(is, link);
    nr_people_numeric = std::stoi(nr_people);
    e.title=title;
    e.description=description;
    e.date=date;
    e.time=time;
    e.nr_people=nr_people_numeric;
    e.link=link;
    return is;
}

Event& Event::operator= (const Event& e)
{
	// do the copy
	title = e.title;
	description = e.description;
	date = e.date;
	time = e.time;
	nr_people = e.nr_people;
	link = e.link;
	//std::cout << "overloaded equality called\n\t";
	// return the existing object so we can chain this operator
	return *this;
}

bool Event::operator==(Event other) {
	if (title == other.title)
		if (description == other.description)
			if (date == other.date)
				if (time == other.time)
					if (nr_people == other.nr_people)
						if (link == other.link)
							return true;

    return false;
}