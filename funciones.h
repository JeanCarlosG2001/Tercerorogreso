#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void ingresarCliente(char clientes[5][3][40]);
void listarPeliculas(char peliculas[10][4][40]);
void buscarporNombre(char peliculas[10][4][40]);
void buscarporGenero(char peliculas[10][4][40]);
void comprarTicket(char peliculas[10][4][40], double *precio, char clientes[5][3][40], int reserva[10][4]);
void verCompras(char peliculas[10][4][40], double *precio, char clientes[5][3][40], int reserva[10][4]);
