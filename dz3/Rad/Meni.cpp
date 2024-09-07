//
// Created by Igor on 22.12.23..
//
#include <iostream>
#include <string>

#include "AddressFunction.h"
#include "LinearAddressing.h"
#include "HashTable.h"
#include "FileIO.h"

#include "Meni.h"
using namespace  std;

extern HashTable* hTable;

void IspisiMeni()
{
    cout<<"====================================="<<endl;
    cout<<"Izaberite jednu opciju:"<<endl;
    cout<<"1. Pronadji kljuc" <<endl;
    cout<<"2. Unesi kljuc" <<endl;
    cout<<"3. Izbrisi kljuc" <<endl;
    cout<<"4. Prosecan broj pristupa pri uspesnoj pretrazi" <<endl;
    cout<<"5. Prosecan broj pristupa pri neuspesnoj pretrazi" <<endl;
    cout<<"6. Resetuj statistiku" <<endl;
    cout<<"7. Ocisti tabelu" <<endl;
    cout<<"8. Broj kljuceva" <<endl;
    cout<<"9. Velicina tabele" <<endl;
    cout<<"10. Procenat popunjenosti"<<endl;
    cout<<"11. Ispis tabele"<<endl;
    cout<<"12. Kraj programa" << endl;
    cout<<"====================================="<<endl;

}

void Opcija1()
{
    // Pronadji kljuc
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Unesite kljuc koji zelite da pronadjete: "<<endl;
    long long kljuc;
    cin >> kljuc;

    string * foundStr = hTable->findKey(kljuc);
    cout << (foundStr ? *foundStr : "Kljuc se ne nalazi u tabeli!") << endl;
}

void Opcija2()
{
    // Unesi kljuc
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Unesite kljuc koji zelite da ubacite u tabelu: "<<endl;
    long long kljuc;
    cin >> kljuc;
    cout<<"Unesite string koji zelite da ubacite u tabelu:" <<endl;
    string str;
    cin>>str;

    cout<<(hTable->insertKey(kljuc,str) ? "Kljuc je uspesno ubacen!": "Kljuc nije ubacen!");

}
void Opcija3()
{
    // Izbrisi kljuc
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Unesite kljuc koji zelite da izbrisete: "<<endl;
    long long kljuc;
    cin >> kljuc;


    cout<<(hTable->deleteKey(kljuc) ? "Kljuc je uspesno obrisan!": "Kljuc nije obrisan!");

}
void Opcija4()
{
    //Prosecan broj pristupa pri uspesnoj pretrazi
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Prosecan broj pristupa pri uspesnoj pretrazi je "<<hTable->avgAccessSuccess()<<"!"<<endl;
}
void Opcija5()
{
    //Prosecan broj pristupa pri neuspenoj pretrazi
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Prosecan broj pristupa pri neuspesnoj pretrazi je "<<hTable->avgAccesUnsuccess()<<"!"<<endl;

}
void Opcija6()
{
    //Resetuj statistiku

    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    hTable->resetStatistics();
    cout<<"Statistika je resetovana!"<<endl;

}
void Opcija7()
{
    //Ocisti tabelu
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    hTable->clear();
    cout<<"Tabela je ociscena!"<<endl;

}
void Opcija8()
{
    //Broj kljuceva;
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Broj kljuceva je "<<hTable->keyCount()<<"!"<<endl;

}
void Opcija9()
{
    //Velicina tabele
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Velicina tabele je "<<hTable->tableSize()<<"!"<<endl;

}void Opcija10()
{
    //Procenat popunjenosti
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Procenat popunjenosti je "<<hTable->fillRatio()*100<<"%!"<<endl;
}

void Opcija11(){
    //Ispis tabele;
    cout<<"~~~~~~~~Tabela~~~~~~~~~~~"<<endl;
    cout<<*hTable;

}

void Opcija12(){
    //Prekid programa
    exit(0);
}

void Meni()
{
    IspisiMeni();

    int opcija;
    cout <<"Unesite opciju: ";
    cin >> opcija;
    switch (opcija) {
        case 1: Opcija1(); break;
        case 2: Opcija2(); break;
        case 3: Opcija3(); break;
        case 4: Opcija4(); break;
        case 5: Opcija5(); break;
        case 6: Opcija6(); break;
        case 7: Opcija7(); break;
        case 8: Opcija8(); break;
        case 9: Opcija9(); break;
        case 10: Opcija10(); break;
        case 11: Opcija11(); break;
        case 12: Opcija12(); break;
        default: cout<<"Pogresan unos!"<<endl;  Meni();
    }

    Meni();
}