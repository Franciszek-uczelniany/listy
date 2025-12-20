#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "drzewo.h"
#include <bits/stdc++.h>

vector<vector<char*>> treeToMatrix(weld* root);

Drzewo::Drzewo()
{
    l = p = o = nullptr;
    licznik = 0;
    x = nullptr;
    len = 0;
}

Drzewo::Drzewo(const char* s)
{
    len = std::strlen(s);
    x = new char[len + 1];
    std::strcpy(x, s);

    l = p = o = nullptr;
    licznik = 1;
}

// 1 - A jest wieksze od B
// 0, A == B
// -1 A<B
int porownaj(const char* a, unsigned short la,
             const char* b, unsigned short lb)
{
    if (a == nullptr || b == nullptr) return -3;
    if (la < lb) return -1;
    if (la > lb) return 1;
    unsigned short min = (la < lb) ? la : lb;

    for (unsigned short i = 0; i < min; ++i)
    {
        // 9 to 71 miejsce w ascii, 0 przed nim
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }


    return 0;
}

bool Drzewo::operator==(const weld& w)
{
    return porownaj(x, len, w.wsp, w.len) == 0;
}

bool Drzewo::operator<(const weld& w)
{
    return porownaj(x, len, w.wsp, w.len) < 0;
}

bool Drzewo::operator>(const weld& w)
{
    return porownaj(x, len, w.wsp, w.len) > 0;
}

bool Drzewo::operator<=(const weld& w)
{
    return porownaj(x, len, w.wsp, w.len) <= 0;
}

bool Drzewo::operator>=(const weld& w)
{
    return porownaj(x, len, w.wsp, w.len) >= 0;
}


// n - maksymalna ilosc elementów w tablicy dst
// poz - pozycja w tablicy od której mo¿emy zacz¹æ wpisywanie 
// Zwracana wartoœæ to iloœæ zapisanych elementów do tablicy //////
/*clear

unsigned Zapisz_tab(drzewo d, int* dst, int n, int poz) {
    if (d == NULL) return 0;

    Zapisz_tab(d->lewy, dst, n);
    Zapisz_tab(d, dst, n);
    Zapisz_tab(d->prawy, dst, n);
} */

///todo ^^^


/*
int czy_rowne(drzewo d, drzewo f) {
    // Zapisujemy zawartoœæ obu drzew do dwóch tablic, nastêpnie porównujemy wartoœci
    // Aby by³o szybciej nie sprawdzamy obu tablic element po elemencie, zamiast tego
    // 1. Sprawdzamy czy iloœæ elementu w drzewie d jest równa iloœci w drzewie f
    // 2. Sprawdzamy czy wartoœci minimalne i maksymalne s¹ sobie równe
    // 3. Sprawdzamy tablicê element po elemencie

    // problem: operujemy na drzewie ³añcuchów znakowych.....

}



int max(drzewo d) {

    while (d->prawy) {
        d = d->prawy;
    }

    printf("\n Maksymalna wartosc wynosi %s", d->klucz);
    return atoi(d->klucz);
}

int min(drzewo d) {

    while (d->lewy) {
        d = d->lewy;
    }

    printf("\n Minimalna wartosc wynosi %s", d->klucz);
    return atoi(d->klucz);
}

drzewo* el_Max(drzewo* d) {

   while((*d)->prawy) d = &(*d)->prawy;

  return d;

}


drzewo* el_Min(drzewo* d) {

    while((*d)->lewy) d = &(*d)->lewy;

    return d;

}

void DrukujDrzewo0(drzewo d, int glebokosc) {
    if (d == NULL) return;
    DrukujDrzewo0(d->lewy, glebokosc + 1);
    for (int i = 0; i < glebokosc; i++)
        putchar(' ');
    printf("%s\n", d->klucz);
    DrukujDrzewo0(d->prawy, glebokosc + 1);
}
*/



/*
void DodajD(drzewo* d, int klucz) {
    if (*d == NULL) {
        *d = (drzewo)malloc(sizeof(wDrzewaB));
        if (*d == NULL) {
            perror("Nie udalo sie przydzielic pamieci");
            exit(1);
   	}

	sprintf((*d)->klucz, "%d", klucz);
        (*d)->licznik = 1;
        (*d)->lewy = (*d)->prawy = NULL;
    }
    else if (klucz < atoi((*d)->klucz)) {
        DodajD(&((*d)->lewy), klucz);

    }
    else if (klucz > atoi((*d)->klucz)) {
        DodajD(&((*d)->prawy), klucz);
    }
    else {
        (*d)->licznik++;
    }
}

void UsunD(drzewo* d, int klucz) {
    if (*d == NULL) return;
    drzewo* do_usuniecia;
    drzewo* ds;
    ds = ZnajdzD(d, klucz);
    if (*ds == NULL) return;
    if ((*d)->licznik > 1) {
     (*d)->licznik--;
     return;
    }
   if( (*d)->lewy == NULL ||  (*d)->prawy == NULL ) do_usuniecia = d;
   else {
     do_usuniecia = el_Max(&(*d)->lewy);
     int buff = atoi((*do_usuniecia)->klucz);
     sprintf((*d)->klucz, "%d", buff);

     (*d)->licznik = (*do_usuniecia)->licznik;
}
    ds = do_usuniecia;
    if((*do_usuniecia)->lewy == NULL) *do_usuniecia = (*do_usuniecia)->prawy;
     else *do_usuniecia = (*do_usuniecia)->lewy;

    free(*ds);

}

drzewo* ZnajdzD(drzewo* d, int klucz) {
    if (*d == NULL) return NULL;
    if (klucz < atoi((*d)->klucz)) {
        return ZnajdzD(&((*d)->lewy), klucz);
    }
    else if (klucz > atoi( (*d)->klucz) ) {
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


*/


/*
void poprzednik(drzewo d, int liczba) {

    drzewo i = d;
    int pop = -255;

    do {
         if (atoi(i->klucz) >= liczba) {
               
                i = i->lewy;
            }
            else 
            {
                pop = atoi(i->klucz);
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

    drzewo i = d;   //po co? drzewo to nie wsk na wskaznik
    int pop = -255;


    // logika bled,a do napisania od nowa

    do {
        
        if (atoi(i->klucz) <= liczba) {
            
            i = i->prawy;
        }
        else
        {
            pop = atoi(i->klucz); // kandydat na nastepnika musi byc wiekszy
            i = i->lewy;
        }

    } while (i);

    if (pop == -255) {
        printf("\n Nie udalo sie znalezc");
        return;
    };

    printf("\n Nastepnik: %d", pop);

}

*/

void drukuj(vector<vector<char*>> &arr) {
    for (auto &row : arr) {
        for (auto &cell : row) {
            if (cell == nullptr) {
                cout << " ";
            }
            else {
                cout << cell;
            }
        }
        cout << endl;
    }
}

int wysokosc(weld* root) {
    if (!root) {
        return -1;
    }

    int l = wysokosc(root->l);
    int p = wysokosc(root->p);

    return max(l, p) + 1;
}

// To jest potrzebne do wyswietlania drzewa, output jest w ans
void inorder(weld *root, int row, int col, int height,
             vector<vector<char*>> &ans) {
    if (!root) {
        return;
    }

    int offset = pow(2, height - row - 1);

   // przejdz po lewym drzewie, czyli 
   //lewe <= obecne < Prawe
    if (root->l) {
        inorder(root->l, row + 1, col - offset, height, ans);
    }

    ans[row][col] = root->wsp;

    if (root->p) {
        inorder(root->p, row + 1, col + offset, height, ans);
    }
}



vector<vector<char*>> treeToMatrix(weld* root) {

    int h = wysokosc(root);

    int rows = h + 1;
    int cols = pow(2, h + 1) - 1;

    vector<vector<char*>> ans(rows, vector<char*>());

    inorder(root, 0, (cols - 1) / 2, h, ans);

    return ans;
}


 void DrukujDrzewo(weld* d) {
    std::vector<vector<char*>> ret = treeToMatrix(d);

    drukuj(ret);
}