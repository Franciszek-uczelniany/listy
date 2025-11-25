#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define NR 2

void usun_i(lista* l) {
    if(*l==NULL) return;
    lista t = *l; //aby nie modyfikować głowy
    lista rem;
    lista p = t;
    // musimy miec p bo nie mozemy zwyczajnie przeskakiwac na nastepny el, bo nie wiem czy on nie jest przypadkiem taki sam
     
    while (t->nast) {
            while(p->nast && p->nast->klucz == t->klucz) {
                // usuń następny element
                rem = p->nast;
                p->nast = rem->nast;
                free(rem);
            }; 
            // kończymy tą pętle i zapisujemy do p kopię wsk.
			// przechodzimy na nastepny (byc moze nie powtarzający sie) element
			t = t->nast; 
            p = t;
    }

}

 int main(int argc, char* argv [])  {
	 lista l[NR] = {0, 0};
	int wybor = 0;
	int w2;
	int nr_listy=0;
	int ret;

	while(1) {

	printf("\n Wybierz operacje: \n"
       " 0 - wyjscie \n"
       " 1 - Dodaj do posortowanej listy\n"
		" 2 - laczenie dwoch list \n"
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


	" Obecnie zlapana lista: %d \n", nr_listy);

		printf("\n wybor = ");
		scanf("%d", &wybor);
		switch(wybor) {

			case 44:
			nr_listy=++nr_listy%NR;
			break;

			case 0:
			exit(0);
			break;

			case 1:
			printf("\n klucz=");
			scanf("%d", &wybor);
			DL_sort(&l[nr_listy], wybor);
			break;

			case 2:
			merge(&l[0], &l[1]);
			printf("\n Lista 0:");
			WyswietlListe(l[0]);
			printf("\n Lista 1:");
			WyswietlListe(l[1]);
			break;

			case 3:
			Wyswietl_Pierwszy(&l[nr_listy]);
			break;

			case 4:
			Wyswietl_Ostatni(&l[nr_listy]);
			break;

			case 5:
			printf("\n klucz =");
			scanf("%d", &wybor);
			ret = odszukaj(&l[nr_listy], wybor);
			if(ret > 0) printf("\n zadany el. jest %d w liscie", ret); else 
			printf("\n nie znaleziono tego elementu");
			break;

			case 6:
			usun_i(&l[nr_listy]);
						WyswietlListe(l[nr_listy]);
			break;

			case 7:
			printf("\n klucz=");
			scanf("%d", &wybor);
			printf("\n Podaj liczbe el do usuniecia, 0 oznacza wszystkie \n :");
			scanf("%d", &w2);
			if(w2==0) w2--;
			UEL_k(&l[nr_listy], wybor, w2);
			break;

			case 8:
			Wczytaj(&l[nr_listy], nr_listy == 0 ? "lista.txt" : "lista2.txt");
			break;

			case 9:
			Zapisz(&l[nr_listy], nr_listy == 0 ? "lista.txt" : "lista2.txt");
			break;


			case 12:
			odwroc(&l[nr_listy]);
			break;

			case 13:
			l[nr_listy] = odwroc_r(l[nr_listy]);
			break;




			case 10:
			WyswietlListe(l[nr_listy]);
			break;

			case 11:
			WyswietlOdTylu(l[nr_listy]);
			break;

			case 14:
			//undeclared join(l[0], l[1]);
			nr_listy=0;
			break;

			case 20:
			UPEL(&l[nr_listy]);
			break;

			case 21:
			porownaj(l[0], l[1]);
			break;

			};

	};

};

