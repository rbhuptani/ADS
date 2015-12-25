///////////////////////////////////////////////////////////////
// VectortKeyValue1.h - class definitions of VectortKeyValue1//
// Application: To implement Assignment#2                    //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////
#pragma once
#include "Interfaces02.h"
#include "KeyValue.h"
#include <string>
using namespace std;

class VectorKeyValue1 : public IVectorKeyValue {

private:
    size_t _vsize;
    size_t _capacity;
    IKeyValue **_vIKeyValue;
    IVectorString *string;
public:
    VectorKeyValue1() {
        _vsize = 0;
        _capacity = 10;
        _vIKeyValue = new IKeyValue*[_capacity];
        string = new VectorString();
    }
    VectorKeyValue1(size_t cap) {
        _vsize = 0;
        _capacity = cap;
         _vIKeyValue = new IKeyValue*[_capacity];
         string = new VectorString();
    }
    ~VectorKeyValue1() {
         delete[] _vIKeyValue;
    }
    void push_back(IKeyValue * item) ;
    void pop_back();
    IKeyValue * get(int index);
    void set(int index, IKeyValue * item);
    size_t size();
    void increaseCapacityI(size_t newCap);
    void swap(int index1,int index2);
    void show();
};

