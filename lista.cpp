#include <stdio.h>
#include <stdlib.h>
#include "drzewo.h"


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

drzewo* MaxD(drzewo* d) {
    if (*d == NULL) return NULL;
    while ((*d)->prawy != NULL) {
        d = &((*d)->prawy);
    }
    return d;
}

drzewo* MinD(drzewo* d) {
    if (*d == NULL) return NULL;
    while ((*d)->lewy != NULL) {
        d = &((*d)->lewy);
    }
    return d;
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
