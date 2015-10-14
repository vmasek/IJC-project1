/**
 * 	Název:		steg-decode.c
 * 	Řešení 		IJC-DU1, příklad b), 25.3.2014
 * 	Autor: 		Vojtech Mašek, FIT 1BIB xmasek15
 * 	Přeloženo: 	gcc 4.8.1
 *
 * 	Napište testovací program "steg-decode.c", kde ve funkci main načtete ze
    souboru zadaného jako jediný argument programu obrázek ve formátu PPM
    a v něm najdete uloženou "tajnou" zprávu. Zprávu vytisknete na stdout.
 */

#include <stdlib.h>
#include <stdio.h>

#include "error.h"
#include "bit-array.h"
#include "eratosthenes.h"
#include "ppm.h"



void PrintSecretMessage(struct ppm *img, BitArray_t pole)
{
	unsigned int j = 0;
    unsigned char znak[2] = {0};

	for(unsigned long i=0;i<pole[0];i++)
	{
		if(GetBit(pole,(i))==0)
		{
			DU1__SET_BIT(znak, j, (img->data[i] & 1) ); //nastavi bit podla LSB v zadanom prvku pola, syntax rovnaky ako MASK s rozdielom ignorovania posunutia pola o prvy prvok
            if (j < 7)
                j++;
            else if (znak[1] == '\0')     //zjistena koncova nula, nepokracuji
                break;
            else
            {
                printf("%c",znak[1]);     //nacteno 8 bitu, vytiskni je jako char
                j = 0;
            }
		}
	}
	printf("\n"); 
}

void decode(struct ppm *img)
{
	unsigned long *pole=calloc(BYTE_SIZE((img->xsize*img->ysize*3))+1,sizeof(unsigned long));

	if(!pole)
		FatalError("Nedostatok pameti\n");
		
	pole[0]=(img->xsize*img->ysize*3);
	

	Eratosthenes(pole);
	
	PrintSecretMessage(img, pole);

	free(pole);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Warning("Nespravny pocet parametrov\nSyntax spustenia:\t./steg-decode obrazok.ppm\n");
        return EXIT_FAILURE;
    }
    
    
    struct ppm *img=ppm_read(argv[1]);
	if(!img)
		Warning("no img\n");
	
	decode(img);	
	
	free(img);
    return EXIT_SUCCESS;
}
