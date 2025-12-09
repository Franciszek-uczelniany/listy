#include <assert.h> 
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "lista_various.h"


//Funkcja: Dodaj do posortowanej Listy
/*
todo: czy to dla dwukierunkowej czy nie, goto end zastosowac?
todo: brak dla wartownika.
*/
void DL_sort(lista* l, int klucz) {
	if (l == NULL) return;

	lista nowy = (lista)malloc(sizeof(elListy));
	assert(nowy != NULL);
	nowy->klucz = klucz;

	// Dodajemy pierwszy element listy
	if (*l == 0) {
		*l = nowy;
		nowy->nast = NULL;
#ifdef dwukierunkowa
		nowy->pop = NULL
#endif
		return;
	}

	// Jeœli element który dodajemy jest mniejszy od nastêpnego elementu, dodajemy go przed nim
	if (klucz < (*l)->klucz) {
		nowy->nast = *l;
		*l = nowy;
#ifdef dwukierunkowa
		nowy->pop = NULL
#endif
		return;
	}
	lista pop, nast;
	pop = (*l);
	nast = (*l)->nast;

	// Nastepnie ponizej my tylko szukany wskaznika na poprzedni element, ale nie 
	// musimy tego robic bo mamy funkcje znajdz.

#ifdef wartownik
	for (nast = (*l)->nast; nast->klucz < klucz; nast = nast->nast) {
		pop = nast;
}
#else
	for (nast = (*l)->nast; nast && nast->klucz < klucz; nast = nast->nast) {
		pop = nast;
	}
#endif

	pop->nast = nowy;
	nowy->nast = nast;

	return;
};



void doklej(lista* q, lista pNast) {
	if (pNast == NULL || *q == NULL) return;
	lista t = *q;
	lista schowek;
	while (t->klucz < pNast->klucz)
		t = t->nast;
	schowek = t->nast;  // Zapisujemy do schowka nastêpny element listy q, ten którego juz nie
	// doklejamy do listy p
	t->nast = pNast;
	(*q) = schowek;
}

// Funkcja z dwóch list posortowanych tworzy jedn¹ posortowan¹ listê
// lista q jest doklejana do listy p
// to do: przetestowac jak zachowa siê funkcja po odwroceniu argumentow...
void merge(lista* p, lista* q) {
	if (*p == NULL || *q == NULL) return;
	lista t = *p;
	lista schowek;

	// Je¿eli q->klucz jest mniejsze od g³owy listy p, doklej go na pocz¹tek

	if ((*q)->klucz < (*p)->klucz) {
		doklej(q, *p);
		*p = *q;
	}

	while (*q && t->nast && t->nast->klucz < (*q)->klucz) {
		t = t->nast;
	}
	schowek = t->nast;
	t->nast = (*q);
	doklej(q, schowek);
	merge(p, q);
}