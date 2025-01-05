/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

# pragma once

#include "TADEdificio.h"
#include "TADTransaccion.h"
#include "types.h"

const int LongitudVectorEdificios = 5;
const int LongitudVectorRegistros = 10;

typedef TADEdificio TipoVectorEdificios[LongitudVectorEdificios];
typedef int         TipoVectorRegistros[LongitudVectorRegistros];

typedef struct TADGestor {
  int   main_loop();

  private:
    TipoVectorEdificios vectorEdificios;
    TipoVectorRegistros vectorRegistros;
    TADTransaccion      transaccion;

    void            intro();
    int             indiceEdificioValidado(PtrChar mensaje);
    void            editarEdificio();
    void            listarEdificios();
    void            apartamentosDisponibles();
    void            reservarApartamento();
    void            reservasMensualesApartamento();
    int             validarPalabra(TipoVectorChars InputUsuario);
    int             validarNumeros(TipoVectorChars InputUsuario);
    void            asignarNombreDeEdificio(PtrDatosEdificio DatosEdificio);
    int             asignarApartamentosDeEdificio(PtrDatosEdificio DatosEdificio);
    int             validarOperacion();
    PtrReserva      crearReserva(PtrDatosReserva DatosReserva);
    void            recogerDatosApartamento(PtrDatosReserva DatosReserva, PtrEdificio Edificio);
    int             recogerDatosFecha(PtrDatosReserva DatosReserva);
    int             validarReserva();
    int             inputUsuarioNumero(PtrChar mensaje, PtrChar MensajeError);
    void            limpiarInput();


};
