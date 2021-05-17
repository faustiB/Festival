
/***********************************************
*
* @Proposito: libreria de acciones
* @Autor/es: Faozi Bouybaouene Gadrouz
* @Fecha creacion: 11 de Abril 2021
* @Fecha ultima modificacion:8 Mayo 2021
*
************************************************/
// librerias sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//libreria propias
#include "libreria_ficheros_head.h"

//constantes
#define MAX_FILENAME 30
#define MAX_LINE 50
#define MAX_LEN 50


/***********************************************
*
* @Finalidad: Función creada para la lectura del fichero bands..
* @Parametros:
*  - Names fileNames -- struct con los nombres del fichero
* @Retorno: 
* - Names fileNames -- struct con los nombres del fichero
************************************************/

Names readBands(Names fileNames)
{

    FILE *filePointer;
    char fileName[MAX_FILENAME];

    printf("\t- Bands: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "r");
    if (filePointer == NULL)
    {
        printf("ERROR: Can't open file '%s'\n", fileName);
    }
    else
    {
        strcpy(fileNames.bandsFileName, fileName);
        fclose(filePointer);
    }

    return fileNames;
}


/***********************************************
*
* @Finalidad: Función creada para la lectura del fichero Musicians.
* @Parametros:
*  - Names fileNames -- struct con los nombres del fichero
* @Retorno: 
* - Names fileNames -- struct con los nombres del fichero
************************************************/

Names readMusicians(Names fileNames)
{

    FILE *filePointer;
    char fileName[MAX_FILENAME];

    printf("\t- Musicians: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "r");
    if (filePointer == NULL)
    {
        printf("ERROR: Can't open file '%s'\n", fileName);
    }
    else
    {
        strcpy(fileNames.musiciansFileName, fileName);
        fclose(filePointer);
    }

    return fileNames;
}

/***********************************************
*
* @Finalidad: Función creada para la lectura del fichero venues.
* @Parametros:
*  - Names fileNames -- struct con los nombres del fichero
* @Retorno: 
* - Names fileNames -- struct con los nombres del fichero
************************************************/


Names readVenues(Names fileNames)
{

    FILE *filePointer;
    char fileName[MAX_FILENAME];

    printf("\t- Venues: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "r");
    if (filePointer == NULL)
    {
        printf("ERROR: Can't open file '%s'\n", fileName);
    }
    else
    {
        strcpy(fileNames.venuesFileName, fileName);
        fclose(filePointer);

    }

    return fileNames;
}



/***********************************************
*
* @Finalidad: Función creada para la lectura inicial de ficheros.
* @Parametros:
*  - Names fileNames -- struct con los nombres del fichero
* @Retorno: 
* - Names fileNames -- struct con los nombres del fichero
************************************************/

Names filesRead(Names fileNames)
{

    int exit = 0, c = 0;

    printf("\nWelcome!\n\n");
    printf("Introduce the file names: \n");

    while (exit == 0)
    {
        switch (c)
        {
        case 0:

            //Lectura del fichero Bands
            fileNames = readBands(fileNames);

            //Check filename de band viene lleno
            if (strlen(fileNames.bandsFileName) > 0)
            {
                c++;
            }

            break;

        case 1:

            //Lectura del fichero Musicians
            fileNames = readMusicians(fileNames);
            //Check filename de musicians viene lleno
            if (strlen(fileNames.musiciansFileName) > 0)
            {
                c++;
            }
            break;

        case 2:

            //Lectura del fichero Venues
            fileNames = readVenues(fileNames);
            //Check filename de venues viene lleno
            if (strlen(fileNames.venuesFileName) > 0)
            {
                c++;
            }
            if (c > 2)
            {
                exit = 1;
            }
            break;
        default:
            break;
        }
    }

    return fileNames;
}

/***********************************************
*
* @Finalidad: Función Creada para rellenear el struct de los Musicians. 
* @Parametros:
*  - char name_band[MAX_LEN] -- nombre de la banda 
*  - int quantity_musicians -- cantidad de músicos
*  - Names fileNames -- struct con los nombres del fichero
* @Retorno: 
* - Names fileNames -- struct con los nombres del fichero
************************************************/

Musician *fillMusiciansStruct(char name_band[MAX_LEN], int quantity_musicians, int first, Names fileNames)
{

    FILE *filePointer;
    Musician *musicians;
    int quantity_elements, i = 0, age_aux;
    char name_singer_aux[MAX_LEN], name_band_aux[MAX_LEN];

    filePointer = fopen(fileNames.musiciansFileName, "r");
    if (filePointer == NULL)
    {
        printf("ERROR: Can't open file 'musicians'\n");
    }
    else
    {

        //Lectura cantidad de elementos
        fscanf(filePointer, " %d ", &quantity_elements);

        //Reserva de memoria para los músicos totales
        musicians = (Musician *)malloc(sizeof(Musician) * quantity_musicians);

        while (!feof(filePointer))
        {
            //Lectura del fichero
            fgets(name_singer_aux, MAX_LINE, filePointer);
            name_singer_aux[strlen(name_singer_aux) - 1] = '\0';
            fgets(name_band_aux, MAX_LINE, filePointer);
            fscanf(filePointer, " %d ", &age_aux);

            //Check que la banda leída en el fichero, es la introducida en el método
            if (strcmp(name_band, name_band_aux) == 0)
            {
                //Asignación de valores
                strcpy(musicians[i].name, name_singer_aux);
                musicians[i].age = age_aux;

                i++;
            }
        }
        fclose(filePointer);
    }

    return musicians;
}


/***********************************************
*
* @Finalidad:  Función creada para rellenar el structs de las bands. 
* @Parametros:
*  - Names fileNames -- struct con los nombres del fichero
* @Retorno: 
* - Names fileNames -- struct con los nombres del fichero
************************************************/
Band *fillBandsStruct(Names fileNames)
{
    FILE *filePointer;
    Band *bands;
    char aux[MAX_LINE];
    int quantity_elements, quantity_musicians, i = 0;

    filePointer = fopen(fileNames.bandsFileName, "r");
    if (filePointer == NULL)
    {
        printf("ERROR: Can't open file 'bands'");
    }
    else
    {
        //Lectura de la cantidad de elementos.
        fscanf(filePointer, "%d", &quantity_elements);
        //reserva de memoria para las bandas
        bands = (Band *)malloc(sizeof(Band) * quantity_elements);

        //lectura auxiliar
        fgets(aux, MAX_LINE, filePointer);

        while (!feof(filePointer))
        {

            //Lectura del nombre de la banda
            fgets(bands[i].name, MAX_LINE, filePointer);
            //bands[i].name[strlen(bands[i].name) - 1] = '\0';

            //lectura del cache
            fscanf(filePointer, " %d ", &bands[i].cache);

            //lectura de la cantidad de musicos
            fscanf(filePointer, " %d ", &quantity_musicians);
            // Reserva de memoria para la cantidad de músicos
            bands[i].musicians = (Musician *)malloc(sizeof(Musician) * quantity_musicians);
            bands[i].num_musicians = quantity_musicians;

            bands[i].musicians = fillMusiciansStruct(bands[i].name, bands[i].num_musicians, i,fileNames);

            i++;
        }
    }

    fclose(filePointer);
    return bands;
}


/***********************************************
*
* @Finalidad:  Función creada para rellenar el structs de las venues. 
* @Parametros:
*  - Names fileNames -- struct con los nombres del fichero
* @Retorno: 
* - Names fileNames -- struct con los nombres del fichero
************************************************/
Venue *fillVenueStruct(Names fileNames)
{

    FILE *filePointer;
    Venue *venues;
    char aux[MAX_LINE];
    int quantity_elements, i = 0;

    filePointer = fopen(fileNames.venuesFileName, "r");
    if (filePointer == NULL)
    {
        printf("ERROR: Can't open file 'Venues'\n");
    }
    else
    {
        //Lectura de la cantidad de elementos.
        fscanf(filePointer, "%d", &quantity_elements);
        //reserva de memoria para las bandas
        venues = (Venue *)malloc(sizeof(Venue) * quantity_elements);

        //lectura auxiliar
        fgets(aux, MAX_LINE, filePointer);
        while (!feof(filePointer))
        {
            //Lectura del nombre de la Venue
            fgets(venues[i].name, MAX_LINE, filePointer);

            //Lectura de la capacidad
            fscanf(filePointer, " %d ", &venues[i].capacity);

            i++;
        }
    }

    fclose(filePointer);
    return venues;
}

/***********************************************
*
* @Finalidad:  Función creada para liberar memoria
* @Parametros:
*  - Band *bands -- struct bandas 
*  - Venue *venues -- struct venues 
* @Retorno: 
************************************************/

void freeMemory(Band *bands, Venue *venues)
{

    free(bands->musicians);
    free(bands);
    free(venues);
}


/***********************************************
*
* @Finalidad:  Función creada para leer la primera línea del fichero. Todos los ficheros tienen en la primera línea la
    cantidad de elementos que tiene el fichero, por lo que esta función lee la primera línea y devuelve la 
    cantidad de elementos. 
* @Parametros:
*  - char nameOfFile[MAX_LEN] -- nombre del fichero
*  - Venue *venues -- struct venues 
* @Retorno: int -- cantidad 
************************************************/


int getQuantityOfElementsInFile(char nameOfFile[MAX_LEN])
{

    FILE *filePointer;
    int quantity_elements;

    filePointer = fopen(nameOfFile, "r");
    if (filePointer == NULL)
    {
        printf("ERROR: Can't open file '%s'",nameOfFile);
    }
    else
    {
        //Lectura de la cantidad de elementos.
        fscanf(filePointer, "%d", &quantity_elements);
        fclose(filePointer);
    }

    return (quantity_elements);
}

/***********************************************
*
* @Finalidad:  Funcion creada para mostrar las bandas 
* @Parametros:
*  - Names fileNames -- struct con nombres de ficheros
* @Retorno: 
************************************************/

void showBands(Names fileNames)
{

    Band *bands;
    int i, quantity_bands;

    //Llenado de los datos del fichero
    bands = fillBandsStruct(fileNames);

    //lectura de cuántos elementos hay en el fichero
    quantity_bands = getQuantityOfElementsInFile(fileNames.bandsFileName);

    //Mostrado de todas las bandas que se han llenado en el struct.
    printf("\nBands: \n");
    for (i = 1; i <= quantity_bands; i++)
    {
        printf("\t%d - %s", i, bands[i - 1].name);
    }

    //Liberado de memoria
    free(bands->musicians);
    free(bands);
}

/***********************************************
*
* @Finalidad:  Funcion creada para mostrar los Venues
* @Parametros:
*  - Names fileNames -- struct con nombres de ficheros
* @Retorno: 
************************************************/

void showVenues(Names fileNames)
{

    Venue *venues;
    int i, quantity_venues;

    //Llenado de los datos del fichero
    venues = fillVenueStruct(fileNames);

    //lectura de cuántos elementos hay en el fichero
    quantity_venues = getQuantityOfElementsInFile(fileNames.venuesFileName);

    //Mostrado de todas las venues que se han llenado en el struct.
    printf("\nVenues: \n");
    for (i = 1; i <= quantity_venues; i++)
    {
        printf("\t%d - %s", i, venues[i - 1].name);
    }

    //liberado de memoria
    free(venues);
}


/***********************************************
*
* @Finalidad:  FFunción para la opcion 1. Show bands or venues
* @Parametros:
*  - Names fileNames -- struct con nombres de ficheros
* @Retorno: 
************************************************/
void doActionShowBandsVenues(Names fileNames)
{

    int eleccion, exit = 0;

    while (exit == 0)
    {
        //Petición y elección de la opción.
        printf("\n1. Show bands | 2. Show Venues");
        printf("\nSelect option: ");
        scanf("%d", &eleccion);
        switch (eleccion)
        {
        case 1:

            showBands(fileNames);
            exit = 1;
            break;

        case 2:

            showVenues(fileNames);
            exit = 1;
            break;

        default:
            //Error handling
            printf("ERROR: Wrong option number \n");
            break;
        }
    }
}


/***********************************************
*
* @Finalidad:     Función para obtener la elección de banda pedida por pantalla y checkeando que sea un valor correcto
* @Parametros:
* @Retorno: int eleccion de banda
************************************************/

int getBandElection(Names fileNames)
{

    int quantity_bands, exit_band = 0, eleccion_band;

    //Obtención de la cantidad de bandas
    quantity_bands = getQuantityOfElementsInFile(fileNames.bandsFileName);

    //Petición del número de la band
    while (exit_band == 0)
    {
        //Elección de la band
        printf("\nSelect band number: ");
        scanf("%d", &eleccion_band);

        /*Error handling de que el valor introducido tenga sentido en el struct 
            - No sea más pequeño o igual a 0 
            - No sea más grande que el número total de bandas */
        if (eleccion_band <= 0 || eleccion_band > quantity_bands)
        {
            printf("ERROR: Invalid band number\n");
        }
        else
        {
            exit_band = 1;
        }
    }

    return eleccion_band;
}

/***********************************************
*
* @Finalidad: Función para obtener la elección de venue pedida por pantalla y checkeando que sea un valor correcto
* @Parametros:
* @Retorno: int -- eleccion de venue
************************************************/

int getVenueElection(Names filenNames)
{

    int eleccion_venue, quantity_venues, exit_venue = 0;

    //Obtención de la cantidad de venues
    quantity_venues = getQuantityOfElementsInFile(filenNames.venuesFileName);

    while (exit_venue == 0)
    {
        //Elección de la venue
        printf("\nSelect venue number: ");
        scanf("%d", &eleccion_venue);

        /*Error handling de que el valor introducido tenga sentido en el struct 
            - No sea más pequeño o igual a 0 
            - No sea más grande que el número total de bandas -1(para poder leerlo del struct )*/
        if (eleccion_venue <= 0 || eleccion_venue > quantity_venues)
        {
            printf("ERROR: Invalid venue number\n");
        }
        else
        {
            exit_venue = 1;
        }
    }
    return eleccion_venue;
}

/*

    Funcion para la accion de calcular el ticket price

*/
/***********************************************
*
* @Finalidad: Funcion para la accion de calcular el ticket price
* @Parametros:
*  - Names fileNames -- struct con nombres de ficheros
* @Retorno: 
************************************************/
void doActionCalculateTicketPrice(Names fileNames)
{

    int eleccion_band, eleccion_venue;
    double ticket_price;
    Band *bands;
    Venue *venues;

    //elecion de banda
    eleccion_band = getBandElection(fileNames);

    //eleccion de venue
    eleccion_venue = getVenueElection(fileNames);

    //llenado las bands del fichero
    bands = fillBandsStruct(fileNames);
    //llenado de las venues por fichero
    venues = fillVenueStruct(fileNames);

    //cálculo de ticket price
    ticket_price = (double)(bands[eleccion_band - 1].cache) / (double)(venues[eleccion_venue - 1].capacity);

    printf("\nThe minimum ticket price is %.2f  euros\n", ticket_price);

    //liberado de memoria
    freeMemory(bands, venues);
}

/***********************************************
*
* @Finalidad: Función para mostrar los miembros de una banda
* @Parametros:
* - Names filenames -- struct con el nombre de los ficheros
* @Retorno:
************************************************/

void doActionShowBandMembers(Names fileNames)
{

    Band *bands;
    int eleccion_band, i;

    //Eleccion de banda
    eleccion_band = getBandElection(fileNames);

    bands = fillBandsStruct(fileNames);

    printf("\nMembers:\n");

    for (i = 0; i < bands[eleccion_band - 1].num_musicians; i++)
    {

        printf("\t- %s\n", bands[eleccion_band - 1].musicians[i].name);
    }
    printf("\n");

    //Liberado de memoria
    free(bands);
    free(bands->musicians);
}

/***********************************************
*
* @Finalidad: uncion para la elección de acción en el menú
* @Parametros:
* - Names filenames -- struct con el nombre de los ficheros
* @Retorno:
************************************************/

void menuActions(Names fileNames)
{

    int action;

    while (action != 4)
    {

        printf("\n1. Show Bands or Venues | 2. Calculate ticket price | 3. Show band members | 4. Exit");
        printf("\nSelect option: ");
        scanf("%d", &action);

        switch (action)
        {
        case 1:

            //Acción para mostrar bandas o Lugares de concierto.
            doActionShowBandsVenues(fileNames);
            break;

        case 2:
            //Acción para calcular el minimum ticket price
            doActionCalculateTicketPrice(fileNames);
            break;

        case 3:
            //Acción para mostrar los band members
            doActionShowBandMembers(fileNames);
            break;

        case 4:
            printf("\nBye!\n");
            break;
        default:
            printf("ERROR: Wrong option number\n");
            break;
        }
    }
}
