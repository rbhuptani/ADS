///////////////////////////////////////////////////////////////
// VectortKeyValue.h - class definitions of VectortKeyValue  //
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

class VectorKeyValue : public IVectorKeyValue {

private:
    size_t _vsize;
    size_t _capacity;
    KeyValue **_vKeyValue;
    IVectorString *string;
public:
    VectorKeyValue() {
        _vsize = 0;
        _capacity = 10;
        _vKeyValue = new KeyValue*[_capacity];
        string = new VectorString();
    }
    VectorKeyValue(size_t cap) {
        _vsize = 0;
        _capacity = cap;
        _vKeyValue = new KeyValue*[_capacity];
    }
    ~VectorKeyValue() {
        delete[] _vKeyValue;
    }
    void push_back(IKeyValue * item) ;
    void pop_back();
    IKeyValue * get(int index);
    KeyValue *getNode(int index);
    void set(int index, IKeyValue * item);
    void set(int index, KeyValue* item);
    size_t size();
    void show();
    void increaseCapacity(size_t newCap);
    void swap(int index1,int index2);
    void push_back(KeyValue * item);

};
