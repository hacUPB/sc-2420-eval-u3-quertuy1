#ifndef PERSONAJE_H
#define PERSONAJE_H

typedef struct Personaje {
    char nombre[30];
    int vida;
    int nivel;
    void (*mostrar_estado)(const struct Personaje* this);
} Personaje;

Personaje* Personaje_crear(const char* nombre, int vida, int nivel);
void Personaje_destruir(Personaje* this);
char* get_name(Personaje* this);


#endif // PERSONAJE_H