#include "pch.h"
#include "Estructuras.h"
#include "Config.h"
#include "Dataset.h"
#include "Entidad.h"
#include "HistorialMedico.h"
#include "Grafo.h"

int main() {
	setup_window();
	
	//dataread y hashtable
	Dataset* data = new Dataset();
	HashTable<int>* historial = new HashTable<int>(200);

	data->readPacientes();
	data->readOwners();


	//
	ListaPacientes<Patient*>* listaPacientes = new ListaPacientes<Patient*>();

	//empresa

	//grafos
	// HABITACIONES VACIAS 
	

	//arboles binario
	//
	// tranajadores-> jefe medcio, especialista, un aistente y tencino
	// 
	// 

	int  i = 0;
	while (i < 5) {
	    /*pacientes->push(new Paciente(data->nombres_mascotas[i],
	        data->especie[i], 
	        data->sexo[i], 
	        data->owners[i], 
	        data->estados[i], 
	        data->id[i]));*/
	    
		Patient* a = new Patient(data->nombres_mascotas[i],
			data->especie[i],
			data->sexo[i],
			data->owners[i],
			data->estados[i],
			data->id[i]);
		cout<< a->ficha_paciente();
		listaPacientes->agregar_inicio(a);
		i++;
	}

	

	//historial->print_hastable();

	system("pause>0");
	return 0;
}
