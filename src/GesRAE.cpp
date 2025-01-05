/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

#include <string.h>

#include "TADGestor.h"

int main(){
  TADGestor Programa;
  int         ValorSalida;

  memset(&Programa, 0, sizeof(TADGestor));

  ValorSalida = Programa.main_loop();
  return ValorSalida;
}
