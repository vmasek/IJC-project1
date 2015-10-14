/**
 * 	Název:		ppm.h
 * 	Řešení 		IJC-DU1, příklad b), 25.3.2014
 * 	Autor: 		Vojtech Mašek, FIT 1BIB xmasek15
 * 	Přeloženo: 	gcc 4.8.1
 *
 * 	Napište modul "ppm.c" s rozhraním "ppm.h",
	ve kterém definujete datový typ struct ppm
	a funkce:
	struct ppm * ppm_read(const char * filename);
        načte obsah PPM souboru do touto funkcí dyanmicky
        alokované struktury. Při chybě formátu použije funkci Warning
        a vrátí NULL.

    int ppm_write(struct ppm *p, const char * filename);
        zapíše obsah struktury p do souboru ve formátu PPM.
        Při chybě použije funkci Warning a vrátí záporné číslo.
 */

#ifndef PPM_H_INCLUDED
#define PPM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "bit-array.h"
#include "eratosthenes.h"



struct ppm {
    unsigned long xsize;
    unsigned long ysize;
    char data[];
};

struct ppm *ppm_read(const char *filename);

int ppm_write(struct ppm *p, const char *filename);

#endif
