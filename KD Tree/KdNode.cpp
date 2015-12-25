#include "Interfaces04.h"
#include "KdNode.h"
#include<iostream>
using namespace std;

void KdNode::setPoint(std::vector<int> point){
    _point.clear();
    _point = point;
}

std::vector<int> KdNode::getPoint(){
    return _point;
}

void KdNode::setLeft(IKdNode *left){
    _left = left;
}

IKdNode* KdNode::getLeft(){
    return _left;
}

void KdNode::setRight(IKdNode *right){
    _right = right;
}

IKdNode* KdNode::getRight(){
    return _right;
}
