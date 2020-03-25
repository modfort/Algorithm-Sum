#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
typedef struct data{
	float v[4];
	char name [30];
}data_; 
typedef struct vector
{	
	data_ *data;
	size_t size,capacity;
}vector;
void print_data(data_ aff);

vector initvector(size_t capacity);
void copyvector(vector *dest , vector *src);
void fill(vector* t , data_ v);
void printvector(vector* t);
void reserve(vector *t);
void pushfront(vector*t,data_ v);
void pushback(vector *t,data_ v);
data_ front(vector*t);
data_ back(vector*t);
void freevector(vector *t);
size_t size(vector*);
size_t capacity(vector*);
void copiedata(data_ *src,data_ src);
