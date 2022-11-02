#pragma once
#include "Repo.h"
#include <vector>
#include "Comparator.h"
class Controller_User
{
    Repo r;
public:
    Controller_User();
    Controller_User(Repo& r);
    Controller_User(const Controller_User& other);
    ~Controller_User();
    Controller_User& operator= (const Controller_User& c);

    void add(const Event& e);

    std::vector<Event> getAll();

    //Returns a vector of indexes(associated to the events), sorted according to the events' calendaristic order.
    std::vector<int> getOrderedIndexes();

    //Returns a vector of indexes(associated to the events), from a specific month, sorted according to the events' calendaristic order.
    std::vector<int> getOrderedIndexesMonth(std::string month);

    //Returns true if e1 has a bigger date than e2 (e1's date is later than e2), false otherwise.
    bool hasBiggerDate(Event e1, Event e2);

    // sorting function for getAllOrdered.
    // returns hasBiggerDate result for the events associated to the indexes i1 and i2 (i1-th event, i2-th event).
    bool indexBiggerDate(int i1, int i2, std::vector<Event> v);


    //increments the nr of people going to the i-th event.
    void increment(int i);

    //decrements the nr of people going to the i-th event.
    void decrement(int i);

    void readAllFromTxtFile(const char* filename);

    template <typename T>
    void sortVector(std::vector<T> v, Comparator<T>* c){
        //    std::sort(v.begin(), v.end(), [=](Event a, Event b){
//        return c->compare(a,b);
//    });

        //bubble sort
        bool ordered=false;
        while (!ordered){
            ordered=true;
            for (int i=0;i<v.size()-1;i++){
                if(!c->compare(v[i], v[i+1])){
                    ordered=false;
                    std::iter_swap(v.begin()+i, v.begin()+i+1);

                }
            }
        }
    }

};

