#include "funciones.h"
//Caso1
void ingresarCliente(char clientes[][3][40]) {
    char seguir[3];
    int j = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][0], "") == 0) {
            printf("Maximo 5 clientes: ");
            printf("Cliente %d\n", j);
            j++;
            printf("Ingrese nombre del nuevo cliente: ");
            scanf("%s", clientes[i][0]);
            printf("Ingrese cedula del nuevo cliente: ");
            scanf("%s", clientes[i][1]);
            printf("Ingrese la edad del nuevo cliente: ");
            scanf("%s", clientes[i][2]);
            printf("quiere seguir ingresando clientes (si/no): ");
            scanf("%s", seguir);
            if (strcmp(seguir, "no") == 0) {
                break;
            }  
        }
    }
    if (j == 5) {
        printf("Numero maximo de clientes alcanzado\n");
    }
}

//Caso2
void listarPeliculas(char peliculas[][4][40]) {
    printf("Peliculas Disponibles:\n");
    printf("Sala\tNombre\tDuracion\tGenero\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\t%s\t%s\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }
}

//Caso3.1
void buscarporNombre(char peliculas[][4][40]) {
    char nombre[40];
    printf("Ingrese el nombre de la pelicula: ");
    scanf("%s", nombre);
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][1], nombre) == 0) {
            printf("Sala\tNombre\tDuracion\tGenero\n");
            printf("%s\t%s\t%s\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
            return;
        }
    }
    printf("No hay peliculas con ese nombre\n");
}

//Caso3.2
void buscarporGenero(char peliculas[][4][40]) {
    printf("Ingrese el genero de la pelicula: ");
    char genero[40];
    int j = 0;
    scanf("%s", genero);
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][3], genero) == 0) {
            printf("Sala\tNombre\tDuracion\tGenero\n");
            printf("%s\t%s\t%s\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
            j ++;
        }else if(j != 0){
            printf("No hay mas peliculas con ese genero\n");
            return;
        }
    }
}

//Caso4
void comprarTicket(char peliculas[][4][40], double precio[3], char clientes[][3][40], int reserva[10][4]) {
    char cedula[40];
    printf("Comprar Ticket\n");
    printf("Ingrese el numero de cedula del cliente: ");
    scanf("%s", cedula);
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            printf("Cliente encontrado: %s\n", clientes[i][0]);
            printf("Sala\tNombre\tDuracion\tGenero\n");
            char nombre[40];
            printf("Ingrese el nombre de la pelicula: ");
            scanf("%s", nombre);
            for (int j = 0; j < 10; j++) {
                if (strcmp(peliculas[j][1], nombre) == 0) {
                    printf("Pelicula encontrada: %s\n", peliculas[j][1]);
                    printf("Sala\tNombre\tDuracion\tGenero\n");
                    printf("%s\t%s\t%s\t%s\n", peliculas[j][0], peliculas[j][1], peliculas[j][2], peliculas[j][3]);
                    //Cliente
                    reserva[i][0] = clientes[i][0];
                    // Pelicula
                    reserva[i][1] = peliculas[i][1];
                    // edad
                        int edad = atoi(clientes[i][2]);
                        if (edad >= 18) {
                            // Es mayor de edad
                            reserva[i][2] = precio[0];
                        } else {
                            // Es menor de edad
                            reserva[i][2] = precio[2];
                        }
                    // Cedula
                    reserva[i][3] = clientes[i][2];
                    return;
                }
            }
            printf("Pelicula no encontrada\n");
            return;
        }
    }
    printf("El cliente no existe o no está registrado\n");
}

//Caso5
void verCompras(char peliculas[][4][40], double precio[3], char clientes[][3][40], int reserva[10][4]) {
    char cedula[40];
    printf("Ver Compras\n");
    printf("Ingrese el numero de cedula del cliente: ");
    scanf("%s", cedula);
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            printf("N° Cliente \t Nombre de pelicula \t Precio \t Cedula\n");
            if (reserva[i][0] != -1) {
                int j = reserva[i][1];
                printf("%d\t\t%s\t\t%.2f\t\t%s\n", reserva[i][0], reserva[i][1], reserva[i][2],reserva[i][1]);
            } else {
                printf("No hay compras registradas para este cliente\n");
            }
            return;
        }
    }
    printf("El cliente no existe o no está registrado\n");
}