/**
 * 	Název:		error.c
 * 	Řešení:		IJC-DU1, příklad a), 25.3.2014
 * 	Autor: 		Vojtech Mašek, FIT 1BIB xmasek15
 * 	Přeloženo: 	gcc 4.8.1
 */

#include "error.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void Warning(const char *fmt, ...)
{
	va_list arg;
	const char *chyba ="CHYBA: ";
	long strlenght=strlen(fmt)+strlen(chyba);
	char format[strlenght+1];
	va_start(arg, fmt);
	strcpy(format, chyba); 
	strcat(format, fmt);
	format[strlenght]=0;
	vfprintf(stderr, format, arg);
	va_end(arg);
}

void FatalError(const char *fmt, ...)
{
	va_list arg;
	va_start(arg, fmt);
	Warning(fmt, arg);
	va_end(arg);
	exit(1);
}

