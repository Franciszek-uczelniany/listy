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


drzewo* poprzednik(drzewo d, int liczba) {

    drzewo i = d;
    drzewo* pop = NULL; // poprzedni element

    while (i) {
        if (liczba > i->klucz ) {
            pop = &i;
            if (i->lewy) i = i->lewy;
        }
        else {
            if (i->prawy) i = i->prawy;
        }

    }

    return pop;


}
