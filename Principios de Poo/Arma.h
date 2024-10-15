
#ifndef ARMA_H
#define ARMA_H

typedef struct Arma {
    char nombre[40];
    int municion;
    float cadencia;
    void (*mostrar_estado)(const struct Arma* this);
} Arma;

Arma* Arma_crear(const char nombre[40], int municion, float cadencia);
void Arma_destruir(Arma* this);
void Mosatrarinfo(Arma* this);




#endif // ARMA_H