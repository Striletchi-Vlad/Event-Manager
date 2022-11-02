#include "Controller.h"
#include "Event.h"
#include <vector>
#include <algorithm>
#include <fstream>

Controller::Controller(){}

Controller::Controller(Repo& _r, const char* output_file_txt):r(_r), txt_file(output_file_txt){}

Controller::Controller(const Controller& other){
	r = other.r;
    txt_file = "default_out_file.txt";
}

Controller::~Controller()= default;

Controller& Controller::operator=(const Controller& c)
= default;

void Controller::add(const Event& e)
{
	r.add(e);
    writeAllToTxtFile(txt_file);
}

void Controller::remove(int index)
{
	r.remove(index);
    writeAllToTxtFile(txt_file);

}

void Controller::update(int index, const Event& e)
{
	r.update(index, e);
    writeAllToTxtFile(txt_file);

}

int Controller::getSize()
{
	return r.getSize();
}

std::vector<Event> Controller::getAll(){
	return r.getAll();
}

bool Controller::hasBiggerDate(Event e1, Event e2)
{
	std::string date1 = e1.getDate();
	std::string date2 = e2.getDate();
	int day1 = stoi(date1.substr(0, 2));
	int month1 = stoi(date1.substr(3, 2));
	int year1 = stoi(date1.substr(6, 4));
	int day2 = stoi(date2.substr(0, 2));
	int month2 = stoi(date2.substr(3, 2));
	int year2 = stoi(date2.substr(6, 4));
	if (year1 > year2) 
		return true;
	if (year1 < year2)
		return false;
	if (month1 > month2)
		return true;
	if (month1 < month2)
		return false;
	if (day1 > day2)
		return true;
	return false;
}

bool Controller::indexBiggerDate(int i1, int i2, std::vector<Event> v)
{
	return hasBiggerDate(v[i1], v[i2]);
}

void Controller::readAllFromTxtFile(const char* filename) {
    std::ifstream fin;
    std::string title, description, date, time, link, nr_people;
    int nr_people_numeric;
    fin.open(filename);
    Event e;
    while(fin>>e){
        add(e);
    }
    fin.close();
}

void Controller::writeAllToTxtFile(const char* filename) {
    std::ofstream fout;
    fout.open(filename);
    for(auto e:getAll()){
        fout<<e;
    }
    fout.close();
}
