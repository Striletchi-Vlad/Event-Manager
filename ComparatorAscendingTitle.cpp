//
// Created by vlads on 5/6/2022.
//

#include "ComparatorAscendingTitle.h"

bool ComparatorAscendingTitle::compare(Event e1, Event e2) {
    return e1.getTitle() > e2.getTitle();
}
