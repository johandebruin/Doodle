/**************************************
* Implementación del modulo: TipoPreferencia
***************************************/

#include <stdio.h>
#include "tipopreferencia.h"
#include "calendario.h"

/*===============================================
1.Pregunta al usuario su preferencia
2.Imprime calendario con mes y anno sleccionados
3.Guarda resultado en el propio TAD
4.Devuelve false si algun dato es erroneo
=================================================*/
bool TipoPreferencia::PreguntarPreferenciaAlUsuario(){
  int diaMaximo;
  printf("Nombre?");
  scanf("%s", &nombre);
  printf("Mes (1..12)?");
  scanf("%d", &mes);
  if(mes < 0 || mes > 13){
    printf("\n<<ERROR: Mes no valido>>\n");
    return false;
  }
  printf("Anno (2011..3000)?");
  scanf("%d", &anno);
  if(anno < CAL_Aini || anno > CAL_Afin){
    printf("\n<<ERROR: Anno no valido>>\n");
    return false;
  }
  diaMaximo = CAL_ImprimirCalendario(mes,anno);

  printf("Dia?");
  scanf("%d",&dia);
  if(dia > diaMaximo || dia < 1) {
    printf("Dia no valido %d...\n",diaMaximo);
    return false;
  }
  return true;
}

void TipoPreferencia::ImprimirPreferencia(){
  printf("%s prefiere que la reunion sea el %d-%d-%d\n",nombre,dia,mes,anno);
}
