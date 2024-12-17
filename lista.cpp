#include <stdio.h>
#include <stdlib.h>
#include "drzewo.h"


int max(drzewo d) {

    while (d->prawy) {
        d = d->prawy;
    }

    printf("\n Maksymalna wartosc wynosi %d", d->klucz);
    return d->klucz;
}

int min(drzewo d) {

    while (d->lewy) {
        d = d->lewy;
    }

    printf("\n Minimalna wartosc wynosi %d", d->klucz);
    return d->klucz;
}

void DrukujDrzewo0(drzewo d, int glebokosc) {
    if (d == NULL) return;
    DrukujDrzewo0(d->lewy, glebokosc + 1);
    for (int i = 0; i < glebokosc; i++)
        putchar(' ');
    printf("%d\n", d->klucz);
    DrukujDrzewo0(d->prawy, glebokosc + 1);
}

void DrukujDrzewo(drzewo d) {
    DrukujDrzewo0(d, 0);
    putchar(' ');
}

void DodajD(drzewo* d, int klucz) {
    if (*d == NULL) {
        *d = (drzewo)malloc(sizeof(wDrzewaB));
        if (*d == NULL) {
            perror("Nie udalo sie przydzielic pamieci");
            exit(1);
        }
        (*d)->klucz = klucz;
        (*d)->licznik = 1;
        (*d)->lewy = (*d)->prawy = NULL;
    }
    else if (klucz < (*d)->klucz) {
        DodajD(&((*d)->lewy), klucz);
    }
    else if (klucz > (*d)->klucz) {
        DodajD(&((*d)->prawy), klucz);
    }
    else {
        (*d)->licznik++;
    }
}

void UsunD(drzewo* d, int klucz) {
    if (*d == NULL) return;

    // drzewo binarne kluczow znakowym 
    // kluczem nie jest int tylko char*
    // to jest koniecznie do poprawy

    // na wykladzie jest



    DFS(Depth - First Search)

        zadanie 16:


    wystarczy przejsc przez drzewo zapisujac wszystko do macierzy sasiedztwa lub tablicy list
        a nastepnie porownac oba listy


        zapisac oba drzewa jako tablica list(i porownac rownoczesnie jesli jest taka mozliwosc)



        5 - Odszukaj zadany element nie dziala w main
        wiec trzeba zadanie 1 poprawic
        usuwanie odnalezionego nie dziala na posortowanej i na main
        nie mam funkcji(zadanie3) najczestszej wartosci
        6 nie dziala
        trzeciego nie mam

        funkcja join tez jest do poprawy





    if (*d->prawy == NULL && *d->lewy == NULL) {

        //usuwanie bezdzietnego wezla

        if (*d->ojciec) {
            // wykrywanie czy d jest lewym czy prawym 

            // ustawianie tego wskaznika na NULL

            free(*d);

            return;

        }

        // obsluzenie pozostalych przypadkow

        return;

    }

    // https://eduinf.waw.pl/inf/utils/002_roz/mp001.php




}

drzewo* ZnajdzD(drzewo* d, int klucz) {
    if (*d == NULL) return NULL;
    if (klucz < (*d)->klucz) {
        return ZnajdzD(&((*d)->lewy), klucz);
    }
    else if (klucz > (*d)->klucz) {
        return ZnajdzD(&((*d)->prawy), klucz);
    }
    else {
        return d;
    }
}

void ZwolnijD(drzewo* d) {
    if (*d == NULL) return;
    ZwolnijD(&((*d)->lewy));
    ZwolnijD(&((*d)->prawy));
    free(*d);
    *d = NULL;
}

void poprzednik(drzewo d, int liczba) {

    drzewo i = d;
    int pop = -255;

    do {
         if (i->klucz >= liczba) {
               
                i = i->lewy;
            }
            else 
            {
                pop = i->klucz;
                i = i->prawy;
            }

    } while (i);
    
    if (pop == -255) {
        printf("\n Nie udalo sie znalezc");
        return;
    };

    printf("\n Poprzednik: %d", pop);

}

void nastepnik(drzewo d, int liczba) {

    drzewo i = d;
    int pop = -255;

    do {
        
        if (i->klucz <= liczba) {
            
            i = i->prawy;
        }
        else
        {
            pop = i->klucz; // kandydat na nastepnika musi byc wiekszy
            i = i->lewy;
        }

    } while (i);

    if (pop == -255) {
        printf("\n Nie udalo sie znalezc");
        return;
    };

    printf("\n Nastepnik: %d", pop);

}
