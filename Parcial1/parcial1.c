#include <stdio.h>

float buscarNotaMaxima(float notas[], int n);
float calcularPromedio(float notas[], int n, int i, float suma);
void selectionSortRecursivo(int codigos[], float notas[], int n, int inicio);
int buscarMinimo(int codigos[], int inicio, int fin);
void intercambiar(int *a, int *b);
void intercambiarFloat(float *a, float *b);
void mostrarEstudiantes(int codigos[], float notas[], int n);

int main(){
    int codigos[8] = {2024105, 2024101, 2024108, 2024103, 2024107, 2024102, 2024106, 2024104};
    float notas[8] = {4.2, 4.5, 2.8, 3.7, 4.8, 3.2, 4.1, 3.9};

    int opcion;
    
    printf("SISTEMA DE GESTION DE ESTUDIANTES\n");
    mostrarEstudiantes(codigos, notas, 8);

    do {
        printf("\n1. Buscar Nota Maxima\n2. Calcular Promedio\n3. Ordenar por Codigos\n4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if(opcion == 1){
            printf("Nota maxima: %.2f\n", buscarNotaMaxima(notas, 8));
        }
        else if(opcion == 2){
            printf("Promedio: %.2f\n", calcularPromedio(notas, 8, 0, 0.0));
        }
        else if(opcion == 3){
            selectionSortRecursivo(codigos, notas, 8, 0);
            printf("Ordenado:\n");
            mostrarEstudiantes(codigos, notas, 8);
        }
    } while (opcion != 4);

    return 0;
}

float buscarNotaMaxima(float notas[], int n) {
    if (n == 1) return notas[0];
    float max = buscarNotaMaxima(notas + 1, n - 1);
    if(notas[0] > max) {
        return notas[0];
    } else {
        return max;
    }
}

float calcularPromedio(float notas[], int n, int i, float suma) {
    if (i == n) return suma / n;
    return calcularPromedio(notas, n, i + 1, suma + notas[i]);
}

void selectionSortRecursivo(int codigos[], float notas[], int n, int inicio) {
    if (inicio >= n - 1) return;
    int pos = buscarMinimo(codigos, inicio, n - 1);
    if (pos != inicio) {
        intercambiar(&codigos[inicio], &codigos[pos]);
        intercambiarFloat(&notas[inicio], &notas[pos]);
    }
    selectionSortRecursivo(codigos, notas, n, inicio + 1);
}

int buscarMinimo(int codigos[], int inicio, int fin) {
    if (inicio == fin) return inicio;
    int pos = buscarMinimo(codigos, inicio + 1, fin);
    if(codigos[inicio] < codigos[pos]) {
        return inicio;
    } else {
        return pos;
    }
}

void intercambiar(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void intercambiarFloat(float *a, float *b) {
    float temp = *a; *a = *b; *b = temp;
}

void mostrarEstudiantes(int codigos[], float notas[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Codigo: %d - Nota: %.1f\n", codigos[i], notas[i]);
    }
}