#include <iostream>
#include <string>

#include "AddressFunction.h"
#include "LinearAddressing.h"
#include "HashTable.h"
#include "AdaptiveHashTable.h"
#include "QuadraticHashing.h"
#include "FileIO.h"

#include "Meni.h"


using namespace  std;

extern HashTable * hTable = nullptr;

void PretrazivanjeBrojaKljuceva(long long numOfRandKeys, long long minKey, long long maxKey)
{

    for (int i = 0; i < numOfRandKeys; ++i) {

        long long randKey = minKey + (double ) rand()/RAND_MAX * (maxKey-minKey);

        cout<<randKey<< " :: "<< (hTable->findKey(randKey) == nullptr ? "Nije nadjen" :"Nadjen")<<endl;
        cout<<'\t'<<"Prosek uspesna pretraga: "<<hTable->avgAccessSuccess()<<endl;
        cout<<'\t'<<"Prosek neuspesna pretraga: "<<hTable->avgAccesUnsuccess()<<endl;
    }
}

void DodavanjeIPretragaVecegBrojaKljuceva(HashTable& hTable, long long * keysToAdd, long long n, long long numOfRandKeys)
{
    long long minKey = INFINITY;
    long long maxKey = 0;

    for (int i = 0; i < n; ++i) {
        long long keyToAdd = keysToAdd[i];
        hTable.insertKey(keyToAdd,"");

        if(keyToAdd > maxKey) maxKey = keyToAdd;
        if(keyToAdd < minKey) minKey = keyToAdd;
    }

    PretrazivanjeBrojaKljuceva(numOfRandKeys, minKey, maxKey);
}



int main() {

    srand(24141);

    // Quadratic hashing
    long long c1 = 12;
    long long c2 = 56;

    long long hTableCapacity = 20;

    //testiranje
    long long numRandKeys = 100000;

    int brKljucevaIzFajla = 200;

      AddressFunction *a;
//    a = new LinearAddressing(2);

    a= new QuadraticHashing(c1,c2);



    cout<<"Da li zelite da koristite adaptivnu hash tabelu?: (y,n)"<<endl;

    char c;
    cin>>c;
    if(c == 'y')
        hTable = new AdaptiveHashTable(hTableCapacity,a);
    else
        hTable = new HashTable(hTableCapacity,a);

    //Unosenje kljuceva u tabelu

    cout<<"Da li zelite da dodate kljuceve iz fajla?: (y,n)"<<endl;

    cin>>c;
    if(c == 'y')
    {
        ifstream  dat ;
        dat.open("DZ3_Recnik_10K.txt");

        string * s = getOneRowAcc(dat) ;
        long long minKey = INFINITY;
        long long maxKey = 0;

        while(s != nullptr && brKljucevaIzFajla-- > 0 )
        {
            long long key;
            string str;
            getKeyStrFromRow(s,&key,&str);
           // cout<<key<<" "<<str<<endl;

            if(key > maxKey) maxKey = key;
            if(key <  minKey) minKey = key;


            hTable->insertKey(key,str);
            s = getOneRowAcc(dat);
        }

        PretrazivanjeBrojaKljuceva(numRandKeys, minKey,maxKey);

        dat.close();
    }
    else
    {
        long long keysToAdd[] = {5,24,19,233,6,8,18};
        long long n = 7;
        DodavanjeIPretragaVecegBrojaKljuceva(*hTable, keysToAdd, n, numRandKeys);
    }

    cout<<"Ispisivanje tabele:"<<endl<<*hTable;

    Meni();

    return 0;
}
