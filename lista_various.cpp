
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista_various.h"

// Dodaj Na Koniec Listy
#ifndef cykliczna
void DNKL(lista* l, int i) {
    if (l == NULL) return;

    lista p = (lista)malloc(sizeof(elListy));
    if (!p) return;
    p->klucz = i;
    p->nast = NULL;


    if (*l == NULL) {
        *l = p;
#ifdef dwukierunkowa
        p->pop = NULL;
#endif
        return;
    }

    lista cur = *l;
    while (cur->nast) cur = cur->nast;      // Idziemy na koniec listy.
    cur->nast = p;

#ifdef dwukierunkowa
    p->pop = cur;
#endif
}

#else
// Poniższy kod jest dla cyklicznej listy, dwukierunkowej lub nie
void DNKL(lista* l, int i) {
    if (l == NULL) return;
    lista head = *l;

    lista p = (lista)malloc(sizeof(elListy));
    if (!p) return;
    p->klucz = i;
    p->nast = head;

    // Lista jest pusta. Dodajemy jeden element do listy cyklicznej.
    if (*l == NULL) {
        *l = p;
        p->nast = p;
#ifdef dwukierunkowa
        p->pop = p;
#endif
        return;
    }

    lista cur = *l;
    while (cur->nast!=head) cur = cur->nast;
    cur->nast = p;

#ifdef dwukierunkowa   
    p->pop = cur;
    // Warto w tym miejscu przypomnieć, że p->nast = head zrobiliśmy zaraz po alokacji pamięci
#endif
}
#endif

// Dodaj Na Poczatek Listy
// zwracamy wskaźnik na nowo utworzony element
#ifndef dwukierunkowa
lista DNPL(lista* l, int i) {
    if (l == NULL) return NULL;

    lista p = (lista)malloc(sizeof(elListy));
    if (!p) return NULL;
    p->klucz = i;


    if (*l == NULL)  *l = p;
    else p->nast = *l;

#ifdef cykliczna
    lista tail = p;
    if (*l != p) for (tail = (*l); tail->nast != (*l); tail = tail->nast);
    tail->nast = p;
#endif

    *l = p;
    return p;
}
#endif

#ifdef dwukierunkowa
lista DNPL(lista* l, int i) {
    if (l == NULL) return NULL;

    lista p = (lista)malloc(sizeof(elListy));
    if (!p) return NULL;
    p->klucz = i;


    if (*l == NULL)  *l = p;
    else p->nast = *l;
#ifndef cykliczna
    p->pop = NULL;
    if (*l && *l != p) (*l)->pop = p;
#else
    lista tail = p;
    if (*l != p) for (tail = (*l); tail->nast != (*l); tail = tail->nast);
    p->pop = tail;
    tail->nast = p;
#endif
    * l = p;
    return p;
}
#endif

// Usuń Ostatni Element Listy 
#ifndef cykliczna
// dla niecyklicznej
void UOEL(lista* l) {
    if (l == NULL || *l == NULL) return;

    lista obecny = *l;
    lista poprzedni = *l;
    while ((obecny->nast)) {
        poprzedni = obecny;
        obecny = obecny->nast;
    }
    if (obecny == poprzedni) {
        *l = NULL; // lista składa się wyłącznie z jednego elementu, który zostanie właśnie usunięty
    }
    poprzedni->nast = NULL;
    free(obecny);

    return;
}
#else
//  dla cyklicznej
void UOEL(lista* l) {
    if (l == NULL || *l == NULL) return;

    lista glowa = *l;
    lista obecny = *l;
    lista poprzedni = *l;
    while ((obecny->nast)) {
        poprzedni = obecny;
        obecny = obecny->nast;
    }
    if (obecny == poprzedni) {
        *l = NULL; // lista składa się wyłącznie z jednego elementu, który zostanie właśnie usunięty
    }
    poprzedni->nast = glowa;
#ifdef dwukierunkowa
    glowa->pop = poprzedni;
#endif
    free(obecny);

    return;
}
#endif

// Zwolnij listę (usuń wszystkie elementy)
void ZL(lista *l) {
    if (l == NULL) return;
    while (*l) {
        UOEL(l);
    }
}

// Sprawdza, czy element o kluczu 'arg' występuje w liście 'lst'
static bool istnieje_w(lista lst, int arg) {
    for (lista i = lst; i != NULL; i = i->nast) {
        if (i->klucz == arg) return true;
    }
    return false;
}

// Funkcja sprawdza, czy element istnieje w obu listach (zwraca 1 jeśli tak)
int CzyIstnieje(lista l1, lista l2, int arg) {
    if (istnieje_w(l1, arg) && istnieje_w(l2, arg)) return 1;
    return 0;
}

// Porównaj dwie listy: wynik to tablica dwóch list (unika­towe elementy w l1 i w l2)
lista* porownaj(lista l1, lista l2) {
    lista w1 = NULL;
    lista w2 = NULL;

    // elementy unikatowe w l1 (występują w l1, ale nie w l2)
    for (lista i = l1; i != NULL; i = i->nast) {
        if (!istnieje_w(l2, i->klucz)) {
            DNKL(&w1, i->klucz);
        }
    }

    // elementy unikatowe w l2 (występują w l2, ale nie w l1)
    for (lista i = l2; i != NULL; i = i->nast) {
        if (!istnieje_w(l1, i->klucz)) {
            DNKL(&w2, i->klucz);
        }
    }

    printf("\nLista w1 (unikatowe w l1): ");
    WyswietlListe(w1);
    printf("\nLista w2 (unikatowe w l2): ");
    WyswietlListe(w2);

    // Zwracamy tablicę dwóch wskaźników typu lista
    lista* wynik = (lista*)malloc(2 * sizeof(lista));
    if (!wynik) {
        // w razie błędu zwracamy NULL (użytkownik powinien to obsłużyć)
        return NULL;
    }
    wynik[0] = w1;
    wynik[1] = w2;
    return wynik;
}

// Wczytaj listę z pliku (zastępuje dotychczasową)
void Wczytaj(lista* l, const char* filename) {
    if (l == NULL) return;
    ZL(l);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku %s\n", filename);
        return;
    }

    int value;
    while (fscanf(file, "%d", &value) == 1) {
        DNKL(l, value);
    }

    fclose(file);
}

// Zapisz listę do pliku
void Zapisz(lista* l, const char* filename) {
    if (l == NULL) return;
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Nie można otworzyć pliku %s do zapisu\n", filename);
        return;
    }

    for (lista i = *l; i != NULL; i = i->nast) {
        fprintf(file, "%d\n", i->klucz);
    }

    fclose(file);
}

// Iteracyjne odwrócenie listy
void odwroc(lista *l) {
    if (l == NULL || *l == NULL) return;

    lista prev = NULL;
    lista cur = *l;
    lista next = NULL;

    while (cur) {
        next = cur->nast;
        cur->nast = prev;
        prev = cur;
        cur = next;
    }
    *l = prev;
}

// Rekurencyjne odwrócenie listy (zwraca nową głowę)
lista odwroc_r(lista l) {
    if (l == NULL || l->nast == NULL) return l;
    lista newHead = odwroc_r(l->nast);
    l->nast->nast = l;
    l->nast = NULL;
    return newHead;
}

/*
 Odszukaj: zwraca numer pozycji elementu o kluczu k (1-based), -1 jeśli nie znaleziono.
*/
int odszukaj(lista *l, int k) {
    if (l == NULL || *l == NULL) return -1;
    int pos = 1;
    for (lista cur = *l; cur != NULL; cur = cur->nast, pos++) {
        if (cur->klucz == k) return pos;
    }
    return -1;
}


// Znajdź() działa tak jak odszukaj(), ale zwraca wskaźnik
lista znajdz(int klucz, lista wel) {
    if (!wel) return NULL;

    lista ret = wel;
    while (ret && ret->klucz != klucz) {
        ret = ret->nast;
    };
    if (ret) return ret;

    printf("\n Nie znaleziono szukanego klucza.");
    return NULL;
}

// Wyświetl listę od tylu (rekurencyjnie)
#ifndef wart
#ifndef dwukierunkowa
void WyswietlOdTylu(lista l) {
    if (l == NULL) return;
    WyswietlOdTylu(l->nast);
    printf("%d-", l->klucz);
}
#endif
#endif

#ifdef dwukierunkowa
void WyswietlOdTylu(lista l) {
    if (!l) return;
    while (l->nast) l = l->nast; // idź na koniec
    while (l) {
        printf("%d-", l->klucz);
        l = l->pop;
    }
    printf("|\n");
}
#endif

// Wyświetl listę (różne tryby: z wartownikiem, cykliczna, zwykła)
void WyswietlListe(lista _lista) {
    lista l = _lista;
#ifdef wart
    while (l && l->klucz != INT_MAX) {
        printf("%d-", l->klucz);
        l = l->nast;
    }
#elif defined(cykliczna)
    if (l == NULL) {
        printf("|\n");
        return;
    }
    lista glowa = l;
    do {
        printf("%d-", l->klucz);
        l = l->nast;
    } while (l != glowa && l != NULL);
#else
    while (l) {
        printf("%d-", l->klucz);
        l = l->nast;
    }
#endif
    printf("|\n");
}

// Wyświetl pierwszy element (z wskaźnika na listę)
void Wyswietl_Pierwszy(lista *l) {
    if (l == NULL || *l == NULL) return;
    printf("\n%d", (*l)->klucz);
}

// Wyświetl ostatni element
void Wyswietl_Ostatni(lista *l) {
    if (l == NULL || *l == NULL) return;
#ifdef wart
    lista cur = *l;
    while (cur->nast && cur->nast->klucz != INT_MAX) cur = cur->nast;
    printf("\n%d", cur->klucz);
#else
    lista cur = *l;
    while (cur->nast) cur = cur->nast;
    printf("\n%d", cur->klucz);
#endif
}


// Strona: -1 czyli przed wskazanym elementem,
// 0 czyli zastąp dany element
// 1 to za danym elementem
#ifdef dwukierunkowa
void dodaj_we_wskazane_miejsce(int wskazany, lista* p, int wstawiany, int strona) {
    if (!*p) return;
    lista schowek, szukany, wstawiany_el;

    switch (strona) {

    case -1:
        szukany = znajdz(wskazany, *p);
        if (!szukany) return;
        schowek = szukany->pop;							// zapisujemy wartość wskaznika przed wskazanym elemente, poniewaz do funkcji dodaj_na_poczatek przekazujemy wskaznik na wskaznik, wiec ulegnie zmianie wsk 'szukany'
        // zapisujemy szukany->pop poniewaz nas interesuje ściśle mówiąc element przed tym szukanym elementem.
        wstawiany_el = DNPL(&szukany, wstawiany);
        if (schowek) {
            schowek->nast = wstawiany_el;
            wstawiany_el->pop = schowek;
        }
        else *p = wstawiany_el;							//zrobilismy lokalną kopię wskaźnika na listę do lokalnej zmiennej 'szukany', ale jeśli szukany jest pierwszym elementem to musimy zaaktualizować głowę listy														
        break;

    case 0:
        szukany = znajdz(wskazany, *p);
        if (!szukany) return;
        szukany->klucz = wstawiany;
        break;

    case 1:
        szukany = znajdz(wskazany, *p);
        if (!szukany) return;
        wstawiany_el = DNPL(&szukany->nast, wstawiany);
        wstawiany_el->pop = szukany;
        break;

    default:
        printf("\n Niepoprawny argument");
        break;
    }
}
#endif

/*
 Usuń wszystkie/podaną liczbę wystąpień elementu o kluczu k (iteracyjnie)
 ilosc_razy == -1 -> usuń wszystkie
*/void UEL_k(lista* l, int k, int ilosc_razy) {
    if (l == NULL || *l == NULL) return;

    lista cur = *l;

    while (cur && ilosc_razy != 0) {
        if (cur->klucz == k) {
            if (ilosc_razy != -1) ilosc_razy--;
            lista rem = cur;
#ifdef dwukierunkowa
            if (cur->pop) cur->pop->nast = cur->nast;
            else *l = cur->nast;
            if (cur->nast) cur->nast->pop = cur->pop;
            cur = cur->nast;
            free(rem);
#else
            if (cur == *l) {
                *l = cur->nast;
                free(rem);
                cur = *l;
            }
            else {
                lista prev = *l;
                while (prev->nast != rem) prev = prev->nast;
                prev->nast = cur->nast;
                cur = cur->nast;
                free(rem);
            }
#endif
            continue;
        }
        cur = cur->nast;
    }
}

/*
 Usuń elementy o kluczu k (rekurencyjnie)
*/
void UELR_k(lista *l, int k, int ilosc_razy) {
    if (l == NULL || *l == NULL) return;
    if (ilosc_razy == 0) return;

    if ((*l)->klucz == k) {
        lista rem = *l;
        *l = (*l)->nast;
        free(rem);
        if (ilosc_razy != -1) ilosc_razy--;
        UELR_k(l, k, ilosc_razy);
    } else {
        UELR_k(&(*l)->nast, k, ilosc_razy);
    }
}

void UPEL(lista* l) {
    if (l == NULL || *l == NULL) return;
    lista head = *l;
    *l = (*l)->nast;
#ifdef dwukierunkowa
#ifndef cykliczna
    if (*l) (*l)->pop = NULL;
#else // dla cyklicznej:
    if (*l != head) {
        lista tail;
        for (tail = head; tail->nast != head; tail = tail->nast);
        (*l)->pop = tail;
}
#endif
#endif
    free(head);
}


// Usuń k-ty element listy (1-based)
void U_wsk(lista *l, int k) {
    if (l == NULL || k <= 0) return;
    int i = 1;
    lista *p = l;
    while (i != k && *p) {
        p = &(*p)->nast;
        i++;
    }
    if (*p) UPEL(p);
}
