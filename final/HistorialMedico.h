#pragma once
#include "Config.h"

template <typename T>
class HashEntity {
	int key;
	T value;
public:
	HashEntity(int key, T value) {
		this->key = key;
		this->value = value;
	}
	int getkey() { return key; }
	T getvalue() { return value; }
};

template <typename T>
class HashTable {
	HashEntity<T>** table;
	int table_size;
	int num_elementos;

public:
	HashTable(int table_size = 10) {
		this->table_size = table_size;

		table = new HashEntity<T> * [table_size];
		for (int i = 0; i < table_size; ++i) {
			table[i] = nullptr;
		}

		num_elementos = 0;
	}

	int hashFunction(int key) {
		return key % table_size;
	}

	void insertItem(int key, T value) {
		//si la tabla esta llena
		if (num_elementos == table_size)return;

		//hallamos el id
		int base = hashFunction(key);
		int hashvalue = base;
		int step = 0;

		cout << "el Hash value es[ID]:" << hashvalue << endl;

		//si no hay espacio
		while (table[hashvalue] != nullptr) {
			hashvalue = (base + step) % table_size;
			step++;

			cout << "(" << base << ' + ' << step << ')' << ' % ' << table_size << endl;
			cout << "New Hash value:" << hashvalue << endl;

		}
		table[hashvalue] = new HashEntity(key, value);
		num_elementos++;
	}

	void deleteItem(int key) {
		int hashvalue = hashFunction(key);
		table[hashvalue] = nullptr;
	}

	void print_hastable() {
		int hashvalue;
		for (int key = 0; key < table_size; key++) {
			hashvalue = hashFunction(key);
			if (table[hashvalue] != nullptr) {
				//cout << key << " || " << table[hashvalue]->getvalue() << endl;
				cout << key << " || " << " WIP " << endl;
			}
			else {
				cout << key << " || " << -1 << endl;
			}

		}
	}

	T buscar(int key_element) {
		int hashvalue;
		for (int key = 0; key < table_size; key++) {
			hashvalue = hashFunction(key);
			if (hashFunction(key_element) == hashFunction(key)) {
				if (table[hashvalue] == nullptr) {
					return table[hashvalue]->getvalue();
				}
				else {
					return -1;
				}
			}
		}
	}

	int size() {
		return table_size;
	}
	int sizeactual() {
		return num_elementos;
	}

};

