///////////////////////////////////////////////////////////////
// VectorKeyValue1.cpp - class definitions of VectorKeyValue1//
// Application: To implement Assignment#2                    //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////

#include "Interfaces02.h"
#include "KeyValue.h"
#include<iostream>
#include "VectorKeyValue1.h"
using namespace std;

void VectorKeyValue1::push_back(IKeyValue * item) {
     if(_vsize >= _capacity )
        increaseCapacityI(_capacity + 1000);
    _vIKeyValue[_vsize] = item;
    _vsize++;
}

void VectorKeyValue1::increaseCapacityI(size_t newCap){
    _capacity += newCap;
    IKeyValue **tempKeyValue;
    tempKeyValue = new IKeyValue*[_capacity];

    for(size_t i =0;i<_vsize;i++)
        tempKeyValue[i] = _vIKeyValue[i];

    if(_vIKeyValue != NULL)
        delete[] _vIKeyValue;

    _vIKeyValue = tempKeyValue;
}



void VectorKeyValue1::pop_back(){
    _vsize--;
}

void VectorKeyValue1::set(int index, IKeyValue * item){
    if(index < _vsize && index >= 0)
		_vIKeyValue[index] = item;
}


size_t VectorKeyValue1::size(){
    return _vsize;
}

IKeyValue * VectorKeyValue1::get(int index){
    return _vIKeyValue[index];
}

void VectorKeyValue1::swap(int index1,int index2){

    if(index1 == index2)
        return;
    IKeyValue * temp;
    temp = this->get(index1);
    this->set(index1,this->get(index2));
    this->set(index2,temp);
}

void VectorKeyValue1::show(){

}
