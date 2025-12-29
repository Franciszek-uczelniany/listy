#include <cstdio>
#include "drzewo.h"

#define MAX_DRZEW 2

int main() {
    Drzewo drzewa[MAX_DRZEW];
    int current = 0;
    int wybor, w;

    while (true) {
        printf("\n0 - wyjscie\n1 - Dodaj\n2 - Drukuj\n4 - min\n5 - max\n\nWybor: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 0: return 0;
            case 1:
                printf("Wprowadz liczbe: ");
                scanf("%d", &w);
                drzewa[current].DodajD(w);
                break;
            case 2:
                DrukujDrzewo(&drzewa[current]);
                break;
            case 4:
                drzewa[current].min()->Pokaz();
                break;
            case 5:
                drzewa[current].max()->Pokaz();
                break;
            default:
                printf("Nieznana opcja\n");
        }
    }
}
