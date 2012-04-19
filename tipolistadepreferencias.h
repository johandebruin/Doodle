/**************************************
* Interfaz del modulo: TipoListaDePreferencias
*
*   Almacena todas las preferencias del usuario hasta
*   un máximo de 50. Es un TAD.
***************************************/

#pragma once
#include "tipopreferencia.h"

typedef struct TipoListaDePreferencias {
  void InicializarPreferencias();
  void AnnadirPreferencia(TipoPreferencia preferencia);
  void ImprimirPreferencias();
  bool ExistePreferencia(int i);
  TipoPreferencia ObtenerPreferencia(int i);
};
