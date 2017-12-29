//////////////////////////////////////////////////////////////
//															//
//	@company : 	Competencia Robotica						//
//				Innovacion y Robotica Estudiantil			//
//				Universidad Técnica Federico Santa María	//
//															//
//	@author : Diego Pandolfa								//
//	@date : Dec 2017										//
//															//
//	@brief : Implementación de la clase Sumo				//
//	@description : 	Software desarrollado para la			//
//					competencia All Japan Robot-Sumo		//
//					Tournament en la categoria 				//
//					Autonomo-3Kg.							//
//															//
//////////////////////////////////////////////////////////////
#include "sumo.h"

void spin_left(void);
void forward(void);
int read_proximity(void);

Sumo::Sumo(){
	state_global = 0;
	next_state_global = 0;
	state_search = 0;
	next_state_search = 0;
	state_fight = 0;
	next_state_fight = 0;
}

Sumo::~Sumo(){

}

int Sumo::init(){
	state_global = IDLE;
	next_state_global = IDLE;
	state_search = IDLE;		// <---- llamar a una funcion que lea el puerto asociado a los switch y setear este estado segun corresponda.
	next_state_search = state_search; 	// Por ahora no implementado
	state_fight = IDLE;		// <---- llamar a una funcion que lea el puerto asociado a los switch y setear este estado segun corresponda.
	next_state_fight = state_fight; // por ahora no implementado.
	return 0;
}

int Sumo::calcNextState(){
	switch(state_global){
		case IDLE :
			next_state_global = STOP;
			break;
		case STOP :
			next_state_global = STOP;
			break;
		case WAIT :
			next_state_global = SEARCH;
			break;
		case SEARCH :
			next_state_global = SEARCH; // se cambia por interrupcion
			break;
		case FIGHT :
			next_state_global = SEARCH; // <---- llamar a una funcion que lea el puerto asociado a los switch y setear este estado segun corresponda.
			break;
		default :
			next_state_global = IDLE;
			break;
	}
	state_global = next_state_global;
	return 0;
}

int Sumo::actuator(){
	switch(state_global){
		case IDLE :
			asm("NOP"); // se deben setear las condiciones iniciales de todos los puertos.
			break;
		case STOP :
			asm("NOP"); // se deben desabilitar los motores 
			break;
		case WAIT :	// ademas, se deben desabilitar los motores
			delay(5000);
			break;
		case SEARCH :
			this->search();
			break;
		case FIGHT :
			this->fight();
			break;
		default :
			asm("NOP");
			break;
	}
	return 0;
}

int Sumo::search(){
	switch(){
		case SEARCH_1 :
			spin_left();
			break;
		case SEARCH_2 :
			break;
		case SEARCH_3 :
			break;
		default :
			break;
	}
	return 0;
}

int Sumo::fight(){
	switch(){
		case FIGHT_1 :
			int sensor = read_proximity();
			if(sensor == 1){
				state_global = SEARCH;
			}
			forward();
			break;
		case FIGHT_2 :
			break;
		case FIGHT_3 :
			break;
		default :
			break;
	}
	return 0;
}

int Sumo::wait(){

}

int Sumo::setState(int state){
	state_global = state;
	return 0;
}

int Sumo::stop(){

	return 0;
}