/*

    Creado por : Faozi Bouybaouene
    Creado el  : 11 de Abril 2021

*/

#define MAX_LEN 50
#define MAX_FILENAME 30

typedef struct
{
    char name[MAX_LEN];
    int age;
} Musician;

typedef struct
{
    char name[MAX_LEN];
    int cache;
    int num_musicians;
    Musician *musicians;
} Band;

typedef struct
{
    char name[MAX_LEN];
    int capacity;
} Venue;

typedef struct
{
    char bandsFileName[MAX_FILENAME];
    char musiciansFileName[MAX_FILENAME];
    char venuesFileName[MAX_FILENAME];

} Names;

//Funciones
Names filesRead(Names fileNames);
void menuActions(Names fileNames);
Band* fillBandsStruct();
Venue *fillVenueStruct();