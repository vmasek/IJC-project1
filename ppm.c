/**
 * 	Název:		ppm.c
 * 	Řešení 		IJC-DU1, příklad b), 25.3.2014
 * 	Autor: 		Vojtech Mašek, FIT 1BIB xmasek15
 * 	Přeloženo: 	gcc 4.8.1
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "error.h"
#include "ppm.h"

struct ppm *ppm_read(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (!f)
    {
        Warning("Nepodarilo sa otvorit subor .ppm\n");
        return NULL;
    }

    unsigned long x, y;
    int color_max;
    
    if (fscanf(f, "P6 %lu %lu %d%*c", &x, &y, &color_max)!= 3||color_max != 255) //predpokladany LF na konci je ignorovany
    {
        if (fclose(f) == EOF)
             Warning("Neuspesne zatvaranie suboru\n");
        Warning("Chybny format suboru\n");
        return NULL;
    }

    struct ppm *img = malloc(sizeof(struct ppm) + 3*x*y+1);
    if (!img)
    {
        if (fclose(f) == EOF)
             Warning("Neuspesne zatvaranie suboru\n");
         Warning("Nedostatok pameti.\n");
        return NULL;
    }
    
    img->xsize = x;
    img->ysize = y;
    
    if (fread(img->data, 1, 3*x*y, f) < 3*x*y)
    {
        if (fclose(f) == EOF)
             Warning("Neuspesne zatvaranie suboru\n");
        free(img);
        Warning("Chyba pri cteni souboru.\n");
        return NULL;
    }

    if (fclose(f) == EOF)
    {
		Warning("Neuspesne zatvaranie suboru\n");
		free(img);
		return NULL;
	}
	
    return img;
}

int ppm_write(struct ppm *p, const char * filename)
{
	if(!p)
	{
		Warning("Chybne vstupne data");
		return -1;
	}
		
	FILE *file = fopen(filename, "wb+");
	if (!file)
	{
		Warning("Nevytvorilo file");
		return -1;
	}
	fprintf(file,"P6\n%lu %lu\n255\n",p->xsize,p->ysize);
	
	fwrite(p->data, (p->xsize*p->ysize*3), 1, file);
	
	if (fclose(file) == EOF)
             Warning("Neuspesne zatvaranie suboru\n");
             
	return 0;
}

