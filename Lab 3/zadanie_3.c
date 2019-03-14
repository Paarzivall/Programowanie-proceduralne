/*
napisz funkcjê strend przyjmuj¹c¹ 2 parametry s1 i s2 ktora zwraca s1 jezeli ciag s2 wystepuje na koncu ciagu s1 
zwraca 0 jezeli ten ciag nie wystepuje
*/

#include <stdio.h>

int sstrend(char *, char *);

int main(void)
{
	char s1[50]="Ala ma kota";
	char s2[]="kota";
	
	if(sstrend(s1, s2)==1)
	{
		printf("ciag 1 zawiera ciag 2");
	}
	else
	{
		printf("ciag 1 nie zawiera ciagu 2");
	}
	
	return 0;
}

int sstrend(char *s1, char *s2)
{
	int i=0, j=0;
	while(s1[i]!='\0')
	{
		i++;
	}
	
	while(s2[j]!='\0')
	{
		j++;
	}
	
	while(j>=0)
	{
        if(s1[i--]!=s2[j--])
        {
	    	return 0;
        }
	}

	return 1;
}
