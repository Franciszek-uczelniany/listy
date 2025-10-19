#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

/* definicja elementu listy i aliasu typu */
typedef struct elListy {
    int klucz;
    struct elListy *nast;
} elListy;

typedef elListy *lista;

/* podstawowe operacje */
void ZL(lista *l);
void DNPL(lista *l, int i);
void DNKL(lista *l, int i);
void DL(lista *l, int szukany, int nowy, int side);

void UPEL(lista *l);
void UOEL(lista *l);
void U_wsk(lista *l, int k);
void UEL_k(lista *l, int k, int ilosc_razy);
void UELR_k(lista *l, int k, int ilosc_razy);

int odszukaj(lista *l, int k);
lista* przesun(lista *l, int k, int side);

void WyswietlListe(lista _lista);
void WyswietlOdTylu(lista l);
void Wyswietl_Pierwszy(lista *l);
void Wyswietl_Ostatni(lista *l);

void odwroc(lista *l);
lista odwroc_r(lista l, lista prev, lista next);

/* dodatkowe operacje plikowe/porównawcze */
void Wczytaj(lista *l);
void Zapisz(lista *l);

int CzyIstnieje(lista l1, lista l2, int arg);
void* porownaj(lista l1, lista l2);

#endif /* LISTA_H */

