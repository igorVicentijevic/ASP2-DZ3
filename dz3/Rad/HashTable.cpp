//
// Created by Igor on 20.12.23..
//

#include "HashTable.h"
#include "AddressFunction.h"

#include <iostream>

using namespace std;

std::string* HashTable::findKey(long long k)
{
    long long numberOfAccess= 0;
    long long matAddr = k % n;\

    numberOfAccess++;
    if(table[matAddr] == nullptr ) {
        unSucc += numberOfAccess;
        nUnSucc++;
        paramChange();
        return nullptr;
    }


    if(table[matAddr]->key == k) {
        succ += numberOfAccess;
        nSucc++;
        paramChange();
        return &table[matAddr]->s;
    }

    int i = 0;

    while(i<n)
    {
        long long newAddr = addressFunction->getAddress(k,matAddr,i++) % n;
        numberOfAccess++;
        if(table[newAddr] == nullptr) break;
        if(table[newAddr]->key == k)
        {
            nSucc++;
            succ+=numberOfAccess;
            paramChange();
            return &table[newAddr]->s;
        }
    }


    unSucc+=numberOfAccess;
    nUnSucc++;
    paramChange();
    return nullptr;
}

bool HashTable::insertKey(long long k,std::string s)
{
    long long matAddr = k % n;

    if(table[matAddr] == nullptr)
    {
        Location* newLocation= new Location(k,s);
        table[matAddr] = newLocation;
        numberOfElements ++;
        paramChange();
        return true;
    }

    int i = 0;

    while(i<n)
    {
        long long newAddr = addressFunction->getAddress(k,matAddr,i++) % n;
        if(table[newAddr] == nullptr)
        {
            Location* newLocation= new Location(k,s);
            table[newAddr] = newLocation;
            numberOfElements++;
            paramChange();
            return true;
        }
    }

    paramChange();
    return false;
}

bool HashTable::deleteKey(long long k)
{
    long long matAddr = k % n;

    if(table[matAddr] == nullptr) {
        numberOfElements--;
        paramChange();
        return true;
    }

    if(table[matAddr]->key == k)
    {
        delete table[matAddr];
        table[matAddr] = nullptr;
        numberOfElements--;
        paramChange();
        return true;
    }

    int i = 0;

    while(i<n)
    {
        long long newAddr = addressFunction->getAddress(k,matAddr,i++) % n;

        if(table[newAddr]->key == k)
        {
            delete table[newAddr];
            table[newAddr] = nullptr;
            numberOfElements--;
            paramChange();
            return true;
        }
    }

    paramChange();
    return false;
}

std::ostream & operator<<(std::ostream & it, HashTable& hashTable)
{
    for (int i = 0; i < hashTable.n; ++i) {
        if(hashTable.table[i]== nullptr)
        {
            it<<"EMPTY"<<endl;
            continue;
        }
        it<< hashTable.table[i]->key<<'\t'<<hashTable.table[i]->s<<endl;
    }

    return it;
}

long long HashTable::keyCount() const
{
    return numberOfElements;
}

long long HashTable::tableSize() const
{
    return n;
}

void HashTable::clear() {
    for (int i = 0; i <n; ++i) {
        delete table[i];
        table[i] = nullptr;
    }

    numberOfElements = 0;
    paramChange();
}

double HashTable::fillRatio() const
{
    return (double)numberOfElements/(double) n;
}

int HashTable::avgAccessSuccess() const
{
    if(nSucc == 0) return -1;
    return succ/nSucc;
}

int HashTable::avgAccesUnsuccess() const
{
    if(nUnSucc == 0) return -1;
    return unSucc/nUnSucc;
}

void HashTable::resetStatistics()
{
    succ = 0;
    nSucc = 0;

    unSucc = 0;
    nUnSucc = 0;
}


HashTable::~HashTable()
{
    clear();
    delete[] table;
}

