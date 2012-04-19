/**************************************
* Implementación del modulo: TipoListaDePreferencias
***************************************/

#include "tipolistadepreferencias.h"
#include <stdio.h>

static int nPreferenciasInsertadas;
typedef TipoPreferencia TiposPreferencia[50];
static TiposPreferencia preferencias;

void TipoListaDePreferencias::InicializarPreferencias() {
  nPreferenciasInsertadas = 0;
}

void TipoListaDePreferencias::AnnadirPreferencia(TipoPreferencia preferencia){
  if(nPreferenciasInsertadas < 50) {
    if(preferencia.PreguntarPreferenciaAlUsuario()) {
      preferencias[nPreferenciasInsertadas] = preferencia;
      nPreferenciasInsertadas++;
    }
  }
  else {
    printf("\n<<ERROR: Se supero el limite de 50 preferencias>>\n");
  }
}

void TipoListaDePreferencias::ImprimirPreferencias() {
  printf("LISTADO DE PREFERENCIAS:\n");
  for(int i = 0; i < nPreferenciasInsertadas; i++) {
    preferencias[i].ImprimirPreferencia();
  }
}

bool TipoListaDePreferencias::ExistePreferencia(int i) {
  if ( i > -1 && i < nPreferenciasInsertadas) {
    return true;
  }
  return false;
}

TipoPreferencia TipoListaDePreferencias::ObtenerPreferencia(int i) {
  if ( i > -1 && i < nPreferenciasInsertadas) {
    return preferencias[i];
  }
}
