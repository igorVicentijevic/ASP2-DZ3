//
// Created by Igor on 20.12.23..
//

#include "LinearAddressing.h"


long long LinearAddressing::getAddress(long long key,long long address, int attempt)
{
    return address + s*attempt;
}
