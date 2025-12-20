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

Drzewo* l;
Drzewo* p;
Drzewo* o;	//o jak ojciec
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
};




void DrukujDrzewo(Drzewo* );

#endif // DRZEWO_H
