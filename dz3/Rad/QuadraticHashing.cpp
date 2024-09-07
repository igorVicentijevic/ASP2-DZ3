//
// Created by Igor on 25.12.23..
//

#include "QuadraticHashing.h"

long long QuadraticHashing::getAddress(long long key,long long address, int attempt)
{
    return address + attempt*c1 + attempt*attempt*c2;
}