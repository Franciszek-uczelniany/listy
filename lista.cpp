#include <assert.h> 
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "lista_various.h"


//Funkcja: Dodaj do posortowanej Listy
void DL_sort(lista *l, int klucz) {
	assert(l != NULL);

	lista nowy  = (lista) malloc(sizeof(elListy));
	assert(nowy != NULL);
	nowy->klucz = klucz;

	// Dodajemy pierwszy element listy
	if (*l == 0) {
		*l = nowy;
		nowy->nast == NULL;
		return;
	}

	// Jeœli element który dodajemy jest mniejszy od nastêpnego elementu, dodajemy go przed nim
	if( klucz < (*l)->klucz) {
		nowy->nast  = *l;
		*l       = nowy;
		return; 
	}
	lista obecny = *l;
	while (obecny != NULL && obecny->nast != NULL) {
			if (obecny->klucz < klucz) {
				obecny = obecny->nast;
		} else break;
	}; // koñczymy pêtlê kiedy element który chcemy dodaæ jest wiêkszy równy "obecny" el.


		nowy->nast  = obecny->nast;
		obecny->nast = nowy;
		return; 
};

