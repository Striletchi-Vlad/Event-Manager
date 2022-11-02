#define _CRT_SECURE_NO_WARNINGS
#pragma once
//Each Event has a title, a description, a date and time, a number of people who are going and a link towards the online resource containing the event.

#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

class Event {
	std::string title;
	std::string description;
	std::string date;
	std::string time;
	int nr_people;
	std::string link;

public:
	Event()
		:title(std::string("")), description(std::string("")), date(std::string("")), time(std::string("")),nr_people(0), link(std::string(""))
	{}

	Event(std::string _title, std::string _description, std::string _date, std::string _time, int _nr_people, std::string _link)
		:title(_title), description(_description), date(_date), time(_time), nr_people(_nr_people), link(_link)
	{}

	Event(const Event& e)
		:title(e.title), description(e.description), date(e.date), time(e.time), nr_people(e.nr_people), link(e.link)
	{
	}

	~Event() {
	}

    friend std::ostream& operator<<(std::ostream& os, const Event& e);
    friend std::istream& operator>>(std::istream& os, Event& e);

	bool operator==(Event other);

	Event& operator= (const Event& e);
	std::string getTitle() {
		return title;
	}

	std::string getDescription() {
		return description;
	}
	
	std::string getDate() const{
		return date;
	}
	
	std::string getTime() {
		return time;
	}

	int getNrPeople() {
		return nr_people;
	}

	std::string getLink() {
		return link;
	}

};

