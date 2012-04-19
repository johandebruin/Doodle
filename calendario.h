/**************************************
* Interfaz del modulo: Calendario
*
*   Este modulo define la abstracción funcional ImprimirCalendario
*   capaz de imprimir en pantalla un calendario, el método empleado
*   para el calculo principal es la congruencia de Zeller.
***************************************/

#pragma once

const int CAL_Aini = 2011; /* anno minimo para proponer una reunion */
const int CAL_Afin = 3000; /* anno maximo para proponer una reunion */

/* ImprimirCalendario:
* - imprime el calendario correspondiente a Mes y Anno
* - devuelve el numero total de dias de Mes, que puede ser:
*   * 28, 29, 30 o 31 si el mes y el anno son correctos
    * 0 si el mes o el anno son incorrectos
*/
int CAL_ImprimirCalendario(int mes, int anno);
