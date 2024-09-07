//
// Created by Igor on 25.12.23..
//

#ifndef RAD_QUADRATICHASHING_H
#define RAD_QUADRATICHASHING_H

#include "AddressFunction.h"

class QuadraticHashing: public AddressFunction {

    long long c1,c2;

public:

    QuadraticHashing(long long c1, long long c2): AddressFunction(), c1(c1),c2(c2){}

    long long getAddress(long long key,long long address, int attempt) override;

};


#endif //RAD_QUADRATICHASHING_H
