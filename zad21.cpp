//Do zaimplementowania: metoda shella na bazie sortowania babelkowego i quick sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include <algorithm>
#define NUM 100
#define VERBOSE 1
#define N 10000
#define M 1000



struct stats {
    long wstawienia = 0;
    long porownania = 0;

};

struct stats bubble(int* tablica, unsigned int size);
struct stats wstawienie(int* tab, unsigned int size);
void qsort(int* A, int p, int r);
int partition(int* A, int p, int r);
struct stats shell(int* A);


// Powinienem zrobic qsort w formie iteracyjnej

unsigned int minimum(int* A, int size) {

    int ret = A[0];

    for (int i = 0; i < size; i++) if (A[i] < ret) ret = A[i];

    return ret;
}

unsigned int maximum(int* A, int size) {

    int ret = A[0];

    for (int i = 0; i < size; i++) if (A[i] < ret) ret = A[i];

    return ret;
}

int main()
{
    srand(time(NULL));
    int* tablica = (int*) malloc(sizeof(int) * NUM);

    // powtarzamy tą czynnosc 1000 razy (M)
    struct stats* wyniki_bu = new struct stats[M];
    struct stats* wyniki_ws = new struct stats[M];
    struct stats* wyniki_qs = new struct stats[M];
    struct stats* wyniki_sh = new struct stats[M];



    for (int i = 0; i < M; i++) {
    
        for (int i = 0; i < NUM; i++)
            tablica[i] = rand() % N; // ustalamy, że liczby są z zakresu 1 do 10 000
        
        
        wyniki_bu[i] = bubble(tablica, NUM);
        wyniki_ws[i] = wstawienie(tablica, NUM);
      //  wyniki_qs[i] = qsort(tablica, NUM);
        wyniki_sh[i] = shell(tablica);

    }

    // Drukujemy wyniki
    printf("\n Typ sortowania \t MIN wstawien \t MAX wstawien \t srednia wstawien \t MIN porownan \t MAX porownan \t srednia porownan");
//    printf("\n sortowanie babelkowe \t %ld \t %ld", );
  




    // Dla każdej z
   //  wymienionych metod program powinien wyświetlić w tabeli następujące dane : maksymalna
     //   i minimalna w serii M prób liczba wykonanych podstawień i porównań sortowanych kluczy
     //   oraz średnia liczba podstawień i porównań.

    // free(tablica);
    int size = NUM;

    shell(tablica);

    return 0;
    qsort(tablica, 0, --size);




    
    bubble(tablica, NUM);
    wstawienie(tablica, NUM);
    

printf("\n");


return 0;
    }

struct stats shell(int* A) {

    struct stats ret;

    int h, i, j, x;
    for (h = 1; h < NUM; h = 3 * h + 1);
    h /= 9;
    if (!h) h++;
        
  

    while (h)
    {
        for (j = NUM - h - 1; j >= 0; j--)
        {
            x = A[j];
            i = j + h;
            while ((i < NUM) && (x > A[i]))
            {
                ret.porownania++; // tutaj chodzi o porownanie wyzej w warunku petli while

                A[i - h] = A[i];
                ret.wstawienia++;
                i += h;
            }
            A[i - h] = x;
            ret.wstawienia++;
        }
        h /= 3;
    }

#ifdef VERBOSE
    printf("\n posortowane: ");
    for (int i = 0; i < NUM; i++)
        printf("\n %d", A[i]);
#endif


    return ret;
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

struct stats wstawienie(int* tab, unsigned int size) {

    struct stats ret;

    int* wynik = (int*)malloc(sizeof(int) * size);


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
            ret.porownania++;
            ret.wstawienia++;
        }

        // Wstawienie elementu buf w odpowiednie miejsce
        wynik[j + 1] = buf;
        ret.wstawienia++; // Wstawienie elementu
    }



    printf("\n sortowanie przez wstawienie: porownania: %ld  wstawienia: %ld", ret.porownania, ret.wstawienia);

#ifdef VERBOSE
    for (unsigned int i = 0; i < size; i++)
        printf("\n %d", wynik[i]);
#endif

    free(wynik);

    return ret;
}

struct stats bubble(int* tablica, unsigned int size) {

    int* wynik = (int*)malloc(sizeof(int) * size);

    struct stats ret;

   
    for (unsigned int i = 0; i < size; i++)
        wynik[i] = tablica[i];

   

    int buf;

    for(unsigned int i=0; i<size; i++) 
        for (unsigned int j = 1; j < size - i; j++) {
            ret.porownania++;
            if (wynik[j - 1] > wynik[j]) {
                buf = wynik[j - 1];
                wynik[j - 1] = wynik[j];
                wynik[j] = buf;
                ret.wstawienia++;
            }

        }


    printf("\n babelkowe: porownania: %ld wstawienia: %ld", ret.porownania, ret.wstawienia);

#ifdef VERBOSE
    for (unsigned int i = 0; i < size; i++)
        printf("\n %d", wynik[i]);
#endif

    free(wynik);

    return ret;
}
