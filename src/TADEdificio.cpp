/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "TADEdificio.h"

int TADEdificio::_validar_palabra(Bufer input_usuario) {

  for (int idx = 0; idx < LongitudBufer && input_usuario[idx]; idx++) {
    if (!isalpha(input_usuario[idx])) {
      printf("%c\n", input_usuario[idx]);
      fprintf(stderr, "[ERROR] - Validacion de nombre incorrecta!\n");
      return 1;
    }
  }
  return 0;
}

int TADEdificio::_validar_numeros(Bufer input_usuario) {

  for (int idx = 0; idx < LongitudBufer && input_usuario[idx]; idx++) {
    if (!isdigit(input_usuario[idx])) {
      printf("%c\n", input_usuario[idx]);
      fprintf(stderr, "[ERROR] - Validacion de numeros!\n");
      return 1;
    }
  }
  return 0;
}

void TADEdificio::Print() {
  printf("Nombre: %s\n", this->_nombre);
  printf("Apartamentos Basicos: %d\n", this->_apartamentos_basicos);
  printf("Apartamentos Normales: %d\n", this->_apartamentos_normales);
  printf("Apartamentos de Lujo: %d\n", this->_apartamentos_lujo);
}

void TADEdificio::Editar() {
  Bufer input_usuario = {0};
  int longitud;

  longitud = 0;

  printf("Nombre (entre 1 y 20 caracteres)? ");
  scanf("%29s", input_usuario);
  longitud = strlen(input_usuario);
  if (longitud > 20 || longitud == 0 || this->_validar_palabra(input_usuario)) {
    fprintf(stderr, "El nombre para el edificio es incorrecto!!\n");
    fprintf(stderr, "\t - Input: %s\n", input_usuario);
    fprintf(stderr, "\t - Longitud input: %d\n", longitud);
    return ;
  }
  strncpy(this->_nombre, input_usuario, LongitudBufer);

  printf("Numero de Apartamentos Basicos? ");
  scanf("%29s", input_usuario);
  if (this->_validar_numeros(input_usuario)) {
    fprintf(stderr, "El numero de apartamentos basicos contiene letras!\n");
    return ;
  }
  this->_apartamentos_basicos = atoi(input_usuario);

  printf("Numero de Apartamentos Normales? ");
  scanf("%29s", input_usuario);
  if (this->_validar_numeros(input_usuario)) {
    fprintf(stderr, "El numero de apartamentos normales contiene letras!\n");
    return ;
  }
  this->_apartamentos_normales = atoi(input_usuario);

  printf("Numero de Apartamentos de Lujo? ");
  scanf("%29s", input_usuario);
  if (this->_validar_numeros(input_usuario)) {
    fprintf(stderr, "El numero de apartamentos de lujo contiene letras!\n");
    return ;
  }
  this->_apartamentos_lujo = atoi(input_usuario);

  if ((this->_apartamentos_basicos + this->_apartamentos_normales + this->_apartamentos_lujo) == 0
      || this->_apartamentos_basicos < 0 || this->_apartamentos_normales < 0 || this->_apartamentos_lujo < 0) {
    fprintf(stderr, "[ERROR] - Los valores de los apartamentos son nulos o negativos!\n\n");
    this->id = 0;
    return ;
  }

  printf("Edificio editado de forma correcta!\n");
  this->Print();
}
