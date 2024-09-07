//
// Created by Igor on 20.12.23..
//

#ifndef RAD_LINEARADDRESSING_H
#define RAD_LINEARADDRESSING_H

#include "AddressFunction.h"

class LinearAddressing: public  AddressFunction{

    int s;

public:

    LinearAddressing(int s): AddressFunction(), s(s){}
     long long getAddress(long long key,long long address, int attempt) override;

};


#endif //RAD_LINEARADDRESSING_H
