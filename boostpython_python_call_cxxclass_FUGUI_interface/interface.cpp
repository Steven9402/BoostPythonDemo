// pymodule.cc

// this is in your boost/lib dir
#include <boost/python.hpp>

// your stuff
#include "CalculateSkuidNum.h"  


#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(CalculateSkuidNum)  // foo will be the name you import in python
{

    class_<MyList>("MyList")
        .def(vector_indexing_suite<MyList>() );

    class_<CalculateSkuidNum>("CalculateSkuidNum",   
                 init<int>())  // constructor args
        .def("start", &CalculateSkuidNum::start)  // send start signal
        .def("stop",&CalculateSkuidNum::stop)  //send stop signal
        .def("getSkuid",&CalculateSkuidNum::getSkuid)
        .def("getSkuNum",&CalculateSkuidNum::getSkuNum)
    ;    
}
