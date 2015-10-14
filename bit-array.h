/**
 * 	Název:		bit-array.h
 * 	Řešení 		IJC-DU1, příklad a), 25.3.2014
 * 	Autor: 		Vojtech Mašek, FIT 1BIB xmasek15
 * 	Přeloženo: 	gcc 4.8.1
 *
 * 	V rozhraní "bit-array.h" definujte makra pro pole bitů:
	BitArray(jmeno_pole,velikost)
       definuje a nuluje pole

	typedef BitArray_t
       Typ bitového pole (pro předávání parametru do funkce)

	BitArraySize(jmeno_pole)
       vrátí deklarovanou velikost pole v bitech

	SetBit(jmeno_pole,index,výraz)
       nastaví zadaný bit v poli na hodnotu zadanou výrazem

	GetBit(jmeno_pole,index)
       získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1

	Kontrolujte meze polí. V případě chyby volejte funkci
    FatalError("Index %ld mimo rozsah 0..%ld", (long)index, (long)mez).
	(Použijte modul error.c/error.h z příkladu b)

	Napište pomocná makra DU1__GET_BIT(p,i), DU1__SET_BIT(p,i,b)
	pro indexování bitů v poli T *p nebo T p[NN] bez kontroly mezí,
	kde T je libovolný celočíselný typ (char, unsigned short, ...).
	Pro vaši implementaci použijte pole typu: unsigned long [].
	Implementace musí efektivně využívat paměť (využít každý
	bit pole až na posledních max. X-1, pokud má unsigned long X bitů).

	Podmíněným překladem zajistěte, aby se při definovaném symbolu
	USE_INLINE místo těchto maker definovaly inline funkce.	
 */

#include "error.h"


#ifndef BIT_ARRAY_H_INCLUDED
#define BIT_ARRAY_H_INCLUDED

//#define USE_INLINE

typedef unsigned long BitArray_t[];


void Warning(const char *fmt, ...);
void FatalError(const char *fmt, ...);



#define BitArray(jmeno_pole, velikost)  unsigned long jmeno_pole[BYTE_SIZE(velikost)+1] = {(velikost)};

#define BYTE_SIZE(velikost) (((velikost)%BitArraySize(unsigned long)==0) ? ((velikost)/BitArraySize(unsigned long)) : ((velikost)/BitArraySize(unsigned long)+1) )

#define BitArraySize(jmeno_pole) (sizeof(jmeno_pole)*8)
#define ArraySize(jmeno_pole) (sizeof(jmeno_pole[0])*8) //32 pokial je 4B typ

#define SIZE(velikost, typ) ( (velikost)/ArraySize(typ) )		// nieco/32(vecsinou) //pri char 8
#define mSIZE(velikost, typ) ( (velikost)%ArraySize(typ) )		// nieco%32(vecsinou)

#define WriteBIT(byte, value) ( (byte) |= (value) )
#define ClearBIT(byte, value) ( (byte) &= ~(value) )
 
#define DU1__SET_BIT(p,i,b) ( (b==0) ? ClearBIT( p[(1 + SIZE((i),p))], SHIFT(p,i)) : WriteBIT( p[(1 + SIZE((i),p))], (SHIFT(p,i)) ) ) //je nutne shiftovat ulong koli kompatibilite s x86/x64

#define DU1__GET_BIT(p,i) ( ((MASK(p,i)) > 0) ? 1 : 0 )

#define SHIFT(p,i) (1UL << mSIZE((i),p))

#define MASK(p,i) (p[1+SIZE(i, p)]) & (SHIFT(p,i))


#ifndef USE_INLINE

#define SetBit(jmeno_pole,index,vyraz) ( OPP(jmeno_pole,(index)) DU1__SET_BIT(jmeno_pole,index,vyraz) )

#define GetBit(jmeno_pole,index) ( OPP(jmeno_pole,(index)) DU1__GET_BIT(jmeno_pole, (index)) )

#define OPP(jmeno_pole,index) ((index)>=(jmeno_pole[0])) ? FatalError("Index mimo rozsah\n"),0\
														:

#else

inline void SetBit(BitArray_t jmeno_pole, unsigned long index, int vyraz)
{
	if( index >= jmeno_pole[0] )
		FatalError("Index mimo rozsah\n");
	else
	{
		if(vyraz==0)
		{
			jmeno_pole[(1 + SIZE(index,jmeno_pole))] &= ~(1UL << mSIZE(index,jmeno_pole));
		}
		else
		{
			jmeno_pole[(1 + SIZE(index,jmeno_pole))] |= (1UL << mSIZE(index,jmeno_pole));
		} 
	}	
}

inline int GetBit(BitArray_t jmeno_pole, unsigned long index)
{
	if( index >= jmeno_pole[0] )
		FatalError("Index mimo rozsah\n");
	
	return ( (((jmeno_pole[1+SIZE(index, jmeno_pole)]) & (1UL << mSIZE((index),jmeno_pole))) > 0) ? 1 : 0 );
}

#endif

#endif
