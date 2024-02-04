#pragma once
#include "Config.h"


template<class T, T vacio = -1>
class CGrafo {
private:
    // creando class arco con t info e indice vacio
    class CArco {
    public:
        T info;//info del arco
        int v;//indice del vertice
        CArco(int VLlegada) {
            info = vacio;
            v = VLlegada; //vertice a donde llega
        }
    };
    class CVertice {
    public:
        T info; //informacion del vertice
        vector<CArco*>* ady; //arcos relacionados a vertice - lista adyaencia
        CVertice() {
            info = vacio;
            ady = new vector<CArco*>();
        }
    };
    //lista de vertices
    vector<CVertice*>* vertices;
public:
    CGrafo() {
        vertices = new vector<CVertice*>();
    }

    //operaciones del CGrafo
    void adicionar_vertice(T info) {
        CVertice* vert = new CVertice(); //vertice temporal (puntero)
        vert->info = info; //le asigno el valor
        vertices->push_back(vert); //agrego el vertice
    }

    int cant_vertices() {
        return vertices->size();
    }
    T obtener_vertice(int v) {
        return (vertices->at(v))->info; //como hacer vertices[v]
    }
    void modificar_vertice(int v, T info) {
        (vertices->at(v))->info = info;
    }
    //operaciones del arco
    void adicionar_arco(int v, int vLlegada) {
        CVertice* ver = vertices->at(v); //creacion del temporal
        CArco* arc = new CArco(vLlegada); //crear un temporal del arco
        ver->ady->push_back(arc);
    }
    int cantidad_arcos(int v) {
        return (vertices->at(v))->ady->size();
    }
    T obtener_arco(int v, int apos) {
        CVertice* ver = vertices->at(v);
        return (ver->ady->at(apos))->info;
    }
    void modificar_arco(int v, int apos, T info) {
        CVertice* ver = vertices->at(v);
        (ver->ady->at(apos))->info = info;
    }
    int obtener_vertice_llegada(int v, int apos) {
        CVertice* ver = vertices->at(v);
        return (ver->ady->at(apos))->v;
    }
};