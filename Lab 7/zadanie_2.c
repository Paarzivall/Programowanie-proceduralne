#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct daneKW{
	double a, b, c, xf, xl, krok;
	int steps;
};

double f(struct daneKW, double);
int ZapisDoBin(char*, struct daneKW);
void czytajDane(struct daneKW *);
double LiczKroki(struct daneKW);
void pokazDane(struct daneKW);
void czytajzBin(char *);
int ZapisDoTxt(char *, struct daneKW);
void czytajzTxt(char *);

int main(int argc, char *argv[])
{
	struct daneKW dane;
	char nazwaPliku[256];
	int success;
	
	if(argc == 2)
	{
		if(strstr(argv[1], ".bin")!=NULL)
		{
			czytajzBin(argv[1]);
			success = 0;
		}
		else if(strstr(argv[1], ".txt")!=NULL)
		{
			czytajzTxt(argv[1]);
			success=0;
		}
		else
		{
			printf("Blad!!!");
			success = -1;
		}
	}
	else if(argc == 8)
	{
		dane.a = strtof(argv[1], NULL);
		dane.b = strtof(argv[2], NULL);
		dane.c = strtof(argv[3], NULL);
		dane.xf = strtof(argv[4], NULL);
		dane.xl = strtof(argv[5], NULL);
		dane.steps = (int)strtol(argv[6], NULL, 10);
		strcpy(nazwaPliku, argv[7]);
		printf ("%s\n", nazwaPliku);
		pokazDane(dane);
			if(strstr(argv[7], ".bin")!=NULL)
			{
				success = ZapisDoBin(argv[7], dane);
			}
			else if(strstr(argv[7], ".txt")!=NULL)
			{
				success = ZapisDoTxt(argv[7], dane);
			}
			else
			{
				printf("Blad!!!\nZle rozszerzenie");
				success = -1;	
			}	
	}
	else if(argc == 1)
	{
		printf("Podaj nazwe pliku do ktorego chcesz zapisac dane(.bin albo .txt)");
		gets(nazwaPliku);
		czytajDane(&dane);
		printf("%s\n", nazwaPliku);
		pokazDane(dane);
			if(strstr(nazwaPliku, ".bin")!=NULL)
			{
				success = ZapisDoBin(nazwaPliku, dane);
			}
			else if(strstr(nazwaPliku, ".txt")!=NULL)
			{
				success = ZapisDoTxt(nazwaPliku, dane);
			}
			else
			{
				printf("Blad!!!\nZle rozszerzenie");
				success = -1;	
			}	
	}	
	else
	{
		success = 0;
	}
	return success;
}

double f(struct daneKW daneK, double x)
{
	return (daneK.a*x*x) + (daneK.b*x) + daneK.c;
}

int ZapisDoBin(char * nazwaPliku, struct daneKW daneK)
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

double LiczKroki(struct daneKW daneK)
{
	return ((daneK.xl - daneK.xf)/(double)(daneK.steps - 1));
}

void pokazDane(struct daneKW daneK)
{
	printf("\nWczytane dane:\na=%f\nb=%f\nc=%f\nxf=%f\nxl=%f\nsteps=%d\n\n", daneK.a, daneK.b, daneK.c, daneK.xf, daneK.xl, daneK.steps);
}

void czytajzBin(char * filename) {
    FILE * plik;
    int n;
    double x, fx;
   
    plik = fopen(filename, "rb");
    printf("n\t|\tx\t|\tf(x)\n");
    printf("----------------------------------------\n");
    rewind(plik);
    while(!feof(plik)) {
        fread(&n, sizeof(int), 1, plik);
        if(ferror(plik) || feof(plik)) break;
        fread(&x, sizeof(double), 1, plik);
        fread(&fx, sizeof(double), 1, plik);
        printf("%d\t|%13.6f\t|%13.6f\n", n, x, fx);
    }
    fclose(plik);
}

int ZapisDoTxt(char * nazwaPliku, struct daneKW daneK) 
{
    double x, step;
    int ile = 1;
    FILE * plikT;
   
    step = LiczKroki(daneK);
   
    plikT = fopen(nazwaPliku,"w");
    if(ferror(plikT)) return 0;
   
    fprintf(plikT, "%d\n", daneK.steps);
    for(x = daneK.xf; daneK.steps-- > 0; x+=step) 
	{
        fprintf(plikT, "%d %f %f\n", ile++, x, f(daneK, x));
        if(ferror(plikT))	return 0;
    }    
    if(ferror(plikT)) return 0;
    fclose(plikT);
    
    return 1;
}

void czytajzTxt(char * nazwaPliku) {
    int n, i, ile;
    double x, fx;
    FILE * plik;
   
    plik = fopen(nazwaPliku, "r");
    fscanf(plik, "%d", &n);
    printf("%d\n", n);
    printf("n\t|\tx\t|\tf(x)\n");
    printf("----------------------------------------\n");
    for(i = 0; i < n; i++) {
        fscanf(plik, "%d %lf %lf", &ile, &x, &fx);
        printf("%d\t|%13.6f\t|%13.6f\n", ile, x, fx);
    }
    fclose(plik);    
}
