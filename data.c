#ifndef DATA_H
#include "data.h"
#endif
void
 print_data(data aff)
{
	printf("%f,%f,%f,%f,%s\n",aff.v[0],aff.v[1],aff.v[2],aff.v[3],aff.name );
}

void print_data_tab(data*tab, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		print_data(tab[i]);
	}
}
/*
	fonction qui des que tu lui passe une ligne te renvoie un objet data
*/
void
  normalize(data *tab,int n)
{	
	float somme;
	for (int i = 0; i < n; ++i)
	{	somme=0;
		for (int j = 0; j < 4; ++j)
		{
			somme+=pow(tab[i].v[j],2);
		}
		somme=sqrt(somme);
		for (int j = 0; j < 4; ++j)
		{
			tab[i].v[j]/=somme;
		}	
	}

	
}

void
  Moyenne(data *tab,int n,double*Moy)
{	
	for (int i = 0; i < n; ++i)
	{
		Moy[0]+=tab[i].v[0];	
		Moy[1]+=tab[i].v[1];
		Moy[2]+=tab[i].v[2];
		Moy[3]+=tab[i].v[3];	
	}

	for (int i = 0; i < 4; ++i)
		Moy[i]/=n;

}
	
data
 GetDataFromLine(char*ligne)
{	
	char*get=strtok(ligne,",");
	data New;
	New.v[0]=atof(get);
	get=strtok(NULL,",");
	New.v[1]=atof(get);
	get=strtok(NULL,",");
	New.v[2]=atof(get);
	get=strtok(NULL,",");
	New.v[3]=atof(get);
	get=strtok(NULL,",");
	strcpy(New.name,get);
	return New;
}


void
 Copie(data* Copie, size_t size ,double *Src)
{
	for (size_t i = 0; i < size; ++i)
	
		for (int j = 0; j < 4; ++j)
		
			Copie[i].v[j]=Src[j];
			

	
}
void swap(data tab[],int i , int j)
{
	data tmp;
	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

/*
	distance eucliedienne entre deux tableau de n data
*/
double
 distance_ecl(data *tab1,data *tab2,int n)
{
	double dist=0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 4; ++j)
			dist += pow(tab1[i].v[j]-tab2[i].v[j],2);
	return sqrt(dist);			
}


double
 distance_ecl2(data t1,data t2)
{
	double dist=0;
	for (int j = 0; j < 4; ++j)
		dist += pow(t1.v[j]-t2.v[j],2);
	
	return sqrt(dist);			
}
//on les randomize pour les rendre plus vraie
void
 Add(data*tab,size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int r = rand()%75;
			double random = r/(double)1000.0;
			random -= 0.05;
			tab[i].v[j]+=random;
			if(tab[i].v[j]>=1||tab[i].v[j]<0)
			{
				fprintf(stderr, "%s :%f\n","error lors de l'atribution ",tab[i].v[j] );
				exit(0);
			}
		}
		
	}
}



