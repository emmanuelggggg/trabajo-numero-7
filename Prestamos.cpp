//
// Created by Many1 on 24/05/2020.
//

#include "Prestamos.h"

#include <iostream>
#include <cstring>

using namespace std;

Prestamos::Prestamos() {}

Prestamos::Prestamos(int usuario, int pelicula, char fechaInicial[100]) {
    this->usuario = usuario;
    this-> pelicula = pelicula;
    strcpy(this->fechaInicial, fechaInicial);
    this->estado = 1;
}

void Prestamos::devolucion(char fechaFinal[100]) {
    strcpy(this->fechaInicial, fechaFinal);
    this->estado = 0;
}

int Prestamos::getUsuario() {
    return this->usuario;
}

int Prestamos::getPelicula() {
    return this->pelicula;
}

int Prestamos::getEstado() {
    return this->estado;
}

void Prestamos::toString() {
    cout<<"====================";
    cout << "Fecha Inicial "<< this->fechaInicial << endl;
    if(this->estado == 1){
        cout << "Estado del prestamo: Rentada"<<endl;
    }else{
        cout << "Estado del prestamo: Disponible"<<endl;
        cout << "Fecha final "<< this->fechaFinal << endl;
    }
    cout<<"====================";
}