/*
zaimplementowac funkcje strcat, dwa parametry (lancuchy s1 i s2)
dolaczenie s1 do s2 pod warunkiem ze s1 jest wystarczajaco dlugi
korzystajac z notacji wskaznikowj
*/

#include <stdio.h>

void sstrcat(char s1[], char s2[]);

int main(void)
{
	char s1[50]="Ala ";
	const char *s2="ma kota.";
	sstrcat(s1, s2);
	puts(s1);

return 0;
}

void sstrcat(char* s1, char* s2)
{
int i=0, j=0;
	while(*(s1+i)!='\0')
	{
		i++;
	}
    
    while(*(s2+j)!='\0')
    {
        *(s1+(i++))=*(s2+(j++));
    }
 *(s1+i)='\0';	
}

/*
//2 sposób- szybszy

 while(*s1)
 		   s1++;
 while(*s1++=*s2++);
*/
