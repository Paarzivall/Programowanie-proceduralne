/*
oblicza n-ty wyraz ciagu fibonacciego 
*/
#include <stdio.h>

long int ciag(int);

int main(void)
{
int n;
	printf("Podaj ktory wyraz ciagu chcesz obliczyc:\t");
	scanf("%d",&n);	
	
	printf("%d wyraz ciagu wynosi %d",n, ciag(n));
	
	return 0;
}

long int ciag(int n)
{
	int xz=0, xf=1, i;
	if(n==0)	return 0;
	if(n==1)	return 1;
	 
	for(i=0;i<n;++i)
	{
		int tmp=xz+xf;
		xz=xf;
		xf=tmp;
	}
	return xz;
}
