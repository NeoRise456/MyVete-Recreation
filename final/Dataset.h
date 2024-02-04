#pragma once
#include "Config.h"

class Dataset {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;
	int n;
public:
	vector<string> nombres_mascotas;
	vector<int> especie;
	vector<bool> sexo;
	vector<string> owners;
	vector<int> estados;
	vector<int> id;

	vector<string> nombres_owner;
	vector<int> ids_mascotas_owner;
	vector<int> deudas;

public:
	Dataset() {}
	~Dataset(){}
	void readPacientes() {
		fileRead.open("PACIENTES1.txt", ios::in);
		int i = 0;
		while (i < 5) {
			getline(fileRead, text);
			nombres_mascotas.push_back(text);

			getline(fileRead, text);
			n = atoi(text.c_str());
			especie.push_back(n);

			getline(fileRead, text);
			n = atoi(text.c_str());
			sexo.push_back(n);

			getline(fileRead, text);
			owners.push_back(text);

			getline(fileRead, text);
			n = atoi(text.c_str());
			estados.push_back(n);

			getline(fileRead, text);
			n = atoi(text.c_str());
			id.push_back(n);

			i++;
		}

		/*for (int i = 0; i < 5; i++) {
			cout << nombres_mascotas[i] << "|" << especie[i] << "|";
			cout << sexo[i] << "|" << owners[i] << "|" << estados[i] << "|" << id[i] << endl;
		}*/

		fileRead.close();
	}
	void readOwners() {
		fileRead.open("OWNERS.txt", ios::in);


		getline(fileRead, text);
		nombres_owner.push_back(text);
		getline(fileRead, text);
		n = atoi(text.c_str());
		ids_mascotas_owner.push_back(n);
		getline(fileRead, text);
		n = atoi(text.c_str());
		deudas.push_back(n);

		getline(fileRead, text);
		nombres_owner.push_back(text);
		getline(fileRead, text);
		n = atoi(text.c_str());
		ids_mascotas_owner.push_back(n);
		getline(fileRead, text);
		n = atoi(text.c_str());
		ids_mascotas_owner.push_back(n);
		getline(fileRead, text);
		n = atoi(text.c_str());
		deudas.push_back(n);

		getline(fileRead, text);
		nombres_owner.push_back(text);
		getline(fileRead, text);
		n = atoi(text.c_str());
		ids_mascotas_owner.push_back(n);
		getline(fileRead, text);
		n = atoi(text.c_str());
		deudas.push_back(n);

		getline(fileRead, text);
		nombres_owner.push_back(text);
		getline(fileRead, text);
		n = atoi(text.c_str());
		ids_mascotas_owner.push_back(n);
		getline(fileRead, text);
		n = atoi(text.c_str());
		deudas.push_back(n);


		/*for (int i = 0; i < 3; i++) {
			cout << nombres_owner[i] << "|" << ids_mascotas_owner[i] << "|";
			cout << deudas[i] <<  endl;
		}*/



		fileRead.close();
	}
};