//Do zaimplementowania: metoda shella na bazie sortowania babelkowego i quick sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include <algorithm>
#define NUM 100
//#define VERBOSE 0

void bubble(int* tablica, unsigned int size);
void wstawienie(int* tab, unsigned int size);
void qsort(int* A, int p, int r);
int partition(int* A, int p, int r);

int main()
{
    srand(time(NULL));
    int* tablica = (int*) malloc(sizeof(int) * NUM);

    for (int i = 0; i < NUM; i++)
        tablica[i] = rand() % 10000; // ustalamy, że liczby są z zakresu 1 do 10 000


    // wywolujemy dla kazdego algorytmu 
    // liczymy ilosc porownan i podstawien kluczy (czyli zamian)

    // powtarzamy tą czynnosc 1000 razy (czyli tworzymy tablice dwuwymiarowa i dajemy funkcji wsktaznik do niej)

    // drukujemy wyniki.....

    // free(tablica);
    int size = NUM;

    //qsort(tablica, 0, --size);



    //return 0;
    
    bubble(tablica, NUM);
    wstawienie(tablica, NUM);
    

printf("\n");
    }




//todo: zrobic funkcje partition w taki sposob aby robiła trzy partycje

// funkcja dzieli tablicę A na dwie części A[p,i] <= x <=A[j,r]
int partition(int* A , int p, int r)
{
    int _r = rand() % (r - p + 1) + p;

    int x, i, j;
    int y;

    x = A[p]; A[p] = A[_r]; A[_r] = x;

    x = A[p];  // wybór pivotu, w tym przypadku efektywnie będzie to A[_r]
    i = p - 1; j = r + 1;

    do {
        do { j--; } while (A[j] > x);
        do { i++; } while (A[i] < x);
        if (i < j) {
            y = A[i];
            A[i] = A[j];
            A[j] = y;
        } 

    } while (i < j);

    if (i > j) printf("\n UWAGA: i>j");
    else if (i == j) {
        printf("\n UWAGA: i == j");
        // maxi++ nie moze tu byc poniewaz maxi nie jest zadeklarowane
    }

    int mini = std::min(i, j);
    int maxi = std::max(i, j);
    if(mini == maxi) maxi++;

#ifdef VERBOSE
    printf("\n\n pivot: %d", x);
    printf("\n A[p,i]: ");

    for (unsigned int h = p; h <= mini; h++)
        printf("\n %d", A[h]);

    printf("\n A[j,r]: ");
    for (unsigned int h = maxi; h <= r; h++)
            printf("\n %d", A[h]);


    printf("\n");
#endif

    return j;

}

void part_verify(int* A, int p, int i, int j, int r) {

    //for (unsigned g = 0; );

    // byc moze wystarczy znalezc najwiekszy element pierwszej partycji
    // i sprawdzic czy istnieje element mniejszy od tego najwiekszego w drugiej
    // partycji.

}

void qsort(int* A, int p, int r)
{
    int buff;
    if (p < r)
    {
        buff = partition(A, p, r);
        qsort(A, p, buff);
        qsort(A, buff + 1, r);

    }

}

void wstawienie(int* tab, unsigned int size) {

    int* wynik = (int*)malloc(sizeof(int) * size);
    long porownania = 0, wstawienia = 0;


    for (unsigned int i = 0; i < size; i++)
        wynik[i] = tab[i];



    int buf, j;


    for (unsigned int i = 1; i < size; i++) {
        int buf = wynik[i];
        int j = i - 1;

        // Przesuwanie elementów tablicy, aby zrobić miejsce na buf
        while (j >= 0 && wynik[j] > buf) {
            wynik[j + 1] = wynik[j];
            --j;
            porownania++; // Porównanie
            wstawienia++; // Przesunięcie elementu
        }

        // Wstawienie elementu buf w odpowiednie miejsce
        wynik[j + 1] = buf;
        wstawienia++; // Wstawienie elementu
    }



    printf("\n sortowanie przez wstawienie: porownania: %ld  wstawienia: %ld", porownania, wstawienia);

#ifdef VERBOSE
    for (unsigned int i = 0; i < size; i++)
        printf("\n %d", wynik[i]);
#endif

    free(wynik);
}

void bubble(int* tablica, unsigned int size) {

    int* wynik = (int*)malloc(sizeof(int) * size);

    long porownania = 0, wstawienia = 0;

   
    for (unsigned int i = 0; i < size; i++)
        wynik[i] = tablica[i];

   

    int buf;

    for(unsigned int i=0; i<size; i++) 
        for (unsigned int j = 1; j < size - i; j++) {
            porownania++;
            if (wynik[j - 1] > wynik[j]) {
                buf = wynik[j - 1];
                wynik[j - 1] = wynik[j];
                wynik[j] = buf;
                wstawienia++;
            }

        }


    printf("\n babelkowe: porownania: %ld wstawienia: %ld", porownania, wstawienia);

#ifdef VERBOSE
    for (unsigned int i = 0; i < size; i++)
        printf("\n %d", wynik[i]);
#endif

    free(wynik);
}
