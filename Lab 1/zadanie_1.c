/*
aplikacja która pobierze od u¿ytkownika liczby do tablicy jednowymiarowej a nastêpnie znajdzie minimum i max
*/

#include <stdio.h>

#define N 10

void wypisz(int*, int);
int max(int*, int, int);
int min(int*, int, int);

int main(void)
{
	int tab[N];
	int i, n, maxx,minn;
	for(i=0;i<10;i++)
	{
		int x;
		printf("\nPodaj liczbe: ");
		scanf("%d",&x);
		tab[i]=x;
		minn=tab[0];
		maxx=tab[0];
	}	
	printf("\nNajwieksza wartosc: %d ",max(tab, N, maxx));
	printf("\nNajmniejsza wartosc: %d ",min(tab, N, minn));
	
	return 0;
}

int max(int tab[], int n, int maxx)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(tab[i]>maxx)
		{
			maxx=tab[i];
		}
	}
	return maxx;
}

int min(int tab[], int n, int minn)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(tab[i]<minn)
		{
			minn=tab[i];
		}
	}
	return minn;
}
