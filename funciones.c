#include "funciones.h"

 
//Caso1
void ingresarCliente(char clientes[5][3][40]) {
    char seguir[3]; 
    int j = 0; 

    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][0], "") == 0) { 
            printf("Maximo 5 clientes: ");
            printf("Cliente %d\n", j + 1); 
            j++;

           
            printf("Ingrese nombre del nuevo cliente: ");
            scanf("%39s", clientes[i][0]); 

            printf("Ingrese cedula del nuevo cliente: ");
            scanf("%39s", clientes[i][1]);

            printf("Ingrese la edad del nuevo cliente: ");
            scanf("%39s", clientes[i][2]); 

            
            if (j < 5) { 
                printf("Quiere seguir ingresando clientes (si/no): ");
                scanf("%2s", seguir);
                if (strcmp(seguir, "no") == 0) { 
                    return;
                }
            }
        }
    }

    if (j == 5) {
        printf("Numero maximo de clientes alcanzado\n"); 
        return;
    }
}
 
//Caso2
void listarPeliculas(char peliculas[10][4][40]) {
    printf("Peliculas Disponibles:\n");
    printf("Sala\tNombre\tDuracion\tGenero\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\t%s\t%s\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }
}
 
//Caso3.1
void buscarporNombre(char peliculas[10][4][40]) {
    char nombre[40];
    printf("Ingrese el nombre de la pelicula: ");
    scanf("%39s", nombre);
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
void buscarporGenero(char peliculas[10][4][40]) {
    printf("Ingrese el genero de la pelicula: ");
    char genero[40];
    int j = 0;
    scanf("%39s", genero);
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][3], genero) == 0) {
            printf("Sala\tNombre\tDuracion\tGenero\n");
            printf("%s\t%s\t%s\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
            j++;
        } else if (j != 0) {
            printf("No hay mas peliculas con ese genero\n");
            return;
        }
    }
}
 
//Caso4
void comprarTicket(char peliculas[10][4][40], double *precio, char clientes[5][3][40], int reserva[10][4]) {
    char cedula[40];
    int i;
    printf("Comprar Ticket\n");
    printf("Ingrese el numero de cedula del cliente: ");
    scanf("%39s", cedula);
    for (i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            printf("Cliente encontrado: %s\n", clientes[i][0]);
            printf("Sala\tNombre\tDuracion\tGenero\n");
            char nombre[40];
            printf("Ingrese el nombre de la pelicula: ");
            scanf("%39s", nombre);
            for (int j = 0; j < 10; j++) {
                if (strcmp(peliculas[j][1], nombre) == 0) {
                    printf("Pelicula encontrada: %s\n", peliculas[j][1]);
                    printf("Sala\tNombre\tDuracion\tGenero\n");
                    printf("%s\t%s\t%s\t%s\n", peliculas[j][0], peliculas[j][1], peliculas[j][2], peliculas[j][3]);
 
                    // Asignar datos en la reserva
                    reserva[i][0] = i;  // Índice del cliente
                    reserva[i][1] = j;  // Índice de la película
 
                    // Asignar precio basado en la edad
                    int edad_cliente = atoi(clientes[i][2]);
                    if (edad_cliente >= 18) {
                        // Es mayor de edad
                        reserva[i][2] = precio[0];
                    } else {
                        // Es menor de edad
                        reserva[i][2] = precio[2];
                    }
                    // Asignar cedula del cliente
                    reserva[i][3] = atoi(clientes[i][1]);  // Almacena como entero
 
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
void verCompras(char peliculas[10][4][40], double *precio, char clientes[5][3][40], int reserva[10][4]) {
    printf("Compras realizadas:\n");

    // Abrir archivo para escritura
    FILE *archivo;
    archivo = fopen("reservas.txt", "w");//"w" sobrescribe el archivo

    for (int i = 0; i < 10; i++) {
        if (reserva[i][0] != -1) {
            int clienteIdx = reserva[i][0];
            int peliculaIdx = reserva[i][1];
            double costo = reserva[i][2];
            int cedula = reserva[i][3];
            
            //imprime en la consola
            printf("Cliente: %s\n", clientes[clienteIdx][0]);
            printf("Cedula: %d\n", cedula);
            printf("Pelicula: %s\n", peliculas[peliculaIdx][1]);
            printf("Costo: %.2f\n\n", costo);

            //Guarda en el archivo
            fprintf(archivo, "Cliente: %s\n", clientes[clienteIdx][0]);
            fprintf(archivo, "Cedula: %d\n", cedula);
            fprintf(archivo, "Pelicula: %s\n", peliculas[peliculaIdx][1]);
            fprintf(archivo, "Costo: %.2f\n\n", costo);
        }}
    fclose(archivo);
    printf("Los datos de las reservas se han guardado en el archivo 'reservas.txt'.\n");
}
