#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "hello.h"


// Method hello of module hello.
// first hello is module name, second is function name.
// The function expects a single unicode string argument and 
// returns a python unicode string or NULL if an exception occurred. 
static PyObject *hello_hello(PyObject *self, PyObject *args) {
    const char *inStr;
    if (!PyArg_ParseTuple(args, "s", &inStr))
        return NULL;
	
    // assert inStr is a utf8 encoded C string
	
    // call the wrapped C function returning a heap allocated utf8 c string
    // or NULL when the heap allocation failed.
    const char *outStr = hello(inStr);
    if (outStr == NULL)
        return PyErr_NoMemory();

    // return the utf8 C string as a python unicode string
    PyObject *tmp = PyUnicode_DecodeUTF8(outStr, strlen(outStr), NULL);
    free((char*)outStr);
    return tmp;
}

// Module’s method table and initialization function. 
static PyMethodDef hello_methods[] = {
    {"hello",  (PyCFunction)hello_hello, METH_VARARGS, "hello function"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

// Module definition structure.
static struct PyModuleDef hellomodule = {
    PyModuleDef_HEAD_INIT,
    "hello",   // name of module
    "doc string for hello module", // module documentation, may be NULL
    -1,        // size of per-interpreter state of the module,
               // or -1 if the module keeps state in global variables.
    hello_methods
};

// Module initialization function.
PyMODINIT_FUNC PyInit_hello_ext(void) {
    return PyModule_Create(&hellomodule);
}
