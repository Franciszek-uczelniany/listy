#include <stdio.h>
#include <stdlib.h>     
#include "lista.h"


 int main(int argc, char* argv [])  {
	 lista _l = 0;
	 lista __l=0;
	int wybor = 0;
	int w2, w3;
	unsigned short num_el;
	bool bin;

	while(1) {
		
		printf("\n Wybierz operacje: \n 0 - wyjscie \n 1 - Dodaj na poczatek listy \n 2 - Dodaj na koniec listy  \n 3 - Usun pierwszy element listy \n 4 - Usun ostatni element listy \n 5 - odszukaj zadany element \n 6 - dodaj nowy element przed lub za wskazanym  \n 7 - usun wskazany element \n 7.1 - usun wszystkie wskazane elementy \n 8 - wczytaj zawartosc listy z pliku \n 9 - zapisz zawartosc listy do pliku \n 10 - wyswietl zawartosc listy  \n 11 - posortuj \n 12 - odwroc iteracyjnie \n13 - odwroc rekurencyjnie\n   \n");
		printf("\n wybor = ");
		scanf("%d", &wybor);
		switch(wybor) {

			case 0:
			exit(0);
			break;

			case 1:
			printf("\n klucz=");
			scanf("%d", &wybor);
			DNPL(&_l, wybor);
			break;

			case 2:
			printf("\n klucz=");
			scanf("%d", &wybor);
			DNKL(&_l, wybor);
			break;
			
			case 3:
			UPEL(&_l);
			break;
			
			case 4:
			UOEL(&_l);
			break;

			case 5:
			printf("\n klucz =");
			scanf("%d", &wybor);
			printf("\n zadany el. jest %u w liscie", odszukaj(&_l, wybor));
			break;

			case 6:
			printf("\n klucz el do odszukania=");
			scanf("%d", &wybor);
			printf("\n klucz do wpisania=");
			scanf("%d", &w2);
			printf("\n Czy przed wskazanym? 1 - tak\n");
			scanf("%d", &w3);
			
			w2 == 1? DNPL(przesun(&_l, wybor, 1), w2) : DL(przesun(&_l, wybor, 1), w2);
			
			break;

			case 7:
			printf("\n klucz=");
			scanf("%d", &wybor);
			UEL_k(&_l, wybor, 1);
			break;

			case 8:
			Wczytaj(&_l);
			break;

			case 11:
			posortuj(&_l, &__l);
			break;

			 

		


			case 12:
			odwroc(&_l);
			break;

		//	odwroc_r(&_l, NULL, NULL);
			_l = odwroc_r(_l, NULL, NULL);
			break;




			case 10:
			WyswietlListe(_l);
			WyswietlListe(__l);
			break;
			};

	};

};

