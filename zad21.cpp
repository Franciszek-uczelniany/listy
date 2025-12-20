
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 10000 // Rozmiar tablicy do posortowania
#define M 1000  // Liczba powtórzeń dla każdego z algorytmów


struct stats {
    unsigned long long porownania;
    unsigned long long podstawienia;
};

struct summary {
    unsigned long long min_porownan;
    unsigned long long max_porownan;
    long double sr_porownan;
    unsigned long long min_podst;
    unsigned long long max_podst;
    long double sr_podst;
};

struct stats bubble_sort(int* tablica, int size);
struct stats insertion_sort(int* tablica, int size);
struct stats shell_sort(int* tablica, int size);
struct stats quick_sort(int* tablica, int size);
void quick_sort_recursive(int* A, int low, int high, struct stats* stat);
int partition(int* A, int low, int high, struct stats* stat);

// Funkcja pomocnicza do kopiowania tablicy
// todo: zastapic funkcja memcpy
void copy_array(int* source, int* dest, int size);

// Funkcja do agregacji statystyk
struct summary aggregate_stats(struct stats* results, int count);

int main() {
    srand(time(NULL));
    int* original_array = (int*)malloc(sizeof(int) * N);
    int* working_array = (int*)malloc(sizeof(int) * N);

    // Uwaga: my tutaj tworzymy TABLICĘ struktur przechowujące liczbę porównań i podstawień
    // następnie funkcja agregująca dane zajmuje się np wyliczeniem wartości średnich
    struct stats bubble_stats[M], insertion_stats[M], shell_stats[M], quick_stats[M];

    // Główna pętla testowa, która zostaje wykonana M razy, aby przetestować wydajność każdego z algorytmów
    for (int i = 0; i < M; i++) {
        // Generowanie losowych danych, które mają zostać posortowane
        for (int j = 0; j < N; j++) {
            original_array[j] = rand() % 10000;
        }

        // Sortowanie i zbieranie statystyk dla każdej metody
        copy_array(original_array, working_array, N);
        bubble_stats[i] = bubble_sort(working_array, N);

        copy_array(original_array, working_array, N);
        insertion_stats[i] = insertion_sort(working_array, N);

        copy_array(original_array, working_array, N);
        shell_stats[i] = shell_sort(working_array, N);

        copy_array(original_array, working_array, N);
        quick_stats[i] = quick_sort(working_array, N);
        
    }

    

    struct summary bubble_summary = aggregate_stats(bubble_stats, M);
    printf("\nsortowanie babelkowe \n ========= \n min podstawien: %lld\n max podstawien: %lld\n srednia podstawien: %Lf"
        "\n min porownan: %lld\n max porownan: %lld\n srednia porownan: %Lf",
        bubble_summary.min_podst, bubble_summary.max_podst, bubble_summary.sr_podst, bubble_summary.min_porownan, bubble_summary.max_porownan, bubble_summary.sr_porownan);

    struct summary shell_summary = aggregate_stats(shell_stats, M);
    printf("\nsortowanie shella \n ========= \n min podstawien: %lld\n max podstawien: %lld\n srednia podstawien: %Lf"
        "\n min porownan: %lld\n max porownan: %lld\n srednia porownan: %Lf",
        shell_summary.min_podst, shell_summary.max_podst, shell_summary.sr_podst, shell_summary.min_porownan, shell_summary.max_porownan, shell_summary.sr_porownan);

    struct summary quick_summary = aggregate_stats(quick_stats, M);
    printf("\nquick sort \n ========= \n min podstawien: %lld\n max podstawien: %lld\n srednia podstawien: %Lf"
        "\n min porownan: %lld\n max porownan: %lld\n srednia porownan: %Lf",
        quick_summary.min_podst, quick_summary.max_podst, quick_summary.sr_podst, quick_summary.min_porownan, quick_summary.max_porownan, quick_summary.sr_porownan);

    struct summary insertion_summary = aggregate_stats(insertion_stats, M);
    printf("\nsortowanie przez wstawianie \n ================ \n min podstawien: %lld\n max podstawien: %lld\n srednia podstawien: %Lf"
        "\n min porownan: %lld\n max porownan: %lld\n srednia porownan: %Lf",
        insertion_summary.min_podst, insertion_summary.max_podst, insertion_summary.sr_podst, insertion_summary.min_porownan, insertion_summary.max_porownan, insertion_summary.sr_porownan);

    printf("\n");
    free(original_array);
    free(working_array);



    return 0;
}

// Implementacja funkcji sortujących
struct stats bubble_sort(int* tablica, int size) {
    struct stats stat = {0, 0};
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            stat.porownania++;
            if (tablica[j] > tablica[j + 1]) {
                int temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
                stat.podstawienia++;
            }
        }
    }
    return stat;
}

struct stats insertion_sort(int* tablica, int size) {
    struct stats stat = {0, 0};
    for (int i = 1; i < size; i++) {
        int key = tablica[i];
        int j = i - 1;
        while (j >= 0 && tablica[j] > key) {
            tablica[j + 1] = tablica[j];
            j--;
            stat.porownania++;
            stat.podstawienia++;
        }
        tablica[j + 1] = key;
        stat.podstawienia++;
    }
    return stat;
}

struct stats shell_sort(int* tablica, int size) {
    struct stats stat = {0, 0};
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = tablica[i];
            int j;
            for (j = i; j >= gap && tablica[j - gap] > temp; j -= gap) {
                tablica[j] = tablica[j - gap];
                stat.porownania++;
                stat.podstawienia++;
            }
            tablica[j] = temp;
            stat.podstawienia++;
        }
    }
    return stat;
}

struct stats quick_sort(int* tablica, int size) {
    struct stats stat = {0, 0};
    quick_sort_recursive(tablica, 0, size - 1, &stat);
    return stat;
}

void quick_sort_recursive(int* A, int low, int high, struct stats* stat) {
    if (low < high) {
        int pi = partition(A, low, high, stat);
        quick_sort_recursive(A, low, pi - 1, stat);
        quick_sort_recursive(A, pi + 1, high, stat);
    }
}

int partition(int* A, int low, int high, struct stats* stat) {
    int pivot = A[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        stat->porownania++;
        if (A[j] < pivot) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            stat->podstawienia++;
        }
    }
    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;
    stat->podstawienia++;
    return (i + 1);
}

void copy_array(int* source, int* dest, int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

struct summary aggregate_stats(struct stats* results, int count) {
    struct summary podsu = {};
    podsu.min_podst = results[0].podstawienia;
    podsu.max_podst = results[0].podstawienia;
    podsu.min_porownan = results[0].porownania;
    podsu.max_porownan = results[0].porownania;

    for (int i = 0; i < count; i++) {
            if(results[i].podstawienia > podsu.max_podst) podsu.max_podst = results[i].podstawienia;
            if(results[i].porownania > podsu.max_porownan) podsu.max_porownan = results[i].porownania;
            if(results[i].porownania < podsu.min_porownan) podsu.min_porownan = results[i].porownania;
            if(results[i].podstawienia < podsu.min_podst) podsu.min_podst = results[i].podstawienia;

            podsu.sr_podst += results[i].podstawienia;
            podsu.sr_porownan += results[i].porownania;

            //co 100 iteracji wykonaj dzielenie, aby uzyskać średnią arytmetyczną
            if (i%100 == 0) {
                podsu.sr_podst /= count;
                podsu.sr_porownan /= count;
            }
    }
    return podsu;
}
