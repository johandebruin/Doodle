/**************************************
* Implementación del modulo: TipoFechaElegida
***************************************/

#include <stdio.h>
#include "tipofechaelegida.h"

void TipoFechaElegida::ImprimirFecha(){
  printf("%d-%d-%d ha sido elegida %d veces\n",dia,mes,anno,numeroDeVeces);
}
