#pragma once
#include "Config.h"

class Entity {
protected:
	int id;
	string nombre;
public:
	Entity(){}
	int get_id() {
		return id;
	}
	string get_nombre() {
		return nombre;
	}
};

class Patient : public Entity {
private:
	int especie;// 0 perro - 1 gato - 2 conejo
	bool sexo; //0 macho - 1 hembra
	int estado;//0 sano - 1 en recuperacion - 2 enfermo 
	string owner;
public:
	Patient(string nombre = "none", int especie = 0, bool sexo = 0,
		string owner = "none", int estado = 0, int id = 0) {

		this->nombre = nombre;
		this->especie = especie;
		this->sexo = sexo;
		this->owner = owner;
		this->estado = estado;
		this->id = id;

	}

	void set_estado(int n) {
		estado = n;
	}

	string ficha_paciente() {
		ostringstream ss;
		ss << "|| Nombre: "<< nombre << endl;
		ss << "|| ID: " << id << endl;


		ss << "|| Especie: ";
		switch (especie){
		case 0:
			ss << "Perro" << endl;
			break;
		case 1:
			ss << "Gato" << endl;
			break;
		case 2:
			ss << "Conejo" << endl;
			break;
		}

		ss << "|| Sexo: ";
		switch (sexo){
		case 0:
			ss << "Macho" << endl;
			break;
		case 1:
			ss << "Hembra" << endl;
			break;
		}

		ss << "|| Estado: ";
		switch (estado){
		case 0:
			ss << "Sano" <<endl;
			break;
		case 1:
			ss << "En Recuperacion" << endl;
			break;
		case 2:
			ss << "Enfermo" << endl;
			break;
		}

		ss << endl;

		return (ss.str());
	}

};

class Owner : public Entity {
private:
	vector<int> mascotas_id;
	long deuda;
public:
	Owner(string nombre = "none", long deuda = 0 , int id = 0) {
		this->nombre = nombre;
		this->deuda = deuda;
		this->id = id;
	}
	void agregar_id_mascota(int n) {
		mascotas_id.push_back(n);
	}
	string ficha_owner() {
		ostringstream ss;
		ss << "|| Nombre : " << nombre << endl;
		ss << "|| ID: " << id << endl;
		ss << "|| MASCOTAS: ";
		if (mascotas_id.size() != 0) {
			ss << endl;
			for (int i = 0; i < mascotas_id.size(); i++) {
				ss << "||	Mascota[" << i + 1 << "]: " << mascotas_id[i] << endl;
			}
		}
		else {
			ss << "NONE" << endl;
		}
		
		ss << "|| Deuda: " << deuda << endl;
		ss << endl;
		return (ss.str());
	}
};

class Cita {
public:
	int id_paciente;
	int hora_cita;
	int fecha_cita;
	string motivo;
	int precio;
	int id_cita;

	Cita(int id_paciente, int hora, int fecha, string motivo, int precio) {

		auto rand_id = []() {return rand() % 999 + 100; };

		this->id_paciente = id_paciente;
		this->hora_cita = hora;
		this->fecha_cita = fecha;
		this->motivo = motivo;
		this->precio = precio;
		this->id_cita = rand_id();
	}
	string toString() {
		ostringstream ss;

		ss << "Cita : ( ID paciente : ";
		ss << id_paciente;
		ss << ", Hora: ";
		ss << hora_cita;
		ss << ", Fecha[mmdd]: ";
		ss << fecha_cita;
		ss << ", Motivo: ";
		ss << motivo;
		ss << ", Precio: ";
		ss << precio;
		ss << ", ID Cita: ";
		ss << id_cita;
		ss << ")";

		return (ss.str());
	}

};