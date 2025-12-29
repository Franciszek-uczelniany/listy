#ifndef DRZEWO_H
#define DRZEWO_H

#include <string>
using namespace std;

struct weld {
    char* wsp;
    unsigned short len;
    int licznik;
};

class Drzewo {
public:
    Drzewo* l;
    Drzewo* p;
    Drzewo* o;
    weld* data;

    Drzewo();
    Drzewo(const char*);
    void DodajD(int);

    bool operator>(const weld&);
    bool operator<(const weld&);
    bool operator==(const weld&);
    bool operator==(const int&);
    bool operator>(const int&);
    bool operator<(const int&);
    bool operator<=(const weld&);
    bool operator>=(const weld&);

    Drzewo* min();
    Drzewo* max();
    Drzewo* korzen();               // Funkcja zwraca korzen dla calego d, potrzebne dla heapify
    void Pokaz();
	Drzewo* poprzednik(Drzewo* d);
	Drzewo* nastepnik(Drzewo* d);
    Drzewo* poprzednik();
	Drzewo* nastepnik();
    Drzewo* znajdz(int war);        // kiedy chcemy wyznaczyc poprzednika lub nastepnika danego el
                                    // to musimy najpierw przejsc na ten dany element

    // alternatywą dla funkcji znajdź jest dodawanie do listy jednokierukowej wszystkich el. d
    // w momencie dodawania/usuwania
};

void DrukujDrzewo(Drzewo* d);
int pord(Drzewo* p, Drzewo* q);
void heapsort(int *A, int n);
void podmien(Drzewo* p, Drzewo* q);

#endif
