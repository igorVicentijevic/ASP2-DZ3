//
// Created by Jasam on 24-Nov-23.
//

#ifndef ASP2DZ2_FILEIO_H
#define ASP2DZ2_FILEIO_H


#include <iostream>


#include <fstream>
#include <string>

std::string* getOneRowAcc(std::ifstream& dat,int numOfStrings=2);
void getKeyStrFromRow(std::string* row, long long * key, std::string * str);

#endif //ASP2DZ2_FILEIO_H
