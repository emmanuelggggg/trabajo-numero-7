//
// Created by Many1 on 24/05/2020.
//

#ifndef UNTITLED1_PRESTAMOS_H
#define UNTITLED1_PRESTAMOS_H


class Prestamos {
    private:
        int usuario;
        int pelicula;
        char fechaInicial[100];
        char fechaFinal[100];
        int estado;
    public:
        Prestamos();
        Prestamos(int, int, char []);
        void devolucion(char []);
        int getUsuario();
        int getPelicula();
        int getEstado();
        void toString();
};


#endif //UNTITLED1_PRESTAMOS_H
