//包含boost::python头文件
#include <boost/python.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>
namespace bp = boost::python;
using namespace std;

bp::object py_serial;

struct weight{
    float g0;
    float g1;
    float g2;
    float g3;
};

void setEnv()
{
    try {
        Py_Initialize();

        bp::object sys = bp::import("sys");
        sys.attr("path").attr("append")(boost::python::str("../py_serial/"));

        for (int i = 0; i < bp::len(sys.attr("path")); ++i) {
            string str2 = bp::extract<string>(boost::python::getitem(sys.attr("path"), bp::object(i)));
            cout << "Have: " << str2 << endl;
        }

        bp::object os = bp::import("os");
        py_serial = bp::import("py_serial");
    }
    catch (...) {
        PyErr_Print();
    }
}

bool getWeight(string& line,weight& mweight){
    //count the num of ',' to verify
    if(line.length()<8)return false;

    int countcomma=0;
    vector<int> pos;

    int ind=0;
    for(auto c:line){
        if(c==','){
            pos.push_back(ind);
            countcomma++;
        }
        ind++;
    }
    if(countcomma!=4)return false;

    if(pos[3]>line.length())return false;

    //get weight
    string g0=line.substr(0,pos[0]-0);
    string g1=line.substr(pos[0]+1,pos[1]-pos[0]-1);
    string g2=line.substr(pos[1]+1,pos[2]-pos[1]-1);
    string g3=line.substr(pos[2]+1,pos[3]-pos[2]-1);

    mweight.g0=atof(g0.c_str());
    mweight.g1=atof(g1.c_str());
    mweight.g2=atof(g2.c_str());
    mweight.g3=atof(g3.c_str());
    return true;
}

int main(){
    setEnv();

    int loopcount=1;
    while(1){
        loopcount++;

        bp::object pline = py_serial.attr("readLinefromSerialPort")();
        string line = bp::extract<string>(pline);

        cout<<line<<endl;
        cout<<"------------------------"<<endl;

        weight mweight;
        bool suc = getWeight(line,mweight);
        if(suc){
            cout<<"g0 = "<<mweight.g0<<" g"<<endl;
            cout<<"g1 = "<<mweight.g1<<" g"<<endl;
            cout<<"g2 = "<<mweight.g2<<" g"<<endl;
            cout<<"g3 = "<<mweight.g3<<" g"<<endl;
            cout<<"************************"<<endl;
        }
    }
    return 1;
}
