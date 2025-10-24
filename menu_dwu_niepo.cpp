#include <stdio.h>
#include <stdlib.h>
// w ustawieniach projektu "lista dwukierunkowa" jest #define dwukierunkowa 1
#include "lista_various.h"
#include "lista_nieposortowana.h"

 int main(int argc, char* argv [])  {
	 lista _l = 0;
	 lista __l=0;
	int wybor = 0;
	int w2, w3;
	int ret;

	while(1) {
		printf("\n Wybierz operacje: \n"
			" 0 - wyjscie \n"
			" 1 - Dodaj na poczatek listy \n"
			" 2 - Dodaj na koniec listy \n"
			" 3 - Usun pierwszy element listy \n"
			" 4 - Usun ostatni element listy \n"
			" 5 - Odszukaj zadany element \n"
			" 6 - Dodaj nowy element przed lub za wskazanym \n"
			" 7 - Usun wskazany element / elementy \n"
			" 8 - Wczytaj zawartosc listy z pliku \n"
			" 9 - Zapisz zawartosc listy do pliku \n"
			" 10 - Wyswietl zawartosc listy \n"
			" 0 - Zakoncz dzialanie programu \n"
		);
// 5 odszukaj zadany element - bez zmian
// 6 tutaj duzo zmian
// 7 chyba nie za duzo zmian, usuwajac musimy ustawic przed->nast na nastepny po usuwanym
// I nastepny->pop na przed. Cale zadanie sprowadza sie do aktualizacji wskaznika pop

		printf("\n wybor = ");
		scanf("%d", &wybor);
		switch(wybor) {

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
			ret = odszukaj(&_l, wybor);
			if(ret > 0) printf("\n zadany el. jest %d w liscie", ret); else
			printf("\n nie znaleziono tego elementu");
			break;

			case 6:
			printf("\n klucz el do odszukania=");
			scanf("%d", &wybor);
			printf("\n klucz do wpisania=");
			scanf("%d", &w2);
			printf("\n 0 - przed,  1 - za szukany element\n");
			scanf("%d", &w3);
			DL(&_l, wybor, w2, w3);
			break;

			case 7:
			printf("\n klucz=");
			scanf("%d", &wybor);
			printf("\n Podaj liczbe el do usuniecia, 0 oznacza wszystkie \n :");
			scanf("%d", &w2);
			if(w2 == 0) w2--;
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
//			WyswietlListe(__l);
			break;

			case 0:
			exit(0);
			break;

			};

	};

};

