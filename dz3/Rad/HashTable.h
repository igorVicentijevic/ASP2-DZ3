//
// Created by Igor on 20.12.23..
//

#ifndef RAD_HASHTABLE_H
#define RAD_HASHTABLE_H

#include "AddressFunction.h"
#include <string>

class HashTable {
protected:
    struct Location{
        long long key;
        std::string s;

        Location(long long k,std::string s):key(k),s(s){}

    };
    Location ** table = nullptr;
    long long n;

private:
    AddressFunction* addressFunction;
    //moze i const

    long long numberOfElements = 0;

    long long succ = 0;
    long long nSucc = 0;
    long long unSucc = 0;
    long long nUnSucc = 0;

    virtual void paramChange(){};


public:


    HashTable(long long n, AddressFunction * af):n(n),addressFunction(af)
    {
        table = new Location*[n]{nullptr};
    }

    std::string * findKey(long long k);
    bool insertKey(long long k,std::string s);
    bool deleteKey(long long k);

    int avgAccessSuccess() const;
    int avgAccesUnsuccess() const;
    void resetStatistics();

    void clear();
    long long keyCount() const;
    long long tableSize() const;

    friend std::ostream & operator<<(std::ostream & it, HashTable& hashTable);

    double fillRatio() const;

    ~HashTable();

};


#endif //RAD_HASHTABLE_H
