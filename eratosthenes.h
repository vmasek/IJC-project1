/**
 * 	Název:		eratosthenes.h
 * 	Řešení:		IJC-DU1, příklad a), 25.3.2014
 * 	Autor: 		Vojtech Mašek, FIT 1BIB xmasek15
 * 	Přeloženo: 	gcc 4.8.1
 *
 * 	Jako testovací příklad implementujte funkci, která použije algoritmus známý
	jako Eratostenovo síto (void Eratosthenes(BitArray_t pole);) a použijte ji
	pro výpočet posledních 10 prvočísel ze všech prvočísel od 2 do
	N=101000000 (101 milionů).
	Funkci Eratosthenes napište do samostatného modulu "eratosthenes.c".
 */

#ifndef ERATOSTHENES_H_INCLUDED
#define ERATOSTHENES_H_INCLUDED

#include "error.h"
#include "bit-array.h"
#include <math.h>
#include <stdlib.h>

void Eratosthenes(BitArray_t pole);

#endif

