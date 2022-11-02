//
// Created by vlads on 5/6/2022.
//

#ifndef A8_9_917_STRILETCHI_VLAD_COMPARATOR_H
#define A8_9_917_STRILETCHI_VLAD_COMPARATOR_H

template <typename TElem>
class Comparator{
public:
    virtual bool compare(TElem, TElem)=0;
};


#endif //A8_9_917_STRILETCHI_VLAD_COMPARATOR_H
