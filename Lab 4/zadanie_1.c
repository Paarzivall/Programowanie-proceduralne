/*
zaimplementowac rekurencyjnie funkcje silnia
*/
#include <stdio.h>

long int silnia(int);

int main(void)
{
	int n;
 	printf("Podaj n:\t");
    scanf("%d",&n);
    printf("Silnia wynosi: %ld",silnia(n));

return 0;
}

long int silnia(int n)
{
	if(n==0)	return 1;
	return n*silnia(n-1);
}
