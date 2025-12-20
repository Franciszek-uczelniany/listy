#include <stdio.h>
#include <stdlib.h>     
#include "drzewo.h"

#define NR 2

 int main(int argc, char* argv [])  {

	int wybor = 0;
	int w, w2, w3;
	int ii = 0;

	Drzewo l[NR];	

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
       " 10 - Drukuj\n"

	" Obecnie zlapane drzewo: %d \n", ii);


		printf("\n wybor = ");
		scanf("%d", &wybor);
		switch(wybor) {

		case 0:
			return 0;
			break;
		case 1:
			printf("\n i=");
			scanf("%d", &w);
			l[ii].DodajD(w);
			break;

		case 2:
			printf("\n i=");
			scanf("%d", &w);
	//todo		UsunD(&d, w);
			break;

		case 4:
//			min(d);
			break;

		case 5:
//			max(d);
			break;


		case 6:
			printf("\n i=");
			scanf("%d", &w);
//			poprzednik(d, w);
			break;

		case 7:
			printf("\n i=");
			scanf("%d", &w);
//			nastepnik(d, w);
			break;

		case 10:
			DrukujDrzewo(&l[ii]);
			break;

		case 11:
			ii = ++ii % NR;
			break;
};

	};

};

