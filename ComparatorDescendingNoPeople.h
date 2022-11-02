//
// Created by vlads on 5/6/2022.
//

#ifndef A8_9_917_STRILETCHI_VLAD_COMPARATORDESCENDINGNOPEOPLE_H
#define A8_9_917_STRILETCHI_VLAD_COMPARATORDESCENDINGNOPEOPLE_H
#include "Comparator.h"
#include "Event.h"

class ComparatorDescendingNoPeople : public Comparator<Event>{
    bool compare(Event e1, Event e2);
};


#endif //A8_9_917_STRILETCHI_VLAD_COMPARATORDESCENDINGNOPEOPLE_H
