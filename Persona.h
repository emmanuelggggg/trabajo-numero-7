//
// Created by Many1 on 24/05/2020.
//

#ifndef UNTITLED1_PERSONA_H
#define UNTITLED1_PERSONA_H


class Persona {
private:
    char nombre[100];
    char apellido[100];
    int edad;
public:
    Persona();
    Persona(char [], char [], int);
    void toString();

};
