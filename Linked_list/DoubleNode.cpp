///////////////////////////////////////////////////////////////
// DoubleNode.cpp - all method description of DoubleNode.h   //
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


DoubleNode::DoubleNode(){

}

DoubleNode::~DoubleNode(){}

void DoubleNode::setValue(int value){
    node_value = value;
}

int DoubleNode::getValue(){
    return node_value;
}

void DoubleNode::setNext(IDoubleNode * next){
    this->node_next = next;
}

void DoubleNode::setPrev(IDoubleNode * prev){
    this->node_prev = prev;
}

IDoubleNode *DoubleNode::getNext(){
    return this->node_next;
}

IDoubleNode *DoubleNode::getPrev(){
    return this->node_prev;
}
