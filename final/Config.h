#pragma once
#include <iostream>
#include <sstream>
#include <vector>

#include <stdlib.h>
#include <fstream>
#include <string>


using namespace System;
using namespace std;

typedef unsigned int uint;


void setup_window() {
    Console::SetWindowSize(150, 46);
    Console::CursorVisible = true;
}

template<class T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;
    Nodo(T v, Nodo<T>* sig = NULL) {
        dato = v;
        siguiente = sig;
    }
};



