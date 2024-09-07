//
// Created by Igor on 22.12.23..
//

#include "AdaptiveHashTable.h"


void AdaptiveHashTable::paramChange() {
    if(fillRatio() > granicaPopunjenosti || avgAccesUnsuccess() > granicaProsecanBrojPristupaNeuspesna )
    {
        MakeNewTable();
    }
}