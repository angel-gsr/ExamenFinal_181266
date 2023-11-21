#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 50000
#define veces 100

void generarArregloOrdenado(int arreglo[n]) 
{
    int i;
    for (i = 0; i < n; i++) 
	{
        arreglo[i] = rand() % 50000;
    }
}

int busquedaSecuencial(int arreglo[n], int elemento) 
{
    for (int i = 0; i < n; i++) 
	{
        if (arreglo[i] == elemento) 
		{
            return i;
        }
    }
    return -1; //no encontrado
}

int busquedaBinaria(int arreglo[n], int elemento) 
{
    int izquierda = 0;
    int derecha = n - 1;
    while (izquierda <= derecha) 
	{
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arreglo[medio] == elemento) 
		{
            return medio; //encontrado
        }
        if (arreglo[medio] < elemento) 
		{
            izquierda = medio + 1;
        } 
		else 
		{
            derecha = medio - 1;
        }
    }
    return -1; //no encontrado
}

int main() 
{
    int arregloOrdenado[n];
    clock_t inicio, fin;
    double tiempoTotal;
    double tiemposSecuencial[veces];
    double tiemposBinaria[veces];

    srand(time(NULL));

    generarArregloOrdenado(arregloOrdenado);

    for (int i = 0; i < veces; i++) 
	{
        int elementoBuscado = rand() % 50000;

        //Tiempo Busqueda secuencial
        inicio = clock();
        busquedaSecuencial(arregloOrdenado, elementoBuscado);
        fin = clock();
        tiempoTotal = ((double)(fin - inicio)) / CLOCKS_PER_SEC * 1000; //milisegundos
        tiemposSecuencial[i] = tiempoTotal;

        //Tiempo Busqueda binaria
        inicio = clock();
        busquedaBinaria(arregloOrdenado, elementoBuscado);
        fin = clock();
        tiempoTotal = ((double)(fin - inicio)) / CLOCKS_PER_SEC * 1000; //milisegundos
        tiemposBinaria[i] = tiempoTotal;
    }

    //Busqueda secuencial resultado
    double tiempoPromedioSecuencial = 0;
    double tiempoMinimoSecuencial = tiemposSecuencial[0];
    double tiempoMaximoSecuencial = tiemposSecuencial[0];

    for (int i = 0; i < veces; i++) 
	{
        tiempoPromedioSecuencial += tiemposSecuencial[i];
        if (tiemposSecuencial[i] < tiempoMinimoSecuencial) 
		{
            tiempoMinimoSecuencial = tiemposSecuencial[i];
        }
        if (tiemposSecuencial[i] > tiempoMaximoSecuencial) 
		{
            tiempoMaximoSecuencial = tiemposSecuencial[i];
        }
    }

    tiempoPromedioSecuencial /= veces;

    //Busqueda binaria resultado
    double tiempoPromedioBinaria = 0;
    double tiempoMinimoBinaria = tiemposBinaria[0];
    double tiempoMaximoBinaria = tiemposBinaria[0];

    for (int i = 0; i < veces; i++) 
	{
        tiempoPromedioBinaria += tiemposBinaria[i];
        if (tiemposBinaria[i] < tiempoMinimoBinaria) 
		{
            tiempoMinimoBinaria = tiemposBinaria[i];
        }
        if (tiemposBinaria[i] > tiempoMaximoBinaria) 
		{
            tiempoMaximoBinaria = tiemposBinaria[i];
        }
    }

    tiempoPromedioBinaria /= veces;

    //Resultados
    printf("Busqueda Secuencial:\n");
    printf("Tiempo promedio: %.6f ms\n", tiempoPromedioSecuencial);
    printf("Tiempo minimo: %.6f ms\n", tiempoMinimoSecuencial);
    printf("Tiempo maximo: %.6f ms\n", tiempoMaximoSecuencial);
	///////////////////////////////////
    printf("\nBusqueda Binaria:\n");
    printf("Tiempo promedio: %.6 ms\n", tiempoPromedioBinaria);
    printf("Tiempo minimo: %.6f ms\n", tiempoMinimoBinaria);
    printf("Tiempo maximo: %.6f ms\n", tiempoMaximoBinaria);

    return 0;
}
