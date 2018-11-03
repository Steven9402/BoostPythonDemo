#include <vector>
#include <string.h>
#include "stdlib.h"
using namespace std;
typedef vector<int> MyList;

class CalculateSkuidNum {
private:
    MyList mSkuid;
    MyList mSkuNum;
    bool loop;
public:
    CalculateSkuidNum(int a);  // constructor , load DNN models
   
    bool start(); // start to calculating skuid skunum
    bool stop();
    MyList getSkuid();
    MyList getSkuNum();
};

