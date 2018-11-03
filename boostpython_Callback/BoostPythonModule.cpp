#include <boost/python.hpp>

#include "soldier.hpp"  

#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(soldier)
{
	class_<soldier>("soldier", init<std::string, unsigned int>())
        .def("init", &soldier::init)
        .def("start", &soldier::start)
        .def("stop", &soldier::stop)
		.def("greet", &soldier::greet)
		.def("setId", &soldier::setId)
		.def("getId", &soldier::getId);
}
