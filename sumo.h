//////////////////////////////////////////////////////////////
//															//
//	@company : 	Competencia Robotica						//
//				Innovacion y Robotica Estudiantil			//
//				Universidad Técnica Federico Santa María	//
//															//
//	@author : Diego Pandolfa								//
//	@date : Dec 2017										//
//															//
//	@brief : Definicion de la clase Sumo					//
//	@description : 	Software desarrollado para la			//
//					competencia All Japan Robot-Sumo		//
//					Tournament en la categoria 				//
//					Autonomo-3Kg.							//
//															//
//////////////////////////////////////////////////////////////
#ifndef __SUMO_H__
#define __SUMO_H__

#include "Arduino.h"

#ifndef __MACROS_GLOBAL_STATE_MACHINE__
#define __MACROS_GLOBAL_STATE_MACHINE__
#define IDLE	1
#define STOP	2
#define WAIT 	3
#define SEARCH 	4
#define FIGHT 	5
#endif

#ifndef __MACROS_SEARCH_STATE_MACHINE__
#define __MACROS_SEARCH_STATE_MACHINE__
#define SEARCH_1	11
#define SEARCH_2	12
#define SEARCH_3	13
#endif

#ifndef __MACROS_FIGHT_STATE_MACHINE__
#define __MACROS_FIGHT_STATE_MACHINE__
#define FIGHT_1		21
#define FiGHT_2		22
#define FIGHT_3		23
#endif

#ifndef __PINES_ARDUINO_NANO_SUMO__
#define __PINES_ARDUINO_NANO_SUMO__
// macros de los sensores de proximidad
#define DIFUSE_SENSOR_FL
#define DIFUSE_SENSOR_FR
#define DIFUSE_SENSOR_L 
#define DIFUSE_SENSOR_R
// macros para los sensores de linea
#define LINE_SENSOR_FL
#define LINE_SENSOR_FR
#define LINE_SENSOR_BL
#define LINE_SENSOR_BR
// macros para el driver de motor
#define ENABLE_MOTOR_L
#define ENABLE_MOTOR_R
#define PWM_MOTOR_L
#define PWM_MOTOR_R
#define CONTROL_MOTOR_L
#define CONTROL_MOTOR_R
// led indicador
#define LED_INDICATOR	13
#endif

/**
  *	@brief : 	Clase que define un Objeto del tipo Sumo, en donde se declaran todas sus funciones
  *				miembros y atributos.
  */
class Sumo
{
public:
	/**
	  *	@brief : Sumo() Constructor que crea una instancia de la clase Sumo() y reserva espacio
	  *					para todas las variables.
	  */
	Sumo();

	/**
	  *	@brief : ~Sumo() Destructor de la clase Sumo, libera el espacio solicitado por el
	  *					constructor.
	  */
	~Sumo();

	/**
	  *	@brief : int init()	Rutina que inicializa todas las variables del Robot.
	  *	@return : Retorna un 0 si la rutina se ejecutó con exito, -1 en caso contrario.
	  */
	int init();

	/**
	  *	@brief : int calcNextState()	Rutina que calcula el proximo estado en funcion del estado
	  *								actual y las variables externas.
	  *	@return : Retorna un 0 si la rutina se ejecutó con exito, -1 en caso contrario.
	  */
	int calcNextState();

	/**
	  * @brief : int actuator()	Rutina que ejecuta y actua sobre los motores segun el estado
	  *							actual de todas las máquinas de estados implementadas.
	  *	@return : Retorna un 0 si la rutina se ejecutó con éxito, -1 en caso contrario.
	  */
	int actuator();

	/**
	  *	@brief : int search()	Rutina que se encarga de ejecutar la búsqueda seteada.
	  *	@return : Retorna un 0 si la rutina se ejecuta con exito, -1 en caso contrario.
	  */
	int search();

	/**
	  * @brief : int fight()	Rutina que se encarga de ejecutar la rutina de combate
	  *							seleccionada previamente.
	  *	@return : Retorna un 0 si la rutina se ejecuta con exito. -1 en caso contrario.
	  */
	int fight();

	/**
	  * @brief : int wait()	Rutina que espera por la orden "start" del control remoto
	  *						y que luego de 5 segundos activa el estado de SEARCH
	  *	@return : Retorna un 0 si la rutina se ejecuta con exito, .1 en caso contrario.
	  */
	int wait();

	/**
	  *	@brief : int setState(int state)	Rutina que es llamada por las interrupciones
	  *										y que cambia inmediatamente el estado de la 
	  *										máquina de estados.
	  *	@param : Entero que representa el estado que se quiere forzar en la máquina de
	  *			 estados.
	  *	@return : Retorna un 0 si la rutina se ejecutó con exito, -1 en caso contrario.
	  */
	int setState(int state);

	/**
	  *	@brief : int stop()	Rutina que desabilita los motores.
	  * @return : Retorna un 0 si la rutina se ejecuto con exito, -1 en caso contrario.
	  */
	int stop();

private:

	/**
	  *	@brief : int state_global 	Variable que guarda el estado de la máquina de
	  *								estados global.
	  */
	int state_global;

	/**
	  *	@brief : int next_state_global 	Variable que guarda el proximo estado calculado
	  *									de la máquina de estados glabal.
	  */
	int next_state_global;

	/**
	  *	@brief : int state_search 	Variable que guarda el estado que setea la rutina 
	  *								de SEARCH seleccionada.
	  */
	int state_search;

	/**
	  *	@brief : int next_state_search 	Varible que guarda el proximo estado calculado
	  *									de la máquina de estado de SEARCH.
	  */
	int next_state_search;

	/**
	  *	@brief : int state_fight 	Variable que guarda el estado que setea la rutina
	  *								de FIGHT seleccionada.
	  */
	int state_fight;

	/**
	  *	@brief : next_state_fight 	Variable que guarda el proximo estado calculado de
	  *								la máquina de estado de FIGHT.
	  */
	int next_state_fight;
};
#endif