#include <cstdio>
#include "drzewo.h"

#define MAX_DRZEW 2

int main() {
    Drzewo drzewa[MAX_DRZEW];
    Drzewo *out;
    int current = 0;
    int wybor, w;

    while (true) {
        printf("\n0 - wyjscie\n1 - Dodaj\n2 - Porownaj czy drzewa sa identyczne\n4 - min\n5 - max"
            "\n6 - poprzednik\n 7 - nastepnik \n 10 - Drukuj" 
            "\n\nWybor: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 0: return 0;
            case 1:
                printf("Wprowadz liczbe: ");
                scanf("%d", &w);
                drzewa[current].DodajD(w);
                break;
            case 2:
                pord(&drzewa[0], &drzewa[1]) == 0 ? printf("\n Drzewa rozne") : printf("\n Drzewa takie same"); 
                break;
            case 4:
                drzewa[current].min()->Pokaz();
                break;
            case 5:
                drzewa[current].max()->Pokaz();
                break;
            case 6:
                printf("\n Element: ");
                scanf("%d", &w);
                out = drzewa[current].znajdz(w)->poprzednik();
                out->Pokaz();
            break;
            case 7:
                printf("\n Element: ");
                scanf("%d", &w);
                out = drzewa[current].znajdz(w)->nastepnik();
                out->Pokaz();
            break;
            case 10:
                DrukujDrzewo(&drzewa[current]);
                break;
            default:
                printf("Nieznana opcja\n");
        }
    }
}
