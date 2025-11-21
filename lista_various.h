
#ifndef LISTA_VA
#define LISTA_VA

//TODO: czy lista cykliczna zawiera we wlasnym eL wskaznik na glowe i na koniec?

typedef struct elListy {
    int klucz;
    struct elListy* nast;
#ifdef dwukierunkowa
    struct elListy* pop;
#endif
} elListy;

typedef elListy *lista;
// mozna dac wskaznik na poczatek, koniec jesli czesto wykonujemy dzialania aby nie przechodzic
// przez cala liste.

#ifdef wart
// Wtedy uzywamy wartownika w naszej liście
#endif

void ZL(lista *l);

int CzyIstnieje(lista l1, lista l2, int arg);
lista* porownaj(lista l1, lista l2);
void Wczytaj(lista* l, const char* filename);
void Zapisz(lista* l, const char* filename);
void odwroc(lista *l);
lista odwroc_r(lista l);
int odszukaj(lista *l, int k);
void WyswietlOdTylu(lista l); 
void WyswietlListe( lista _lista);
void Wyswietl_Pierwszy(lista *l);

void Wyswietl_Ostatni(lista *l); 
void dodaj_we_wskazane_miejsce(int wskazany, lista* p, int wstawiany, int strona);


void DNKL(lista *l, int i);
lista DNPL(lista* l, int i); 

void UEL_k( lista *l, int k, int ilosc_razy);

void UELR_k( lista *l, int k, int ilosc_razy);

void UPEL(lista *l);
void zostaw_unikalne(lista* l1, lista l2);

void UOEL(lista *l);

void U_wsk(lista *l, int k);

#endif
