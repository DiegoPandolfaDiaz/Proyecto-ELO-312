//////////////////////////////////////////////////////////////
//															//
// @company : 	Competencia Robotica						//
//				Innovacion y Robotica Estudiantil			//
//				Universidad Técnica Federico Santa María	//
//															//
// @author :	Diego Pandolfa								//
// @date : 		Dec 2017									//
// 															//
// @brief : 	Función principal de Robot-Summo			//
// @description :	Software desarrollado para la			//
//					competencia All Japan Robot-Sumo		//
//					Tournament en la categoria 				//
//					Autonomo-3Kg.							//
//															//
//////////////////////////////////////////////////////////////
//#define __uC_ARDUINO_NANO__
#define __uC_MSP4301612__

#ifdef __uC_ARDUINO_NANO__
#include "Arduino.h"
#include "sumo.h"
#endif

#ifdef __uC_MSP4301612__
#include "msp430_version.h"
#include "sumo.h"
#endif

Sumo *robot = new Sumo();

int main(){
	// habilitar interrupciones
	osc_init_xt2();
    WDTCTL = WDTPW + WDTHOLD;
    
//    P3DIR |= 0x0F; // sensores inferiores
    
    P1DIR = 0xE0; //puerto 1 entrada
    P1IES = 0x1; // negedge
    P1IE = 0x1; // habilita las interrupciones de P1
    
    P1OUT=0xEF;
    
    P4DIR |= 0x06; // pwm para timer b
    P4SEL |= 0x06; //     
    

    TACCTL0 = CCIE;  
    
    TACCR0 = 10000; //timer para los sensores inferiores
    TACCR1 = 3200;
    
    TBCCTL0 = CCIE;
    
    TB0CCR0 = 100; //PWM frecuencia
    
    TB0CCR1 = 75; //ciclo 1
    TB0CCR2 = 75; //ciclo 2
    
    
    TBCCTL1= OUTMOD_7;
    TBCCTL2= OUTMOD_7; 
    
    TACCTL1= OUTMOD_7;
    
    TACTL = TASSEL_1 + MC_1;    // reloj ACLK, modo up to TCCR0
    TBCTL = TASSEL_2 + MC_1;
    
    display_init();
  //  adc_init_single_channel_single_conv_it();
    
    _BIS_SR(GIE);	// Interrupt enable
	// inicializar variables
	robot->init();
	while(true){
		calcNextState();
		actuator();
	}
	return 0;
}

#define CONV(x)      x*0.000807			// convertir x en voltaje

// INTERRUPCION PARA LEER LOS SENSORES INFERIORES
#pragma vector = TIMERA0_VECTOR
__interrupt void Timer_A (void)
{
  
   //adc_single_channel_single_conv_it(0);
  
   
}


//INTERRUPCION PARA LAS PWM
#pragma vector = TIMERB0_VECTOR
__interrupt void Timer_B (void)
{
  
   //adc_single_channel_single_conv_it(0);
   
   
}


#pragma vector = PORT1_VECTOR
__interrupt void PORT_1_VECTOR_interrupt(void){
  
	
  if(TB0CCR1==75){
    TB0CCR1=25;
  }
  else if(TB0CCR1=25){
    TB0CCR1=75;
  }
  else{
    TB0CCR1=75;
  }
  
  P1IFG = 0x0;
  
}

//rutinas de interrupcion