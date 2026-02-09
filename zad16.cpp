#include <stdio.h>
#include <stdlib.h>

struct elDrzewaB {
    int klucz;
    int licznik;
    struct elDrzewaB *lewy;
    struct elDrzewaB *prawy;
    struct elDrzewaB *ojciec;
};
typedef struct elDrzewaB wDrzewaB;
typedef wDrzewaB* drzewo;

int maxD(drzewo d) {
    if (d == 0) return 0;
    while(d->prawy) d = d->prawy;
    return d->klucz;
}

int zliczWezly(drzewo root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + zliczWezly(root->lewy) + zliczWezly(root->prawy);
}

// Funkcja do zbierania wartości w drzewie
void zbierzWartosci(drzewo root, int* tablica, int* index) {
    if (root == NULL) {
        return;
    }
    tablica[(*index)++] = root->klucz;
    zbierzWartosci(root->lewy, tablica, index);
    zbierzWartosci(root->prawy, tablica, index);
}


void insert(int* tablica, int rozmiar) {
    for (int i = 1; i < rozmiar; i++) {
        int klucz = tablica[i];
        int j = i - 1;

        while (j >= 0 && tablica[j] > klucz) {
            tablica[j + 1] = tablica[j];
            j--;
        }
        tablica[j + 1] = klucz;
    }
}

int porownajDrzewa(drzewo root1, drzewo root2) {
    int liczbaWezlow1 = zliczWezly(root1);
    int liczbaWezlow2 = zliczWezly(root2);

    if (liczbaWezlow1 != liczbaWezlow2) {
        return 0;
    }

    int m1 = maxD(root1);
    int m2 = maxD(root2);

    if (m1 != m2) {
        return 0;
    }

    int* wartosci1 = (int*)malloc(liczbaWezlow1 * sizeof(int));
    int* wartosci2 = (int*)malloc(liczbaWezlow2 * sizeof(int));
    int index1 = 0, index2 = 0;

    zbierzWartosci(root1, wartosci1, &index1);
    zbierzWartosci(root2, wartosci2, &index2);

    insert(wartosci1, liczbaWezlow1);
    insert(wartosci2, liczbaWezlow2);

    int wynik = 1;
    for (int i = 0; i < liczbaWezlow1; i++) {
        if (wartosci1[i] != wartosci2[i]) {
            wynik = 0;
            break;
        }
    }


    free(wartosci1);
    free(wartosci2);

    return wynik;
}


drzewo dodaj(drzewo root, int klucz) {
    if (root == NULL) {
        drzewo nowy = (drzewo)malloc(sizeof(wDrzewaB));
        nowy->klucz = klucz;
        nowy->licznik = 1;
        nowy->lewy = NULL;
        nowy->prawy = NULL;
        nowy->ojciec = NULL;
        return nowy;
    }
    if (klucz < root->klucz) {
        drzewo lewy = dodaj(root->lewy, klucz);
        root->lewy = lewy;
        lewy->ojciec = root;
    } else if (klucz > root->klucz) {
        drzewo prawy = dodaj(root->prawy, klucz);
        root->prawy = prawy;
        prawy->ojciec = root;
    } else {
        root->licznik++; // Zwiększ licznik, jeśli klucz się powtarza
    }
    return root;
}

// Nie jest to optymalny sposób.
int main() {
    drzewo d1 = NULL;
    d1 = dodaj(d1, 5);
    d1 = dodaj(d1, 3);
    d1 = dodaj(d1, 8);

    drzewo d2 = NULL;
    d2 = dodaj(d2, 8);
    d2 = dodaj(d2, 5);
    d2 = dodaj(d2, 4);


    if (porownajDrzewa(d1, d2)) {
        printf("Drzewa zawieraja te same wartosci.\n");
    } else {
        printf("Drzewa nie zawieraja tych samych wartosci.\n");
    }



    return 0;
}
