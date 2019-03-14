/*
zapis do pliku tekstowego
*/

#include <stdio.h>
#include <math.h>

double funkcja(double, double, double, double);

int main(void)
{
	double a,b,c,x,xf,xl;
	int steps;
	
	printf("Podaj wartosci wspolczynnikow: \n");
	printf("a:\t");
				   scanf("%lf",&a);
    printf("b:\t");
				   scanf("%lf",&b);
 	printf("c:\t");
				   scanf("%lf",&c);
	printf("Podaj zakres w jakim chcesz obliczyc dana funkcje:\n");
	printf("x1:\t");
					scanf("%lf",&xf);
	printf("x2:\t");
					scanf("%lf",&xl);
	printf("Ile krokow ma sie wykonac?\t");
				scanf("%d",&steps);
	
	double krok=(xl-xf)/(steps-1);
	
	if(krok<0)	krok*=-1;
	
	printf("\nkrok=%.2lf\n\n",krok);
	
		FILE * plik; 
		plik= fopen("wyniki.txt", "w");
	int ile=1;
	
	if(xf>xl)
	{
		for(x=xl;x<=xf;x+=krok)
		{
			double fx=funkcja(a,b,c,x);
			printf("krok=%d x=%.1lf\t y=%.2lf\n",ile,x, fx);
			fprintf ( plik, "krok=%d\tx=%.1f\t y=%.2f\n",ile,x, funkcja(a,b,c,x));
			ile++;
		}
	}
	else
	{
		for(x=xf;x<=xl;x+=krok)
		{
			double fx=funkcja(a,b,c,x);
			printf("krok=%d x=%.1lf\t y=%.2lf\n",ile,x, fx);
			fprintf ( plik, "krok=%d\tx=%.1f\t y=%.2f\n",ile,x, funkcja(a,b,c,x));
			ile++;
		}	
	}
	fclose(plik);
	
	return 0;
}

double funkcja(double a, double b, double c, double x)
{
	return a*pow(x,2)+b*x+c;
}
