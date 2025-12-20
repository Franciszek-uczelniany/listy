#include <string>

#ifndef DRZEWO_H
#define DRZEWO_H

using namespace std;

struct weld
{
	char* wsp;
	unsigned short len;
	int licznik;
	struct weld* l;
	struct weld* p;
	struct weld* o;
	
};

class Drzewo {

public:

weld* l;
weld* p;
weld* o;	//o jak ojciec
int licznik;
char* x;
unsigned short len;	// dlugosc tablicy klucza

Drzewo();
Drzewo(const char* );

bool operator ==( const weld& );
bool operator >( const weld& );
bool operator >=( const weld& );
bool operator <( const weld& );
bool operator <=( const weld& );
//todo: operator zwracający klucz w formie unsigned long...
// jesli taka potrzeba ofc
weld* nastepnik();
weld* poprzednik();
};

/*
void DrukujDrzewo0(drzewo d, int glebokosc);
void DrukujDrzewo(drzewo d);
void DodajD(drzewo* d, int klucz);
void UsunD(drzewo* d, int klucz);
drzewo* ZnajdzD(drzewo* d, int klucz);

int max(drzewo d);
int min(drzewo d);

drzewo* el_Min(drzewo* d);
drzewo* el_Max(drzewo* d);


void poprzednik(drzewo d, int liczba);
void nastepnik(drzewo d, int liczba);

*/

#endif // DRZEWO_H
