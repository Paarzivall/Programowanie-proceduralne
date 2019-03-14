/*
obliczyc czas wykonania ciagu fibonacciego dla kilku wyrazow miêdzy 30 a 48
*/

#include <stdio.h>
#include <time.h>

long int ciag(int);

int main(void)
{
	int n;
	clock_t czas=clock();
	for(n=30;n<=45;n++)
	{
		int wyraz=ciag(n);
	    printf("%d wyraz ciagu fibonaciego wynosi: %ld a czas jego wykonania wynosi:%.3f \n",n,wyraz,(float)(clock()-czas)/CLOCKS_PER_SEC);
		czas=clock();
	}
	
	return 0;
}

long int ciag(int n)
{
	if(n==0)	return 0;
	if(n==1)	return 1;
	return ciag(n-1)+ciag(n-2);
}
