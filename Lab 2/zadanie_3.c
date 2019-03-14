/*
uzytkownik ma wskazac rozmiar tablicy jaka ma powstac, uzytkownik ma wpisac wartosci tej tablicy
*/

#include <stdio.h>
#include <stdlib.h>

void wypelnij(int*, int);
void wypisz(int*, int);

int main(void)
{
	int *tab, n;
	printf("Podaj ilosc elementow w tablicy jednowymiarowej: \t");
	scanf("%d", &n);
	
	tab=(int *)malloc(n * sizeof(int));
	if(tab==NULL)
	{
		printf("\nPrzydzial pamieci nie powiodl sie\n");
	}
	
	wypelnij(tab, n);	
	wypisz(tab, n);
	free(tab);
	
	return 0;
}

void wypelnij(int tab[], int n)
{
	int i, liczba;
	for(i=0;i<n;i++)
	{
		printf("Podaj liczbe ktora chcesz umiescic w %d wierszu\t", i+1);
		scanf("%d",&liczba);
		tab[i]=liczba;
	}
}

void wypisz(int tab[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("tab[%d]=%d\n",i,tab[i]);
	}
}
