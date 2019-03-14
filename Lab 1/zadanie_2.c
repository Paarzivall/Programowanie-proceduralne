/*
utworzy tablice dwuwymiarowa i wyswietli ja a nastepnie wyswietli elementy z przekatnej
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5

void wypelnij(int[N][N]);
void wypisz(int[N][N]);
void przekatna(int[N][N]);//wyswietla elementy z przekatnej

int main(void)
{
	srand((unsigned)time(0));
	int tab[N][N];
	wypelnij(tab);
	wypisz(tab);
	printf("\n\n");
	przekatna(tab);
}

void wypelnij(int tab[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			tab[i][j]=1+rand()%100;
		}
	}	
}

void wypisz(int tab[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d\t",tab[i][j]);
		}
	printf("\n");
	}
}

void przekatna(int tab[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i==j)
			{
				printf("%d\t",tab[i][j]);
			}
		}
	printf("\n");
	}
}
