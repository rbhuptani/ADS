///////////////////////////////////////////////////////////////
// PriorityQueue.cpp - class definitions of PriorityQueue    //
// Application: To implement Assignment#2                    //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////

#include "Interfaces02.h"
#include "PriorityQueue.h"
#include<iostream>
#include <string>
using namespace std;

void PriorityQueue::enqueue(IKeyValue * key_value){

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
    if(Queue->size() > 1)
			heapUp();

}
int PriorityQueue::KeyExist(int key){
    size_t i = Queue->size();
    size_t j=0;
    while(j!=i){
        if(Queue->getNode(j)->getKey() == key)
            return j;
        j++;
    }
    return -1;
}

IVectorKeyValue * PriorityQueue::returnSorted(){
    return NULL;
}

int PriorityQueue::lowestKey(){
    return Queue->getNode(0)->getKey();
}

IVectorString * PriorityQueue::lowestValues(){
    IVectorString *result = new VectorString();
	for(int j = 0; j < Queue->getNode(0)->getVectorStringValues()->size(); j++)
		result->push_back(Queue->getNode(0)->getVectorStringValues()->get(j));
	return result;
}

void PriorityQueue::dequeue(){
    if(Queue->size() <= 0)
		return;
	else
	{
		Queue->set(0, Queue->getNode(Queue->size() - 1));
		Queue->pop_back();
		if(Queue->size() > 0)
			heapDown();
	}
}
size_t PriorityQueue::size(){
    return Queue->size();
}

void PriorityQueue::showQueue(){

    size_t i = Queue->size();
    size_t j=0;
    while(j!=i){
        cout<<endl<<Queue->getNode(j)->getKey()<<"  ::  "<<Queue->getNode(j)->getValue();
        j++;
    }
    cout<<endl;
}
void PriorityQueue::heapUp()
{
	int current = Queue->size() - 1;
	int parent = (current - 1) / 2;
	while(Queue->getNode(parent)->getKey() > Queue->getNode(current)->getKey() && parent >= 0)
	{
		KeyValue * tempNode = Queue->getNode(parent);
		Queue->set(parent, Queue->getNode(current));
		Queue->set(current, tempNode);
		current = parent;
		parent = (current - 1) / 2;
	}
}
void PriorityQueue::heapDown()
{
	int parent = 0;
	int size = Queue->size();
	int left = 2 * parent + 1;
	int right = 2 * parent + 2;
	int smallest = parent;

	while(left < size)
	{
		if(Queue->getNode(left)->getKey() < Queue->getNode(parent)->getKey())
			smallest = left;
		if(right < size && Queue->getNode(right)->getKey() < Queue->getNode(smallest)->getKey())
			smallest = right;
		if(smallest != parent)
		{
			KeyValue * tempNode = Queue->getNode(parent);
			Queue->set(parent, Queue->getNode(smallest));
			Queue->set(smallest, tempNode);
			parent = smallest;
			left = 2 * parent + 1;
			right = 2 * parent + 2;
		}
		else
			left = size + 1;
	}
}
