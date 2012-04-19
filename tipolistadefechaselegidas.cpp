/**************************************
* Implementación del modulo: TipoListaDeFechasElegidas
***************************************/

#include <stdio.h>
#include "tipolistadefechaselegidas.h"

typedef TipoFechaElegida TipoFechasElegidas[50];
static int nFechasInsertadas;
static TipoFechasElegidas fechas;

static int ObtenerFecha(int anno, int mes, int dia) {
  for(int i = 0; i < nFechasInsertadas; i++) {
    if(fechas[i].anno == anno && fechas[i].mes == mes && fechas[i].dia == dia) {
      return i;
    }
  }
  return -1;
}

static int InsertarFecha(int anno, int mes, int dia) {
  fechas[nFechasInsertadas].anno = anno;
  fechas[nFechasInsertadas].mes = mes;
  fechas[nFechasInsertadas].dia = dia;
  fechas[nFechasInsertadas].numeroDeVeces = 1;
  nFechasInsertadas++;
}

void TipoListaDeFechasElegidas::ObtenerFechasElegidasAPartirDeLasPreferencias(TipoListaDePreferencias preferencias)  {
  int i = 0;
  TipoPreferencia preferencia;
  nFechasInsertadas = 0;
  while(preferencias.ExistePreferencia(i)){
    preferencia = preferencias.ObtenerPreferencia(i);
    if(ObtenerFecha(preferencia.anno, preferencia.mes, preferencia.dia) == -1) {
      InsertarFecha(preferencia.anno, preferencia.mes, preferencia.dia);
    } else {
      fechas[ObtenerFecha(preferencia.anno, preferencia.mes, preferencia.dia)].numeroDeVeces++;
    }
    i++;
  }
}

void TipoListaDeFechasElegidas::OrdenarFechasElegidas()  {
  int j;
  TipoFechaElegida valor;
  for(int i = 1; i < nFechasInsertadas; i++) {
    valor = fechas[i];
    j = i;
    while(j > 0 && valor.numeroDeVeces < fechas[j-1].numeroDeVeces) {
      fechas[j] = fechas[j-1];
      j--;
    }
    fechas[j] = valor;
  }
}

void TipoListaDeFechasElegidas::ImprimirFechasElegidas()  {
   printf("LISTADO DE FECHAS ELEGIDAS:\n");
   for(int i = nFechasInsertadas-1; i >= 0; i--) {
    fechas[i].ImprimirFecha();
  }

}
