/*
Autores: 
Nerea López Fernández (NIP: 966496)
Carla Genoveva Cajal Pérez (NIP: 875406)
Eva Qiuxiang Campo Calvo (NIP: 926619)
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "anuncio.hpp"
#include "coleccionITF.hpp"
using namespace std;


bool leerFecha(ifstream& entrada, Fecha& f);
bool leerAnuncio(ifstream& entrada, Anuncio& a);
string leerIdentificador (ifstream& entrada);
string leerCategoria(ifstream& entrada);
void escribirFecha(ofstream& salida, const Fecha& f);
void escribirAnuncio(ofstream& salida, const Anuncio& a);
void escribirListadoAnuncios(ofstream& salida, coleccion<Anuncio>& c);
void escribirIdentificadores(ofstream& salida, const string& identificadores);

// Funciones auxiliares
// Para A, C, P, LO
bool leerFecha(ifstream& entrada, Fecha& f) {

    string cadena;
    bool error;

    if (!getline(entrada, cadena)) {
        return false;
    }
    if (cadena.length() != 10 || cadena[4] != '-' || cadena[7] != '-') {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && (cadena[i] < '0' || cadena[i] > '9')) {
            return false;
        }
    }

    int a = (cadena[0] - '0') * 1000 + (cadena[1] - '0') * 100 + (cadena[2] - '0') * 10 + (cadena[3] - '0');
    int m = (cadena[5] - '0') * 10 + (cadena[6] - '0');
    int d = (cadena[8] - '0') * 10 + (cadena[9] - '0');

    crear(d, m, a, f, error);

    return !error;
}


// Para A, C
bool leerAnuncio(ifstream& entrada, Anuncio& a) {

    string identificador, titulo, descripcion, categoria;
    Fecha publicacion, finalizacion;

    if (!getline(entrada, identificador) || !getline(entrada, titulo) || !getline(entrada, descripcion) || !getline(entrada, categoria)) {
        return false;
    }
    if (!leerFecha(entrada, publicacion) || !leerFecha(entrada, finalizacion)) {
        return false;
    }

    crearAnuncio(identificador, titulo, descripcion, categoria, publicacion, finalizacion, a);

    return true;
}


// Para O, E, B
string leerIdentificador(ifstream& entrada) {
    string identificador;
    entrada >> identificador;
    return identificador;
}

// Para EC, BC, LC
string leerCategoria(ifstream& entrada) {
    string cat;
    getline(entrada,cat);
    return cat;
}

// Para A, C, O, P, LO, LT
void escribirFecha(ofstream& salida, const Fecha& f) {
    salida << setfill('0') << setw(4) << anyo(f) << "-" << setw(2) << mes(f) << "-" << setw(2) << dia(f);
    salida << setfill(' ');
}

// Para A, C, O
void escribirAnuncio(ofstream& salida, const Anuncio& a) {
    salida << suIdentificador(a) << ":::" << suTitulo(a) << ":::" << suCategoria(a) << ":::" << suDescripcion(a) << ":::";
    escribirFecha(salida, suPublicacion(a));
    salida << ":::";
    escribirFecha(salida, suFinalizacion(a));
    salida << endl;
}

// Para LT
void escribirListadoAnuncios(ofstream& salida, coleccion<Anuncio>& c) {

    salida << "-----LISTADO: " << tamanyo(c) << endl;
    iniciarIterador(c);

    while (existeSiguiente(c)) {

        Anuncio a = siguiente(c);

        salida << "[ " << suIdentificador(a) << " -de-> " << suCategoria(a) << " ;;; " << suTitulo(a) << " ] (";
        escribirFecha(salida, suPublicacion(a));
        salida << ") --- " << suDescripcion(a) << " --- (";
        escribirFecha(salida, suFinalizacion(a));
        salida << ")" << endl;

        avanza(c);
    }
    salida << "-----" << endl;
}

// Para LO, LC
void escribirIdentificadores(ofstream& salida, const string& identificadores) {
    salida << " --- " << identificadores << " --- " << endl;
}

// Añade un anuncio a la colección
void procesarA(ifstream& entrada, ofstream& salida, coleccion<Anuncio>& c) {
    Anuncio a;
    bool anuncioLeido = leerAnuncio(entrada, a); // Siempre va a poder leer el anuncio
    string identificador = suIdentificador(a);
    bool anuncioRepetido = esta(identificador, c); // Ya hay un anuncio con ese identificador en c
    if (!anuncioRepetido) {
        anyadir(c, a);
        salida << "INTRODUCIDO: ";
    } else {
        salida << "NO INTRODUCIDO: ";
    }
    escribirAnuncio(salida, a);
}

// Cambia un anuncio de la colección
void procesarC(ifstream& entrada, ofstream& salida, coleccion<Anuncio>& c) {
    Anuncio a;
    bool anuncioLeido = leerAnuncio(entrada, a);
    string identificador = suIdentificador(a);
    bool anuncioExistente = esta(identificador, c);
    
    if (anuncioExistente){
        //escribe linea fich salida de anuncio cambiado
        actualizar(c,a);
        salida << "CAMBIADO: ";
        escribirAnuncio(salida,a);
        salida << endl;
    }else{
        //escribe linea fich salida de anuncio no cambiado
        salida << "NO CAMBIADO: ";
        salida << identificador << endl;
    }

}

// Obtiene la información de un anuncio de la colección
void procesarO(ifstream& entrada ,ofstream& salida, coleccion<Anuncio>& c) {
    string identificador = leerIdentificador(entrada);
    if(esta(identificador,c)) {
        Anuncio a = obtenerITF(identificador,c);
        salida << "LOCALIZADO: ";
        escribirAnuncio(salida,a);
    } else {
        salida << "NO LOCALIZADO: " << identificador << endl;
    }
}


// Comprueba que existe un anuncio por identificador
void procesarE(ifstream& entrada, ofstream& salida, coleccion<Anuncio>& c) {
    string identificador = leerIdentificador(entrada);
    if(esta(identificador,c)) {
        salida << "EXISTENTE: " << identificador << endl;
    } else {
        salida << "DESCONOCIDO: " << identificador << endl;
    }
}


// Comprueba que existe un anuncio por categoría
void procesarEC(ifstream& entrada, ofstream& salida, coleccion<Anuncio> c) {
    string categoria = leerCategoria(entrada);
    
    if (existeTema(categoria,c)) {
        salida << "CATEGORIA CONOCIDA: " << categoria << endl;
    } else {
        salida << "CATEGORIA DESCONOCIDA: " << categoria << endl;
    }
}

// Borra un anuncio de la colección
void procesarB(ifstream& entrada, ofstream& salida, coleccion<Anuncio>& c) {
    string identificador = leerIdentificador(entrada);

    if( esta(identificador, c ) ){
        borrar(identificador,c);
        salida << "BORRADO: " << identificador << endl;
    }else{
        salida << "NO BORRADO: " << identificador << endl;
    }
    
}

// Borra todos los anuncios de la colección de una categoría dada
void procesarBC(ifstream& entrada, ofstream& salida, coleccion<Anuncio>& c) {
    string categoria = leerCategoria(entrada);

    if(existeTema(categoria,c)){
        zanjarTema(categoria,c);
        salida << "ELIMINADOS: " << categoria << endl;
    }else{
        salida << "NO ELIMINADOS: " << categoria << endl;
    }
}

// Purga la colección: borra todos los anuncios con fecha anterior a la dada
void procesarP(ifstream& entrada, ofstream& salida, coleccion<Anuncio>& c) {
    Fecha f;
    leerFecha(entrada, f);

    if(!obsoletos(f, "", c).empty()){
        purgar(f,c);
        salida << "PURGADOS: ";
        escribirFecha(salida,f);
        salida << endl;
        
    }else{
        salida << "NO PURGADOS: ";
        escribirFecha(salida,f);
        salida << endl;
        
    }
}

// Lista los identificadores de los anuncios obsoletos de la colección
void procesarLO(ifstream& entrada, ofstream& salida, coleccion<Anuncio>& c) {
    Fecha f;
    leerFecha(entrada, f);

    salida << "ANTERIORES A: ";
    escribirFecha(salida, f);
    escribirIdentificadores(salida,obsoletos(f,":::",c));
    salida << endl;
}

// Lista los identificadores de los anuncios de una categoría dada
void procesarLC(ifstream& entrada, ofstream& salida, coleccion<Anuncio>& c) {
    string categoria = leerCategoria(entrada);

    salida << "DE CATEGORIA: " << categoria;
    escribirIdentificadores(salida, delTema(categoria,":::",c));
    salida << endl;
}

// Lista la información de todos los anuncios por orden lexicográfico
void procesarLT(ifstream& entrada, ofstream& salida, coleccion<Anuncio>& c) {
    escribirListadoAnuncios(salida, c);
}
// Programa de prueba que gestiona una colección de anuncios
int main () {

    // Crea una colección vacía de anuncios
    coleccion<Anuncio> c;
    crear(c);

    // Abre entrada.txt para lectura y salida.txt para escritura
    ifstream f_entrada;
    f_entrada.open("entrada.txt");
    if (!f_entrada.is_open()) {
        cerr << "Error al abrir entrada.txt" << endl;
        return 1;
    }

    ofstream f_salida;
    f_salida.open("salida.txt");
    if (!f_salida.is_open()) {
        cerr << "Error al abrir salida.txt" << endl;
        return 1;
    }

    // Lee y procesa las instrucciones
    string instruccion;
    string salto;

    while (f_entrada >> instruccion) {
        getline(f_entrada,salto);

        if (instruccion == "A") {
            procesarA(f_entrada, f_salida, c);
        } else if (instruccion == "C") {
            procesarC(f_entrada, f_salida, c);
        } else if (instruccion == "O") {
            procesarO(f_entrada, f_salida, c);
        } else if (instruccion == "E") {
            procesarE(f_entrada, f_salida, c);
        } else if (instruccion == "EC") {
            procesarEC(f_entrada, f_salida, c);
        } else if (instruccion == "B") {
            procesarB(f_entrada, f_salida, c);
        } else if (instruccion == "BC") {
            procesarBC(f_entrada, f_salida, c);
        } else if (instruccion == "P") {
            procesarP(f_entrada, f_salida, c);
        } else if (instruccion == "LO") {
            procesarLO(f_entrada, f_salida, c);
        } else if (instruccion == "LC") {
            procesarLC(f_entrada, f_salida, c);
        } else if (instruccion == "LT") {
            procesarLT(f_entrada, f_salida, c);
        }
    }
    
    // Cierra los ficheros
    f_entrada.close();
    f_salida.close();

    return 0;
}
