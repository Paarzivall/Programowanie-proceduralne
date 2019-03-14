/*
zamiana wierszy w tablicy kwadratowej. pobieramy nr wierszy
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5

void wypelnij(int (*tab)[N]);
void wypisz(int (*tab)[N]);
void zamiana(int (*tab)[N], int, int);

int main(void)
{
	srand((unsigned)time(0));
	int tab[N][N];
	int aa, bb;
	wypelnij(tab);
	wypisz(tab);
	printf("\n\n");
	printf("Podaj numery wierszy ktore chcesz zamienic(1-%d):\t",N);
	scanf("%d %d", &aa, &bb);
	zamiana(tab, aa, bb);
	wypisz(tab);
}

void wypelnij(int (*tab)[N])
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

void wypisz(int (*tab)[N])
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

void zamiana(int (*tab)[N], int aa, int bb)
{
	int j,tmp;
	int a=aa-1, b=bb-1;
	for(j=0;j<N;j++)
	{ 
		tmp=*(*(tab+a)+j);
		*(*(tab+a)+j)=*(*(tab+b)+j);
		*(*(tab+b)+j)=tmp;
	}
}
