#include "Interfaces04.h"
#include "AVLTreeNode.h"
class AVLTree : public IAVLTree{
private:
    IAVLTreeNode *_root= NULL;

public :
    AVLTree() { }
    ~AVLTree() { }

    void insert(int key);
    AVLTreeNode * insert(AVLTreeNode* root,int key);

    void remove(int key);
    AVLTreeNode * remove(AVLTreeNode* root,int key);

    int kthMin(int k);
    int kthMin(AVLTreeNode* root, int k);
    int leftNodes(AVLTreeNode *root);
    IAVLTreeNode * getRoot();


    AVLTreeNode *rightRotate(AVLTreeNode *node);
    AVLTreeNode *leftRotate(AVLTreeNode *node);
    AVLTreeNode *rightleftRotate(AVLTreeNode *node);
    AVLTreeNode *leftrightRotate(AVLTreeNode *node);

    void setNewHeight(AVLTreeNode *node);
    int getHeight(AVLTreeNode *node);
    int getMax(int x,int y);
};
