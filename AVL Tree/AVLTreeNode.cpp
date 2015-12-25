#include<iostream>
#include "AVLTreeNode.h"

using namespace std;

void AVLTreeNode::setLeft(IAVLTreeNode *left){
    _left = left;
}

void AVLTreeNode::setRight(IAVLTreeNode *right){
    _right = right;
}

void AVLTreeNode::setKey(int key){
    _key = key;
}

IAVLTreeNode * AVLTreeNode::getLeft(){
    return _left;
}

IAVLTreeNode * AVLTreeNode::getRight(){
    return _right;
}

int AVLTreeNode::getKey(){
    return _key;
}

int AVLTreeNode::getHeight(){
    if(this == NULL)
        return 0;
    return this->_height;
}

void AVLTreeNode::setHeight(int height){
    _height = height;
}
