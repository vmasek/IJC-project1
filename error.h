/**
 * 	Název:		error.h
 * 	Řešení:		IJC-DU1, příklad a), 25.3.2014
 * 	Autor: 		Vojtech Mašek, FIT 1BIB xmasek15
 * 	Přeloženo: 	gcc 4.8.1
 * 
 * 	Napište modul "error.c" s rozhraním v "error.h", který definuje
	funkci void Warning(const char *fmt, ...) a
	funkci void FatalError(const char *fmt, ...). Tyto funkce mají
	stejné parametry jako printf(); tisknou text "CHYBA: " a potom
	chybové hlášení podle formátu fmt. Vše se tiskne do stderr
	(funkcí vfprintf) a potom FatalError ukončí program voláním
	funkce exit(1).  Použijte definice ze stdarg.h.
 */



#ifndef _ERROR_H
#define _ERROR_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void Warning(const char *fmt, ...);

void FatalError(const char *fmt, ...);

#endif
