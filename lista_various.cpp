#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
// Ten plik definiuje różne funkcje, które mogą zostać użyte w obu typach list: posortowanych i nieposort.
// odpowiedni nagłówek musi zostać wczytany wcześniej przez inny plik .cpp


// Funkcja sprawdza, czy element istnieje w obu listach
int CzyIstnieje(lista l1, lista l2, int arg) {
    int w1 = 0, w2 = 0;

    for (lista i = l1; i != NULL; i = i->nast) {
        if (i->klucz == arg) {
            w1 = 1;
            break;
        }
    }

    for (lista i = l2; i != NULL; i = i->nast) {
        if (i->klucz == arg) {
            w2 = 1;
            break;
        }
    }

    if (w1 == 1 && w2 == 1) return 1;
    return 0;
}

// Funkcja porównuje dwie listy
void* porownaj(lista l1, lista l2) {
    lista w1 = NULL, w2 = NULL;

    for (lista i = l1; i != NULL; i = i->nast) {
        if (!CzyIstnieje(l1, l2, i->klucz)) {
            DNKL(&w1, i->klucz);   // zmiana: używamy DNKL do doklejania na koniec
        }
    }

    for (lista i = l2; i != NULL; i = i->nast) {
        if (!CzyIstnieje(l1, l2, i->klucz)) {
            DNKL(&w2, i->klucz);   // zmiana: używamy DNKL do doklejania na koniec
        }
    }

    printf("\nLista w1 (unikatowe w l1): ");
    WyswietlListe(w1);
    printf("\nLista w2 (unikatowe w l2): ");
    WyswietlListe(w2);

    // Wskaźnik na tablicę dwóch list
    lista* wynik = (lista*)malloc(2 * sizeof(lista));
    wynik[0] = w1;
    wynik[1] = w2;

    return wynik;
}

// Funkcja odczytuje listę z pliku
void Wczytaj(lista* l) {
    ZL(l);
    FILE* file = fopen("lista.txt", "r");
    if (file == NULL) {
        printf("Nie można otworzyc pliku lista.txt\n");
        return;
    }

    int value;
    while (fscanf(file, "%d", &value) == 1) {
        DNKL(l, value);   // zmiana: DNKL zamiast DL
    }

    fclose(file);
}

// Funkcja zapisuje listę do pliku
void Zapisz(lista* l) {
    FILE* file = fopen("lista.txt", "w");
    if (file == NULL) {
        printf("Nie można otworzyc pliku lista.txt do zapisu\n");
        return;
    }

    lista i = *l;
    while (i) {
        fprintf(file, "%d\n", i->klucz);
        i = i->nast;
    }

    fclose(file);
}



// Funkcja: iteracyjne odwracanie listy
void odwroc(lista *l) {

    lista prev = NULL;
    lista cur = *l;
    lista next = NULL;

    while(cur){
        next=cur->nast;
        cur -> nast = prev;
        prev = cur;
        cur = next;
    }
    *l=prev;
    return;

}


lista odwroc_r(lista l, lista prev, lista next) {
    if (l) {
        next = l->nast;
        l->nast = prev;
        return odwroc_r(next, l, NULL);
    } else {
        return prev;
    }
}


 /* 
 Funkcja: Przesun wskaznik na liste na lub za wskazany element
 1 - Na. Domyslna opcja.
    kiedy jest "na" a nie "przed", prosciej zaimplementowac dodawanie el. przed lub za wskazanym

 */
lista* przesun(lista *l, int k, int side) {

    if(!(*l)) return l;
    lista *ret = l;


    while ((*ret) && (*ret)->nast && (*ret)->klucz != k) {
        ret = &(*ret)->nast;
    }


    // Sprawdzamy, czy znaleziono element z kluczem k
    if ((*ret) && (*ret)->klucz == k) {
        if (side != 1) {
            if ((*ret)->nast) ret = &(*ret)->nast;
        }
    } else {
        printf("\n Nie znaleziono elementu o kluczu %d\n", k);
        return l;
    };


  return ret;

};

/*
Funkcja: Odszukaj
Wynik: numer elementu z kluczem równym k.
*/

int odszukaj(lista *l, int k) {
  int ret = 1;
  lista _l = *l;
  while(_l) {
    if(_l->klucz == k) return ret;
    _l = _l->nast;
    ret++;
  };
  return -1;

};

// Funkcja: wyświetl listę w odwrotnej kolejności
void WyswietlOdTylu(lista l) {
    if (l == NULL) {
        return;  
    }

    WyswietlOdTylu(l->nast);  


    printf("%d-", l->klucz);
};


void WyswietlListe( lista _lista)  { 

     lista l = _lista;
     while (l){ 
         printf ("%d-", l->klucz);
         l = l->nast;
         } ;
 printf ("|\n");
 };


void Wyswietl_Pierwszy(lista *l)
 { 
    if (l==0) return;
    printf("\n %d", (*l)->klucz);
 };


void Wyswietl_Ostatni(lista *l)  { 
    if(l==0) return;

    while ( (*l)->nast ) l = &(*l)->nast;
    printf("\n %d", (*l)->klucz);
 };

/* 
Funkcja: Dodaj Na Koniec Listy

*/

void DNKL(lista *l, int i)  { 
    if(l==0) return;
     lista p = ( lista )malloc(sizeof( elListy ));
    p->klucz = i;
     p->nast = 0;    
     while ((* l )) l = &(*l)->nast;
 *l = p;
 };

/*
Funkcja: Dodaj do Listy
Dodaje element za wskazany element
///Powinno być kompatobilne zarówno z posortowaną jak nie
1 - za element
0 - przed
*/
void DL(lista *l, int szukany, int nowy, int side) {

    if(*l==0) return;

    lista p = *l;
    while(p && p->nast && p->nast->klucz != szukany) p = p->nast;

 // Nie znaleziono
    if(!(p->nast) || p->nast->klucz != szukany) return; 

    lista k = (lista) malloc(sizeof(elListy));
    k->klucz = nowy;

    if (side == 1) {
        p = p->nast;
        k->nast = p->nast;
        p->nast = k;
    } else if (side == 0) {
        k->nast = p->nast;
        p->nast = k;
    };
};


/*
Funkcja: Usun Element Listy - k

Usuwa z kolejki element/-y z kluczem równym k.

Opcjonalny argument: Liczba wystąpień k, które mają zostać usunięte.
                     -1 oznacza każde wystąpienie


Wersja iteracyjna

*/

void UEL_k( lista *l, int k, int ilosc_razy) {

  if(!(*l)) {
   printf("\n Lista pusta"); 
   return;
  };


  lista obecny = *l;
  lista poprzedni = NULL;

    while(obecny && ilosc_razy != 0) {

        if(obecny->klucz == k) {
            if(ilosc_razy != -1) ilosc_razy--;

            if (poprzedni)
                    poprzedni->nast = obecny->nast;
            else 
                   *l = obecny->nast;


            lista rem = obecny;
            obecny = obecny->nast;
            free(rem);
            continue;
        }

        poprzedni = obecny;
        obecny = obecny->nast;
    }}


/*
Funkcja: Usun Element Listy - k

Usuwa z kolejki element/-y z kluczem równym k.

Opcjonalny argument: Liczba wystąpień k, które mają zostać usunięte.
                     -1 oznacza każde wystąpienie


Wersja rekurencyjna
*/

void UELR_k( lista *l, int k, int ilosc_razy) {

  if(!(*l)) {
   return;
  };  

if (ilosc_razy == 0) return;

    if((*l)->klucz == k) {
        UPEL(l);
        if (ilosc_razy != -1) ilosc_razy--;
        UELR_k(l, k, ilosc_razy);
    }

    else 
    {
        l = &(*l)->nast;
        UELR_k(l, k, ilosc_razy);
    };


};

 /* 
 Funkcja: Usun Pierwszy Element Listy

 Usuwa pierwszy element wskazany przez wskaznik l.


 */

void UPEL(lista *l) {

    if(*l) {
        lista p;         // lista to wskaznik, a nie struktura
        p = *l;
        *l = (*l)->nast;
        free(p);
    };

};


 /* 
 Funkcja: Usun Ostatni Element Listy

 */

void UOEL(lista *l) {

    if((*l)) {
        while ((*l) && (*l)->nast) l = &(*l)->nast;
        free(*l);
        *l = 0;
        }


};
 /*
  Funkcja: Usun wskazany element listy

  Usuwa k-ty element

*/

void U_wsk(lista *l, int k) {
    if(l==0) return;
    int i = 1;
    lista *p = l;
    while(i != k && (*p)) {
        p=&(*p)->nast;
        i++;
    };
    UPEL(p);

};

