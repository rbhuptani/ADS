///////////////////////////////////////////////////////////////
// VectorKeyValue.cpp - class definitions of VectorKeyValue  //
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
#include "VectorKeyValue.h"
using namespace std;

void VectorKeyValue::push_back(IKeyValue * item) {
    cout<<endl<<"Interface Pushback called."<<endl;
}
void VectorKeyValue::push_back(KeyValue * item) {
    if(_vsize >= _capacity )
        increaseCapacity(2*_capacity);
    _vKeyValue[_vsize] = item;
    _vsize++;
}

void VectorKeyValue::increaseCapacity(size_t newCap){
    _capacity += newCap;
    KeyValue **tempKeyValue;
    tempKeyValue = new KeyValue*[_capacity];
    for(size_t i =0;i<_vsize;i++)
        tempKeyValue[i] = _vKeyValue[i];
    if(_vKeyValue != NULL)
        delete[] _vKeyValue;
    _vKeyValue = tempKeyValue;
}

void VectorKeyValue::pop_back(){
    _vsize--;
}

void VectorKeyValue::set(int index, IKeyValue * item){
    cout<<endl<<"Interface set called."<<endl;
}
void VectorKeyValue::set(int index, KeyValue* item)
{
	if(index < _vsize && index >= 0)
		_vKeyValue[index] = item;
}

size_t VectorKeyValue::size(){
    return _vsize;
}

IKeyValue * VectorKeyValue::get(int index){
    return _vKeyValue[index];
}
KeyValue *VectorKeyValue::getNode(int index){
    return _vKeyValue[index];
}
void VectorKeyValue::show(){

}
void VectorKeyValue::swap(int index1,int index2){
    if(index1 == index2)
        return;
    KeyValue * temp;
    temp = this->getNode(index1);
    this->set(index1,this->getNode(index2));
    this->set(index2,temp);
}
