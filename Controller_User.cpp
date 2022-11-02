#include "Controller_User.h"
#include "Event.h"
#include <vector>
#include <algorithm>
#include <fstream>

Controller_User::Controller_User(){}

Controller_User::Controller_User(Repo& _r):r(_r){}

Controller_User::Controller_User(const Controller_User& other){
    r = other.r;
}

Controller_User::~Controller_User()= default;

Controller_User& Controller_User::operator=(const Controller_User& c)
= default;

void Controller_User::add(const Event& e)
{
    r.add(e);
}

std::vector<Event> Controller_User::getAll(){
    return r.getAll();
}

std::vector<int> Controller_User::getOrderedIndexes(){
    //cannot use copy or copy_if because I iterate events and append ints, they aren't the same type
    std::vector<Event> temp = r.getAll();
    std::vector<int> res;
    for (int i = 0; i < temp.size(); i++) {
        res.push_back(i);
    }
    std::sort(res.begin(), res.end(), [this, temp](int i1, int i2) {
        return indexBiggerDate(i2,i1, temp);
    });

    return res;
}

std::vector<int> Controller_User::getOrderedIndexesMonth(std::string month)
{
    std::vector<Event> temp = r.getAll();
    std::vector<int> res;
    for (int i = 0; i < temp.size(); i++) {
        if(temp[i].getDate().substr(3,2) == month)
            res.push_back(i);
    }
    std::sort(res.begin(), res.end(), [this, temp](int i1, int i2) {
        return indexBiggerDate(i2, i1, temp);
    });

    return res;
}

bool Controller_User::hasBiggerDate(Event e1, Event e2)
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
    //return false;
}

bool Controller_User::indexBiggerDate(int i1, int i2, std::vector<Event> v)
{
    return hasBiggerDate(v[i1], v[i2]);
}

void Controller_User::increment(int i)
{
    Event _event = r.getElem(i);
    r.update(i, Event(_event.getTitle(), _event.getDescription(), _event.getDate(), _event.getTime(), _event.getNrPeople()+1, _event.getLink()));
}

void Controller_User::decrement(int i)
{
    Event _event = r.getElem(i);
    r.update(i, Event(_event.getTitle(), _event.getDescription(), _event.getDate(), _event.getTime(), _event.getNrPeople() - 1, _event.getLink()));
}

void Controller_User::readAllFromTxtFile(const char* filename) {
    std::ifstream fin;
    std::string title, description, date, time, link, nr_people;
    int nr_people_numeric;
    fin.open(filename);
    while(std::getline(fin, title)){
        std::getline(fin, description);
        std::getline(fin, date);
        std::getline(fin, time);
        std::getline(fin, nr_people);
        std::getline(fin, link);
        nr_people_numeric = std::stoi(nr_people, nullptr, 10);
        add(Event(title, description, date, time, nr_people_numeric, link));
    }
    fin.close();
}






//void Controller_User::sortVector(std::vector<Event> v, Comparator<Event> *c) {
////    std::sort(v.begin(), v.end(), [=](Event a, Event b){
////        return c->compare(a,b);
////    });
//
//    //bubble sort
//    bool ordered=false;
//    while (!ordered){
//        ordered=true;
//        for (int i=0;i<v.size()-1;i++){
//            if(!c->compare(v[i], v[i+1])){
//                ordered=false;
//                std::iter_swap(v.begin()+i, v.begin()+i+1);
//
//            }
//        }
//    }
//}

