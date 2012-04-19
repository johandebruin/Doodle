/**************************************
* NOMBRE: #Johan Javier#
* PRIMER APELLIDO: #de#
* SEGUNDO APELLIDO: #Bruin#
* DNI: #711252542#
* EMAIL: #johanb@friiweb.com#
***************************************/

/**************************************
* Planificador
*   Fichero de implemenacion del planificador
***************************************/

#include <stdio.h>
#include <ctype.h>
#include "tipolistadepreferencias.h"
#include "tipolistadefechaselegidas.h"

int main() {
  int opcion;
  TipoPreferencia preferencia;
  TipoListaDePreferencias preferencias;
  TipoListaDeFechasElegidas fechasElegidas;

  preferencias.InicializarPreferencias();

  while(opcion != 4) {
    opcion = 0;
    printf("\n\nPLANIFICADOR DE EVENTOS PARA REUNIONES\n\n");
    printf("1. Introducir las preferencias de un usuario\n");
    printf("2. Listar las preferencias de todos los usuarios\n");
    printf("3. Calcular la fecha optima para la reunion\n");
    printf("4. Salir\n");
    scanf("%d", &opcion);
    if( (opcion < 1) || (opcion > 4) ) {
      printf("\n<<ERROR: opcion incorrecta, para evitar bubles infinitos me salgo del programa>>\n");
      opcion = 4;
    }
    if( opcion == 1) {
      preferencias.AnnadirPreferencia(preferencia);
    }
    if( opcion == 2) {
      preferencias.ImprimirPreferencias();
    }
    if( opcion == 3) {
      fechasElegidas.ObtenerFechasElegidasAPartirDeLasPreferencias(preferencias);
      fechasElegidas.OrdenarFechasElegidas();
      fechasElegidas.ImprimirFechasElegidas();
    }
  }
}
