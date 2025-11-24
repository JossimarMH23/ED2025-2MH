#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int documento;
    int destino;
    int tipo_pasaje;
    struct nodo *izq;
    struct nodo *der;
} nodo;

nodo *raiz;

void registrarPasajero();
void posicionar(nodo *nuevaRaiz, nodo *nuevo);
void recorrerInorden(nodo *nuevaRaiz);
void recorrerPreorden(nodo *nuevaRaiz);
void recorrerPostorden(nodo *nuevaRaiz);
int contarPasajeros(nodo *nuevaRaiz);
nodo* eliminarPasajero(nodo *nuevaRaiz, int doc);
nodo* buscarMinimo(nodo *nuevaRaiz);
void mostrarDestino(int destino);
void mostrarTipoPasaje(int tipo);

int main(){
    int opc, opcListar;
    
    do {
        printf("\n--------------------------------------------\n");
        printf("  SISTEMA DE GESTION DE TIQUETES - MUELLE\n");
        printf("--------------------------------------------\n");
        printf("1. Registrar Pasajero\n");
        printf("2. Listar Pasajeros\n");
        printf("3. Numero total de Pasajeros\n");
        printf("4. Eliminar Pasajero\n");
        printf("5. Salir\n");
        printf("--------------------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);
        
        switch (opc) {
            case 1:
                registrarPasajero();
                break;
            case 2:
                if(raiz == NULL) {
                    printf("\nNo hay pasajeros registrados.\n");
                } else {
                    printf("1. Inorden\n");
                    printf("2. Preorden\n");
                    printf("3. Postorden\n");
                    printf("Seleccione tipo de recorrido: ");
                    scanf("%d", &opcListar);
                    
                    if(opcListar == 1) {
                        printf("\nLISTADO INORDEN\n\n");
                        recorrerInorden(raiz);
                    } else if(opcListar == 2) {
                        printf("\nLISTADO PREORDEN\n\n");
                        recorrerPreorden(raiz);
                    } else if(opcListar == 3) {
                        printf("\nLISTADO POSTORDEN\n\n");
                        recorrerPostorden(raiz);
                    } else {
                        printf("\nOpcion no valida\n\n");
                    }
                }
                break;
            case 3:
                printf("\nTotal de pasajeros registrados: %d\n", contarPasajeros(raiz));
                break;
            case 4: {
                int doc;
                printf("\nIngrese el numero de documento a eliminar: ");
                scanf("%d", &doc);
                raiz = eliminarPasajero(raiz, doc);
                break;
            }
            case 5:
                printf("\nGracias por usar el sistema\n");
                break;
            default:
                printf("\nOpcion no valida.\n");
        }
    } while(opc != 5);
    
    return 0;
}

void registrarPasajero(){
    nodo *nuevo = (nodo *) malloc(sizeof(nodo));
    
    printf("\nREGISTRO DE PASAJERO\n\n");
    printf("Numero de documento: ");
    scanf("%d", &nuevo->documento);
    
    printf("\nDESTINOS DISPONIBLES\n\n");
    printf("1. Timbiqui\n");
    printf("2. Juanchaco\n");
    printf("3. Tumaco\n");
    printf("4. Guapi\n");
    printf("Seleccione destino: ");
    scanf("%d", &nuevo->destino);
    
    printf("\nTIPO DE PASAJE\n\n");
    printf("1. Ida\n");
    printf("2. Ida y Regreso\n");
    printf("Seleccione tipo de pasaje: ");
    scanf("%d", &nuevo->tipo_pasaje);
    
    nuevo->der = nuevo->izq = NULL;
    
    if(raiz == NULL) {
        raiz = nuevo;
        printf("\nPasajero registrado exitosamente\n");
    } else {
        posicionar(raiz, nuevo);
    }
    
    nuevo = NULL;
    free(nuevo);
}

void posicionar(nodo *nuevaRaiz, nodo *nuevo){
    if(nuevo->documento < nuevaRaiz->documento) {
        if(nuevaRaiz->izq == NULL) {
            nuevaRaiz->izq = nuevo;
            printf("\nPasajero registrado exitosamente\n");
        } else {
            posicionar(nuevaRaiz->izq, nuevo);
        }
    } else if(nuevo->documento > nuevaRaiz->documento) {
        if(nuevaRaiz->der == NULL) {
            nuevaRaiz->der = nuevo;
            printf("\nPasajero registrado exitosamente!\n");
        } else {
            posicionar(nuevaRaiz->der, nuevo);
        }
    } else {
        printf("\nError\n");
        free(nuevo);
    }
}

void recorrerInorden(nodo *nuevaRaiz) {
    if(nuevaRaiz != NULL) {
        recorrerInorden(nuevaRaiz->izq);
        printf("Doc: %d | Destino: ", nuevaRaiz->documento);
        mostrarDestino(nuevaRaiz->destino);
        printf(" | Tipo: ");
        mostrarTipoPasaje(nuevaRaiz->tipo_pasaje);
        printf("\n");
        recorrerInorden(nuevaRaiz->der);
    }
}

void recorrerPreorden(nodo *nuevaRaiz) {
    if(nuevaRaiz != NULL) {
        printf("Doc: %d | Destino: ", nuevaRaiz->documento);
        mostrarDestino(nuevaRaiz->destino);
        printf(" | Tipo: ");
        mostrarTipoPasaje(nuevaRaiz->tipo_pasaje);
        printf("\n");
        recorrerPreorden(nuevaRaiz->izq);
        recorrerPreorden(nuevaRaiz->der);
    }
}

void recorrerPostorden(nodo *nuevaRaiz) {
    if(nuevaRaiz != NULL) {
        recorrerPostorden(nuevaRaiz->izq);
        recorrerPostorden(nuevaRaiz->der);
        printf("Doc: %d | Destino: ", nuevaRaiz->documento);
        mostrarDestino(nuevaRaiz->destino);
        printf(" | Tipo: ");
        mostrarTipoPasaje(nuevaRaiz->tipo_pasaje);
        printf("\n");
    }
}

int contarPasajeros(nodo *nuevaRaiz) {
    if(nuevaRaiz == NULL) {
        return 0;
    }
    return 1 + contarPasajeros(nuevaRaiz->izq) + contarPasajeros(nuevaRaiz->der);
}

nodo* buscarMinimo(nodo *nuevaRaiz) {
    while(nuevaRaiz->izq != NULL) {
        nuevaRaiz = nuevaRaiz->izq;
    }
    return nuevaRaiz;
}

nodo* eliminarPasajero(nodo *nuevaRaiz, int doc) {
    if(nuevaRaiz == NULL) {
        printf("\nPasajero no encontrado.\n");
        return nuevaRaiz;
    }
    
    if(doc < nuevaRaiz->documento) {
        nuevaRaiz->izq = eliminarPasajero(nuevaRaiz->izq, doc);
    } else if(doc > nuevaRaiz->documento) {
        nuevaRaiz->der = eliminarPasajero(nuevaRaiz->der, doc);
    } else {
        if(nuevaRaiz->izq == NULL) {
            nodo *temp = nuevaRaiz->der;
            free(nuevaRaiz);
            printf("\nPasajero eliminado exitosamente.\n");
            return temp;
        } else if(nuevaRaiz->der == NULL) {
            nodo *temp = nuevaRaiz->izq;
            free(nuevaRaiz);
            printf("\nPasajero eliminado exitosamente.\n");
            return temp;
        }
        
        nodo *temp = buscarMinimo(nuevaRaiz->der);
        nuevaRaiz->documento = temp->documento;
        nuevaRaiz->destino = temp->destino;
        nuevaRaiz->tipo_pasaje = temp->tipo_pasaje;
        nuevaRaiz->der = eliminarPasajero(nuevaRaiz->der, temp->documento);
        printf("\nPasajero eliminado exitosamente.\n");
    }
    
    return nuevaRaiz;
}

void mostrarDestino(int destino) {
    if(destino == 1) {
        printf("Timbiqui");
    } else if(destino == 2) {
        printf("Juanchaco");
    } else if(destino == 3) {
        printf("Tumaco");
    } else if(destino == 4) {
        printf("Guapi");
    } else {
        printf("Desconocido");
    }
}

void mostrarTipoPasaje(int tipo) {
    if(tipo == 1) {
        printf("Ida");
    } else {
        printf("Ida y Regreso");
    }
}