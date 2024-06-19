#include <stdio.h>
#include <string.h>


void ingresarCliente(char clientes[][3][40]);
void listarPeliculas(char peliculas[][4][40]);
void buscarporNombre(char peliculas[][4][40]);
void buscarporGenero(char peliculas[][4][40]);
void comprarTicket(char peliculas[][4][40], double precio[3], char clientes[][3][40], int reserva[10][4]);
void verCompras(char peliculas[][4][40], double precio[3], char clientes[][3][40], int reserva[10][4]);