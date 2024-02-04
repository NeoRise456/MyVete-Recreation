#pragma once
#include "Config.h"
#include "Entidad.h"

class Boleta {
	Cita* cita_realizada;
	ofstream fileWrite;
	string text;
public:
	Boleta(Cita* cita_realizada) {
		this->cita_realizada = cita_realizada;
	}
	void imprimir_boleta() {
		cout << "\n || Boleta de servicio || \n";
		//servicio
		cout << "servicio: Cita" << endl;
		//motivo
		cout << "Motivo: " << cita_realizada->motivo << endl;
		//mascota
		cout << "ID Mascota :" << cita_realizada->id_paciente << endl;

		fileWrite.open("Boletas.txt", ios::out);
		fileWrite << "Cita |" << cita_realizada->motivo << "|" << cita_realizada->id_paciente << endl;
		fileWrite.close();
	}


};

class Security {
	ofstream fileWrite;
	string text;
public:
	Security() {}
	void registrar_nueva_cita() {
		fileWrite.open("Sec.txt", ios::out);
		fileWrite << "MOV : Nueva Cita" << endl;
		fileWrite.close();
	}
	void registrar_nuevo_Owner() {
		fileWrite.open("Sec.txt", ios::out);
		fileWrite << "MOV : Nuevo Owner" << endl;
		fileWrite.close();
	}
	void registrar_nuevo_paciente() {
		fileWrite.open("Sec.txt", ios::out);
		fileWrite << "MOV : Nuevo Paciente" << endl;
		fileWrite.close();
	}
	void registrar_cita_atendida() {
		fileWrite.open("Sec.txt", ios::out);
		fileWrite << "MOV : Cita Atendida" << endl;
		fileWrite.close();
	}
	void registrar_mod_Paciente() {
		fileWrite.open("Sec.txt", ios::out);
		fileWrite << "MOV : Paciente Modificado" << endl;
		fileWrite.close();
	}


};