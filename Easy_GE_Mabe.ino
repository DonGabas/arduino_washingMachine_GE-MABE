/**
 * firmware para manejar la tarjeta 189D3632G006 amazonia
 * de la lavadora GE modelo TL1003PB0
 * version 1.0.0
 * 
 * por: Gabaniel Guerrero
 */
/***********************************************************/
/*                 Tiempo de config                        */

/******** real *****************/
#define manchasd_lavar 2401                         // ciclos de lavada : 20 min
#define manchasd_enjuagar 961                       // ciclos de lavada : 8 min
#define blancos_lavar 2161                          // ciclos de lavada : 18 min
#define blancos_enjuagar 961                        // ciclos de lavada : 8 min
#define color_lavar 1801                            // ciclos de lavada : 15 min
#define color_enjuagar 840                          // ciclos de lavada : 7 min
#define cama_lavar 2161                             // ciclos de lavada : 18 min
#define cama_enjuagar 840                           // ciclos de lavada : 7 min
#define delicada_lavar 1681                         // ciclos de lavada : 14 min
#define delicada_enjuagar 720                       // ciclos de lavada : 6 min
#define espress_lavar 1201                          // ciclos de lavada : 10 min
#define espress_enjuagar 600                        // ciclos de lavada : 6 min
#define remojo 255                                  // ciclos de lavada : 15 min
#define exprimirL 240000UL                          // milisegundos centrifugado continuo: 4 min
#define exprimirF 480000UL                          // milisegundos centrifugado continuo: 8 min

#define exp_cicloI 30                               // ciclos menores con powOne y powOne_
#define exp_cicloII 50                              // ciclos menores con powTwo y powTwo_
#define exp_cicloIII 75                             // ciclos menores con powThree y powThree_interUp
#define t_drenado 240000UL                          // timepo en que la bomba ya deberia haber vaciado la tina
#define t_tapa 10000UL                               // tiempo en que deberia haber activado el seguro de la tapa

#define powOne 2000UL                               // motor en ccw encendido para acomodo de la ropa fase 1
#define powOne_ 5000UL                              // motor en ccw apagado para acomodo de la ropa fase 1
#define powTwo 3000UL                               // motor en ccw encendido para acomodo de la ropa fase 2
#define powTwo_ 5000UL                              // motor en ccw apagado para acomodo de la ropa fase 2
#define powThree 4000UL                             // motor en ccw encendido para acomodo de la ropa fase 3
#define powThree_ 6000UL                            // motor en ccw apagado para acomodo de la ropa fase 3

#define t_irocio 120000UL                           // tiempo para comenzar el rociado en centrifugado
#define t_rocio 30000UL                             // periodo de rociado en centrifugado
#define toEnd 120000UL                               // tiempo muerto al culminar

/******* para depurar  ******
#define manchasd_lavar 41
#define manchasd_enjuagar 31
#define blancos_lavar  37
#define blancos_enjuagar 27
#define color_lavar 35
#define color_enjuagar 25
#define cama_lavar 39
#define cama_enjuagar 29
#define delicada_lavar 29
#define delicada_enjuagar 19
#define espress_lavar 23
#define espress_enjuagar 17
#define remojo 25
#define exprimirL 4000UL
#define exprimirF 6000UL

#define exp_cicloI 8
#define exp_cicloII 14
#define exp_cicloIII 17
#define t_drenado 3000UL
#define t_tapa 1500UL

#define powOne 500UL
#define powOne_ 1000UL
#define powTwo 1000UL
#define powTwo_ 1500UL
#define powThree 1500UL
#define powThree_ 2000UL

#define t_irocio 1000UL
#define t_rocio 500UL
#define toEnd 3000UL 
*/
/***********************************************************/

#define tunningU 200UL                              // tiempo de encendido del motor en calibracion
#define tunningD 1000UL                             // tiempo de apagado del motor en calibracion
#define motorL_up 300UL                             // tiempo de encendido del motor en normal
#define motorL_down 1700UL                          // tiempo de apagada del motor en normal
#define motorLF_up 400UL                            // tiempo de encendido del motor en lavado fuerte
#define motorLF_down 1600UL                         // tiempo de apagado del motor en lavado fuerte
#define motorLD_up 300UL                            // tiempo de encendido del motor en lavado delicado
#define motorLD_down 1700UL                         // tiempo de apagado del motor en lavado delicado
#define motorR_up 500UL                             // tiempo de encendido del motor en remojo
#define motorR_down 11500UL                         // tiempo de apagado del motor en remojo

/******************************/

/***********************************************************/
#define INTER_ALARM_LEDS 200UL                   // intervalo on/off para los leds en estado de error
#define INTER_PAUSA_LEDS 200UL                   // intervalo on/off para un led en estado de pausa
#define antirebote 300UL                         // intervalo antirebote


//############################################################
// numeros de pin usados
const byte pinTempAgua = A0;                     // selector de temperatura de agua
const byte pinProgLavado = A1;                   // selector programa de lavado
const byte pinPresostato = A2;                   // señal de presostato lleno/no lleno
const byte pinTapa = A3;                         // señal boton Seleccion de funcion
const byte pinInicioPausa = 2;                   // señal boton Inicio-Pausa
const byte pinSeleccion = 3;                     // señal boton Seleccion de funcion
const byte pinMotorCW = 4;                       // Motor on derecha
const byte pinMotorCCW = 5;                      // Motor on izquierda
const byte pinValvulaC = 6;                      // Electrovalvula para agua fria
const byte pinValvulaH =7;                       // Electrovalvula para agua caliente
const byte pinBomba = 8;                         // Bomba de desague
const byte pinLedExprimir = 9;                   // Led tablero exprimir
const byte pinLedEnjuagar = 10;                  // Led tablero enjuagar
const byte pinLedLavar = 11;                     // Led tablero lavar
const byte pinLedRemojo = 12;                    // Led tablero remojo
const byte pinLedTapa = 13;                      // Led tablero seguro tapa

//############################################################
// Variables

unsigned long INTERVALO_CW;                     // intervalo on/off para motot sentido horario
unsigned long INTERVALO_CCW;                    // intervalo on/off para motot sentido anti horario
unsigned long INTERVALO_LED;                    // intervalo on/off para led especifico
unsigned long e_principal;
unsigned long e_temp;
unsigned long e_ch_cw;                          // evento para cambio del estado del motor en CW    mov lavado
unsigned long e_ch_ccw;                         // evento para cambio del estado del motor en CCW   mov lavado
unsigned long e_e_cwF;                          // evento para cambio del estado del motor en CW   mov exprimido continuo
unsigned long e_led_chch;                       // evento para cambio del estado del led en chacachaca
unsigned long e_reboteS;                        // evento para cambio del estado de los pulsadores
unsigned long e_reboteIP;                       // evento para cambio del estado de los pulsadores
unsigned long e_reboteP;                        // evento para cambio del estado presostato
unsigned long e_reboteLT;                       // evento para cambio del estado lock tapa
unsigned long blink;                            // evento para cambio de estado en los led en estado de alarma
unsigned long blinkP;                           // evento para cambio de estado en led en estado de pausa
unsigned long endWork;                          // evento para cambio de estado en el tiempo muerto al terminar un ciclo de lavado
unsigned long drenado;                          // evento para tiempo muerto despues del drenado (presostato)
unsigned long e_bomba;                          // evento para el cual deberia haberse drenado
unsigned long lockT;                            // evento para el cual deberia haberse activado el seguro de la tapa
unsigned long interUp;                          // tiempo que estara encendido el motor
unsigned long interDown;                        // tiempo que estara apagado el motor

bool alarmStatus;                               // estado de alarma
bool aguaTop;                                   // estado del presostato
bool tapaLock;                                  // seguro de la tapa
bool v_leds[5] = {0, 0, 1, 1, 1};               // estados de los leds {tapa,remojo,lavar,enjuagar,exprimir}
bool v_funcion[5] = {0, 1, 1, 1, 1};            // estado definidos para programacion de lavada {remojo,lavar,enjuagar,exprimir,exprimir-lavado}
bool v_fcopia[5] = {0, 1, 1, 1, 1};             // copia de v_funcion[] para ir eliminando conforme se han hecho
bool cw;                                        // estado para alternar los cambios de estado en CW
bool ccw;                                       // estado para alternar los cambios de estado en CCW
bool OFF;                                       // lavadora encendida o apagada
bool est;                                       // bandera para funcion lavado
bool aguaDone;                                  // estado de seguridad de que está llena la tina
bool flag_exp;                                  // estado para esperar drenar el agua para centrifugado
bool flag_PL;                                   // permite o bloquea el cambio de estado la programacion del lavado
bool updateLeds;                                // para actualizar los leds
bool chcchc;                                    // para saber si está en chacachaca
bool flag_bomba;                                // evento para comenzar el drenado
bool flag_onWork;                               // trabajando: true, en espera: false
bool isWork;                                    // estado lavadora trabando
bool flag_llenado;                              // true: se esta llenando, false: no
bool pausa;                                     // estado de pausa definido por el pulsador
bool istDone;                                   // estado para culminacion de programa de lavado
bool f_calibrar;                                // estado de motor calibrando
bool alarm;                                     // para estar seguro de entrar a error 

byte selector;                                  // 0: apagado
                                                // 1: manchas dificiles
                                                // 2: blancos
                                                // 3: de color
                                                // 4: de cama-edredon
                                                // 5: delicada
                                                // 6: lavado express
                                                // 7: extra centrifugado
byte temperatura;                               // 0: caliente-frio
                                                // 1: tibio-tibio
                                                // 2: frio-frio
                                                // 3: tibio-frio
byte funcionC;                                  // 0: {0, 1, 1, 1}
                                                // 1: {1, 1, 1, 1}
                                                // 2: {0, 0, 0, 1}
                                                // 3: {0, 0, 1, 1}
byte selWork;                                   // copia cuando es permitido el valor de selector
byte lastTemp;
unsigned int c_ciclos;                          // contador de ciclos en alternamiento entre cw y ccw
byte c_exp;                                     // contador de ciclos en alternamiento ON/OFF del centrifugado
byte ciclos;                                    // contador de ciclos en alternamiento ON/OFF del calibrado
byte c_roc;                                     // contador de ciclos en alternamiento ON/OFF del rociado en centrifugado

// ppara depurar
//unsigned long genesis;

// monitor de seleccion de perilla de Programas de lavado
void updatePrincipal(void) {
    unsigned long actual = millis();
    /*  On/Off y eleccion de programa de lavado */ 
    float aux = analogRead(pinProgLavado)*5.0/1023.0;
    if( actual > e_principal ){
        if ( alarm ){
            if ( (aux <= .3) || aux >= 4.45 ) alarmStatus = 1;
            else alarm = false;
        }
        if ( aux > .3 ){
            if ( aux < .75 ){// 550mV   Apagado
                if ( !OFF ){
                    reset();
                    resetFunciones();
                }
            }
            else if ( aux < 1.34 ){// 1.09 V    manchas dificiles
                if ( OFF ){
                    reset();
                    selWork = 0;
                }
                selector = 1;
                OFF = false;
            }
            else if ( aux < 1.85 ){// 1.61V     blancos
                if ( OFF ){
                    reset();
                    selWork = 0;
                }
                selector = 2;
                OFF = false;
            }
            else if ( aux < 2.36 ){// 2.11V     color
                if ( OFF ){
                    reset();
                    selWork = 0;
                }
                selector = 3;
                OFF = false;
            }
            else if ( aux < 2.86 ){// 2.61V     cama-edredon
                if ( OFF ){
                    reset();
                    selWork = 0;
                }
                selector = 4;
                OFF = false;
            }
            else if ( aux < 3.36 ){// 3.11V     delicado
                if ( OFF ){
                    reset();
                    selWork = 0;
                }
                selector = 5;
                OFF = false;
            }
            else if ( aux < 3.87 ){// 3.62V     express
                if ( OFF ){
                    reset();
                    selWork = 0;
                }
                selector = 6;
                OFF = false;
            }
            else if ( aux < 4.45 ){// 4.12      extra centrifugado
                if ( OFF ){
                    reset();
                    selWork = 0;
                }
                selector = 7;
                OFF = false;
            }
            else alarm = true;
        }else alarm = true;
    }
    if ( alarm && (actual > e_principal) ) e_principal = actual + antirebote;
    if ( !isWork ){
        if ( pausa ){// si hay cambio del selector en una pausa, restablecer
            if ( selWork != selector ) reset();
        }
        if ( selWork != selector ){
            e_principal = actual + antirebote;
            selWork = selector;
            resetFunciones();
            if ( selWork == 7 ){
                v_funcion[0] = 0;
                v_funcion[1] = 0;
                v_funcion[2] = 0;
                v_funcion[3] = 1;
                v_funcion[4] = 0;
                for (byte i = 0; i < 5; i++)
                    v_fcopia[i] = v_funcion[i];
            }
        }
        
    }
}

// monitor componentes secundarios
void updateStatus(void) {
    unsigned long actual = millis();
    //####### Seleccion de temperatura ##############
    float aux = analogRead(pinTempAgua)*5.0/1023.0;
    if ( flag_PL ){
        if( actual > e_temp ){
            if ( aux > 0.18 ){
                if ( aux < 1.0 )// 0.54V       caliente-frio
                    temperatura = 0;
                else if ( aux < 2.1 )// 1.6V    tibio-tibio
                    temperatura = 0;
                else if ( aux < 3.1 )// 2.6V    frio-frio
                    temperatura = 0;
                else if ( aux < 4.3 )// 3.5V    tibio-frio
                    temperatura = 0;
                else alarmStatus = 1;
            }else alarmStatus = 1;
        }
        if ( lastTemp != temperatura ){
            e_temp = actual + antirebote;
        }
    }
    //#############################################
    //####### cambio de funcion de lavado #########
    if ( flag_PL && !pausa ){
        if ( !digitalRead(pinSeleccion) ){
            if( actual > e_reboteS ){
                funcionC++;
                if ( funcionC > 4 ) funcionC = 0;
                e_reboteS = actual + antirebote;
                est = 1;
                
            }
            
            if ( est && (selWork != 7) ){
                switch (funcionC) {
                    case 0:     // {0, 1, 1, 1, 1}
                        v_funcion[0] = 0;
                        v_funcion[1] = 1;
                        v_funcion[2] = 1;
                        v_funcion[3] = 1;
                        v_funcion[4] = 1;
                        est = 0;
                        break;
                    case 1:     // {1, 1, 1, 1, 1}
                        v_funcion[0] = 1;
                        v_funcion[1] = 1;
                        v_funcion[2] = 1;
                        v_funcion[3] = 1;
                        v_funcion[4] = 1;
                        est = 0;
                        break;
                    case 2:     // {0, 0, 0, 1, 0}
                        v_funcion[0] = 0;
                        v_funcion[1] = 0;
                        v_funcion[2] = 0;
                        v_funcion[3] = 1;
                        v_funcion[4] = 0;
                        est = 0;
                        break;
                    case 3:     // {0, 0, 1, 1, 0}
                        v_funcion[0] = 0;
                        v_funcion[1] = 0;
                        v_funcion[2] = 1;
                        v_funcion[3] = 1;
                        v_funcion[4] = 0;
                        est = 0;
                        break;
                    case 4:     // {0, 1, 0, 1, 0}
                        v_funcion[0] = 0;
                        v_funcion[1] = 1;
                        v_funcion[2] = 0;
                        v_funcion[3] = 1;
                        v_funcion[4] = 0;
                        est = 0;
                        break;
                }
            }
            for (byte i = 0; i < 5; i++)
                v_fcopia[i] = v_funcion[i];
        }
    }
    //#############################################
    //####### activacion del presostato ###########
    bool now = digitalRead(pinPresostato);
    if ( now != aguaTop ){
        actual = millis();
        if( actual > e_reboteP ){
            e_reboteP = actual + antirebote;
            aguaTop = !aguaTop;
            flag_llenado = !flag_llenado;
                
        }
    }
    //#############################################
    //#############################################
    //##### activacion del seguro de la tapa ######
    now = !digitalRead(pinTapa);
    if ( now != tapaLock ){
        actual = millis();
        if( actual > e_reboteLT ){
            e_reboteLT = actual + antirebote;
            tapaLock = !tapaLock;
            // actualizar led de seguro de tapa
            //v_leds[0] = !v_leds[0];
            update_leds();
                
        }
    }
    //#############################################
    //#############################################
    /*********          LEDS            ******** */
    if( selWork != 0 ){// chequeo que esté en On
        if ( updateLeds ){//  en espera de funcionamiento, brillo continuo
            update_leds();
        }
    }
    //#############################################
    
}
// configuracion de los leds en caso de error
// parpadeo rápido
void leds_alarm(){
    if ( alarmStatus ){
        unsigned long actual = millis();
        if ( tapaLock ) v_leds[0] = 1;
        else v_leds[0] = 0;
        if( actual > blink ){
            toggleLEDS();
            blink += INTER_ALARM_LEDS;
        }
    }
}
// actualiza el estado de los leds
void update_leds(){
    for (byte i = 1; i < 5; i++)
        v_leds[i] = v_fcopia[i-1];
    digitalWrite(pinLedExprimir,!v_leds[4]);
    digitalWrite(pinLedEnjuagar,!v_leds[3]);
    digitalWrite(pinLedLavar,!v_leds[2]);
    digitalWrite(pinLedRemojo,!v_leds[1]);
    if ( tapaLock ) digitalWrite(pinLedTapa,LOW);
    else digitalWrite(pinLedTapa,HIGH);
}
// alternar estados de todos los leds
void toggleLEDS(){
    if( digitalRead( pinLedTapa ) ){
        digitalWrite(pinLedTapa, LOW);
        digitalWrite(pinLedRemojo, LOW);
        digitalWrite(pinLedLavar, LOW);
        digitalWrite(pinLedEnjuagar, LOW);
        digitalWrite(pinLedExprimir, LOW);
    }
    else{
        digitalWrite(pinLedTapa, HIGH);
        digitalWrite(pinLedRemojo, HIGH);
        digitalWrite(pinLedLavar, HIGH);
        digitalWrite(pinLedEnjuagar, HIGH);
        digitalWrite(pinLedExprimir, HIGH);
    }
}
// configuracion de los leds en caso de pausa
// parpadeo del led de la funcion correspondiente
void leds_pausa(){
    unsigned long actual = millis();
    if( actual > blinkP ){
        toggleLedsPausa();
        blinkP += INTER_PAUSA_LEDS;
    }
}
// alternar el led de acuerdo a la funcion actual
void toggleLedsPausa(){
    if ( v_fcopia[0] )// remojo
        toggleOneLed(1);
    else
        if ( v_fcopia[1] )// lavado
            toggleOneLed(2);
        else
            if ( v_fcopia[2] )// enjuague
                toggleOneLed(3);
            else
                if ( v_fcopia[3] )// exprimir
                    toggleOneLed(4);
}
// alternar estado del led k
void toggleOneLed(byte k){
    digitalWrite(pinLedExprimir,!v_leds[4]);
    digitalWrite(pinLedEnjuagar,!v_leds[3]);
    digitalWrite(pinLedLavar,!v_leds[2]);
    digitalWrite(pinLedRemojo,!v_leds[1]);
    digitalWrite(pinLedTapa,!v_leds[0]);
    v_leds[k] = !v_leds[k];
}
//restablecer funciones de lavado
void resetFunciones(){
    funcionC = 0;
    v_funcion[0] = 0;
    for (byte i = 1; i < 5; i++)
        v_funcion[i] = 1;
    for (byte i = 0; i < 5; i++)
        v_fcopia[i] = v_funcion[i];
    
}
// protocolo en caso de error
void error(){
    if ( !OFF ){
        digitalWrite(pinMotorCW, LOW);
        digitalWrite(pinMotorCCW, LOW);
        digitalWrite(pinValvulaC, LOW);
        digitalWrite(pinValvulaH, LOW);
        digitalWrite(pinBomba, LOW);
        leds_alarm();
    }
}
// monitor para trabajar
void checkWork() {
    if( flag_onWork ){
        switch (selWork) {
            case 1:     // manchas dificiles
                work(manchasd_lavar,manchasd_enjuagar,1);
                break;
            case 2:     // blanco
                work(blancos_lavar,blancos_enjuagar,1);
                break;
            case 3:     // de color
                work(color_lavar,color_enjuagar,2);
                break;
            case 4:     // de cama-edredon
                work(cama_lavar,cama_enjuagar,0);
                break;
            case 5:     // delicada
                work(delicada_lavar,delicada_enjuagar,2);
                break;
            case 6:     // lavado espress
                work(espress_lavar,espress_enjuagar,0);
                break;
            case 7:     // extra centrifugado
                extra();
                break;
        }
    }
        
}
// trabaja según lo programado
void work(unsigned int lavar,unsigned int enjuague,byte tipo) {
    if ( v_fcopia[0] ){// remojo
        llenado();
        chacachaca(remojo,1,0,tipo);
    }else{
        if ( v_fcopia[1] ){//lavado
            llenado();
            chacachaca(lavar,0,1,tipo);
        }else{
            if ( v_fcopia[4] ){// exprimido de la lavado
                exprimir(exprimirL,4);
            }else{
                if ( v_fcopia[2] ){// enjuague
                    llenado();
                    chacachaca(enjuague,0,2,2);
                }else{
                    if ( v_fcopia[3] ){// exprimido final
                        exprimir(exprimirF,3);
                    }else{// final de ciclo programado
                        endWait();
                    }
                }
            }
        }
    }
}
void extra() {
    if ( v_fcopia[3] ){// exprimido final
        exprimir(exprimirF,3);
    }else{// final de ciclo programado
        endWait();
    }
}
// motor alternando giros, alternará c_max veces
void chacachaca(unsigned int c_max,bool rem,byte k,byte tipo){
    if (!flag_llenado){
        unsigned long actual = millis();
        if ( !aguaDone ) alarmStatus = 1;
        if ( c_ciclos < c_max ){
            /****************************************************************************************/
            /* t0-------t1-------t2-------t3-------t4-------t5-------t6-------t7-------t8-------t9-------t10...
            * cw ON    cw OFF                     cw ON    cw OFF                     cw ON...
            * ccw OFF           ccw ON   ccw OFF                    ccw ON   ccw OFF                    ccw ON...  */
            if (rem==1){// movimiento de remojo
                unsigned int desfase = (motorR_up + motorR_down)/2;
                if (c_ciclos == 0){
                    chcchc = true;
                    e_ch_cw = actual + 4000UL;
                    e_ch_ccw = e_ch_cw + desfase;       // desfase
                    e_led_chch = e_ch_cw;
                    c_ciclos++;
                    
                }
                if (cw)
                    INTERVALO_CW = motorR_up;
                else
                    INTERVALO_CW = motorR_down;
                if (ccw)
                    INTERVALO_CCW = motorR_up;
                else
                    INTERVALO_CCW = motorR_down;
                if ( cw && ccw )
                    INTERVALO_LED = motorR_up;
                else
                    INTERVALO_LED = desfase-motorR_up;
            }
            if (rem == 0){// movimiento de lavado
                if ( tipo == 0 ){
                    interUp = motorL_up;
                    interDown = motorL_down;
                }
                if ( tipo == 1 ){
                    interUp = motorLF_up;
                    interDown = motorLF_down;
                }
                if ( tipo == 2 ){
                    interUp = motorLD_up;
                    interDown = motorLD_down;
                }
                unsigned int desfase = (interUp + interDown)/2;
                if (c_ciclos == 0){
                    chcchc = true;
                    e_ch_cw = actual + 4000UL;
                    e_ch_ccw = e_ch_cw + desfase;
                    e_led_chch = e_ch_cw;
                    c_ciclos++;
                    
                }
                if (cw)
                    INTERVALO_CW = interUp;
                else
                    INTERVALO_CW = interDown;
                if (ccw)
                    INTERVALO_CCW = interUp;
                else
                    INTERVALO_CCW = interDown;
                if ( cw && ccw )
                    INTERVALO_LED = interUp;
                else
                    INTERVALO_LED = desfase-interUp;
            }
        /****************************************************************************************/
            if( actual > e_ch_cw ){
                toggleCW();
                e_ch_cw += INTERVALO_CW;
                c_ciclos++;
                
            }

            if( actual > e_ch_ccw ){
                toggleCCW();
                e_ch_ccw += INTERVALO_CCW;
                c_ciclos++;
                
            }
            if( actual > e_led_chch ){
                toggleOneLed(k+1);
                e_led_chch += INTERVALO_LED;
                
            }
        }else{// terminado chacachaca
            digitalWrite(pinMotorCW, LOW);
            digitalWrite(pinMotorCCW, LOW);
            
            if ( c_ciclos == c_max ){
                c_ciclos++;
                endWork = actual + 4000UL;
            }
            if( actual > endWork ){ 
                v_fcopia[k] = 0;
                c_ciclos = 0;
                update_leds();
                aguaDone = false;
                cw = true;
                ccw = true;
                chcchc = false;
            }
            
        }
    }
}
// alternar estado de giro horario
void toggleCW(){
    cw = !cw;
    if( digitalRead( pinMotorCW ) ){
        digitalWrite(pinMotorCW, LOW);
    }
    else{
        digitalWrite(pinMotorCCW, LOW);
        digitalWrite(pinMotorCW, HIGH);
    }
}
// alternar estado de giro anti horario
void toggleCCW(){
    ccw = !ccw;
    if( digitalRead( pinMotorCCW ) ){
        digitalWrite(pinMotorCCW, LOW);
    }
    else{
        digitalWrite(pinMotorCW, LOW);
        digitalWrite(pinMotorCCW, HIGH);
    }
}
// llenado del tambor
void llenado(void) {
    /*      Configurada para siempre usar agua fria     */
    unsigned long actual = millis();
    if (!aguaTop){// presostato abierto - por llenar
        if ( chcchc ){// No deberia estar en este punto en pleno lavado 
            alarmStatus = 1;
        }
        if ( !f_calibrar ){
            e_reboteIP = actual + antirebote;
            digitalWrite(pinValvulaC,HIGH);
            flag_llenado = true;
            f_calibrar = true;
        }
        digitalWrite(pinMotorCW, LOW);
        digitalWrite(pinMotorCCW, LOW);
    }else{// presostato cerrado: LLENADA
        if ( f_calibrar ){
            e_reboteIP = actual + antirebote;
            digitalWrite(pinValvulaC,LOW);
            flag_llenado = false;       // no llenando
            aguaDone = true;
            f_calibrar = false;
        }
    }
}
// inicialmente alterna el tiempo de centrifugado para acomode de la ropa
// el centrifugado continuo tardara tiempo milisegundos
void exprimir(unsigned long tiempo,byte k){
    unsigned long actual = millis();
    if ( c_exp < (exp_cicloIII+1) ){//131
        if ( !flag_bomba ){
            e_reboteIP = actual + antirebote;
            digitalWrite(pinBomba,HIGH);
            flag_bomba = true;
            e_bomba = actual + t_drenado;
            lockT = actual + t_tapa;
        }
        if( actual > lockT ){
            if ( !tapaLock ) alarmStatus = 1;
            else digitalWrite(pinLedTapa,LOW);
        }
        if (!aguaTop){// esperar que drene el agua
            if ( !flag_exp ){
                flag_exp = true;
                drenado = actual + 90000UL;
                e_ch_cw = actual + 90000UL;
            }
            if( actual > drenado ){
                if ( c_exp < exp_cicloI ){
                    if ( cw ) INTERVALO_CW = powOne;
                    else INTERVALO_CW = powOne_;
                }
                else{
                    if ( c_exp < exp_cicloII ){
                        if ( cw ) INTERVALO_CW = powTwo;
                        else INTERVALO_CW = powTwo_;
                    }
                    else{
                        if ( c_exp < exp_cicloIII ){
                            if ( cw ) INTERVALO_CW = powThree;
                            else INTERVALO_CW = powThree_;
                        }
                        else{
                            c_exp++;
                            e_e_cwF = actual + tiempo;
                            e_ch_cw += INTERVALO_CW;
                            
                        }
                    }
                }
                
                if( actual > e_ch_cw ){
                    toggleCW();
                    e_ch_cw += INTERVALO_CW;
                    c_exp++;
                    
                }
            }
        }else if( actual > e_bomba ) alarmStatus = 1;
    }else{
        if (actual < e_e_cwF){
            if ( c_exp == (exp_cicloIII+1) ){
                digitalWrite(pinMotorCW, HIGH);
                //e_ch_ccw = actual + t_irocio;                 // uso e_ch_ccw para tarea de rociado
                c_exp++;
                
            }
            if (c_roc < 4){// rociado, 2 veces
                if( actual > e_ch_ccw ){
                    digitalWrite(pinValvulaC,ccw);
                    ccw = !ccw;
                    e_ch_ccw += t_rocio;
                    c_roc++;
                    
                }
            }
            
        }else{
            digitalWrite(pinMotorCW, LOW);
            
            if ( c_exp == (exp_cicloIII+2) ){
                c_exp++;
                endWork = actual + 4000UL;
                e_reboteIP = actual + antirebote;
                digitalWrite(pinBomba, LOW);
            }
            if( actual > endWork ){ 
                v_fcopia[k] = 0;
                c_exp = 0;
                flag_exp = false;
                flag_bomba = false;
                cw = true;
                ccw = true;
                c_roc = 5;
                update_leds();
            }
            
        }
    }
}
// timepo muerto al final del trabajo configurado
void endWait(){
    unsigned long actual = millis();
    if ( istDone ){
        istDone = false;
        endWork = actual + toEnd;
        tapaLock = 1;
        
    }
    if( actual > endWork ){
        reset();
        OFF = false;
        selector = selWork;
        for (byte i = 0; i < 5; i++)
            v_fcopia[i] = v_funcion[i];
    }
}
// restablecimiento de parametros
void reset(){
    
    OFF = true;
    selector = 0;
    alarmStatus = 0;
    c_ciclos = 0;
    ciclos = 0;
    c_exp = 0;
    flag_llenado = false;
    flag_onWork = false;
    isWork = false;
    pausa = false;
    flag_PL = true;
    cw = true;
    ccw = true;
    istDone = true;
    flag_exp = false;
    flag_bomba = false;
    est = 0;
    aguaTop = 0;
    tapaLock = 0;
    v_leds[0] = 0;
    aguaDone = 0;
    f_calibrar = false;
    updateLeds = true;
    chcchc = false;
    c_roc = 5;
    temperatura = 1;
    lastTemp = 1;
    alarm = false;
    
    e_ch_cw = millis();
    blink = millis();
    blinkP = millis();
    e_reboteS = millis();
    e_reboteIP = millis();
    e_reboteP = millis();
    e_reboteLT = millis();
    e_principal = millis();
    e_temp = millis();
    
    digitalWrite(pinMotorCW, LOW);
    digitalWrite(pinMotorCCW, LOW);
    digitalWrite(pinValvulaC, LOW);
    digitalWrite(pinValvulaH, LOW);
    digitalWrite(pinBomba, LOW);
    digitalWrite(pinLedTapa, HIGH);
    digitalWrite(pinLedRemojo, HIGH);
    digitalWrite(pinLedLavar, HIGH);
    digitalWrite(pinLedEnjuagar, HIGH);
    digitalWrite(pinLedExprimir, HIGH);
    
}
// arduino startup
void setup() {
    
    funcionC = 0;
    selWork = 0;
    reset();
    
    // Pines de entrada
    pinMode(pinInicioPausa,INPUT_PULLUP);
    pinMode(pinSeleccion,INPUT_PULLUP);
    // Pines de salida
    pinMode(pinMotorCW,OUTPUT);
    pinMode(pinMotorCCW,OUTPUT);
    pinMode(pinValvulaC,OUTPUT);
    pinMode(pinValvulaH,OUTPUT);
    pinMode(pinBomba,OUTPUT);
    pinMode(pinLedExprimir,OUTPUT);
    pinMode(pinLedEnjuagar,OUTPUT);
    pinMode(pinLedLavar,OUTPUT);
    pinMode(pinLedRemojo,OUTPUT);
    pinMode(pinLedTapa,OUTPUT);
    
    //Configura la interrupción en el PIN del pulsador Inincio-Pausa en modo FALLING
    attachInterrupt(digitalPinToInterrupt(pinInicioPausa), inicioPausa, FALLING);

}
// arduino loop de eventos
void loop() {
    
    if ( !alarmStatus ){
        updatePrincipal();
        if ( !pausa && !OFF ){
            updateStatus();
            checkWork();
        }
        if ( pausa ){
            leds_pausa();
            updateStatus();
        }
    }else
        error();
    
}
// interrupcion con pulsador Inicio-Pausa
void inicioPausa(){
    
    if ( !OFF ){
        unsigned long actual = millis();
        if( actual > e_reboteIP ){
            e_reboteIP = actual + antirebote;
            
            if ( !flag_onWork ){
                flag_onWork = true;
                isWork = true;
                pausa = false;
                flag_PL = false;
                updateLeds = false;
                update_leds();
                
                if ( chcchc ){                          // restablecer tiempos para continuar
                    cw = true;
                    ccw = true;
                    if ( c_ciclos%2 == 0 ) c_ciclos++;
                    e_ch_cw = actual;
                    e_led_chch = e_ch_cw;
                    if ( v_fcopia[0] ) e_ch_ccw = e_ch_cw + (motorR_up + motorR_down)/2;
                    else e_ch_ccw = e_ch_cw + (interUp + interDown)/2;
                }
                if ( flag_bomba ){ // al volver del pause debería estar bien la ropa
                    flag_bomba = false;
                    flag_exp = false;
                    c_exp = exp_cicloIII;
                }
                if ( f_calibrar ) f_calibrar = false;
                
            }else{
                if ( !pausa ){
                    pausa = true;
                    flag_onWork = false;
                    flag_PL = true;
                    isWork = false;
                    
                    digitalWrite(pinMotorCW, LOW);
                    digitalWrite(pinMotorCCW, LOW);
                    digitalWrite(pinValvulaC, LOW);
                    digitalWrite(pinValvulaH, LOW);
                    digitalWrite(pinBomba, LOW);
                    
                }
            }
        }
    }
}
