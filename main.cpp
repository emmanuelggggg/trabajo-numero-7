#include <iostream>
#include "Persona.h"
#include "Pelicula1.h"
#include "Prestamos.h"

using namespace std;

void menu(){
    cout<<"===MENU PRINCIPAL==="<<endl;
    cout<<"1.- Administrar Usuarios"<<endl;
    cout<<"2.- Administrar Peliculas"<<endl;
    cout<<"3.- Administrar Prestamos"<<endl;
    cout<<"4.- Salir"<<endl;
    cout<<"====================";
}

void menuUsuarios(){
    cout<<"===MENU USUARIOS==="<<endl;
    cout<<"1.- Registrar Usuario"<<endl;
    cout<<"2.- Editar Usuario"<<endl;
    cout<<"3.- Consultar Usuario"<<endl;
    cout<<"4.- Eliminar Usuario"<<endl;
    cout<<"5.- Regresar"<<endl;
    cout<<"====================";
}

void menuPeliculas(){
    cout<<"===MENU PELICULAS==="<<endl;
    cout<<"1.- Registrar Pelicula"<<endl;
    cout<<"2.- Editar Pelicula"<<endl;
    cout<<"3.- Consultar Pelicula"<<endl;
    cout<<"4.- Eliminar Pelicula"<<endl;
    cout<<"5.- Regresar"<<endl;
    cout<<"====================";
}

void menuPrestamos(){
    cout<<"===MENU PRESTAMOS==="<<endl;
    cout<<"1.- Realizar Prestamo"<<endl;
    cout<<"2.- Devolver Pelicula"<<endl;
    cout<<"3.- Consultar Prestgamo"<<endl;
    cout<<"4.- Regresar"<<endl;
    cout<<"====================";
}

Persona registrarUsuario(){
    char nombre[100];
    char apellido[100];
    int edad;

    cout<<"Nombre: "; cin>>nombre;
    cout<<"Apellido: "; cin>>apellido;
    cout<<"Edad: "; cin>>edad;

    Persona usuario = Persona(nombre, apellido, edad);
    return usuario;
}

Pelicula1 registrarPelicula(){

    char titulo[100];
    int annio;
    char genero[100];
    char productora[100];
    int duracion;

    /*VARIABLES DIRECTOR*/
    char nombre[100];
    char apellido[100];
    int edad;

    cout<<"===DATOS DE PELICULAS==="<<endl;
    cout<<"Titulo: "; cin>>titulo;
    cout<<"Annio: "; cin>>annio;
    cout<<"Genero: "; cin>>genero;
    cout<<"Productora: "; cin>>productora;
    cout<<"Duracion: "; cin>>duracion;
    cout<<"====================";
    cout<<"\n";

    cout<<"===DATOS DEL AUTOR==="<<endl;
    cout<<"Nombre: "; cin>>nombre;
    cout<<"Apellido: "; cin>>apellido;
    cout<<"Edad: "; cin>>edad;
    cout<<"====================";

    Persona director = Persona(nombre, apellido, edad);
    Pelicula1 pelicula = Pelicula1(titulo, director, annio, genero, productora, duracion);
    return pelicula;

}

Prestamos registrarPrestamo(int pelicula){
    int usuario;
    char fechaInicial[100];

    cout<<"Ingrese el numero de usuario: "; cin>>usuario;
    cout<<"Ingrese la fecha inicial: "; cin>>fechaInicial;

    Prestamos nuevoPrestamo = Prestamos(usuario, pelicula, fechaInicial);
    return nuevoPrestamo;
}

void mostrarPeliculas(Pelicula1 peliculas[10], int contPeliculas){
    for (int i = 0; i < contPeliculas; ++i) {
        cout << "< === Pelicula # "<< (i) << endl;
        peliculas[i].toString();
    }
}

int main() {
    int opc, no, contUsuarios = 0, contPeliculas = 0, contPrestamos = 0;
    bool system = true;
    bool usuario = true;
    bool pelicula = true;
    bool prestamo = true;
    bool temp = true;
    char fechaFinal[100];

    Persona usuarios[10];
    Pelicula1 peliculas[10];
    Prestamos prestamos[10];

    while (system == true) {
        menu();
        cin >> opc;

        usuario = true;
        pelicula = true;
        prestamo = true;

        switch (opc) {
            case 1:
                while (usuario) {
                    menuUsuarios();
                    cin >> opc;
                    switch (opc) {
                        case 1:
                            cout << "====REGISTRO DE USUARIO====" << endl;
                            usuarios[contUsuarios] = registrarUsuario();
                            cout << "SE A REGISTRADO CON EXITO" << endl;
                            cout<<"================================";
                            contUsuarios++;
                            break;
                        case 2:
                            cout << "===EDITAR USUARIOS===" << endl;
                            cout << "Ingresa el numero del usuario: ";
                            cin >> no;
                            cout << "=INFORMACION DE USUARIO=" << endl;
                            usuarios[no].toString();
                            usuarios[no] = registrarUsuario();
                            cout << "===SE A CAMBIADO===" << endl;
                            break;
                        case 3:
                            cout << "===CONSULTA DE USUARIOS===" << endl;
                            cout << "Ingresa el numero del usuario: ";
                            cin >> no;
                            cout << "==INFORMACION SOBRE EL USUARIO==" << endl;
                            usuarios[no].toString();
                            break;
                        case 4:
                            cout << "===ELIMINAR A USUARIO===" << endl;
                            cout << "Ingresa el numero del usuario: ";
                            cin >> no;
                            cout << "INFORMACION DEL USUARIO" << endl;
                            usuarios[no].toString();
                            if (no == prestamos[no].getUsuario() && prestamos[no].getEstado() == 1) {
                                cout << "NO ESTA PERMITIDO ELIMINAR A UN USUARIO CON RENTA" << endl;
                            } else {
                                usuarios[no] = Persona();
                                cout << "==USUARIO ELIMINADO==" << endl;
                            }
                            break;
                        default:
                            usuario = false;
                            break;
                    }
                }
                break;
            case 2:
                while (pelicula) {
                    menuPeliculas();
                    cin >> opc;
                    switch (opc) {
                        case 1:
                            cout << "===REGISTRAR PELICULA===" << endl;
                            peliculas[contPeliculas] = registrarPelicula();
                            cout << "==REGISTRO CON EXITO==" << endl;
                            contPeliculas++;
                            break;
                        case 2:
                            cout << "===EDITAR PELICULA===" << endl;
                            cout << "Ingresa el numero de la pelicula: ";
                            cin >> no;
                            cout << "==INFORMACION SOBRE LA PELICULA==" << endl;
                            peliculas[no].toString();
                            peliculas[no] = registrarPelicula();
                            cout << "CAMBIO CON EXITO" << endl;
                            break;
                        case 3:
                            cout << "===CONSULTAR PELICULA===" << endl;
                            cout << "Ingresa el numero de la pelicula: ";
                            cin >> no;
                            cout << "INFORMACION DE LA PELICULA" << endl;
                            peliculas[no].toString();
                            break;
                        case 4:
                            cout << "===ELIMINAR PELICULA===" << endl;
                            cout << "Ingresa el numero de la pelicula: ";
                            cin >> no;
                            peliculas[no].toString();

                            if (no == prestamos[no].getPelicula() && prestamos[no].getEstado() == 1) {
                                cout << "NO SE PUEDE ELIMINAR UNA PELICULA RENTADA" << endl;
                            } else {
                                peliculas[no] = Pelicula1();
                                cout << "===PELICULA ELIMINADA===" << endl;
                            }
                            break;
                        default:
                            pelicula = false;
                            break;
                    }
                }
                break;
            case 3:
                while (prestamo) {
                    menuPrestamos();
                    cin >> opc;
                    switch (opc) {
                        case 1:
                            cout << "-===PRESTAMOS====" << endl;
                            mostrarPeliculas(peliculas, contPeliculas);
                            cout << "Ingresa el numero de la pelicula: ";
                            cin >> no;
                            temp = true;
                            for (int i = 0; i < contPrestamos; i++) {
                                if (no == prestamos[i].getPelicula() && prestamos[i].getEstado() == 1) {
                                    temp = false;
                                }
                            }
                            if (temp) {
                                prestamos[contPrestamos] = registrarPrestamo(no);
                                contPrestamos++;
                            } else {
                                cout << "La pelicula ya esta rentada" << endl;
                            }
                            break;
                        case 2:
                            cout << "===PARA DEVOLVER UNA PELICULA===" << endl;
                            cout << "Ingresa el numero de prestamo: ";
                            cin >> no;
                            usuarios[prestamos[no].getUsuario()].toString();
                            peliculas[prestamos[no].getPelicula()].toString();
                            prestamos[no].toString();
                            if (prestamos[no].getEstado() == 1) {
                                cout << "Ingresa la fecha de devolucion: ";
                                cin >> fechaFinal;
                                prestamos[no].devolucion(fechaFinal);
                                cout << "===PELICULA DEVUELTA===";
                            } else {
                                cout << "El prestamo ha sido devuelto anteriormente" << endl;
                            }
                            break;
                        case 3:
                            cout << "==CONSULTA DE PRESTAMOS==" << endl;
                            cout << "ingresa el numero de prestamo: " << endl;
                            cin >> no;
                            usuarios[prestamos[no].getUsuario()].toString();
                            peliculas[prestamos[no].getPelicula()].toString();
                            prestamos[no].toString();
                            break;
                        default:
                            prestamo = false;
                            break;
                    }
                }
                break;
            default:
                system = false;
                break;
        }
    }

    return 0;
}