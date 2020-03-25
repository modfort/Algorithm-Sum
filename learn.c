#ifndef LEARN_H
#include "learn.h"
#endif
void affect(data*tab, data*Neuronne, size_t size_tab, size_t size_neuro)
{
	double min_dist,calc_dist;
	liste *tete = malloc(sizeof(liste));
	for (size_t i = 0; i < size_tab; ++i)
	{	min_dist=100000000;
		
		for (size_t j = 0; j < size_neuro ; ++j)
		{	calc_dist=distance_ecl2(Neuronne[j],tab[i]);
			if(min_dist>calc_dist)
			{	
				free_liste(tete);
				initialize(tete, &Neuronne[j]);
				min_dist=distance_ecl2(Neuronne[i],tab[j]);
			}
			if(min_dist == calc_dist)
			{	printf("entre\n");
				add(tete,Neuronne[j]);
			}
		}
		printf("bonsoir\n");
		print_list(tete);
		
		printf("bonjour\n\n");

	}
	free_liste(tete);
}