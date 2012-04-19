/**************************************
* Interfaz del modulo: TipoListaDeFechasElegidas
*
*   Guarda hasta 50 fechas elegidas y ademas es capaz de
*   ordenarlas internamente.
***************************************/

#pragma once
#include "tipofechaelegida.h"
#include "tipolistadepreferencias.h"

typedef struct TipoListaDeFechasElegidas {
  void ObtenerFechasElegidasAPartirDeLasPreferencias(TipoListaDePreferencias preferencias);
  void OrdenarFechasElegidas();
  void ImprimirFechasElegidas();
};
