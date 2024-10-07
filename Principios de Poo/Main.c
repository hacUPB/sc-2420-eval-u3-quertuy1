#include <stdio.h>
#include "Personaje.h"
#include "Arma.h"
int main(void)
{
	Personaje* Mago;
	Mago= Personaje_crear("Gandalf", 3,10);
	printf("El nombre del mago es %s \n", get_name(Mago));

	Personaje_destruir(Mago);

	Arma* Fusil;

	Fusil = Arma_crear("Cualquiera", 48, 3.7);
	Mostrarinfo(Fusil);
	
}