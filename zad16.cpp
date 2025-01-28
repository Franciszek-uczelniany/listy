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


int zliczWezly(drzewo root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + zliczWezly(root->lewy) + zliczWezly(root->prawy);
}

// Funkcja rekurencyjna do zbierania wartości w drzewie
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

// Funkcja sprawdzająca, czy dwa drzewa zawierają takie same wartości
int porownajDrzewa(drzewo root1, drzewo root2) {
    int liczbaWezlow1 = zliczWezly(root1);
    int liczbaWezlow2 = zliczWezly(root2);

    if (liczbaWezlow1 != liczbaWezlow2) {
        return 0;
    }

    // Tablice do przechowywania wartości z drzew
    int* wartosci1 = (int*)malloc(liczbaWezlow1 * sizeof(int));
    int* wartosci2 = (int*)malloc(liczbaWezlow2 * sizeof(int));
    int index1 = 0, index2 = 0;

    // Zbieranie wartości z obu drzew
    zbierzWartosci(root1, wartosci1, &index1);
    zbierzWartosci(root2, wartosci2, &index2);

    // Sortowanie wartości
    insert(wartosci1, liczbaWezlow1);
    insert(wartosci2, liczbaWezlow2);

    // Porównanie wartości
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

// Funkcja pomocnicza do tworzenia nowego węzła
drzewo nowyWezel(int klucz) {
    drzewo nowy = (drzewo)malloc(sizeof(wDrzewaB));
    nowy->klucz = klucz;
    nowy->licznik = 1;
    nowy->lewy = NULL;
    nowy->prawy = NULL;
    nowy->ojciec = NULL;
    return nowy;
}


drzewo dodaj(drzewo root, int klucz) {
    if (root == NULL) {
        return nowyWezel(klucz);
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


int main() {
    // Tworzenie dwóch przykładowych drzew
    drzewo drzewo1 = NULL;
    drzewo1 = dodaj(drzewo1, 5);
    drzewo1 = dodaj(drzewo1, 3);
    drzewo1 = dodaj(drzewo1, 8);

    drzewo drzewo2 = NULL;
    drzewo2 = dodaj(drzewo2, 8);
    drzewo2 = dodaj(drzewo2, 5);
    drzewo2 = dodaj(drzewo2, 3);


    if (porownajDrzewa(drzewo1, drzewo2)) {
        printf("Drzewa zawierają te same wartości.\n");
    } else {
        printf("Drzewa nie zawierają tych samych wartości.\n");
    }



    return 0;
}
