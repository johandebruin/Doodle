/**************************************
* Implementación del modulo: Calendario
***************************************/

#include <stdio.h>
#include <string.h>
#include "calendario.h"

static void ImprimirLinea() {
  for(int i = 0; i < 27;i++) {
    printf("=");
  }
  printf("\n");
}

int CAL_ImprimirCalendario(int mes, int anno){
  /*====================================
  Declaracion de tipos y constantes
  ====================================*/
  typedef enum TipoDia {
    Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo
  };
  typedef enum TipoMes {
    Enero, Febrero, Marzo, Abril, Mayo, Junio, Julio, Agosto, Septiembre,
      Octubre, Noviembre, Diciembre
  };
  typedef struct TipoFecha {
    TipoMes mes;
    int anno;
  };
  /*Gestion de impresion*/
  typedef char Cadena11[11];
  typedef char Cadena2[3];
  typedef Cadena11 TipoMeses[12];
  typedef Cadena2 TipoSemanas[7];
  const TipoMeses Meses = { "ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO",
    "JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE" };
  const TipoSemanas Semanas = { "LU","MA","MI","JU","VI","SA","DO" };
  /*====================================
  Variables
  ====================================*/
  int n,diaSemana,ultimoMes,recuento,dia2,mes2,anno2,a,y,m;
  TipoFecha fecha;

  printf("\n");
  fecha.anno = anno;
  mes = mes-1;
  fecha.mes = TipoMes(mes);

  /*====================================
  Imprimimos el encabezado del calendario
  ====================================*/
  n = strlen(Meses[fecha.mes]);
  printf("%s",Meses[fecha.mes]);
  for(int i = 0; i < 23 - n; i++){
    printf(" ");
  }
  printf("%d\n",fecha.anno);
  ImprimirLinea();
  for(int i = 0; i < 4; i++) {
    printf("%s  ",Semanas[i]);
  }
  printf("%s | %s  %s\n", Semanas[4],Semanas[5],Semanas[6]);
  ImprimirLinea();

  /*====================================
  Imprimimos el cuerpo del calendario
  ====================================*/
  dia2 = 1;
  mes2 = int(fecha.mes)+1;
  anno2 = fecha.anno;
  /*Calculamos el dia de la semana en el que comienza el mes*/
  a = (14 - mes)/12;
  y = anno2 - a;
  m = mes2 + 12*a -2;
  dia2 = (dia2 + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
  if (dia2 > 0) {
    diaSemana = dia2-1;
  } else {
    diaSemana = 6;
  }

  /*Calculamos el último día del mes*/
  switch(fecha.mes){
    case Enero:
    case Marzo:
    case Mayo:
    case Julio:
    case Agosto:
    case Octubre:
    case Diciembre:
      ultimoMes = 31;
      break;
    case Febrero:
      if(fecha.anno % 4 == 0 && (!(fecha.anno % 100 == 0) || fecha.anno % 400 == 0)){
        ultimoMes = 29;
      } else {
        ultimoMes = 28;
      }
      break;
    default:
      ultimoMes = 30;
  }

  /*En recuento almacenamos el numero de itineraciones necesarios
  para imprimir todos los elementos del cuerpo*/
  n = 0;
  if((diaSemana+ultimoMes) %  7 == 0) {
    recuento = diaSemana+ultimoMes;
  }
  else {
    recuento = (((diaSemana+ultimoMes) / 7)+1)*7;
  }
  while(n < recuento) {
      if(n % 7 < 4){
        if(n < diaSemana || n >= ultimoMes + diaSemana){
          printf(" .  ");
        } else {
          printf("%2d  ", n-diaSemana+1);
        }
      } else if(n % 7 == 4) {
        if(n < diaSemana || n >= ultimoMes + diaSemana) {
          printf(" .");
        } else {
          printf("%2d", n-diaSemana+1);
        }
      } else if (n % 7 == 5) {
        if(n < diaSemana || n >= ultimoMes + diaSemana) {
          printf(" |  .  ");
        } else {
          printf(" | %2d  ", n-diaSemana+1);
        }
      } else {
        if(n < diaSemana || n >= ultimoMes + diaSemana) {
          printf(" .\n");
        } else {
          printf("%2d\n", n-diaSemana+1);
        }
      }
      n++;
  }
  return ultimoMes;
}
