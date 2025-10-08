

#ifndef LISTA_H
#define LISTA_H

#define F_DEBUG

struct el { 
	 int klucz ;
	 struct el *nast;
 };
 typedef struct el elListy ;
 typedef elListy  *lista;

void UPEL(lista *l);
void UOEL(lista *l);


void DNPL(lista *l, int i);

void Wczytaj(lista *l);
void Zapisz(lista *l);


void posortuj(lista *l, lista *l2);


void ZL (lista *l);

#endif // LISTA_H
