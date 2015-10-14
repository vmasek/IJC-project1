/**
 * 	Název:		eratosthenes.c
 * 	Řešení:		IJC-DU1, příklad a), 25.3.2014
 * 	Autor: 		Vojtech Mašek, FIT 1BIB xmasek15
 * 	Přeloženo: 	gcc 4.8.1
 */

#include "eratosthenes.h"

void Eratosthenes(BitArray_t pole)
{
	unsigned long max_spol = (unsigned long) sqrt(pole[0]);   //staci prejst cisla do druhej odmocniny max hodnoty
    unsigned long nasobok = 1;
    
    for (unsigned long i = 2; i < max_spol; i++)
    {
        if (GetBit(pole,i) == 0)
        {
            while ( nasobok*i < pole[0])     //odstrani nasobky prvocisla
            {
                SetBit(pole, (nasobok*i), 1);
                nasobok++;
            }
            nasobok = i;
        }
    }
    
    // nula a jedna niesu povazovane za prvocisla a dvojka je prve prvocislo
    SetBit(pole,0,1);
    SetBit(pole,1,1);
	SetBit(pole,2,0);
}
