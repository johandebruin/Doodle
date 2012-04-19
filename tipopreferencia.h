/**************************************
* Interfaz del modulo: TipoPreferencia
*
*   Es un tipo abstracto de datos que pregunta la preferencia al
*   usuario y imprimir una referencia en particular.
***************************************/
#pragma once

typedef struct TipoPreferencia {
  char nombre[50];
  int anno;
  int mes;
  int dia;

  bool PreguntarPreferenciaAlUsuario();
  void ImprimirPreferencia();
};
