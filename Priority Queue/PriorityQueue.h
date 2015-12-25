///////////////////////////////////////////////////////////////
// PriorityQueue.h - class definitions of PriorityQueue      //
// Application: To implement Assignment#2                    //
// Language :   C++                                          //
// Complier :   GNU GCC                                      //
// IDE/OS   :   CodeBlocks/Windows 10                        //
// Author:      Ronak Bhuptani, SUID#429019830               //
//              (201) 755-5242, rmbhupta@syr.edu             //
///////////////////////////////////////////////////////////////

#include "Interfaces02.h"
#include "VectorKeyValue.h"
#include "VectorString.h"
#include "KeyValue.h"
#include <string>
using namespace std;
class PriorityQueue : public IPriorityQueue{
private:

    VectorKeyValue *Queue;
    VectorString *Values;
public:
    PriorityQueue() {
        Queue = new VectorKeyValue();
        Values = new VectorString();
    }
    ~PriorityQueue() {}
    void enqueue(IKeyValue * key_value);
    IVectorKeyValue * returnSorted();
    int lowestKey();
    IVectorString * lowestValues();
    void dequeue();
    size_t size();
    void showQueue();
    int KeyExist(int key);
    void heapUp();
    void heapDown();

};
