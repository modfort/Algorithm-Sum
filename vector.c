#include "vector.h"

	
vector initvector(size_t capacity)
{	if(capacity<1)
		capacity=2;
	
	vector new;
	new.data = (data_*) malloc(sizeof(data_) * capacity);
	assert(new.data);
	new.capacity = capacity;
	new.size = 0;
	return new;
}

void copyvector(vector *dest , vector *src)
{
	if(dest->capacity<=src->size)
	{
		fprintf(stderr, "%s\n", "capacity<size");
		exit(1);
	}
	size_t i;
	for ( i = 0; i < src->size; ++i)
		copiedata(dest->data[i],src->data[i]);
	
}


void copiedata(data_ *dest,data_ *src)
{	
	for (int i = 0; i < 4; ++i)
		dest->v[i] = src->v[i];
	strcpy(dest->name,src->name);

}

void fill(vector* t , data_ v){
	size_t i;
	for ( i = 0; i < t->capacity; ++i)
		copiedata(t->data[i],v);
	
	t->size=t->capacity-1;
}
void print_data(data aff)
{
	printf("%f,%f,%f,%f,%s\n",aff.v[0],aff.v[1],aff.v[2],aff.v[3],aff.name );
}

void printvector(vector *t)
{
	size_t i;
	for (i = 0; i < t->size; ++i)
		print_data(t->data[i]);	
}

void reserve(vector *t)
{
	vector  tmp;
	tmp.data = (data_*) malloc( sizeof(data_) * t->capacity );
	if(tmp.data==NULL)
	{
		fprintf(stderr, "erreur d'allocation\n" );
		exit(0);
	}
	assert(tmp.data);
	tmp.capacity = t->capacity;
	tmp.size = t->capacity;
	copyvector(&tmp,t);
	free(t->data);
	t->data = (data_*)malloc(sizeof (data_)*t->capacity*2);
	assert(t->data);
	t->capacity *= 2;
	copy(t,&tmp);
}

void pushback(vector *t,data_ v)
{	
	if(t->size >= t->capacity-1)
		reserve(t);
	
 	copiedata(t->data[t->size] ,v) ;
	t->size++;	
}

void pushfront(vector*t,data_ v)
{	
	if( t->size >= t->capacity - 1 )
		reserve(t);
	size_t i;
	for ( i = t->size ; i >0 ; --i )
		copiedata(t->data[i],t->data[i-1]);
 	copiedata(t->data[t->size] ,v) ;
	t->size++;
	
}

data_ front(vector*t){
	return t->data[0];
} 

data_ back(vector*t)
{
	return t->data[t->size-1];
}

size_t size(vector*t)
{
	return t->size;
}

size_t capacity(vector*t)
{
	return t->capacity;
}

void freevector(vector *t)
{
	free(t->data);
}

