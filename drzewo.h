

#ifndef DRZEWO_H
#define DRZEWO_H

struct elDrzewaB
{
	int klucz;
	int licznik;
	struct elDrzewaB *lewy;
	struct elDrzewaB *prawy;
	struct elDrzewaB *ojciec;
	
};
typedef struct elDrzewaB wDrzewaB;
typedef wDrzewaB* drzewo;

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

#endif // DRZEWO_H
