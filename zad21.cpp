

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define NUM 100

void bubble(int* tablica, unsigned int size);
void wstawienie(int* tab, unsigned int size);

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

    bubble(tablica, NUM);
    wstawienie(tablica, NUM);
}


//Do zaimplementowania: metoda shella na bazie sortowania babelkowego i quick sort

//TODO: ZADANIE DOMOWE
int partition();

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



    printf("\n porownania: %ld \n wstawienia: %ld", porownania, wstawienia);
    for (unsigned int i = 0; i < size; i++)
        printf("\n %d", wynik[i]);

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


    printf("\n porownania: %ld \n wstawienia: %ld", porownania, wstawienia);
    for (unsigned int i = 0; i < size; i++)
        printf("\n %d", wynik[i]);

    free(wynik);
}
