

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

//lista* odwroc_r( lista* l, lista* prev, lista* next);
lista odwroc_r( lista l, lista prev, lista next);

void odwroc(lista *l);

void WyswietlOdTylu(lista l);

unsigned short odszukaj(lista *l, int k);
lista* przesun(lista *l, int k, int side=1);

void WyswietlListe( lista _lista);

void DL(lista *l, int k);
void DNPL(lista *l, int i);

void Wczytaj(lista *l);
void Zapisz(lista *l);

void DNKL(lista *l, int i);


void UEL_k( lista *l, int k, int ilosc_razy = 0);

void posortuj(lista *l, lista *l2);


void ZL (lista *l);

#endif // LISTA_H
