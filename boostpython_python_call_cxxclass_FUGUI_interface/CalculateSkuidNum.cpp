#include "CalculateSkuidNum.h"

CalculateSkuidNum::CalculateSkuidNum(int a){  // constructor , load DNN models
    loop=false;
}   
bool CalculateSkuidNum::start(){
    loop=true;

    int loopcount=0;
    while(loopcount<50){
        // do something here
	loopcount++;
       
	mSkuid.push_back(loopcount);
        mSkuNum.push_back(loopcount);
    }
    
    return true;
}

bool CalculateSkuidNum::stop(){
    loop=false;
    return true;
}

MyList CalculateSkuidNum::getSkuid(){return mSkuid;}
MyList CalculateSkuidNum::getSkuNum(){return mSkuNum;}


