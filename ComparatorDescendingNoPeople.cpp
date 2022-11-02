//
// Created by vlads on 5/6/2022.
//

#include "ComparatorDescendingNoPeople.h"

bool ComparatorDescendingNoPeople::compare(Event e1, Event e2) {
    return e1.getNrPeople() <= e2.getNrPeople();
}
