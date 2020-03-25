#ifndef DATA_H
#include "data.h"
#endif
typedef struct liste liste;
struct liste
{
	data *data;
	liste*next;
};

void initialize(liste * fi,data first);
void add(liste * fi , data next);
void print_list(liste*fi);
void free_liste(liste*fi);

