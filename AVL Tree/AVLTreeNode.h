#pragma once
#include "Interfaces04.h"

class AVLTreeNode : public IAVLTreeNode{

private :
    IAVLTreeNode *_left=NULL;
    IAVLTreeNode *_right=NULL;
    int _key;
    int _height;

public :
    AVLTreeNode() { }
    AVLTreeNode(int key){
        _height = 1;
        _key = key;
        _left = NULL;
        _right = NULL;
    }
    ~AVLTreeNode() { }
    void setLeft(IAVLTreeNode *left);
    void setRight(IAVLTreeNode *right);

    void setKey(int key);
    IAVLTreeNode * getLeft();
    IAVLTreeNode * getRight();

    int getKey();
    int getHeight();
    void setHeight(int height);
};
