/**
 * 	Název:		prvocisla.c
 * 	Řešení 		IJC-DU1, příklad a), 25.3.2014
 * 	Autor: 		Vojtech Mašek, FIT 1BIB xmasek15
 * 	Přeloženo: 	gcc 4.8.1
 *
 * 	Implementujte funkci, která použije algoritmus Eratostenovo síto a použijte ji
	pro výpis posledních 10 prvočísel ze zadaného rozsahu prvocisel. Každé prvočíslo
	tiskněte na zvláštní řádek v pořadí vzestupném.
 */


#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "bit-array.h"
#include "eratosthenes.h"


void Print_n_Primes(BitArray_t pole, unsigned long n)
{
	unsigned long count=0, *arr=calloc(n,sizeof(unsigned long));

	if(!arr)
		FatalError("Nedostatok pameti\n");
	
	for(unsigned long i=0;i<pole[0];i++)
	{
		if(!GetBit(pole,(i)))
		{
			arr[count%n]=i;
			count++;
		}
	}
	
	if(count<n)
			FatalError("pozadovany pocet %lu prvocisel je o %lu viac ako zadane pole obsahuje\n", n, n-count );
	
	for(unsigned long i=0;i<n;i++)
	{
			printf("%lu\n", arr[(count+i)%n] );
	}

	free(arr);
}

int main(void)
{
	BitArray(pole, 101000000);
	Eratosthenes(pole);
	Print_n_Primes(pole, 10);

	return EXIT_SUCCESS;
}


