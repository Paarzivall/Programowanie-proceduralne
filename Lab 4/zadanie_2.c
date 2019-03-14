/*
zaimplementowac funkce fibonaciego rekurencyjnie
*/
#include <stdio.h>

long int ciag(int);

int main(void)
{
	int n;
 	printf("Podaj ktory wyraz ciagu fibonacciego chcesz obliczyc:\t");
    scanf("%d",&n);
    printf("%d wyraz ciagu fibonaciego wynosi: %ld",n,ciag(n));

	return 0;
}

long int ciag(int n)
{
	if(n==0)	return 0;
	if(n==1)	return 1;
	return ciag(n-1)+ciag(n-2);
}
