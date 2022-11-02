#pragma once
#include "Repo.h"
#include <vector>
class Controller {
    Repo r;
    const char *txt_file;
public:
    Controller();

    Controller(Repo &r, const char *output_file_txt);

    Controller(const Controller &other);

    ~Controller();

    Controller &operator=(const Controller &c);

    void add(const Event &e);

    void remove(int index);

    void update(int index, const Event &e);

    int getSize();

    std::vector<Event> getAll();

    //Returns true if e1 has a bigger date than e2 (e1's date is later than e2), false otherwise.
    bool hasBiggerDate(Event e1, Event e2);

    // sorting function for getAllOrdered.
    // returns hasBiggerDate result for the events associated to the indexes i1 and i2 (i1-th event, i2-th event).
    bool indexBiggerDate(int i1, int i2, std::vector<Event> v);

    void readAllFromTxtFile(const char *filename);

    void writeAllToTxtFile(const char *filename);

};
