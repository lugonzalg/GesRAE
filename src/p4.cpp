/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

//INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TADEdificio.h"

//CONSTANTS
const char Input_posibles[] = "ELARMS";

//PROGRAM

static void Intro() {
  printf("GesRAE: Gestion de Reservas Apartamentos-Edificios\n\n");
  printf("Editar Edificio (Pulsar E)\n");
  printf("Listar Edificios (Pulsar L)\n");
  printf("Apartamentos Disponibles (Pulsar A)\n");
  printf("Reservar Apartamento (Pulsar R)\n");
  printf("Reservas Mensuales Apartamento (Pulsar M)\n");
  printf("Salir (Pulsar S)\n\n");
  printf("Teclear una opcion valida (E|L|A|R|M|S)? ");
}

const int LongitudVectorEdificios = 5;

typedef TADEdificio VectorEdificios[LongitudVectorEdificios];

void Editar_edificio(VectorEdificios vector_edificios) {
  int idx;

  printf("Identificador (numero entre 1 y 5)? ");
  scanf("%d", &idx);

  if (idx < 1 || idx > 5) {
    fprintf(stderr, "[ERROR] - El id esta fuera del rango 1-5: %d\n\n", idx);
    return ;
  }

  vector_edificios[idx - 1].Editar();

}

void Listar_edificios() {}
void Apartamentos_disponibles() {}
void Reservar_apartamento() {}
void Reservas_mensuales_apartamento() {}

static int main_loop() {
  Bufer input_usuario = {0};
  VectorEdificios vector_edificios;

  while (1) {
    Intro();
    fflush(stdout);
    fflush(stderr);
    scanf("%29s", input_usuario);

    switch(input_usuario[0]) {
      case 'E':
        Editar_edificio(vector_edificios);
        break ;
      case 'L':
        break ;
      case 'A':
        break ;
      case 'R':
        break ;
      case 'M':
        break ;
      case 'S':
        return 0;
        break ;
      default:
        fprintf(stderr, "\n[ERROR] - El input %s es incorrecto\n\n", input_usuario);
    }
    fflush(stdout);
    fflush(stderr);
  }

  return 0;
}

int main(){
  int exit_val;

  exit_val = main_loop();
  return exit_val;
}
