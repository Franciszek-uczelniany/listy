
#ifndef LISTA_VA
#define LISTA_VA


struct el { 
	 int klucz ;
	 struct el *nast;
 };
 typedef struct el elListy ;
 typedef elListy  *lista;

#ifdef wart
// Wtedy uzywamy wartownika w naszej liście
#endif

void ZL(lista *l);

int CzyIstnieje(lista l1, lista l2, int arg);
void* porownaj(lista l1, lista l2);
void Wczytaj(lista* l);

void Zapisz(lista* l);
void odwroc(lista *l);

lista odwroc_r(lista l, lista prev, lista next);
lista* przesun(lista *l, int k, int side);
int odszukaj(lista *l, int k);
void WyswietlOdTylu(lista l); 
void WyswietlListe( lista _lista);
void Wyswietl_Pierwszy(lista *l);

void Wyswietl_Ostatni(lista *l); 

void DNKL(lista *l, int i); 
void DL(lista *l, int szukany, int nowy, int side);

void UEL_k( lista *l, int k, int ilosc_razy);

void UELR_k( lista *l, int k, int ilosc_razy);

void UPEL(lista *l);

void UOEL(lista *l);

void U_wsk(lista *l, int k);

#endif
