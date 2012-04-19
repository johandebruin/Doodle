/**************************************
* Interfaz del modulo: TipoFechaElegida
*
*   Almacena cuantas veces ha sido elegida una fecha.
***************************************/

#pragma once

typedef struct TipoFechaElegida {
  int anno;
  int mes;
  int dia;
  int numeroDeVeces;

  void ImprimirFecha();
};
