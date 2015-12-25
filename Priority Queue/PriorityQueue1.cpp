///////////////////////////////////////////////////////////////
// PriorityQueue1.cpp - class definitions of PriorityQueue1  //
// Application: To implement Assignment#2                    //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////


#include "Interfaces02.h"
#include "PriorityQueue1.h"
#include<iostream>
#include <string>
using namespace std;

void PriorityQueue1::enqueue(IKeyValue * key_value){

    int index = KeyExist(key_value->getKey());
    if(index != -1){
        KeyValue *temp = Queue->getNode(index);
        temp->setValue(key_value->getValue());
        return;
    }
    KeyValue * tempNode = new KeyValue();
    tempNode->setKey(key_value->getKey());
    tempNode->setValue(key_value->getValue());
    Queue->push_back(tempNode);
    index = Queue->size()-1;
    if(index > 0)
        if(Queue->getNode(index)->getKey() > Queue->getNode(index-1)->getKey() )
			HeapSort(Queue);

}
int PriorityQueue1::KeyExist(int key){
    size_t i = Queue->size();
    size_t j=0;
    while(j!=i){

        if(Queue->getNode(j)->getKey() == key)
            return j;
        j++;
    }
    return -1;
}

IVectorKeyValue * PriorityQueue1::returnSorted(){

    VectorKeyValue *sorted = new VectorKeyValue(Queue->size());
	KeyValue *keyValue;
	for(int i = Queue->size()-1; i >= 0; i--)
	{
		for(int j = 0; j < Queue->getNode(i)->getVectorStringValues()->size(); j++)
		{
		    keyValue = new KeyValue();
			keyValue->setKey(Queue->getNode(i)->getKey());
			keyValue->setValue(Queue->getNode(i)->getVectorStringValues()->get(j));
			sorted->push_back(keyValue);
		}
	}
	return sorted;
}

int PriorityQueue1::lowestKey(){
    return Queue->getNode(Queue->size() - 1)->getKey();
}

IVectorString * PriorityQueue1::lowestValues(){
    IVectorString *result = new VectorString();
    int i = Queue->size() - 1;
	for(int j = 0; j < Queue->getNode(i)->getVectorStringValues()->size(); j++)
		result->push_back(Queue->getNode(i)->getVectorStringValues()->get(j));
	return result;
}

void PriorityQueue1::dequeue(){
    if(Queue->size() <= 0)
		return;
    Queue->pop_back();
}
size_t PriorityQueue1::size(){
    return Queue->size();
}

void PriorityQueue1::showQueue(){

    size_t i = Queue->size();
    size_t j=0;
    while(j!=i){

        cout<<endl<<Queue->getNode(j)->getKey()<<"  ::  "<<Queue->getNode(j)->getValue();
        j++;
    }
    cout<<endl;
}



void PriorityQueue1::Max_Heapify(VectorKeyValue *q,size_t heapSize,size_t index){
    size_t i, j;
    j = index;
    do
    {
        i = j;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(( left < heapSize) && q->getNode(j)->getKey() > q->getNode(left)->getKey())
            j =left;
        if((right < heapSize) && q->getNode(j)->getKey() > q->getNode(right)->getKey())
            j = right;
        swap(q, i, j);
    }
    while(i != j);
}


void PriorityQueue1::BuildHeap(VectorKeyValue *q){
    for(int i = q->size() - 1; i >= 0; --i)
        Max_Heapify(q,q->size(), i);
}

void PriorityQueue1::HeapSort(VectorKeyValue *q)
{
    BuildHeap(q);
    for(size_t i = q->size()-1; i > 0; --i)
    {
        swap(q, i, 0);
        Max_Heapify(q, i, 0);
    }
}

void PriorityQueue1::swap(VectorKeyValue *q,size_t index1,size_t index2){

    if(index1 == index2)
        return;
    KeyValue * temp;
    temp = q->getNode(index1);
    q->set(index1,q->getNode(index2));
    q->set(index2,temp);
}

