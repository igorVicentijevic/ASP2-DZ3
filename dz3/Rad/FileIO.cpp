//
// Created by Jasam on 24-Nov-23.
//

#include <iostream>


#include <fstream>

#include <string>
#include <sstream>

#include <regex>

using namespace  std;

void getKeyStrFromRow(string* row, long long * key, string* str)
{
    *key = stoll(row[1]);
    *str = row[0];
}


string* getOneRowAcc(ifstream& dat,int numOfStrings=2)
{
    string row;


    getline(dat,row);

    string* res = new string[numOfStrings];

    regex rgx("\\|");
    sregex_token_iterator iter(row.begin(),row.end(),rgx,-1);
    std::sregex_token_iterator end;

    for ( int i = 0; i < numOfStrings; i++)
    {
        if(iter == end) return nullptr;
        res[i] = iter->str();
        iter++;
    }



    return res;


}


