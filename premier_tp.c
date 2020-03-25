#ifndef LEARN_H
#include "learn.h"
#endif

int 
main ( int argc, char const *argv[])
{	
	//t=initvector(10);
	FILE*fp=fopen("iris.data","r");
	char  s [150];
	data Test[150],Neuronne[60],Neuronne1[10][6];
	double Moy[4];
	int i=0,j,random,n=30;

	while(fgets(s,150,fp)!=NULL)
		Test[i++] = GetDataFromLine(s); 

	srand(time(NULL));

	for (i = 0; i < 150; ++i)
	{
		random=rand()%150;
		swap(Test,i,random);
	}


	normalize(Test,150);

	Moyenne(Test,150,Moy);
	
	Copie(Neuronne,60,Moy);
	
	Add(Neuronne,60);
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 6	; ++j)
		{
			Neuronne1[i][j] = Neuronne[i*10+j]; 
		}
	
	}
	//print_data_tab(Neuronne,60);
	for (int i = 0; i < 10; ++i)
	{
		print_data_tab(Neuronne1[i],6);
		printf("\n");
	}
	i=0;
	j=0;
	while(i<n)
	{	
		i+=8;
		j++;
	}
	i-=8;
	j--;
	printf("%d %d \n",i ,j);
	affect(Test,Neuronne,150,60);	
	fclose(fp);
	return 0;
}