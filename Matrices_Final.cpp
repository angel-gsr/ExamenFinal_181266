#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 30

void llenarMatriz(int matriz[n][n]) 
{
    int i, j;
    for (i=0;i<n;i++) 
	{
        for (j=0;j<n;j++) 
		{
            matriz[i][j]=rand()%(10);
        }
    }
}

void imprimirMatriz(int matriz[n][n]) 
{
    int i, j;
    for (i=0;i<n;i++) 
	{
        for (j=0;j<n;j++) 
		{
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

void multip(int matrizA[n][n],int matrizB[n][n],int matrizC[n][n]) 
{
    int i, j, k;
    for (i=0;i<n;i++) 
	{
        for (j=0;j<n;j++) 
		{
            matrizC[i][j]=0;
            for (k=0;k<n;k++) 
			{
                matrizC[i][j]+=matrizA[i][k]*matrizB[k][j];
            }
        }
    }
}

int main() 
{
	clock_t tic = clock();
    srand(time(NULL));

    int matrizA[n][n];
    int matrizB[n][n];
    int matrizC[n][n];

    llenarMatriz(matrizA);
    llenarMatriz(matrizB);

    printf("Matriz A:\n");
    imprimirMatriz(matrizA);

    printf("\nMatriz B:\n");
    imprimirMatriz(matrizB);

    multip(matrizA, matrizB, matrizC);

    printf("\nResultado de la multiplicacion (Matriz C):\n");
    imprimirMatriz(matrizC);
    
    clock_t toc = clock();
	printf("\nElapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;
}

