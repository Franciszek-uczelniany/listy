#include <stdio.h>
#include <stdlib.h>     
#include "drzewo.h"

#define NR 2


 int main(int argc, char* argv [])  {

	int wybor = 0;
	int w2, w3;
	

	drzewo d = NULL;
	drzewo* i;


	DodajD(&d, 4);
	DodajD(&d, 6);
	DodajD(&d, 10);
	DodajD(&d, 2);
	DodajD(&d, 1);
	DodajD(&d, 0);

//	DrukujDrzewo(d);
	

	while(1) {
		

	printf("\n Wybierz operacje: \n"
       " 0 - wyjscie \n"
       " 1 - Dodaj do drzewa\n"
       " 2 - Usun z drzewa\n"
       " 3 - szukaj elementu\n"
       " 4 - wyznacz minimum\n"
       " 5 - wyznacz maksimum\n"
       " 6 - wyznacz poprzednika\n"
       " 7 - wyznacz nastepnika\n\n"
       " 10 - Drukuj");


		printf("\n wybor = ");
		scanf("%d", &wybor);
		switch(wybor) {

		case 0:
			return 0;
			break;
		case 1:
			break;

		case 6:
			i = poprzednik(d, 4);
			printf("\n %d", (*i)->klucz);
			break;

		case 7:
			break;
};

	};

};

