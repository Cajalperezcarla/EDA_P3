/*
Autores: 
Nerea López Fernández (NIP: 966496)
Carla Genoveva Cajal Pérez (NIP: 875406)
Eva Qiuxiang Campo Calvo (NIP: 926619)
*/


#include "anuncio.hpp"

// Implementación de las operaciones del TAD

/* Devuelve un anuncio compuesto con identificador ID, título t, descripción descrip, categoría
categ, y con Fecha de publicación publi y Fecha de finalización fi. */
void crearAnuncio(string ID, string t, string descrip, string categ, Fecha publi, Fecha fi, Anuncio& e) {
    e.identificador = ID;
    e.titulo = t;
    e.descripcion = descrip;
    e.categoria = categ;
    e.publicacion = publi;
    e.finalizacion = fi;
}

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve I, i.e. el identificador del anuncio e. */
string suIdentificador(const Anuncio& e) {
    return e.identificador;
}

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve T, i.e. el título del anuncio e. */
string suTitulo(const Anuncio& e) {
    return e.titulo;
}

/* Dado un anuncio e formado como (I,T,D,C,P,F) y una cadena n, devuelve un anuncio igual al
compuesto como (I,n,D,C,P,F). */
void cambiarTitulo(Anuncio &e, string n) {
    e.titulo = n;
}

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve D, i.e. la descripción del anuncio e. */
string suDescripcion(const Anuncio& e) {
    return e.descripcion;
}

/* Dado un anuncio e formado como (I,T,D,C,P,F) y una cadena n, devuelve un anuncio igual al
compuesto como (I,T,n,C,P,F). */
void cambiarDescripcion(Anuncio &e, string n) {
    e.descripcion = n;
}

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve C, i.e. la categoría del anuncio e. */
string suCategoria(const Anuncio& e) {
    return e.categoria;
}

/* Dado un anuncio e formado como (I,T,D,C,P,F) y una cadena n, devuelve un anuncio igual al
compuesto como (I,T,D,n,P,F). */
void cambiarCategoria(Anuncio &e, string n) {
    e.categoria = n;
}

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve P, i.e. la Fecha de publicación de e. */
Fecha suPublicacion(const Anuncio& e) {
    return e.publicacion;
}

/* Dado un anuncio e formado como (I,T,D,C,P,F) devuelve F, i.e. la Fecha de finalización de e. */
Fecha suFinalizacion(const Anuncio& e) {
    return e.finalizacion;
}

/* Operación que devuelve cadena con el identificador del ítem i. */
string identificador(const Anuncio& i) {
    return suIdentificador(i);
}

/* Operación que devuelve una cadena con el tema del ítem i. */
string tema(const Anuncio& i) {
    return suCategoria(i);
}

/* Operación que devuelve la fecha perteneciente al ítem i. */
Fecha fecha(const Anuncio& i) {
    return suPublicacion(i);
}