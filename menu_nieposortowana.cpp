#include <stdio.h>
#include <stdlib.h>
#include "lista_various.h"
#define NR 2

/*
 * Funkcja: odwroc_el
 * ------------------
 * Próba odwrócenia listy przy użyciu tablicy wskaźników.
 */
void odwroc_el(lista* pp) {
    if (pp == NULL || *pp == NULL) return;

    lista l = *pp;
    lista tab[100];
    int i = 0;

    // Zapisujemy wskaźniki do elementów w tablicy
    while (l != NULL && i < 100) {
        tab[i++] = l;
        l = l->nast;
    }

    if (i == 0) return;  // lista pusta

    // Ostatni element staje się głową
    *pp = tab[i - 1];

    // Łączymy elementy w odwrotnej kolejności
    for (int j = i - 1; j > 0; j--) {
        tab[j]->nast = tab[j - 1];
    }

    // Pierwszy element starej listy (teraz ostatni) wskazuje na NULL
    tab[0]->nast = NULL;
}


int main(void) {
    int nr_listy = 0;
    lista l[NR] = { 0, 0 };
    int wybor = 0;
    int w2, w3;
    int ret;

    while (1) {
        printf(
            "\nWybierz operacje:\n"
            " 0  - wyjscie\n"
            " 1  - Dodaj na poczatek listy\n"
            " 2  - Dodaj na koniec listy\n"
            " 3  - Usun pierwszy element listy\n"
            " 4  - Usun ostatni element listy\n"
            " 5  - Odszukaj zadany element\n"
            " 6  - Dodaj nowy element przed lub za wskazanym\n"
            " 7  - Usun wskazany element / elementy (iteracyjnie)\n"
            " 71 - Usun wskazany element / elementy (rekurencyjnie)\n"
            " 8  - Wczytaj zawartosc listy z pliku\n"
            " 9  - Zapisz zawartosc listy do pliku\n"
            " 10 - Wyswietl zawartosc listy\n"
#ifndef cykliczna
            " 11 - Wyswietl od konca\n"
#endif
            " 12 - Odwroc iteracyjnie\n"
            " 13 - Odwroc rekurencyjnie\n"
#ifdef cykliczna
            " 20 - Zostaw w pierwszej liscie elementy niewyst. w drugiej (zad 12)\n"
#endif
            " 44 - Zmien zlapana liste \n"
            " Obecnie zlapana lista: %d \n", nr_listy);

        printf("\nwybor = ");
        if (scanf("%d", &wybor) != 1) {
            printf("Blad wejscia — zakonczono.\n");
            break;
        }

        switch (wybor) {
            case 0:
                printf("Zakonczono program.\n");
                exit(0);

            case 1:
                printf("\nklucz = ");
                scanf("%d", &w2);
                DNPL(&l[nr_listy], w2);
                break;

            case 2:
                printf("\nklucz = ");
                scanf("%d", &w2);
                DNKL(&l[nr_listy], w2);
                break;

            case 3:
                UPEL(&l[nr_listy]);
                break;

            case 4:
                UOEL(&l[nr_listy]);
                break;

            case 5:
                printf("\nklucz = ");
                scanf("%d", &w2);
                ret = odszukaj(&l[nr_listy], w2);
                if (ret > 0)
                    printf("\nZadany element jest %d w liscie.\n", ret);
                else
                    printf("\nNie znaleziono tego elementu.\n");
                break;

            case 6:
                printf("\nklucz elementu do odszukania = ");
                scanf("%d", &w2);
                printf("\nklucz do wpisania = ");
                scanf("%d", &w3);
                printf("\n0 - przed,  1 - za szukany element\n");
                int side;
                scanf("%d", &side);
             //   DL(&_l, w2, w3, side);
                break;

            case 7:
                printf("\nklucz = ");
                scanf("%d", &w2);
                printf("\nPodaj liczbe elementow do usuniecia (0 oznacza wszystkie): ");
                scanf("%d", &w3);
                if (w3 == 0) w3 = -1;
                UEL_k(&l[nr_listy], w2, w3);
                break;

            case 71:
                printf("\nklucz = ");
                scanf("%d", &w2);
                printf("\nPodaj liczbe elementow do usuniecia (0 oznacza wszystkie): ");
                scanf("%d", &w3);
                if (w3 == 0) w3 = -1;
                UELR_k(&l[nr_listy], w2, w3);
                break;

            case 8:
                Wczytaj(&l[nr_listy], nr_listy == 0 ? "lista.txt" : "lista2.txt");
                break;

            case 9:
                Zapisz(&l[nr_listy], nr_listy == 0 ? "lista.txt" : "lista2.txt");
                break;

            case 10:
                WyswietlListe(l[nr_listy]);
                break;
#ifndef cykliczna
            case 11:
                WyswietlOdTylu(l[nr_listy]);
                printf("|\n");
                break;
#endif
            case 12:
                odwroc_el(&l[nr_listy]);
                printf("\nLista po odwroceniu:\n");
                WyswietlListe(l[nr_listy]);
                break;

            case 13:
                l[nr_listy] = odwroc_r(l[nr_listy]);
                printf("\nLista po odwroceniu rekurencyjnym:\n");
                WyswietlListe(l[nr_listy]);
                break;

#ifdef cykliczna
            case 20:
                zostaw_unikalne(&l[0], l[1]);
                printf("\n Gotowe. l[0]: ");
                WyswietlListe(l[0]);
                break;
#endif
            case 44:
                nr_listy = ++nr_listy % NR;
                break;


            default:
                printf("Niepoprawny wybor.\n");
                break;
        }
    }

    return 0;
}
