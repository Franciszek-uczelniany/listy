#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define NR 2

void usun_i(lista* l) {
    if(*l==NULL) return;
    lista t = *l; //aby nie modyfikować głowy
    lista rem;
    while (t->nast) {
            if(t->nast->klucz == t->klucz) {
                // usuń następny element
                rem = t->nast;
				//
                if(t->nast->klucz != t->klucz) {
					 t->nast = rem->nast;
					 free(rem);
					continue;}
				else if(t->nast->nast && t->nast->nast->klucz == t->klucz) {

				t->nast = rem->nast->nast;
                free(rem->nast);
				free(rem);
				continue;
            }
            t = t->nast;
    }

}}

 int main(int argc, char* argv [])  {
	 lista l[NR] = {0, 0};
	int wybor = 0;
	int w2;
	int i=0;
	int ret;

	while(1) {

	printf("\n Wybierz operacje: \n"
       " 0 - wyjscie \n"
       " 1 - Dodaj do posortowanej listy\n"

       " 3 - Pobierz pierwszy element listy \n" 
       " 4 - Pobierz ostatni element listy \n"
       " 5 - Odszukaj zadany element \n"
		"6 - usun powtarzajace sie elementy iteracyjnie"
       " 7 - Usun wskazany element / elementy \n"
       " 8 - Wczytaj zawartosc listy z pliku \n"
       " 9 - Zapisz zawartosc listy do pliku \n"
       " 10 - Wyswietl zawartosc listy \n"
       " 11 - Wyswietl od konca \n"
       " 12 - Odwroc iteracyjnie \n"
       " 13 - Odwroc rekurencyjnie \n\n"
       " 14 - Polacz dwie listy w jedna \n"
       " 20 - Usun pierwszy element listy \n"
       " 21 - Porownaj obie listy \n"
       " 44 - Zmien zlapana liste \n"


	" Obecnie zlapana lista: %d \n", i);




		printf("\n wybor = ");
		scanf("%d", &wybor);
		switch(wybor) {

			case 44:
			i=++i%NR;
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
			ret = odszukaj(&l[i], wybor);
			if(ret > 0) printf("\n zadany el. jest %d w liscie", ret); else 
			printf("\n nie znaleziono tego elementu");
			break;

			case 6:
			usun_i(&l[i]);
						WyswietlListe(l[i]);
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
			l[i] = odwroc_r(l[i]);
			break;




			case 10:
			WyswietlListe(l[i]);
			break;

			case 11:
			WyswietlOdTylu(l[i]);
			break;

			case 14:
			//undeclared join(l[0], l[1]);
			i=0;
			break;

			case 20:
			UPEL(&l[i]);
			break;

			case 21:
			porownaj(l[0], l[1]);
			break;

			};

	};

};

