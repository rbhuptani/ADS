#include "Interfaces04.h"
#include "AVLTree.h"
#include "AVLTreeNode.h"
#include <iostream>
using namespace std;

void AVLTree::insert(int key){
    _root = insert((AVLTreeNode *)getRoot(),key);
}

AVLTreeNode * AVLTree::insert(AVLTreeNode* root,int key){
    if(root == NULL){
        root = new AVLTreeNode();
        root->setKey(key);
        root->setHeight(1);
        root->setLeft(NULL);
        root->setRight(NULL);
        return root;
    }
    else if(key <= root->getKey()){
        AVLTreeNode *leftnode = insert((AVLTreeNode*)root->getLeft(), key);
        root->setLeft(leftnode);
    }
    else{
        AVLTreeNode *rightnode = insert((AVLTreeNode *)root->getRight(),key );
        root->setRight(rightnode);
    }
    setNewHeight(root);
    AVLTreeNode *leftNode = (AVLTreeNode*) root->getLeft();
    AVLTreeNode *rightNode = (AVLTreeNode*) root->getRight();
    int leftHeight = leftNode->getHeight();
    int rightHeight = rightNode->getHeight();
    int balance = leftHeight - rightHeight;
    if(balance > 1){
        int curKey = root->getLeft()->getKey();
        if(key < curKey)
            return rightRotate(root);
        if(key > curKey)
            return leftrightRotate(root);
    }
    else if(balance < -1){
        int curkey = root->getRight()->getKey();
        if(key > curkey)
            return leftRotate(root);
        if(key < curkey)
            return rightleftRotate(root);
    }
    return root;
}

void AVLTree::remove(int key)
{
    _root = remove((AVLTreeNode *)getRoot(), key);
}

AVLTreeNode * AVLTree::remove(AVLTreeNode* root,int key)
{
    if(root==NULL)
        return NULL;
    else if(key < root->getKey())
        root->setLeft(remove(((AVLTreeNode*)root->getLeft()),key));
    else if(key > root->getKey())
        root->setRight(remove(((AVLTreeNode*)root->getRight()),key));
    else{
        if(root->getLeft() == NULL && root->getRight() == NULL){
            delete root;
            root = NULL;
            return NULL;
        }
        else if(root->getLeft() == NULL){
            AVLTreeNode *rightChild = (AVLTreeNode*)root->getRight();
            root = rightChild;
            delete rightChild;
            rightChild = NULL;
            return root;
        }
        else if(root->getRight() == NULL){
            AVLTreeNode *leftChild = (AVLTreeNode*) root->getLeft();
            root = leftChild;
            delete leftChild;
            leftChild = NULL;
            return root;
        }
        else{
            AVLTreeNode* currentNode = (AVLTreeNode*)root->getRight();
            while(currentNode->getLeft() != NULL)
                currentNode = (AVLTreeNode*)currentNode->getLeft();
            root->setKey(currentNode->getKey());
            root->setRight(remove((AVLTreeNode*)root->getRight(),currentNode->getKey()));
        }
    }

    setNewHeight(root);
    AVLTreeNode *leftNode = (AVLTreeNode*) root->getLeft();
    AVLTreeNode *rightNode = (AVLTreeNode*) root->getRight();
    int leftHeight = leftNode->getHeight();
    int rightHeight = rightNode->getHeight();
    int balance = leftHeight - rightHeight;
    if(balance > 1){
        int curKey = root->getLeft()->getKey();
        if(key < curKey)
            return rightRotate(root);
        if(key > curKey)
            return leftrightRotate(root);
    }
    else if(balance < -1){
        int curkey = root->getRight()->getKey();
        if(key > curkey)
            return leftRotate(root);
        if(key < curkey)
            return rightleftRotate(root);
    }
    return root;
}

int AVLTree::kthMin(int k){
    return kthMin((AVLTreeNode *)getRoot(),k);
}

int AVLTree::leftNodes(AVLTreeNode *root){
    if(root == NULL)
        return 0;
    AVLTreeNode *leftNode = (AVLTreeNode*) root->getLeft();
    AVLTreeNode *rightNode = (AVLTreeNode*) root->getRight();
    return (leftNodes(leftNode) + leftNodes(rightNode) + 1 );
}

int AVLTree::kthMin(AVLTreeNode* root,int k){
    int num_leftnodes = leftNodes((AVLTreeNode*)root->getLeft());

    if(num_leftnodes == k)
        return root->getKey();
    else if(num_leftnodes > k )
        kthMin((AVLTreeNode*)root->getLeft(),k);
    else
        kthMin((AVLTreeNode*)root->getRight(),k - num_leftnodes -1);
}

IAVLTreeNode * AVLTree::getRoot(){
    return _root;
}

AVLTreeNode * AVLTree::rightRotate(AVLTreeNode *node){
    AVLTreeNode *leftNode = (AVLTreeNode *) node->getLeft();
    AVLTreeNode *right_of_leftNode = (AVLTreeNode *)  leftNode->getRight();

    leftNode->setRight(node);
    node->setLeft(right_of_leftNode);

    setNewHeight(node);
    setNewHeight(leftNode);

    return leftNode;
}

AVLTreeNode * AVLTree::leftRotate(AVLTreeNode *node){
    AVLTreeNode *rightNode = (AVLTreeNode *) node->getRight();
    AVLTreeNode *left_of_rightNode = (AVLTreeNode *)rightNode->getLeft();

    rightNode->setLeft(node);
    node->setRight(left_of_rightNode);

    setNewHeight(node);
    setNewHeight(rightNode);


    return rightNode;
}

AVLTreeNode *AVLTree::rightleftRotate(AVLTreeNode *node){
    node->setRight(rightRotate((AVLTreeNode*)node->getRight()));
    return leftRotate(node);
}

AVLTreeNode *AVLTree::leftrightRotate(AVLTreeNode *node){
    node->setLeft(leftRotate((AVLTreeNode*)node->getLeft()));
    return rightRotate(node);
}
void AVLTree::setNewHeight(AVLTreeNode *node){
    int leftHeight = ((AVLTreeNode*) node->getLeft())->getHeight();
    int rightHeight = ((AVLTreeNode*) node->getRight())->getHeight();
    node->setHeight(getMax(leftHeight,rightHeight)  + 1);
}

int AVLTree::getMax(int x,int y){
    return x>y ? x : y;
}
