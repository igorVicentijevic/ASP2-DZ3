//
// Created by Igor on 20.12.23..
//

#ifndef RAD_ADDRESSFUNCTION_H
#define RAD_ADDRESSFUNCTION_H


class AddressFunction {

public:
    virtual long long getAddress(long long key,long long address, int attempt)=0;

};


#endif //RAD_ADDRESSFUNCTION_H
