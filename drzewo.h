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

// lewy, prawy, ojciec
Drzewo* l;
Drzewo* p;
Drzewo* o;
weld* data;	// tutaj skladujemy obecna wartosc

Drzewo();
Drzewo(const char* );


void DodajD(int );
// Te operatory są dla klasy Drzewo
bool operator ==( const weld& );
bool operator >( const weld& );
bool operator >( const int& );
bool operator >=( const weld& );
bool operator <( const weld& );
bool operator <( const int& );
bool operator <=( const weld& );
//todo: operator zwracający klucz w formie unsigned long...
// jesli taka potrzeba ofc
weld* nastepnik();
weld* poprzednik();
Drzewo* min();
Drzewo* max();

void Pokaz();	// Funkcja sluzaca do pokazania klucza węzła lub drzewa
};




void DrukujDrzewo(Drzewo* );

#endif // DRZEWO_H
