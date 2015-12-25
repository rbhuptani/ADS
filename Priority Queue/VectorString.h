///////////////////////////////////////////////////////////////
// VectorString.h - class definitions of VectorString            //
// Application: To implement Assignment#2                      //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////
#pragma once
#include "Interfaces02.h"
#include <string>
using namespace std;
class VectorString : public IVectorString{
private:
    size_t _vsize;
    size_t _capacity;
    string * _vString;
public:
    VectorString() {
        _vsize = 0;
        _capacity = 10;
        _vString = new string[_capacity];
    }
    ~VectorString() {
        delete[] _vString;
    }
    void push_back(std::string item);
    void pop_back();
    std::string get(int index);
    void set(int index, std::string item);
    size_t size();

    void increaseCapacity(size_t newCap);
};


