#include <stdio.h>

/*
odczytuje wartosci z pliku binarnego
*/

int main(void)
{
	FILE * plik;
	plik= fopen("cw7_kwadratowa.bin", "rb");
	int n;
	double x, fx;
	printf("krok\t\t|\tx\t|\tf(x)");
	printf("\n-----------------------------------------------\n");
	while(!feof(plik))
	{
	fread(&n,sizeof(int),1,plik);
	 if(ferror(plik)||feof(plik))	break;
	fread(&x,sizeof(double),1,plik);
	fread(&fx,sizeof(double),1,plik);
	printf("\t%d\t|\t%.2f\t|\t%.2f\n",n,x,fx);
	}
	fclose(plik);
	
	return 0;
}
