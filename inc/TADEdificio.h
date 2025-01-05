/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

# pragma once

#include "TADApartamento.h"
#include "TADDatosEdificio.h"

const int LongitudVectorApartamentos = 20;

typedef TADApartamento  VectorApartamentos[LongitudVectorApartamentos];

typedef struct TADEdificio {

    void            constructor(PtrDatosEdificio datosEdificio);
    void            print();
    void            printParaList(int lontiudMaximaNombre);
    PtrApartamento  asignarReserva(PtrReserva reserva);
    int             obtenerId();
    PtrChar         obtenerNombre();
    void            reset();
    int             obtenerApartamentoDisponible(TipoApartamento tipoApartamento);
    void            obtenerApartamentosLibresPorFecha(PtrReserva reserva, VectorTipoApartamento apartamentosLibres);
    int             printarReservasApartamentoPorFecha(TipoApartamento tipoApartamento, int offset, int mes, int periodoAnual);

  private:
    int                   id;
    TipoVectorChars       nombre;
    VectorTipoApartamento numeroTipoApartamento;
    int                   totalApartamentos;
    VectorApartamentos    apartamentos;
    void                  borrarApartamentos();
    PtrReserva            crearReserva(TipoApartamento tipoApartamento, PtrTm fecha, int periodo);
};

typedef TADEdificio     *PtrEdificio;
