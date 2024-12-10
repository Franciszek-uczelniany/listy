#include <stdio.h>
#include <stdlib.h>     
#include "drzewo.h"

#define NR 2


 int main(int argc, char* argv [])  {

	int wybor = 0;
	int w2, w3;
	int i=0;

	drzewo d = NULL;



	DodajD(&d, 4);
	DodajD(&d, 6);
	DodajD(&d, 10);
	DodajD(&d, 2);
	DodajD(&d, 1);
	DodajD(&d, 0);

	DrukujDrzewo(d);
	return;

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


};

	};

};

