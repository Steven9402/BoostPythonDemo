#include <string>

class soldier
{
public:
        soldier(std::string name, unsigned int id)
    : _name(name), _id(id) {}
    virtual ~soldier() {}

    int init(PyObject* callable);
    int start() { _isStarted = true; }
    int stop() { _isStarted = false; }
    std::string greet();
    void setId(unsigned int id) { this->_id = id; }
	int getId() { return _id; }

    static bool _isStarted;

private:
    static void* actionFunc(void*);
    std::string _name;
    unsigned int _id;
};
