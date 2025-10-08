#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


// Funkcja: Zwolnij liste
void ZL (lista *l) {

	while((*l)) UOEL(l);

};

/* 
Funkcja: Dodaj Na Poczatek Listy

*/
void DNPL(lista *l, int i)
 { 
	if (l==0) return;
	 lista p = ( lista ) malloc(sizeof( elListy ));
	 p->klucz = i;
	 p->nast = *l;
	 *l = p;
 };

