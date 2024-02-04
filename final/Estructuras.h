#pragma once
#include <functional> //lambdas

#include "Config.h"
#include "Entidad.h"

template<class T>
class ListaPacientes {
private:
    Nodo<T>* tope;
public:
    ListaPacientes() { tope = NULL; }



    void agregar_inicio(T v) {
        Nodo<T>* nuevo = new Nodo<T>(v, tope);

        auto null_diff = [](Nodo<T>* a) {return a != NULL; }; // 1

        if (null_diff(nuevo)) { //seguridad
            tope = nuevo;
        }

    }
    bool estaVacia() {
        return (tope == NULL);
    }

    void print_recursivo(Nodo<T>* aux) {
        if (aux == NULL) {
            return;
        }
        Paciente* elem = aux->dato;
        cout << elem->toString() << endl;
        print_recursivo(aux->siguiente);

    }

    void pint_pacientes() {
        if (estaVacia()) return;
        else {
            Nodo<T>* aux = tope;

            /*do {
                Paciente* elem = aux->dato;
                cout << elem->toString() << endl;
                aux = aux->siguiente;
            } while (aux != NULL);*/

            print_recursivo(aux);
        }
    }



    void pint_pacientes_estado(int n) {
        if (estaVacia()) return;
        else {
            Nodo<T>* aux = tope;
            auto diff_estado = [](int a, int b) {return a == b; }; //2


            do {
                Paciente* elem = aux->dato;
                if (diff_estado(elem->estado, n)) {
                    cout << elem->toString() << endl;
                }
                aux = aux->siguiente;
            } while (aux != NULL);
        }
    }
    void pint_pacientes_citas_info() {
        if (estaVacia()) return;
        else {
            Nodo<T>* aux = tope;
            int i = 1;
            auto diff_null = [](Nodo<T>* a) {return a != NULL; }; //8

            do {
                Paciente* elem = aux->dato;
                cout << i << ". " << elem->get_nombre() << " || Estado: " << elem->estado << " || ID: " << elem->id << endl;
                aux = aux->siguiente;
                i++;
            } while (diff_null(aux));
        }
    }
    T search_pos(uint pos) {
        Nodo<T>* aux = tope;
        for (int i = 1; i < pos; i++) {
            aux = aux->siguiente;
        }

        cout << "Paciente:";
        Paciente* p = aux->dato;
        cout << p->toString();

        return p;
    }
    T search_id(uint id) {
        Nodo<T>* aux = tope;
        bool encontrado = false;


        do {
            Paciente* elem = aux->dato;
            if (elem->id == id) {
                encontrado = true;
                break;
            }
            aux = aux->siguiente;
        } while (aux != NULL);

        if (encontrado) {
            Paciente* p = aux->dato;
            cout << "\nPaciente: " << p->get_nombre() << endl;
            cout << "Owner: " << p->owner << endl;
            return p;
        }
        else {
            return NULL;
        }


    }

    bool find_id_recursivo(Nodo<T>* aux, uint id) {
        Paciente* elem = aux->dato;
        if (aux == NULL) {
            return false;
        }

        else if (elem->id == id) {

            return true;
        }
        else {
            find_id_recursivo(aux->siguiente, id);
        }

    }

    T search_id_camiar_estado(uint id, int n) {
        Nodo<T>* aux = tope;
        bool encontrado = false;
        /*do {
            Paciente* elem = aux->dato;
            if (elem->id == id) {
                encontrado = true;
                break;
            }
            aux = aux->siguiente;
        } while (aux != NULL);*/
        encontrado = find_id_recursivo(aux, id);

        if (encontrado) {
            auto diff_null = [](Nodo<T>* a) {return a != NULL; }; //9
            auto id_comparison = [](int a, int b) {return a == b; }; //10
            do {
                Paciente* elem = aux->dato;
                if (id_comparison(elem->id, id)) {
                    encontrado = true;
                    break;
                }
                aux = aux->siguiente;
            } while (diff_null(aux));

            Paciente* p = aux->dato;
            p->set_estado(n);
            aux->dato = p;

            cout << "\nPaciente: " << p->get_nombre() << endl;
            cout << "Estado Nuevo: " << p->estado << endl;
            return p;
        }
        else {
            return NULL;
        }


    }
};

template<class T>
class PilaOwners {
private:
    Nodo<T>* tope;
public:
    PilaOwners() { tope = NULL; }
    void push(T v) {
        if (estaVacia())    tope = new Nodo<T>(v);
        else tope = new Nodo<T>(v, tope);

    }
    void modificar_pos(T dato, uint pos) {
        if (estaVacia())return;
        else {
            Nodo<T>* aux = tope;

            for (int i = 1; i < pos; i++) {

                aux = aux->siguiente;
            }

            aux->dato = dato;
        }
    }
    T pop() {
        if (estaVacia()) return NULL;
        else {
            T elemento = tope->dato;
            tope = tope->siguiente;
            return elemento;
        }
    }
    bool estaVacia() {
        return (tope == NULL);
    }

    void print_recursivo_owners(Nodo<T>* aux) {
        if (aux == NULL) {
            return;
        }
        Owner* elem = aux->dato;
        cout << elem->toString() << endl;
        print_recursivo_owners(aux->siguiente);

    }

    void pint_owners() {
        if (estaVacia()) return;
        else {
            Nodo<T>* aux = tope;

            print_recursivo_owners(aux);
        }
    }
    T search_pos(uint pos) {
        Nodo<T>* aux = tope;
        for (int i = 1; i < pos; i++) {
            aux = aux->siguiente;
        }

        cout << "Owner:";
        Owner* p = aux->dato;
        cout << p->toString();

        return p;
    }

    void agregar_deuda(int id, int deuda_extra) {
        Nodo<T>* aux = tope;
        auto aumenta_deuda = [](int a, int b) { return a + b; }; //5

        do {
            Owner* elem = aux->dato;
            for (int j = 0; j < elem->mascotas_id.size(); j++) {
                if (id == elem->mascotas_id[j]) {
                    elem->deuda = aumenta_deuda(elem->deuda, deuda_extra);
                    cout << "el Owner=> " << elem->get_nombre() << " debe: " << elem->deuda << "soles \n";
                    return;
                }
            }

            aux = aux->siguiente;

        } while (aux != NULL);


    }

    void qiutar_deuda(int id, int deuda_pagada) {
        Nodo<T>* aux = tope;
        auto resta_deuda = [](int a, int b) { return a - b; }; // 4

        do {
            Owner* elem = aux->dato;
            for (int j = 0; j < elem->mascotas_id.size(); j++) {
                if (id == elem->mascotas_id[j]) {
                    elem->deuda = resta_deuda(elem->deuda, deuda_pagada);
                    cout << "\n\n|| El Owner => " << elem->get_nombre() << " debe: " << elem->deuda << "soles \n\n";
                    return;
                }
            }

            aux = aux->siguiente;

        } while (aux != NULL);


    }

    //MERGESORT

    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Crear arreglos temporales
        vector<int> L(n1);
        vector<int> R(n2);

        // Copiar datos a los arreglos temporales L[] y R[]
        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[mid + 1 + j];
        }

        // Combinar los arreglos temporales de nuevo en arr[left...right]
        int i = 0; // Índice inicial de L[]
        int j = 0; // Índice inicial de R[]
        int k = left; // Índice inicial de arr[]

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copiar los elementos restantes de L[], si los hay
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copiar los elementos restantes de R[], si los hay
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            // Encuentra el punto medio del arreglo
            int mid = left + (right - left) / 2;

            // Ordena la primera mitad
            mergeSort(arr, left, mid);

            // Ordena la segunda mitad
            mergeSort(arr, mid + 1, right);

            // Combina las mitades ordenadas
            merge(arr, left, mid, right);
        }
    }


    void pint_owners_por_deuda_acumulada() {
        if (estaVacia()) return;
        else {
            Nodo<T>* aux = tope;
            vector<string> nombres;
            vector<int> deudas;
            vector<int> deuda2;

            do {
                Owner* elem = aux->dato;
                nombres.push_back(elem->get_nombre());
                deudas.push_back(elem->deuda);

                aux = aux->siguiente;


            } while (aux != NULL);

            deuda2 = deudas;

            //acomodando los nombres
            for (int i = 0; i < deudas.size() - 1; i++) {
                for (int j = i + 1; j < deudas.size(); j++) {
                    if (deudas[i] < deudas[j]) {
                        swap(deudas[i], deudas[j]);
                        swap(nombres[i], nombres[j]);
                    }

                }
            }

            //MERGE SORT

            mergeSort(deuda2, 0, deuda2.size() - 1);


            for (int i = 0; i < deudas.size(); i++) {
                cout << "Nombre: " << nombres[i] << " | Deuda: " << deuda2[i] << endl;
            }


        }






    }
};

template<class T>
class ColaCitas {
private:
    Nodo<T>* tope;
    Nodo<T>* fin;
    //definir lambdas

public:
    ColaCitas() { tope = NULL; fin = NULL; }
    bool estaVacia() {
        return (tope == NULL);
    }
    void enqueue(T v) {
        Nodo<T>* nodo = new Nodo<T>(v);
        if (estaVacia()) {
            tope = nodo;
            fin = tope;
        }
        else {

            fin->siguiente = nodo;
            fin = nodo;
        }
        nodo = NULL;
    }

    T dequeue() {
        if (estaVacia()) return NULL;
        else {
            auto nodo_diff = [](Nodo<T>* a, Nodo<T>* b) {return a == b; }; // 3
            T dato = tope->dato;

            if (nodo_diff(tope, fin)) {
                tope = NULL;
                fin = NULL;
            }
            else {
                tope = tope->siguiente;
            }

            return dato;

        }
    }

    T search_pos(uint pos) {
        Nodo<T>* aux = tope;
        for (int i = 1; i < pos; i++) {
            aux = aux->siguiente;
        }

        cout << "Cita:";
        Cita* p = aux->dato;
        cout << p->toString();

        return p;
    }

    void print_recursivo_cita(Nodo<T>* aux) {
        if (aux == NULL) {
            return;
        }
        Cita* elem = aux->dato;
        cout << elem->toString() << endl;
        print_recursivo_cita(aux->siguiente);

    }


    void pint_citas() {
        if (estaVacia()) return;
        else {
            Nodo<T>* aux = tope;

            print_recursivo_cita(aux);

        }
    }

};