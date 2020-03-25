#ifndef LISTE_H
#include "liste.h"	
#endif
void  initialize(liste*fi, data &first)
{
	fi = malloc(sizeof(liste));
	fi->data = first;
	fi->next = NULL; 
}

void add(liste *fi , data &next)
{
	while(fi->next != NULL)
		fi = fi->next;
	liste * nxt;
	nxt 	  = malloc(sizeof(liste));
	nxt->data = next;
	nxt->next = NULL;
}

void print_list(liste *fi)
{
	if(fi)
	{
		print_data(fi->data);
		print_list(fi->next);
	}
}

void free_liste(liste *fi)
{
	if(fi)
	{
		free_liste (fi->next);
		free(fi);
	}

}
