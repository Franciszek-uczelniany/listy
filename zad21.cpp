#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Definicja stałych
#define N 10000 // Rozmiar tablicy
#define M 1000  // Liczba powtórzeń

// Struktura do przechowywania statystyk
struct stats {
    long porownania;
    long podstawienia;
};

// Funkcje sortujące
struct stats bubble_sort(int* tablica, int size);
struct stats insertion_sort(int* tablica, int size);
struct stats shell_sort(int* tablica, int size);
struct stats quick_sort(int* tablica, int size);
void quick_sort_recursive(int* A, int low, int high, struct stats* stat);
int partition(int* A, int low, int high, struct stats* stat);

// Funkcja pomocnicza do kopiowania tablicy
void copy_array(int* source, int* dest, int size);

// Funkcja do agregacji statystyk
struct stats aggregate_stats(struct stats* results, int count);

// Funkcja główna
int main() {
    srand(time(NULL));
    int* original_array = (int*)malloc(sizeof(int) * N);
    int* working_array = (int*)malloc(sizeof(int) * N);

    struct stats bubble_stats[M], insertion_stats[M], shell_stats[M], quick_stats[M];

    // Główna pętla testowa
    for (int i = 0; i < M; i++) {
        // Generowanie losowej tablicy
        for (int j = 0; j < N; j++) {
            original_array[j] = rand() % 10000; // Losowe liczby 0-9999
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

    // Wyliczanie i wyświetlanie wyników
    printf("\nAlgorytm\tMIN Podstawień\tMAX Podstawień\tŚR Podstawień\tMIN Porównań\tMAX Porównań\tŚR Porównań\n");

    struct stats bubble_summary = aggregate_stats(bubble_stats, M);
    printf("Bąbelkowe\t%ld\t\t%ld\t\t%ld\t\t%ld\t\t%ld\t\t%ld\n",
           bubble_summary.podstawienia, bubble_summary.podstawienia, bubble_summary.podstawienia,
           bubble_summary.porownania, bubble_summary.porownania, bubble_summary.porownania);

    struct stats insertion_summary = aggregate_stats(insertion_stats, M);
    printf("Wstawianie\t%ld\t\t%ld\t\t%ld\t\t%ld\t\t%ld\t\t%ld\n",
           insertion_summary.podstawienia, insertion_summary.podstawienia, insertion_summary.podstawienia,
           insertion_summary.porownania, insertion_summary.porownania, insertion_summary.porownania);

    struct stats shell_summary = aggregate_stats(shell_stats, M);
    printf("Shell\t\t%ld\t\t%ld\t\t%ld\t\t%ld\t\t%ld\t\t%ld\n",
           shell_summary.podstawienia, shell_summary.podstawienia, shell_summary.podstawienia,
           shell_summary.porownania, shell_summary.porownania, shell_summary.porownania);

    struct stats quick_summary = aggregate_stats(quick_stats, M);
    printf("QuickSort\t%ld\t\t%ld\t\t%ld\t\t%ld\t\t%ld\t\t%ld\n",
           quick_summary.podstawienia, quick_summary.podstawienia, quick_summary.podstawienia,
           quick_summary.porownania, quick_summary.porownania, quick_summary.porownania);

    // Zwolnienie pamięci
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

struct stats aggregate_stats(struct stats* results, int count) {
    struct stats summary = {LONG_MAX, LONG_MAX};
    for (int i = 0; i < count; i++) {
        summary.podstawienia = results[i].podstawienia;
    }
    return summary;
}
