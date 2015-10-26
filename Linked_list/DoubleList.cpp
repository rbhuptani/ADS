///////////////////////////////////////////////////////////////
// DoubleList.cpp - all method description of DoubleList.h   //
// Application: To implement addsorting, reverse and         //
//              ordering of double link list, Assignment#1   //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////


#include "Interfaces01.h"
#include "DoubleList.h""
#include "DoubleNode.h"
#include "iostream"
using namespace std;

DoubleList::DoubleList() {}
DoubleList::~DoubleList() {}

void DoubleList::setHead(IDoubleNode *newHead){
    head = newHead;
    head->setPrev(NULL);
}

void DoubleList::setTail(IDoubleNode *newTail){
    tail = newTail;
    tail->setNext(NULL);
}
IDoubleNode * DoubleList::getHead(){
    return head;
}
IDoubleNode * DoubleList::getTail(){
    return tail;
}
void DoubleList::addSorted(int value){
    IDoubleNode *newNode = new DoubleNode();
    IDoubleNode *left = getHead();
    IDoubleNode *right = getHead();
    bool flag = true;
    newNode->setValue(value);
    if(getHead() == NULL){
        setHead(newNode);
        setTail(newNode);
    }
    else if(getTail() == NULL){
        if(newNode->getValue() > getHead()->getValue()){
            setTail(newNode);
            getTail()->setNext(NULL);
            getTail()->setPrev(getHead());
            getHead()->setNext(getTail());
        }
        else{
            setTail(getHead());
            setHead(newNode);
            getTail()->setPrev(getHead());
            getHead()->setNext(getTail());
        }
    }
    else if(newNode->getValue() < getHead()->getValue()){
        newNode->setNext(getHead());
        getHead()->setPrev(newNode);
        setHead(newNode);
    }
    else if(newNode->getValue() > getTail()->getValue()){
        newNode->setPrev(getTail());
        getTail()->setNext(newNode);
        setTail(newNode);
    }
    else{
        left = getHead();
        right = getHead()->getNext();
        while(right){
            if(newNode->getValue() >= left->getValue() && newNode->getValue() <= right->getValue() ){
                flag = false;
                left->setNext(newNode);
                right->setPrev(newNode);
                newNode->setPrev(left);
                newNode->setNext(right);
                break;
            }
            left = left->getNext();
            right = right->getNext();
        }
    }
}
void DoubleList::orderSort2(){
    IDoubleNode *tempNode;
    IDoubleNode *prev = getHead();
    IDoubleNode *current = prev->getNext();
    IDoubleNode *next;
    setHead(current);
    while(1){
        next = current->getNext();
        current->setNext(prev);
        if (prev->getPrev() == NULL)
			current->setPrev(NULL);
		else
            current->setPrev(prev->getPrev()->getNext());
        prev->setPrev(current);
        if(next == NULL || next->getNext()==NULL){
            prev->setNext(next);
            break;
        }

        prev->setNext(next->getNext());
        prev = next;
        current = prev->getNext();
    }
    setTail(prev);
}
void DoubleList::orderSort3(){
    IDoubleNode *prev = getHead();
    IDoubleNode *current = prev->getNext()->getNext();
    IDoubleNode *next;
    setHead(current);
    while(true){
        next = current->getNext();
        current->setNext(prev->getNext());
        if(prev->getPrev() == NULL)
            current->setPrev(NULL);
        else
            current->setPrev(prev->getPrev()->getNext()->getNext());
        prev->setPrev(current->getNext());
        current->getNext()->setNext(prev);
        current->getNext()->setPrev(current);
        if(next == NULL || next->getNext()==NULL){
            prev->setNext(NULL);
            break;
        }
        if(next->getNext()->getNext() == NULL){
            prev->setNext(next->getNext());
            next->getNext()->setPrev(prev);
            next->getNext()->setNext(next);
            next->setPrev(next->getNext());
            next->setNext(NULL);
            prev = next;
            break;
        }
        prev->setNext(next->getNext()->getNext());
        prev = next;
        current = prev->getNext()->getNext();

    }
    setTail(prev);
}
void DoubleList::sequenceOrderSort(){
    bool flag = true;
    int seq_size = 2;
    IDoubleNode *current = getHead();
    IDoubleNode *prev,*next,*tempNode;
    prev = NULL;
    setHead(current->getNext());
    tempNode = head;
    while(flag){
        for(int i=0;i<seq_size;i++){
            next = current->getNext();
            current->setNext(prev);
            current->setPrev(next);
            prev = current;
            current = next;
            if(current == NULL){
                flag=false;
                break;
            }
        }
        if(seq_size>2){
            tempNode->setNext(prev);
            prev->setPrev(tempNode);
        }
        else{
            current->setPrev(prev);
			prev->setPrev(NULL);
        }
        while (tempNode->getNext() != NULL)
		{
			tempNode = tempNode->getNext();
		}
		prev = NULL;
		seq_size = seq_size + 1;
    }
    setTail(tempNode);
}
void DoubleList::reverse(){
    IDoubleNode *tempHead = getHead();
    IDoubleNode *prev = getHead();
    IDoubleNode *current = prev->getNext();
    IDoubleNode *next = current->getNext();
    prev->setPrev(current);
    while(1){
        current->setNext(prev);
        current->setPrev(next);
        prev = current;
        current = next;
        if(current == NULL)
            break;
        next = next->getNext();
    }
    getTail()->setNext(prev->getNext());
    setHead(getTail());
    setTail(tempHead);
}

void DoubleList::traverse(){
    IDoubleNode * traverse1;
    traverse1 = getHead();
    cout<<"Node_Address\tNode_Left\tNode_Value\tNode_Right"<<endl;
    while(traverse1){
        cout << endl << traverse1 << " \t " << traverse1->getPrev()<< "\t"<< traverse1->getValue() <<" \t " << traverse1->getNext();
        traverse1 = traverse1->getNext();
    }
    cout<<endl<<"--------------------"<<endl;
}
