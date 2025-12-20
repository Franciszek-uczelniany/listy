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


// Te operatory są dla klasy Drzewo
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


#endif // DRZEWO_H
