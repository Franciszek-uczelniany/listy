
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista_various.h"

// Dodaj Na Koniec Listy
void DNKL(lista *l, int i) {
    if (l == NULL) return;

    lista p = (lista)malloc(sizeof(elListy));
    if (!p) return;
    p->klucz = i;
    p->nast = NULL;

#ifdef wart
    // Dla list z wartownikiem (wartownikiem ma być element z kluczem INT_MAX)
    while (*l && (*l)->klucz != INT_MAX) {
        l = &(*l)->nast;
    }
#else
    // Dla zwykłej listy idziemy do końca
    while (*l) {
        l = &(*l)->nast;
    }
#endif

    *l = p;
}

// Dodaj Na Poczatek Listy
void DNPL(lista* l, int i) {
    if (l == NULL) return;

    lista p = (lista)malloc(sizeof(elListy));
    if (!p) return;
    p->klucz = i;
    p->nast = *l;
    *l = p;
}

// Usuń Ostatni Element Listy
void UOEL(lista *l) {
    if (l == NULL || *l == NULL) return;

#ifdef cykliczna
    // Dla list cyklicznych: jeśli tylko jeden element -> usuń i ustaw na NULL
    if ((*l)->nast == *l) {
        free(*l);
        *l = NULL;
        return;
    }
    // znajdź przedostatni element
    lista cur = *l;
    while (cur->nast && cur->nast->nast && cur->nast != *l) {
        cur = cur->nast;
    }
    // cur->nast to ostatni element
    free(cur->nast);
    cur->nast = *l;
    return;
#endif

    // Dla zwykłej listy
    if ((*l)->nast == NULL) {
        free(*l);
        *l = NULL;
        return;
    }
    lista cur = *l;
    while (cur->nast && cur->nast->nast) {
        cur = cur->nast;
    }
    // cur->nast wskazuje na ostatni element
    free(cur->nast);
    cur->nast = NULL;
}

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
void Wczytaj(lista* l) {
    if (l == NULL) return;
    ZL(l);
    FILE* file = fopen("lista.txt", "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku lista.txt\n");
        return;
    }

    int value;
    while (fscanf(file, "%d", &value) == 1) {
        DNKL(l, value);
    }

    fclose(file);
}

// Zapisz listę do pliku
void Zapisz(lista* l) {
    if (l == NULL) return;
    FILE* file = fopen("lista.txt", "w");
    if (file == NULL) {
        printf("Nie można otworzyć pliku lista.txt do zapisu\n");
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
 Przesuń wskaźnik na element o kluczu k (zwraca wskaźnik do pola wskazującego na ten element).
 side == 1 -> "na" (czyli na sam element)
 side != 1 -> "za" (jeśli istnieje nast)
*/
lista* przesun(lista *l, int k, int side) {
    if (l == NULL) return NULL;
    lista *ret = l;

    // Szukamy elementu o kluczu k
    while (*ret && (*ret)->klucz != k) {
        ret = &(*ret)->nast;
    }

    if (*ret == NULL) {
        printf("\nNie znaleziono elementu o kluczu %d\n", k);
        return l; // zwracamy oryginalny wskaźnik (bez zmiany)
    }

    if (side != 1) {
        // chcemy "za" — jeśli istnieje nast, ustawiamy wskaźnik na pole nast
        if ((*ret)->nast) return &(*ret)->nast;
    }
    return ret;
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

// Wyświetl listę od tylu (rekurencyjnie)
#ifndef wart
void WyswietlOdTylu(lista l) {
    if (l == NULL) return;
    WyswietlOdTylu(l->nast);
    printf("%d-", l->klucz);
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

/*
 DL: dodaj element 'nowy' przed lub za elementem o kluczu 'szukany'
 side == 1 -> za elementem
 side == 0 -> przed elementem
*/
void DL(lista *l, int szukany, int nowy, int side) {
    if (l == NULL) return;

    // Dodawanie na początek jeśli szukany jest pierwszy i side==0
    if (*l && (*l)->klucz == szukany && side == 0) {
        DNPL(l, nowy);
        return;
    }

    // Szukamy elementu z kluczem szukany
    lista prev = NULL;
    lista cur = *l;
    while (cur && cur->klucz != szukany) {
        prev = cur;
        cur = cur->nast;
    }

    if (cur == NULL) {
        // Nie znaleziono elementu docelowego
        return;
    }

    lista k = (lista)malloc(sizeof(elListy));
    if (!k) return;
    k->klucz = nowy;

    if (side == 1) {
        // wstaw za cur
        k->nast = cur->nast;
        cur->nast = k;
    } else {
        // wstaw przed cur (tu prev może być NULL gdy cur to pierwszy element, ale to obsłużyliśmy wyżej)
        k->nast = cur;
        if (prev) prev->nast = k;
        else *l = k;
    }
}

/*
 Usuń wszystkie/podaną liczbę wystąpień elementu o kluczu k (iteracyjnie)
 ilosc_razy == -1 -> usuń wszystkie
*/
void UEL_k(lista *l, int k, int ilosc_razy) {
    if (l == NULL || *l == NULL) {
        printf("\nLista pusta\n");
        return;
    }

    lista cur = *l;
    lista prev = NULL;

    while (cur && ilosc_razy != 0) {
        if (cur->klucz == k) {
            if (ilosc_razy != -1) ilosc_razy--;
            lista rem = cur;
            if (prev) prev->nast = cur->nast;
            else *l = cur->nast;
            cur = cur->nast;
            free(rem);
            continue;
        }
        prev = cur;
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

// Usuń Pierwszy Element Listy
void UPEL(lista *l) {
    if (l == NULL || *l == NULL) return;
    lista p = *l;
    *l = (*l)->nast;
    free(p);
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
