#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10000
#define veces 100

void generarArreglo(int arreglo[n]) 
{
    int i;
    for (i = 0; i < n; i++) 
	{
        arreglo[i] = rand() % 10000; 
    }
}

void copiarArreglo(int origen[n], int destino[n]) 
{
    int i;
    for (i = 0; i < n; i++) 
	{
        destino[i] = origen[i];
    }
}

void imprimirArreglo(int arreglo[n]) 
{
    int i;
    for (i = 0; i < n; i++) 
	{
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

//Bubble Sort func
void bubbleSort(int arreglo[n]) 
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) 
	{
        for (j = 0; j < n - i - 1; j++) 
		{
            if (arreglo[j] > arreglo[j + 1]) 
			{
                temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

//Insertion Sort func
void insertionSort(int arreglo[n]) 
{
    int i, j, temp;
    for (i = 1; i < n; i++) 
	{
        temp = arreglo[i];
        j = i - 1;
        
        while (j >= 0 && arreglo[j] > temp) 
		{
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = temp;
    }
}

//Quick Sort func
void quickSort(int arreglo[n], int izquierda, int derecha) 
{
    int i = izquierda, j = derecha;
    int temp;
    int pivote = arreglo[(izquierda + derecha) / 2];

    while (i <= j) 
	{
        while (arreglo[i] < pivote) 
		{
            i++;
        }
        while (arreglo[j] > pivote) 
		{
            j--;
        }
        if (i <= j) 
		{
            temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
            i++;
            j--;
        }
    }

    //recursivas
    if (izquierda < j) 
	{
        quickSort(arreglo, izquierda, j);
    }
    if (i < derecha) 
	{
        quickSort(arreglo, i, derecha);
    }
}

int main() 
{
    int arregloOriginal[n];
    int arregloOrdenado[n];
    clock_t tic, toc;
    
    double tiempoTotal;
    double tiemposBubble[veces];
    double tiemposInsertion[veces];
    double tiemposQuick[veces];

    srand(time(NULL));

    for (int i = 0; i < veces; i++) 
	{
        generarArreglo(arregloOriginal);
        copiarArreglo(arregloOriginal, arregloOrdenado);

        tic = clock();
        bubbleSort(arregloOrdenado);
        toc = clock();
        tiempoTotal = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000; //milisegundos
        tiemposBubble[i] = tiempoTotal;

		//Insertion sort
        copiarArreglo(arregloOriginal, arregloOrdenado);
        tic = clock();
        insertionSort(arregloOrdenado);
        toc = clock();
        tiempoTotal = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000; //milisegundos
        tiemposInsertion[i] = tiempoTotal;

        //Quick Sort
        copiarArreglo(arregloOriginal, arregloOrdenado);
        tic = clock();
        quickSort(arregloOrdenado, 0, n - 1);
        toc = clock();
        tiempoTotal = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000; //milisegundos
        tiemposQuick[i] = tiempoTotal;
    }

    //Bubble Sort
    double tiempoPromedioBubble = 0;
    double tiempoMinimoBubble = tiemposBubble[0];
    double tiempoMaximoBubble = tiemposBubble[0];

    for (int i = 0; i < veces; i++) 
	{
        tiempoPromedioBubble += tiemposBubble[i];
        if (tiemposBubble[i] < tiempoMinimoBubble) 
		{
            tiempoMinimoBubble = tiemposBubble[i];
        }
        if (tiemposBubble[i] > tiempoMaximoBubble) 
		{
            tiempoMaximoBubble = tiemposBubble[i];
        }
    }

    tiempoPromedioBubble /= veces;

    //Tiempo Insertion Sort
    double tiempoPromedioInsertion = 0;
    double tiempoMinimoInsertion = tiemposInsertion[0];
    double tiempoMaximoInsertion = tiemposInsertion[0];

    for (int i = 0; i < veces; i++) 
	{
        tiempoPromedioInsertion += tiemposInsertion[i];
        if (tiemposInsertion[i] < tiempoMinimoInsertion) 
		{
            tiempoMinimoInsertion = tiemposInsertion[i];
        }
        if (tiemposInsertion[i] > tiempoMaximoInsertion) 
		{
            tiempoMaximoInsertion = tiemposInsertion[i];
        }
    }

    tiempoPromedioInsertion /= veces;

    //Tiempo Quick Sort
    double tiempoPromedioQuick = 0;
    double tiempoMinimoQuick = tiemposQuick[0];
    double tiempoMaximoQuick = tiemposQuick[0];

    for (int i = 0; i < veces; i++) 
	{
        tiempoPromedioQuick += tiemposQuick[i];
        if (tiemposQuick[i] < tiempoMinimoQuick) 
		{
            tiempoMinimoQuick = tiemposQuick[i];
        }
        if (tiemposQuick[i] > tiempoMaximoQuick) 
		{
            tiempoMaximoQuick = tiemposQuick[i];
        }
    }

    tiempoPromedioQuick /= veces;

    //Resultados ------------------------
    printf("Bubble Sort:\n");
    printf("Tiempo promedio: %.4f ms\n", tiempoPromedioBubble);
    printf("Tiempo minimo: %.4f ms\n", tiempoMinimoBubble);
    printf("Tiempo maximo: %.4f ms\n", tiempoMaximoBubble);
	//////////////////////
    printf("\nInsertion Sort:\n");
    printf("Tiempo promedio: %.4f ms\n", tiempoPromedioInsertion);
    printf("Tiempo minimo: %.4f ms\n", tiempoMinimoInsertion);
    printf("Tiempo maximo: %.4f ms\n", tiempoMaximoInsertion);
	/////////////////////
    printf("\nQuick Sort:\n");
    printf("Tiempo promedio: %.4f ms\n", tiempoPromedioQuick);
    printf("Tiempo minimo: %.4f ms\n", tiempoMinimoQuick);
    printf("Tiempo maximo: %.4f ms\n", tiempoMaximoQuick);

    return 0;
}
