

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


lista odwroc_r( lista l, lista prev, lista next);

void odwroc(lista *l);

void WyswietlOdTylu(lista l);

int odszukaj(lista *l, int k);
lista* przesun(lista *l, int k, int side=1);

void WyswietlListe( lista _lista);

void DL(lista *l, int szukany, int nowy, int side);
void DL_sort(lista *l, int klucz);
void DNPL(lista *l, int i);

void Wczytaj(lista *l);
void Zapisz(lista *l);

void DNKL(lista *l, int i);


void UEL_k( lista *l, int k, int ilosc_razy = 0);
void UELR_k( lista *l, int k, int ilosc_razy);

void posortuj(lista *l, lista *l2);

void Wyswietl_Pierwszy(lista *l);
void Wyswietl_Ostatni(lista *l);

void ZL (lista *l);

#endif // LISTA_H
