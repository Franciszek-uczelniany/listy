#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "lista_various.h"

/* 
Funkcja: Dodaj Na Poczatek Listy

*/
void DNPL(lista *l, int i)
 { 
	if (l==0) return;
	 lista p = ( lista )malloc(sizeof( elListy ));
	 p->klucz = i;
	 p->nast = *l;
	 *l = p;
 };


/*
Funkcja: Dodaj do posortowanej Listy

*/
void DL_sort(lista *l, int klucz) {


	lista k  = (lista) malloc(sizeof(elListy));
	k->klucz = klucz;

	if((l == 0 || *l == 0) || (*l)->klucz > klucz) {
		k->nast  = *l;
		*l       = k;
		return; 
	}


	lista obecny = *l;
	
	while (obecny != NULL && obecny->nast != NULL) {


			if (obecny->nast->klucz < klucz) {
				obecny = obecny->nast;
		} else break;
	};

		k->nast  = obecny->nast;
		
		obecny->nast = k;
		return; 
};


