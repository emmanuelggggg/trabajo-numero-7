//
// Created by Many1 on 24/05/2020.
//

#ifndef UNTITLED1_PELICULA1_H
#define UNTITLED1_PELICULA1_H

#include "Persona.h"

class Pelicula1 {
private:
    char titulo[100];
    Persona director;
    int annio;
    char genero[100];
    char productora[100];
    int duracion;
public:
    Pelicula1();
    Pelicula1(char [], Persona, int, char [], char [], int);
    void toString();
};


#endif //UNTITLED1_PELICULA1_H
