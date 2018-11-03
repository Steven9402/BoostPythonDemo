char const* greet()
{
   return "hello, world";
}

#include <boost/python.hpp>
BOOST_PYTHON_MODULE(hello) // hello_ext will be the name you import in python
{
    using namespace boost::python;
    def("greet", greet); //将函数greet的名称定义为"greet"
}

