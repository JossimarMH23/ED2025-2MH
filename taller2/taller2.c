#include <stdio.h>
#include <stdlib.h>

typedef struct Pasajero {
char genero[15];
char apellido[50];
struct Pasajero *siguiente;
} Pasajero;

Pasajero *cabeza = NULL;
int capacidad = 0;
int vendidos = 0;
int abordaje = 0;

void establecerCapacidad() {
if (capacidad > 0) {
printf("Capacidad ya establecida\n");
return;
}
printf("Capacidad del avion: ");
scanf("%d", &capacidad);
}

void venderTiquete() {
if (capacidad == 0) {
printf("Establezca la capacidad primero\n");
return;
}
if (abordaje) {
printf("Abordaje iniciado. No se pueden vender tiquetes\n");
return;
}
if (vendidos >= capacidad + (capacidad / 10)) {
printf("Limite de sobreventa alcanzado\n");
return;
}


Pasajero *nuevo = (Pasajero*) malloc(sizeof(Pasajero));
if (nuevo == NULL) {
    printf("Error en asignacion de memoria\n");
    return;
}

printf("Genero: ");
scanf("%s", nuevo->genero);
printf("Apellido: ");
scanf("%s", nuevo->apellido);
nuevo->siguiente = NULL;

if (cabeza == NULL) {
    cabeza = nuevo;
} else {
    Pasajero *temp = cabeza;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo;
}

vendidos++;
printf("Tiquete vendido. Total: %d\n", vendidos);


}

void iniciarAbordaje() {
if (capacidad == 0) {
printf("Establezca la capacidad primero\n");
return;
}
if (abordaje) {
printf("Abordaje ya iniciado\n");
return;
}
abordaje = 1;
printf("Abordaje iniciado\n");
}

void verAbordados() {
if (!abordaje) {
printf("Abordaje no iniciado\n");
return;
}


printf("--- ABORDADOS ---\n");
Pasajero *temp = cabeza;
int i = 0;

while (temp != NULL && i < capacidad) {
    printf("%d. %s - %s\n", i + 1, temp->apellido, temp->genero);
    temp = temp->siguiente;
    i++;
}


}

void verNoAbordados() {
if (!abordaje) {
printf("Abordaje no iniciado\n");
return;
}


printf("--- NO ABORDADOS ---\n");
Pasajero *temp = cabeza;
int i = 0;

while (temp != NULL && i < capacidad) {
    temp = temp->siguiente;
    i++;
}

i = 0;
while (temp != NULL) {
    printf("%d. %s - %s\n", i + 1, temp->apellido, temp->genero);
    temp = temp->siguiente;
    i++;
}


}

int main() {
int opcion;


do {
    printf("\n1. Establecer Capacidad\n");
    printf("2. Vender Tiquete\n");
    printf("3. Iniciar Abordaje\n");
    printf("4. Ver Abordados\n");
    printf("5. Ver No Abordados\n");
    printf("6. Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    
    switch (opcion) {
        case 1: 
            establecerCapacidad(); 
            break;
        case 2: 
            venderTiquete(); 
            break;
        case 3: 
            iniciarAbordaje(); 
            break;
        case 4: 
            verAbordados(); 
            break;
        case 5: 
            verNoAbordados(); 
            break;
        case 6: 
            while (cabeza != NULL) {
                Pasajero *temp = cabeza;
                cabeza = cabeza->siguiente;
                free(temp);
            }
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida\n");
    }
} while (opcion != 6);

return 0;


}