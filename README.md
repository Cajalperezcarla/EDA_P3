# Práctica 3 \- Implementación lineal en memoria dinámica de TAD genéricos.

## Descripción

Implementación en C\+\+ de una colección genérica de ítems temáticos fechados (colecciónITF) utilizando memoria dinámica y una lista enlazada ordenada.

La práctica incluye además la implementación del TAD anuncio y un programa principal para la gestión automática de anuncios mediante lectura de instrucciones desde un fichero de entrada y generación de resultados en un fichero de salida.

## Objetivos

- Implementar el TAD anuncio.
- Implementar el TAD genérico colecciónITF.
- Utilizar memoria dinámica mediante listas enlazadas ordenadas.
- Gestionar anuncios a través de operaciones de inserción, modificación, consulta y borrado.
- Procesar órdenes almacenadas en un fichero de texto.
- Generar automáticamente un fichero con los resultados obtenidos.

## Funcionalidades

El programa permite:

- Añadir anuncios.
- Modificar anuncios existentes.
- Consultar anuncios por identificador.
- Comprobar la existencia de anuncios.
- Buscar anuncios por categoría.
- Eliminar anuncios concretos o por categoría.
- Purgar anuncios según fecha.
- Listar anuncios obsoletos.
- Mostrar todos los anuncios almacenados ordenados lexicográficamente.

## Estructura del proyecto

.

├── anuncio.cpp

├── anuncio.h

├── coleccionITF.cpp

├── coleccionITF.h

├── fecha.cpp

├── fecha.h

├── main.cpp

├── entrada.txt

├── salida.txt

└── README.md

## Compilación

Compilar con soporte para C\+\+11:

g\+\+ \-std=c\+\+11 \*.cpp \-o practica3

## Ejecución

./practica3

El programa leerá automáticamente el fichero:

entrada.txt

y generará:

salida.txt

## Restricciones de la práctica

- No se utiliza Programación Orientada a Objetos.
- No se utilizan excepciones.
- No se emplea STL ni bibliotecas equivalentes.
- La implementación se realiza íntegramente mediante TADs y memoria dinámica.

## Autor

Carla Genoveva Cajal Pérez

## Asignatura

Estructuras de Datos y Algoritmos (EDA)

Universidad de Zaragoza

