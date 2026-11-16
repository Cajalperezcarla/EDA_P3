/*
Autores: 
Nerea López Fernández (NIP: 966496)
Carla Genoveva Cajal Pérez (NIP: 875406)
Eva Qiuxiang Campo Calvo (NIP: 926619)
*/



#ifndef COLECCION_HPP
#define COLECCION_HPP

#include <iostream>
#include <string>
#include "fecha.hpp"
using namespace std;

//PREDECLARACION DEL TAD GENERICO coleccion (inicio INTERFAZ)
//a rellenar...

template <typename T> struct coleccion;

/* Crea una colección de ITF vacía, sin ítems.
*/
template <typename T> void crear (coleccion<T>& c);

/*Si en c no hay ningún ítem con identificador igual al de i, devuelve una colección igual a la
 resultante de añadir el ítem i a la colección c. En caso contrario, devuelve una colección
 igual a c
 */
template <typename T> void anyadir(coleccion<T>& c, const T& i);

/*Si en c no hay ningún ítem con identificador igual al de i, devuelve una colección igual a c. En
 caso contrario, devuelve una colección igual a la resultante de sustituir en c el ítem que tenía
 identificador igual al de i, por e
 */
template <typename T> void actualizar(coleccion<T>& c, const T& i);

/*Si en c hay algún ítem con identificador igual a ident, devuelve una colección igual a la
 resultante de borrar ese ítem de la colección c. En caso contrario, devuelve una colección
 igual a c
 */
template <typename T> void borrar(string ident, coleccion<T>& c);

/*Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a ident.
*/
template <typename T> bool esta(string ident, coleccion<T>& c);

/*Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
 Parcial: operación no definida si en c no hay ningún ítem con identificador igual a ident.
 */
template <typename T> T obtenerITF(string ident, coleccion<T>& c);

/*Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
 con fecha estrictamente anterior a f, y separados entre sí por la cadena
 separador
 */
template <typename T> string obsoletos(Fecha f, string separador, coleccion<T>& c);

/*Devuelve una colección igual a la resultante de eliminar de c todos los ítems con fecha
 estrictamente anterior a f.
 */
template <typename T> void purgar(Fecha f, coleccion<T>& c);

/*Devuelve verdad si y sólo si en c hay algún ítem i con tema igual a t.
 */
template <typename T> bool existeTema(string t, coleccion<T>& c);

 /*Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
 con tema igual a t, y separados entre sí por la cadena separador.}
 */
template <typename T> string delTema(string t, string separador, coleccion<T>& c);

/*Devuelve una colección igual a la resultante de eliminar de c todos los ítems i cuyo tema es
 igual a t.
 */
template <typename T> void zanjarTema(string t, coleccion<T>& c);

/*Devuelve verdad si y sólo si c no contiene ningún ítem.}
 */
template <typename T> bool esVacia(coleccion<T>& c);

/*Devuelve el número de ítems que hay en la colección c.
*/
template <typename T> int tamanyo(coleccion<T>& c);

//ITERADOR

/*Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente
 ítem a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no
 haber visitado ningún ítem.
 */
template <typename T> void iniciarIterador(coleccion<T>& c);

/*Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c, devuelve
 falso si ya se ha visitado el último ítem
 */
 template <typename T> bool existeSiguiente(coleccion<T>& c);

/*Devuelve el siguiente ítem a visitar con el iterador de la colección c.
 Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c)).
 */
 template <typename T> T siguiente(coleccion<T>& c);

/*Prepara el iterador de la colección c para que se pueda visitar el siguiente ítem, entendiendo
 por siguiente aquel ítem con (lexicográficamente) menor identificador de los todavía no
 visitados.
 Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c)).
 */
 template <typename T> void avanza(coleccion<T>& c);

 //FIN predeclaracion del TAD GENERICO coleccion (Fin INTERFAZ)


 //DECLARACION DEL TAD GENERICO coleccion
 
template<typename T>
struct coleccion{
    friend void crear<T> (coleccion<T>& c);
    friend void anyadir<T>(coleccion<T>& c, const T& i);
    friend void actualizar<T>(coleccion<T>& c, const T& i);
    friend void borrar<T>(string ident, coleccion<T>& c);
    friend bool esta<T>(string ident, coleccion<T>& c);
    friend T obtenerITF<T>(string ident, coleccion<T>& c);
    friend string obsoletos<T>(Fecha f, string separador, coleccion<T>& c);
    friend void purgar<T>(Fecha f, coleccion<T>& c);
    friend bool existeTema<T>(string t, coleccion<T>& c);
    friend string delTema<T>(string t, string separador, coleccion<T>& c);
    friend void zanjarTema<T>(string t, coleccion<T>& c);
    friend bool esVacia<T>(coleccion<T>& c);
    friend int tamanyo<T>(coleccion<T>& c);
    //OPERACIONES ITERADOR 
    friend void iniciarIterador<T>(coleccion<T>& c);
    friend bool existeSiguiente<T>(coleccion<T>& c);
    friend T siguiente<T>(coleccion<T>& c);
    friend void avanza<T>(coleccion<T>& c);
    private: //declaracion de la representacion interna del tipo 
        struct Nodo{ //clase anidada
            T dato;
            Nodo* sig; // siguiente elemento de la lista
        };
        Nodo* primero; // primer elemento de la lista, cima de la pila
        int total; // total de elementos     
        Nodo* iterador; // para poder usar el iterador (puntero auxiliar para recorrer con el iterador)
};
 
// IMPLEMENTACION DE LAS OPERACIONES DEL TAD GENERICO coleccion

/* Crea una colección de ITF vacía, sin ítems.
*/
template<typename T>
void crear(coleccion<T>& c) {
    c.primero = nullptr; //lista vacía
    c.total = 0; //nº de anuncios cero
    c.iterador = nullptr; //iterador no apunta a ningún nodo aún
}

/*Si en c no hay ningún ítem con identificador igual al de i, devuelve una colección igual a la
 resultante de añadir el ítem i a la colección c. En caso contrario, devuelve una colección
 igual a c
 */
template<typename T> 
void anyadir(coleccion<T>& c, const T& i) {
    typename coleccion<T>::Nodo* anterior = nullptr;
    typename coleccion<T>::Nodo* actual = c.primero; //busca posición correcta para mantener orden y verificar si ya estaba
    while(actual!=nullptr && identificador(actual->dato) < identificador(i)) {
        anterior = actual;
        actual = actual -> sig;
    }
    bool duplicado = (actual!=nullptr && identificador(actual->dato) == identificador(i));
    if(!duplicado) {
        typename coleccion<T>::Nodo* nuevo = new typename coleccion<T>::Nodo; //si no es duplicado creamos el nodo nuevo
        nuevo->dato = i;
        if(anterior==nullptr) { //si lista estaba vacía o es menor que el primero
            nuevo->sig = c.primero;
            c.primero = nuevo;
        } else {
            nuevo->sig = actual;
            anterior->sig = nuevo;
        }
        c.total++;
    }
}

/*Si en c no hay ningún ítem con identificador igual al de i, devuelve una colección igual a c. En
 caso contrario, devuelve una colección igual a la resultante de sustituir en c el ítem que tenía
 identificador igual al de i, por e
 */
template<typename T>
void actualizar(coleccion<T>& c, const T& i) {
    typename coleccion<T>::Nodo* actual = c.primero;
    while(actual!=nullptr && identificador(actual->dato) < identificador(i)) {
        actual = actual->sig;
    }
    if(actual!=nullptr && identificador(actual->dato) == identificador(i)) {
        actual->dato = i; //sustituye el ítem antiguo por el nuevo
    }
}

/*
 Si en c hay algún ítem con identificador igual a ident, devuelve una colección igual a la
 resultante de borrar ese ítem de la colección c. En caso contrario, devuelve una colección
 igual a c
 */
template<typename T> 
void borrar(string ident, coleccion<T>& c) {
    typename coleccion<T>::Nodo* anterior = nullptr;
    typename coleccion<T>::Nodo* actual = c.primero;
    while (actual!=nullptr && identificador(actual->dato) < ident) {
        anterior = actual;
        actual = actual->sig;
    }

    if(actual!= nullptr && identificador(actual->dato) == ident) {
        if (anterior==nullptr) { //es el primero de la lista
            c.primero = actual->sig;
        } else { //en medio o al final
            anterior->sig = actual->sig;
        }
        if(c.iterador == actual) {
            c.iterador = actual ->sig; //avanzamos el iterador
        }

        delete actual;
        c.total--;
    }
}

/*
Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a ident.
*/
template<typename T>
bool esta(string ident, coleccion<T>& c) {
    typename coleccion <T>::Nodo* actual = c.primero;
    while(actual!=nullptr && identificador(actual->dato) < ident) {
        actual = actual->sig;
    }
    return (actual!=nullptr && identificador(actual->dato) == ident);
}

/*
Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
 Parcial: operación no definida si en c no hay ningún ítem con identificador igual a ident.
 */
template<typename T> 
T obtenerITF(string ident, coleccion<T>& c) {
    typename coleccion<T>::Nodo* actual = c.primero;
    while(actual!= nullptr && identificador(actual->dato) < ident) {
        actual = actual->sig;
    }
    if(actual!=nullptr && identificador(actual->dato) == ident) {
        return actual->dato;
    }
    return actual->dato;
}

/*
 Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
 con fecha estrictamente anterior a f, y separados entre sí por la cadena
 separador
 */
template<typename T>
string obsoletos(Fecha f, string separador, coleccion<T>& c) {
    string resultado="";
    typename coleccion<T>::Nodo* actual= c.primero;
    bool primerElemento = true; //controla donde coloca el separador
    while(actual!=nullptr) {
        if(anterior(fecha(actual->dato), f)) {
            if(!primerElemento) {
                resultado+=separador;
            }
            resultado+=identificador(actual->dato);
            primerElemento=false;
        }
        actual = actual->sig;
    }
    return resultado;
}

/*
 Devuelve una colección igual a la resultante de eliminar de c todos los ítems con fecha
 estrictamente anterior a f.
 */
template<typename T> 
void purgar(Fecha f, coleccion<T>& c) {
    typename coleccion<T>::Nodo* previo = nullptr;
    typename coleccion<T>::Nodo* actual = c.primero;
    while(actual!= nullptr) {
        if(anterior(fecha(actual->dato), f)) {
            typename coleccion<T>::Nodo* aBorrar = actual;
            if(previo==nullptr) {
                c.primero=actual->sig;
                actual= c.primero;
            } else {
                previo->sig = actual->sig;
                actual = actual->sig;
            }
            if(c.iterador ==aBorrar) {
                c.iterador = actual;
            }
            delete aBorrar;
            c.total--;
        } else {
            previo = actual;
            actual = actual->sig;
        }
    }
}

/*
 Devuelve verdad si y sólo si en c hay algún ítem i con tema igual a t.
 */
template<typename T> 
bool existeTema(string t, coleccion<T>& c) {
    typename coleccion<T>::Nodo* actual = c.primero;
    bool encontrado = false;
    while(actual!=nullptr && !encontrado) {
        if(tema(actual->dato) == t) {
            encontrado=true;
        } else {
            actual = actual -> sig;
        }
    }
    return encontrado;
}

/*
 Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
 con tema igual a t, y separados entre sí por la cadena separador.}
 */
template<typename T> 
string delTema(string t, string separador, coleccion<T>& c) {
    string resultado = "";
    typename coleccion<T>::Nodo* actual = c.primero;
    bool primerElemento = true;
    while(actual!=nullptr) {
        if (tema(actual->dato) == t) {
            if(!primerElemento) {
                resultado+= separador;
            }
            resultado+=identificador(actual->dato);
            primerElemento = false;
        }
        actual = actual->sig;
    }
    return resultado;
}

/*
 Devuelve una colección igual a la resultante de eliminar de c todos los ítems i cuyo tema es
 igual a t.
 */
template<typename T> 
void zanjarTema(string t, coleccion<T>& c) {
    typename coleccion<T>::Nodo* anterior = nullptr;
    typename coleccion<T>::Nodo* actual = c.primero;
    while(actual!=nullptr) {
        if(tema(actual->dato) == t) {
            typename coleccion<T>::Nodo* aBorrar = actual;
            if(anterior ==nullptr) {
                c.primero = actual->sig;
                actual = c.primero;
            } else {
                anterior->sig = actual->sig;
                actual = actual->sig;
            }
            if (c.iterador == aBorrar) {
                c.iterador = actual;
            }
            delete aBorrar;
            c.total--;
        } else {
            anterior = actual;
            actual = actual->sig;
        }
    }
}

/*
 Devuelve verdad si y sólo si c no contiene ningún ítem.}
 */
template<typename T> 
bool esVacia(coleccion<T>& c) {
    return (c.primero == nullptr);
}

/*
 Devuelve el número de ítems que hay en la colección c.
*/
template<typename T> 
int tamanyo(coleccion<T>& c) {
    return c.total;
}

/*
Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente
 ítem a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no
 haber visitado ningún ítem.
 */
template<typename T> 
void iniciarIterador(coleccion<T>& c) {
    c.iterador = c.primero;
}

/*
Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c, devuelve
 falso si ya se ha visitado el último ítem
 */
template<typename T> 
bool existeSiguiente(coleccion<T>& c) {
    return (c.iterador!=nullptr);
}

/*
 Devuelve el siguiente ítem a visitar con el iterador de la colección c.
 Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c)).
 */
template<typename T> 
T siguiente(coleccion<T>& c) {
    return c.iterador->dato;
}

/*
 Prepara el iterador de la colección c para que se pueda visitar el siguiente ítem, entendiendo
 por siguiente aquel ítem con (lexicográficamente) menor identificador de los todavía no
 visitados.
 Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c)).
 */
template<typename T> 
void avanza(coleccion<T>& c) {
    c.iterador = c.iterador->sig;
}

#endif //fin de coleccionITF.hpp