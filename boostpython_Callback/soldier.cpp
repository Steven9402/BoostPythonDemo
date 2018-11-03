#include <boost/python.hpp>
#include "soldier.hpp"
#include <iostream>

using namespace boost::python;

PyObject *py_callback = NULL;
bool soldier::_isStarted = false;

// initialization
int soldier::init(PyObject* callable)
{
    py_callback = callable;

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_t threadId;

    int ret = pthread_create(&threadId, &attr, &actionFunc, (void*)0);
    if (0 != ret) {
        pthread_attr_destroy(&attr);
        return -1;
    } else {
        pthread_detach(threadId);
        pthread_attr_destroy(&attr);
        return 0;
    }
}

std::string soldier::greet()
{
    std::stringstream sstm;
    sstm << "hello, I'm " << _name << ", ID is " << _id;
    return sstm.str();
}

void* soldier::actionFunc(void*)
{
    while (true)
    {
        if (_isStarted)
        {
            srand((int)time(0));
            int killed = rand() % 100;
            usleep(1000 * 1000); // 1s
            PyEval_InitThreads();
            PyGILState_STATE state = PyGILState_Ensure();
            boost::python::call<void>(py_callback, killed);
            PyGILState_Release(state);
        }
    }
    return NULL;
}
