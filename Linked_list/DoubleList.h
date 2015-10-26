///////////////////////////////////////////////////////////////
// DoubleList.h - class definitions of DoubleList            //
// Application: To implement addsorting, reverse and         //
//              ordering of double link list, Assignment#1   //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////

#include "Interfaces01.h"
#include "DoubleNode.h"
using namespace std;

class DoubleList : public IDoubleList{
public:
    IDoubleNode *head = NULL;
    IDoubleNode *tail = NULL;
    IDoubleNode *lastMin = NULL;
    IDoubleNode *lastMax = NULL;
public:
    DoubleList() ;
   ~DoubleList() ;
   IDoubleNode * getHead();
   IDoubleNode * getTail();
   void setHead(IDoubleNode * newHead);
   void setTail(IDoubleNode * newTail);
   void addSorted(int value);
   void orderSort2();
   void orderSort3();
   void sequenceOrderSort();
   void reverse();
   void traverse();
};
