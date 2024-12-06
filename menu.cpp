#include <stdio.h>
#include <stdlib.h>     
#include "lista.h"


 int main(int argc, char* argv [])  {
	 lista l[2] = {0, 0};
	int wybor = 0;
	int w2, w3;
	int i;

	while(1) {
		

	printf("\n Wybierz operacje: \n"
       " 0 - wyjscie \n"
       " 1 - Dodaj do posortowanej listy\n"

       " 3 - Pobierz pierwszy element listy \n" 
       " 4 - Pobierz ostatni element listy \n"
       " 5 - Odszukaj zadany element \n"

       " 7 - Usun wskazany element / elementy \n"
       " 8 - Wczytaj zawartosc listy z pliku \n"
       " 9 - Zapisz zawartosc listy do pliku \n"
       " 10 - Wyswietl zawartosc listy \n"
       " 11 - Wyswietl od konca \n"
       " 12 - Odwroc iteracyjnie \n"
       " 13 - Odwroc rekurencyjnie \n\n"
       
       " 20 - Usun pierwszy element listy \n"
       " l - Zmien zlapana liste \n"


	" Obecnie zlapana lista: %p \n", &l[i]);




		printf("\n wybor = ");
		scanf("%d", &wybor);
		switch(wybor) {

			case 'l':
			i == 0 ? i = 1 : i = 2;
			break;

			case 0:
			exit(0);
			break;

			case 1:
			printf("\n klucz=");
			scanf("%d", &wybor);
			DL_sort(&l[i], wybor);
			break;
			
			case 3:
			Wyswietl_Pierwszy(&l[i]);
			break;
			
			case 4:
			Wyswietl_Ostatni(&l[i]);
			break;

			case 5:
			printf("\n klucz =");
			scanf("%d", &wybor);
			printf("\n zadany el. jest %u w liscie", odszukaj(&l[i], wybor));
			break;

			case 7:
			printf("\n klucz=");
			scanf("%d", &wybor);
			printf("\n Podaj liczbe el do usuniecia, 0 oznacza wszystkie \n :");
			scanf("%d", &w2);
			if(w2==0) w2--;
			UEL_k(&l[i], wybor, w2);
			break;
			
			case 8:
			Wczytaj(&l[i]);
			break;
			
			case 9:
			Zapisz(&l[i]);
			break;


			case 12:
			odwroc(&l[i]);
			break;

			case 13:
			l[i] = odwroc_r(l[i], NULL, NULL);
			break;




			case 10:
			WyswietlListe(l[i]);
			break;

			case 11:
			WyswietlOdTylu(l[i]);
			break;

			case 20:
			UPEL(&l[i]);
			break;

			};

	};

};

