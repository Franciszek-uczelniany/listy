

#ifndef DRZEWO_H
#define DRZEWO_H

struct elDrzewaB
{
	int klucz;
	int licznik;
	struct elDrzewaB *lewy;
	struct elDrzewaB *prawy;
	
};
typedef struct elDrzewaB wDrzewaB;
typedef wDrzewaB* drzewo;

void DrukujDrzewo0(drzewo d, int glebokosc);
void DrukujDrzewo(drzewo d);
void DodajD(drzewo* d, int klucz);
drzewo* ZnajdzD(drzewo* d, int klucz);


#endif // DRZEWO_H
