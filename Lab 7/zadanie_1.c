/*
uzytkownik wpisuje wspolczynniki a,b,c i okresla zakres i mowi ile wartosci funkcji chce uzyskac
wszystko zapisac w pliku tekstowym
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

struct daneKW{
	double a, b, c, xf, xl, krok;
	int steps;
};

double f(struct daneKW, double);
void czytajDane(struct daneKW *);
int ZapisDoBin(char * nazwaPliku, struct daneKW);
double LiczKroki(struct daneKW);

int main(void)
{
	struct daneKW dane;
	char nazwaPliku[256];
	
		printf("Podaj nazwe pliku do ktorego chcesz zapisac dane(z rozszerzeniem '.bin')");
	gets(nazwaPliku);
	czytajDane(&dane);
	ZapisDoBin(nazwaPliku, dane);
 
	return 0;
}

void czytajDane(struct daneKW * daneK)
{
	printf("Podaj a ");
    	scanf("%lf", &daneK->a);
    printf("Podaj b ");
    	scanf("%lf", &daneK->b);
    printf("Podaj c ");
   		scanf("%lf", &daneK->c);
    printf("Podaj x start ");
    	scanf("%lf", &daneK->xf);
    printf("Podaj x koniec ");
    	scanf("%lf", &daneK->xl);
    printf("Podaj ile krokow ");
    	scanf("%d", &daneK->steps);
}


double f(struct daneKW daneK, double x)
{
	return (daneK.a*x*x) + (daneK.b*x) + daneK.c;
}


double LiczKroki(struct daneKW daneK)
{
	return ((daneK.xl - daneK.xf)/(double)(daneK.steps - 1));
}

int ZapisDoBin(char* nazwaPliku, struct daneKW daneK)
{
	FILE * plik;
	int ile = 1;
	double x, fx, step;
	

	plik = fopen(nazwaPliku, "wb");
	if(ferror(plik))	return 0;
	
	step = LiczKroki(daneK);
	   for(x = daneK.xf; daneK.steps-- > 0; x+=step) 
	   {
      		fx = f(daneK, x);
       		fwrite(&ile, sizeof(int), 1, plik);
       			if(ferror(plik)) return 0;
       		fwrite(&x, sizeof(double), 1, plik);
      			if(ferror(plik)) return 0;
        	fwrite(&fx, sizeof(double), 1, plik);
       			if(ferror(plik)) return 0;
       		ile++;
       	}
    fclose(plik);
    
    return 1;
}
