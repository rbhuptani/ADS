///////////////////////////////////////////////////////////////
// VectorString.cpp - class definitions of VectorString      //
// Application: To implement Assignment#2                    //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////

#include "Interfaces02.h"
#include "VectorString.h"
#include <string>
using namespace std;

void VectorString::push_back(std::string item){
    if(_vsize == _capacity)
        increaseCapacity(2*_capacity);
    _vString[_vsize] = item;
    _vsize++;
}

void VectorString::increaseCapacity(size_t newCap){
    _capacity += newCap;
    string *tempString;
    tempString = new string[_capacity];

    for(size_t i =0;i<_vsize;i++)
        tempString[i] = _vString[i];

    if(_vString != NULL)
        delete[] _vString;

    _vString = tempString;
}

void VectorString::pop_back(){
    _vsize--;
}

std::string VectorString::get(int index){
    return _vString[index];
}

void VectorString::set(int index, std::string item){
    _vString[index] = item;
}
size_t VectorString::size(){
    return _vsize;
}



