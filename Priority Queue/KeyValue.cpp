///////////////////////////////////////////////////////////////
// KeyValue.cpp - all the method description of KeyValue     //
//                class                                      //
// Application: Assignment#2                      //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////
#include "KeyValue.h"
#include "VectorString.h"
using namespace std;
void KeyValue::setKey(int key){
    _key = key;
}

int KeyValue::getKey(){
    return _key;
}

void KeyValue::setValue(string value){
    _value->push_back(value);
}

string KeyValue::getValue(){
    return _value->get(0);
}

string KeyValue::getValueIndex(int index)
{
	return _value->get(index);
}
IVectorString* KeyValue::getVectorStringValues()
{
	return _value;
}

