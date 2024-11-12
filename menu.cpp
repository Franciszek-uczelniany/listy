#include <stdio.h>
#include <stdlib.h>     
#include "lista.h"


 int main(int argc, char* argv [])  {
	 lista _l = 0;
	 lista __l=0;
	int wybor = 0;
	int w2, w3;


	while(1) {
		
		// Lista bez wartownika
		
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
       " 13 - Odwroc rekurencyjnie \n\n");

		printf("\n wybor = ");
		scanf("%d", &wybor);
		switch(wybor) {

			case 0:
			exit(0);
			break;

			case 1:
			printf("\n klucz=");
			scanf("%d", &wybor);
			DL_sort(&_l, wybor);
			break;
			
			case 3:
			Wyswietl_Pierwszy(&_l);
			break;
			
			case 4:
			Wyswietl_Ostatni(&_l);
			break;

			case 5:
			printf("\n klucz =");
			scanf("%d", &wybor);
			printf("\n zadany el. jest %u w liscie", odszukaj(&_l, wybor));
			break;

			case 7:
			printf("\n klucz=");
			scanf("%d", &wybor);
			printf("\n Podaj liczbe el do usuniecia, 0 oznacza wszystkie \n :");
			scanf("%d", &w2);
			UEL_k(&_l, wybor, w2);
			break;
			
			case 8:
			Wczytaj(&_l);
			break;
			
			case 9:
			Zapisz(&_l);
			break;


			case 12:
			odwroc(&_l);
			break;

			case 13:
			_l = odwroc_r(_l, NULL, NULL);
			break;




			case 10:
			WyswietlListe(_l);
			break;

			case 11:
			WyswietlOdTylu(_l);
			break;

			};

	};

};

