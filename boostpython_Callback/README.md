###这是一个在python中使用c++类 并且使用回调函数的样例

在c++的耗时操作```actionFunc```中，
启用线程```PyEval_InitThreads```
调用python中的函数```py_callback```,并且向其中传递参数```"killed"```。


