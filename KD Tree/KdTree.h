#include "Interfaces04.h"
#include "KdNode.h"


class KdTree : public IKdTree{
private:
    IKdNode *_root = NULL;
    int _dim;
public:
    KdTree() { }
    ~KdTree() { }
    void setRoot(IKdNode *root);
    IKdNode* getRoot();
    void setDim(int dim);
    int getDim();
    void insert(std::vector<int> point);
    IKdNode * insert(std::vector<int> point, IKdNode * root, int level);
    bool search(std::vector<int> point);
    bool remove(std::vector<int> point);
    IKdNode* remove(std::vector<int> point,IKdNode *root,int level);
    IKdNode* nearestNeighbor(std::vector<int> point);
    void nearestNeighbor(std::vector<int> point,IKdNode *curNode,double &min,IKdNode *&bestNode);
    IKdNode* findMin(IKdNode *root,int dim,int level);
    IKdNode * minimum(IKdNode * node1,IKdNode * node2,IKdNode * node3,int dim);
    double calc2DDist(std::vector<int> point1,std::vector<int> point2);
    double calc3DDist(std::vector<int> point1,std::vector<int> point2);
};
