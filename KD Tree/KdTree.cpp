#include "Interfaces04.h"
#include "KdNode.h"
#include "KdTree.h"
#include <iostream>
#include <math.h>
using namespace std;

void KdTree::setRoot(IKdNode *root){
    _root = root;
}

IKdNode* KdTree::getRoot(){
    return _root;
}

void KdTree::setDim(int dim){
    _dim = dim;
}

int KdTree::getDim(){
    return _dim;
}

void KdTree::insert(std::vector<int> point){
    setRoot(insert(point,getRoot(),0));
}

IKdNode * KdTree::insert(std::vector<int> point, IKdNode * root, int level){

    if(root == NULL){
        return new KdNode(point);
    }
    else{
        std::vector<int> temp = root->getPoint();
        if(point[level] < temp[level])
            root->setLeft(insert(point,root->getLeft(),(level+1)%getDim()));
        else
            root->setRight(insert(point,root->getRight(),(level+1)%getDim()));
    }
    return root;
}

bool KdTree::search(std::vector<int> point){
    IKdNode *root = getRoot();
    int level = 0;
    while(root != NULL){
        if( root->getPoint() == point)
            break;
        else{
            std::vector<int> temp = root->getPoint();
            if(point[level] < temp[level])
                root = root->getLeft();
            else
                root = root->getRight();
            level = (level+1)%getDim();
        }
    }
    if(root == NULL)
        return false;
    if(root->getPoint() == point)
        return true;
}

IKdNode * KdTree::minimum(IKdNode * node1,IKdNode * node2,IKdNode * node3,int dim)
{
    IKdNode * result = node1;
    if(node2 != NULL && node2->getPoint()[dim] < result->getPoint()[dim])
        result = node2;
    if(node3 != NULL && node3->getPoint()[dim] < result->getPoint()[dim])
        result = node3;
    return result;
}

IKdNode * KdTree::findMin(IKdNode *root,int dim,int level){
    if(root == NULL)
        return NULL;

//    int curDim = level%getDim();

    if(level == dim){
        if(root->getLeft() == NULL)
            return root;
        else
            return findMin(root->getLeft(),dim,(level+1)%getDim());
    }
    else
        return minimum(root,findMin(root->getLeft(),dim,(level+1)%getDim()),findMin(root->getRight(),dim,(level+1)%getDim()),dim);
}

bool KdTree::remove(std::vector<int> point){
    //cout<<"Remove Called"<<endl;
    setRoot(remove(point,getRoot(),0));
    if(getRoot()!= NULL)
        return true;
    else
        return false;
}

IKdNode * KdTree::remove(std::vector<int> point,IKdNode *root,int level){
    if(root == NULL)
        return NULL;
    int next_level = (level + 1)%getDim();
    //int curDim = level    %getDim();

    if(root->getPoint() == point){
        if(root->getRight() != NULL){
            IKdNode *temp = findMin(root->getRight(),level,next_level);
            root->setPoint(temp->getPoint());
            root->setRight(remove(root->getPoint(),root->getRight(),next_level));
        }
        else if(root->getLeft() != NULL){
            IKdNode *temp = findMin(root->getLeft(),level,next_level);
            root->setPoint(temp->getPoint());
            root->setRight(remove(root->getPoint(),root->getLeft(),next_level));
            root->setLeft(NULL);
        }
        else{
           // delete root;
            return NULL;
        }
    }
    else if(point[level] <root->getPoint()[level])
        root->setLeft(remove(point,root->getLeft(),next_level));
    else
        root->setRight(remove(point,root->getRight(),next_level));

    return root;
}

double KdTree::calc2DDist(std::vector<int> point1,std::vector<int> point2)
{
    int x2 = point2[0];
    int x1 = point1[0];
    int y2 = point2[1];
    int y1 = point1[1];

    double x = pow((x2-x1),2);
    double y = pow((y2-y1),2);

    return sqrt((x + y));
}
double KdTree::calc3DDist(std::vector<int> point1,std::vector<int> point2)
{
    int x2 = point2[0];
    int x1 = point1[0];
    int y2 = point2[1];
    int y1 = point1[1];
    int z2 = point2[2];
    int z1 = point1[2];

    double x = pow((x2-x1),2);
    double y = pow((y2-y1),2);
    double z = pow((z2-z1),2);
    return sqrt((x + y + z));
}

IKdNode* KdTree::nearestNeighbor(std::vector<int> point){
    double Min = 999999999;
    IKdNode *curNode = getRoot();
    IKdNode *bestNode = curNode;
    nearestNeighbor(point,curNode,Min,bestNode);

    return bestNode;
}

void KdTree::nearestNeighbor(std::vector<int> point,IKdNode *curNode,double &min,IKdNode *&bestNode){
    if(curNode == NULL)
        return;
    double dist;
    if(getDim() == 2)
        dist = calc2DDist(point,curNode->getPoint());
    else
        dist = calc3DDist(point,curNode->getPoint());
    if(dist != 0 && dist < min){
        min = dist;
        bestNode = curNode;
    }
    nearestNeighbor(point,curNode->getLeft(),min,bestNode);
    nearestNeighbor(point,curNode->getRight(),min,bestNode);
}
