/*
implementacja listy jednokierunkowej
mozna dodawac, usuwac, i wyswietlac elementy listy jednokierunkowej
*/

#include <stdio.h>
#include <stdlib.h>

struct list{
	int klucz;
	struct list * next;
};

struct list* dodaj(struct list *q, int x);
void drukuj(struct list *q);
struct list* usun(struct list *q, int x);

int main(void)
{
	int i,x;
	struct list* glowa=NULL;
	
	while(i!=1)
	{
		printf("Podaj element ktory chcesz dodac(1 konczy dodawanie):\t");
		scanf("%d",&i);
		glowa=dodaj(glowa,i);
	}
	
	if(glowa!=NULL)
	{
		printf("\nElementy listy: ");
		drukuj(glowa);
	    printf("\nPodaj element ktory chcesz usunac: \t");
		scanf("%d", &x);
	    glowa=usun(glowa, x);
	}
	else
	{
		printf("Lista jest pusta");
	}
	
	printf("\npo usunieciu: ");
	drukuj(glowa);
	
	return 0;
}

struct list* dodaj(struct list*q, int x)
{
	struct list *pom;
	pom=(struct list*)malloc(sizeof(struct list));
	pom->klucz=x;
	pom->next=q;
	q=pom;
	
	return q;
}

void drukuj(struct list* q)
{
	struct list *pom;
	int i=0;
	pom=q;
	  while(pom!=NULL)
	  {
	  	printf("\nElement nr %d:%d",++i, pom->klucz);
	  	pom=pom->next;
	  }	
}

struct list* usun(struct list *q, int x)
{
	struct list *pom, *tmp;
	pom=q;
	
	while(pom!=0 && pom->klucz!=x)
	{
		tmp=pom;
		pom=pom->next;
	}
	
	if(pom!=0)
	{
		if(pom==q)
				  q=pom->next;
        else
        	tmp->next=pom->next;
        	
       	free(pom);
	}
	else
		printf("\nElementu %d nie ma w liscie",x);
	
	return q;
}
