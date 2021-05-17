
/***********************************************
*
* @Proposito: main
* @Autor/es: Faozi Bouybaouene Gadrouz
* @Fecha creacion: 11 de abril 2021
* @Fecha ultima modificacion: 8 Mayo 2021
*
************************************************/

//librerias sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//librerias propias
#include "libreria_ficheros_head.h"

int main()
{
    Names nameBands;

    //Inicialización de nombres 
    strcpy(nameBands.bandsFileName, "");
    strcpy(nameBands.musiciansFileName, "");
    strcpy(nameBands.venuesFileName, "");


    //Carga de los ficheros
    nameBands = filesRead(nameBands);

    //Mostrado de menú y acciones posibles para ejecutar.
    menuActions(nameBands);

    return 0;
}