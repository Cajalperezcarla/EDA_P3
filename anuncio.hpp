#ifndef ANUNCIO_HPP
#define ANUNCIO_HPP

#include <iostream>
#include <string>
#include "fecha.hpp"
using namespace std;

// PREDECLARACION DEL TAD Anuncio (inicio INTERFAZ)

/* Los valores del TAD anuncio representarán tuplas formadas como:
(identificador, título, descripción, categoría, publicación, finalización), siendo publicación y
finalización sendas Fechas (válidas según el calendario gregoriano), y el resto sendas cadenas. */
struct Anuncio;

/* Devuelve un anuncio compuesto con identificador ID, título t, descripción descrip, categoría
categ, y con Fecha de publicación publi y Fecha de finalización fi. */
void crearAnuncio(string ID, string t, string descrip, string categ, Fecha publi, Fecha fi, Anuncio& e);

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve I, i.e. el identificador del anuncio e. */
string suIdentificador(const Anuncio& e);

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve T, i.e. el título del anuncio e. */
string suTitulo(const Anuncio& e);

/* Dado un anuncio e formado como (I,T,D,C,P,F) y una cadena n, devuelve un anuncio igual al
compuesto como (I,n,D,C,P,F). */
void cambiarTitulo(Anuncio &e, string n);

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve D, i.e. la descripción del anuncio e. */
string suDescripcion(const Anuncio& e);

/* Dado un anuncio e formado como (I,T,D,C,P,F) y una cadena n, devuelve un anuncio igual al
compuesto como (I,T,n,C,P,F). */
void cambiarDescripcion(Anuncio &e, string n);

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve C, i.e. la categoría del anuncio e. */
string suCategoria(const Anuncio& e);

/* Dado un anuncio e formado como (I,T,D,C,P,F) y una cadena n, devuelve un anuncio igual al
compuesto como (I,T,D,n,P,F). */
void cambiarCategoria(Anuncio &e, string n);

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve P, i.e. la Fecha de publicación de e. */
Fecha suPublicacion(const Anuncio& e);

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve F, i.e. la Fecha de finalización de e. */
Fecha suFinalizacion(const Anuncio& e);

/* Operación que devuelve cadena con el identificador del ítem i. */
string identificador(const Anuncio& i);

/* Operación que devuelve una cadena con el tema del ítem i. */
string tema(const Anuncio& i);

/* Operación que devuelve la fecha perteneciente al ítem i. */
Fecha fecha(const Anuncio& i);


// FIN de la PREDECLARACION DEL TAD Anuncio (fin INTERFAZ)

// DECLARACION DEL TAD Anuncio 

struct Anuncio{
    friend void crearAnuncio(string ID, string t, string descrip, string categ, Fecha publi, Fecha fi, Anuncio& e);
    friend string suIdentificador(const Anuncio& e);
    friend string suTitulo(const Anuncio& e);
    friend void cambiarTitulo(Anuncio &e, string n);
    friend string suDescripcion(const Anuncio& e);
    friend void cambiarDescripcion(Anuncio &e, string n);
    friend string suCategoria(const Anuncio& e);
    friend void cambiarCategoria(Anuncio &e, string n);
    friend Fecha suPublicacion(const Anuncio& e);
    friend Fecha suFinalizacion(const Anuncio& e);
    friend string identificador(const Anuncio& i);
    friend string tema(const Anuncio& i);
    friend Fecha fecha(const Anuncio& i);

    private:
    string identificador;
    string titulo;
    string descripcion;
    string categoria;
    Fecha publicacion;
    Fecha finalizacion;
};

#endif