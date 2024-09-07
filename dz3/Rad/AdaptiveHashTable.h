//
// Created by Igor on 22.12.23..
//

#ifndef RAD_ADAPTIVEHASHTABLE_H
#define RAD_ADAPTIVEHASHTABLE_H

#include "HashTable.h"
#include <iostream>

class AdaptiveHashTable: public HashTable {

    using HashTable::HashTable;

    double granicaPopunjenosti = 0.75;
    int granicaProsecanBrojPristupaNeuspesna = tableSize()*0.7;

    void paramChange() override;

    void MakeNewTable()
    {
        std::cout << "Prosirivanje tabele ..."<<std::endl;

        Location ** temp = table;
        table = new Location * [tableSize()*2] {nullptr};
        resetStatistics();

        int prevTableSize = n;

        n *=2;

        for (int i = 0; i < prevTableSize; ++i) {
            if(!temp[i]) continue;
            insertKey(temp[i]->key, temp[i]->s);
        }

        for (int i = 0; i < tableSize(); ++i) {
            delete temp[i];
            temp[i] = nullptr;
        }
        delete[] temp;
        temp = nullptr;


    }
};


#endif //RAD_ADAPTIVEHASHTABLE_H
