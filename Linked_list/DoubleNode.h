///////////////////////////////////////////////////////////////
// DoubleNode.h - class definitions of DoubleNode            //
// Application: To implement addsorting, reverse and         //
//              ordering of double link list, Assignment#1   //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////

#ifndef DOUBLENODE_H
#define DOUBLENODE_H

#include "Interfaces01.h"
using namespace std;

class DoubleNode : public IDoubleNode{
    private :
        int node_value;
        IDoubleNode *node_next=NULL;
        IDoubleNode *node_prev=NULL;
    public :
        DoubleNode();
        ~DoubleNode();
        void setValue(int value);
        int getValue();
        IDoubleNode * getPrev();
        IDoubleNode * getNext();
        void setPrev(IDoubleNode * prev);
        void setNext(IDoubleNode * next);
};
#endif
