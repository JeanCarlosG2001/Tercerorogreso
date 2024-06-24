#include "funciones.h"


int main (int argc, char *argv[]) {
    // {"Numero de Sala", "nombre", "horario", "genero"}
    char peliculas[10][4][40] = {{"1", "Avatar", "10:20", "Fantasia"},
                                 {"5", "Intensamente 2", "15:20", "Aventura"},
                                 {"7", "Garfield: Fuera De Casa", "18:15", "Romance"},
                                 {"3", "Cincuenta sombras de Grey", "12:20", "Ciencia Ficcion"},
                                 {"1", "Planeta De Los Simios: Nuevo Reino", "20:50", "Accion"},
                                 {"2", "Bad Boys: Hasta La Muerte", "18:30", "Accion"},
                                 {"3", "El Rey Leon", "14:00", "Animacion"},
                                 {"5", "Avengers: Endgame", "16:45", "Accion"},
                                 {"6", "Toy Story 4", "17:30", "Animacion"},
                                 {"7", "El Senor de los Anillos", "20:00", "Fantasia"}};
    // {General, Descuento, Preferencial}
    double precio[3] = {7, 3.5, 3};
    // {"Nombre", "cedula", "edad"}
    char clientes[5][3][40] = {{"", "", ""}, {"", "", ""}, {"", "", ""}, {"", "", ""}, {"", "", ""}};
    // {"Cliente", "nombre de pelicula", "precio", "cedula"}
    int reserva[10][4] = {{-1, -1, -1, -1},
                          {-1, -1, -1, -1},
                          {-1, -1, -1, -1},
                          {-1, -1, -1, -1},
                          {-1, -1, -1, -1},
                          {-1, -1, -1, -1},
                          {-1, -1, -1, -1},
                          {-1, -1, -1, -1},
                          {-1, -1, -1, -1},
                          {-1, -1, -1, -1}};
 
    int opcion1 = 0, opcion2 = 0, opcion3 = 0;
    do {
        printf("--Bienvenido al Cine--\n");
        printf("Escoja una opcion:\n1. Ingresar Cliente\n2. Ver Peliculas\n3. Buscar Pelicula\n4. Comprar Ticket\n5. Ver Compras\n>>");
        scanf("%d", &opcion2);
        switch (opcion2) {
            case 1:
                ingresarCliente(clientes);
                break;
            case 2:
                listarPeliculas(peliculas);
                break;
            case 3:
                printf("Que desea buscar?\n1. Por Nombre\n2. Por Genero\n>>");
                scanf("%d", &opcion3);
                switch (opcion3) {
                    case 1:
                        buscarporNombre(peliculas);
                        break;
                    case 2:
                        buscarporGenero(peliculas);
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                comprarTicket(peliculas, precio, clientes, reserva);
                break;
            case 5:
                verCompras(peliculas, precio, clientes, reserva);
                break;
            default:
                break;
        }
        printf("Desea escoger una nueva opcion:\n 1. Si\n2. No\n>>");
        scanf("%d", &opcion1);
    } while (opcion1 != 2);
    return 0;
}
