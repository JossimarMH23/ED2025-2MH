#include <stdio.h>

void llenarArray(int a[], int n) {
printf("INGRESAR DE TIEMPOS\n");
printf("Ingrese %d tiempos en minutos (numeros enteros positivos):\n\n", n);


for (int i = 0; i < n; i++) {
    int tiempo;
    do {
        printf("Tiempo %d: ", i + 1);
        scanf("%d", &tiempo);
        
        if (tiempo <= 0) {
            printf("Error: El tiempo debe ser un numero entero positivo. Intente nuevamente.\n");
        }
    } while (tiempo <= 0);
    
    a[i] = tiempo;
}
printf("\n");

}

void mostrarArray(int a[], int n, char titulo[]) {
printf("%s: [ ", titulo);
for (int i = 0; i < n; i++) {
printf("%d", a[i]);
if (i < n - 1) printf(", ");
}
printf(" ]\n");
}

void copiarArray(int origen[], int destino[], int n) {
for (int i = 0; i < n; i++) {
destino[i] = origen[i];

}
}

void ordenarSelectionAscendente(int a[], int n) {
printf("ORDENAMIENTO SELECTION SORT (MENOR A MAYOR)\n");
printf("Estado inicial: ");
mostrarArray(a, n, "");
printf("\n");


for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    
    for (int j = i + 1; j < n; j++) {
        if (a[j] < a[min_idx]) {
            min_idx = j;
        }
    }
    
    if (min_idx != i) {
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
        
        printf("Paso %d: ", i + 1);
        mostrarArray(a, n, "");
    }
}

printf("\nResultado final (ascendente): ");
mostrarArray(a, n, "");
printf("\n");


}

void ordenarInsertionDescendente(int a[], int n) {
printf("\nORDENAMIENTO INSERTION SORT (MAYOR A MENOR)\n\n");
printf("Estado inicial: ");
mostrarArray(a, n, "");
printf("\n");


for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    
    while (j >= 0 && a[j] < key) {
        a[j + 1] = a[j];
        j = j - 1;
    }
    
    a[j + 1] = key;
    
    printf("Paso %d: ", i);
    mostrarArray(a, n, "");
}

printf("\nResultado final (descendente): ");
mostrarArray(a, n, "");
printf("\n");

}

int main() {
int tiempos[10];
int tiempos_copia[10];


printf("\n\nANALISIS DE TIEMPOS DE SOPORTE\n");
printf("Este programa ordena 10 tiempos de resolucion de problemas\n\n");

llenarArray(tiempos, 10);

printf("ARREGLO ORIGINAL:\n");
mostrarArray(tiempos, 10, "Tiempos ingresados");
printf("\n");

copiarArray(tiempos, tiempos_copia, 10);
ordenarSelectionAscendente(tiempos_copia, 10);

copiarArray(tiempos, tiempos_copia, 10);
ordenarInsertionDescendente(tiempos_copia, 10);

printf("\nFIN\n");

return 0;}