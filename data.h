#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<math.h>
typedef struct data{
	float v[4];
	char name [30];
}data; 

void Add(data*tab,size_t size);
double distance_ecl2(data t1,data t2);
void Copie(data* Copie, size_t size ,double *Src);
void swap(data tab[],int i , int j);
void Moyenne(data *tab,int n,double*Moy);
void normalize(data *tab,int n);
void print_data_tab(data*tab, size_t size);
void print_data(data aff);
data GetDataFromLine(char*ligne);

