all: practica_2

main.o: main.c libreria_ficheros_head.h
	gcc -c main.c 

libreria_ficheros.o: libreria_ficheros.c libreria_ficheros_head.h 
	gcc -c libreria_ficheros.c

practica_2: main.o libreria_ficheros.o
	gcc main.o libreria_ficheros.o -o practica_2.exe


