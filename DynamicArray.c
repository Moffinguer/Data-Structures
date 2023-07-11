#include <stdio.h>
#include <stdlib.h>

// Defined structure

typedef struct dynamicArray 
{
	int *array;
	size_t size;
	size_t length; // size_t is an undefined integer, which can store an integer value of any size
} 
array;


// Starting functions
array *init( void );

// Array needs to be expanded if add to a middle position
void expandArray( array *arr, size_t pos );

int getVal( array *arr, size_t i );

void addVal( array *arr, size_t i, int val );

// Get element from position i, but removes it from the array
int retrieveVal( array *arr, size_t i );

// Add at the end
void pushVal( array *arr, int val );

// Add at the beginning
void unshiftVal( array *arr, int val );


// Get element from the begining, but removes it from the list
int shiftVal( array *arr );


// Get element at the end, but removes it
int popVal ( array *arr );


array *init( void )
{
	array *arr = malloc( sizeof( array ) ); // reservas un espacio de memoria del tamaño de esa estructura
	arr->length = 0; // tamaño array
	arr->size = 8; // set tamaño de bloque

	arr->array = calloc( 0, sizeof( int ) ); // espacio de memoria reservado, seteado a 0, vaciarlo

	return arr;
}


int getVal( array *arr, size_t i )
{
	if ( arr->length <= i ) return 0; // Throw error ¿?

	int value = *( arr->array ) + i;
	return value;
}

void pushVal( array *arr, int val)
{
	if ( arr->length <= arr->size )
	{
		arr->size *= 8;
		arr->array = realloc( arr->array, arr->size * sizeof( int ) );
	}
	arr->array[ arr->length++ ] = val;
}

void unshiftVal( array *arr, int val )
{
	if (arr->length <= arr->size )
	{
		arr->size *= 8;
		arr->array = realloc( arr->array, arr->size * sizeof( int ) );
	}
	arr->length++;
	size_t moved = arr->array[1];
	for ( int i = 1; i < arr->length; i++ )
	{
		arr->array[i - 1] = moved;
		moved = arr->array[i + 1];
	}
	arr->array[0] = val;
}

void addVal( array *arr, size_t pos, int val)
{
	if ( arr->length > arr->size )
	{
		int *tmp;
		tmp = realloc ( arr->array, 8 * arr->size * sizeof ( int ) ); // 3 espacios más
	}
	
	int i = 0;
	while ( i++ < pos );

	int swap = arr->array[i];
	arr->array[i++] = 0;
	arr->length++;

	int tmp;
	while ( i < arr->length )
	{
		tmp = arr->array[i];
		arr->array[i++] = swap;
		swap = tmp;
	}
	return;		
}

int popVal( array *arr )
{
	if ( arr->length == 0 )
	{
		int *tmp;
		tmp = realloc ( arr->array, sizeof ( int ) ); // 3 espacios más	
		arr->array = tmp;

		arr->size = 1;
		
		return 0;
	}
	if ( arr->length % 10 )
	{	
		arr->length--;
		int *tmp;	
		arr->size = ( arr->size - arr->length );
 		tmp = realloc ( arr->array, arr->size * sizeof ( int ) ); // 3 espacios más
		
		int last = arr->array[arr->length];
		for (int i = 0; i < arr->length; i++ ) tmp[i] = arr->array[i];
		return last;
	}
	arr->length--;
	int last = arr->array[arr->length];
	return last;
}

int shiftVal( array *arr )
{
	if ( arr->length == 0 )
	{
		int *tmp;
		tmp = realloc ( arr->array, .5 * arr->size * sizeof ( int ) ); // 3 espacios más
		arr->array = tmp;
		return 0;
	}
	int *tmp;
	tmp = realloc ( arr->array, .5 * arr->size * sizeof ( int ) ); // 3 espacios más
	
	int first = arr->array[0];
	for (int i = 0; i < ( arr->length - 1 ); i++ ) tmp[i] = arr->array[i+1];
	return first;
}

void expandArray( array *arr, size_t pos )
{

}


