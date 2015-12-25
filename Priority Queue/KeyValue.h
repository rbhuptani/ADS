///////////////////////////////////////////////////////////////
// KeyValue.h - class definitions of KeyValue            //
// Application: To implement Assignment#2                      //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////
#ifndef KEYVALUE_H
#define KEYVALUE_H
#include "Interfaces02.h"
#include "VectorString.h"
#include <string>
using namespace std;
class KeyValue : public IKeyValue{
private:
    int _key;
    IVectorString *_value;
public:
    KeyValue() {
        _value = new VectorString();
    }
    ~KeyValue() {}
    void setKey(int key);
    void setValue(string value);
    int getKey();
    string getValue();
    string getValueIndex(int index);
    IVectorString* getVectorStringValues();
};

#endif //KEYVALUE_H
