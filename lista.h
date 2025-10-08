

#ifndef LISTA_H
#define LISTA_H

#define F_DEBUG

struct el { 
	 int klucz ;
	 struct el *nast;
 };
 typedef struct el elListy ;
 typedef elListy  *lista;

void DL_sort(lista *l, int klucz);
void DNPL(lista *l, int i);
void ZL (lista *l);

#endif // LISTA_H
