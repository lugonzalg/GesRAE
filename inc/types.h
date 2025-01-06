/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

# pragma once

const int   LongitudVectorChars = 30;
const char  VectorCharsScanf[] = "%29s";

typedef char TipoVectorChars[LongitudVectorChars];
typedef char *PtrChar;

typedef enum TipoApartamento {
  BASICO,
  NORMAL,
  LUJO,
  SIZE,
  UNKNOWN
};

typedef int VectorTipoApartamento[SIZE];
