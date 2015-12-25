#pragma once
#include "Interfaces04.h"
#include <vector>
using namespace std;
class KdNode : public IKdNode{
private :
    vector<int> _point;
    IKdNode *_left;
    IKdNode *_right;
public:
    KdNode() {
        _left = NULL;
        _right = NULL;
    }
    KdNode(std::vector<int> newPoint){
        _point = newPoint;
        _left = NULL;
        _right = NULL;
    }
    ~KdNode() { }
    void setPoint(std::vector<int> point);
    std::vector<int> getPoint();
    void setLeft(IKdNode *left);
    IKdNode* getLeft();
    void setRight(IKdNode *right);
    IKdNode* getRight();

};
