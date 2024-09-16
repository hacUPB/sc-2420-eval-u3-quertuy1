#include "Arma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void mostrar_estado_impl(const Arma* this) {
    printf("Personaje: %s | Vida: %d | Nivel: %d\\n", this->nombre, this->municion, this->cadencia);
}

Arma* Arma_crear(const char nombre[40], int municion, float cadencia) {
    Arma* nueva_arma = (Arma*)malloc(sizeof(Arma));
    if (!nueva_arma) return NULL;
    strcpy_s(nueva_arma->nombre, 30, nombre);

    //nuevo_personaje->nombre = strdup(nombre)
    nueva_arma-> municion= municion;
    nueva_arma->cadencia = cadencia;
    nueva_arma->mostrar_estado = mostrar_estado_impl;
    return nueva_arma;
}
void Mosatrarinfo(Arma* this)
{
    printf("nombre: %s \n municion: %i \n cadencia: %f  ", this->nombre, this->municion, this->cadencia);
}
void Arma_destruir(Arma* this) {
    if (this) {
        //free(this->nombre);
        free(this);
    }
}