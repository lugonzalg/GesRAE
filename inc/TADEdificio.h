/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

# pragma once

const int LongitudBufer = 30;

typedef char Bufer[LongitudBufer];

typedef struct TADEdificio {

    int id;
    void Editar();
    void Print();

  private:
    Bufer _nombre;
    int _apartamentos_basicos;
    int _apartamentos_normales;
    int _apartamentos_lujo;

    int _validar_palabra(Bufer input_usuario);
    int _validar_numeros(Bufer input_usuario);
};
