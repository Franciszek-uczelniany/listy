#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//todo: dodac wczytaj, zapisz do plkku



// Funkcja: Zwolnij liste

void ZL (lista *l) {

	while((*l)) UOEL(l);

};


// Funkcja: iteracyjne odwracanie listy

void odwroc(lista *l) {

	lista prev = NULL;
	lista cur = *l;
	lista next = NULL;

	while(cur){
		next=cur->nast;
		cur -> nast = prev;
		prev = cur;
		cur = next;

	}

	*l=prev;


return;

}




// Funkcja: rekurencyjne odwracanie listy

/*
lista* odwroc_r( lista* l, lista* prev, lista* next) {

	if( (*l) ) {

		*next = (*l)->nast;
		(*l)->nast = *prev;
		*prev = *l;
		*l = *next;

		l = odwroc_r(l,prev,next);

	} else *l = *prev;

	// ostatnie wywołanie
	return l;


}
*/

lista odwroc_r(lista l, lista prev, lista next) {
    if (l) {
        next = l->nast;
        l->nast = prev;
        return odwroc_r(next, l, NULL);
    } else {
        return prev;
    }
}





void wczytaj (lista *l, const char *plik) {

	ZL(l);
//	FILE *ret = (const char)fopen(*plik, "r");
//	if(ret == 0) {perror(""); return;};
	

	char buff[10];

//	while (fgets(buffer, sizeof(buffer), file) != NULL) {





//	fgets(&buff, 1, ret);
}


// Funkcja: wyswietla listę w odwrotnej kolejności

void WyswietlOdTylu(lista l) {
    if (l == NULL) {
        return;  
    }
    
    WyswietlOdTylu(l->nast);  // rekurencyjnie przechodzimy do końca listy
    
    // Po powrocie z rekurencji wyświetlamy wartości w odwrotnej kolejności
    printf("%d-", l->klucz);


}

 /* 
 Funkcja: Przesun wskaznik na liste na lub za wskazany element
 1 - Na. Domyslna opcja.
 
 
	kiedy jest "na" a nie "przed", prosciej zaimllementowac dodawanie el. przed lub za wskazanym
 
 */
lista* przesun(lista *l, int k, int side) {

	if(!(*l)) return l;
	lista *ret = l;


	while ((*ret) && (*ret)->nast && (*ret)->klucz != k) {
		ret = &(*ret)->nast;
	}


// Sprawdzamy, czy znaleziono element z kluczem k
    if ((*ret) && (*ret)->klucz == k) {
        if (side != 1) {
            if ((*ret)->nast) ret = &(*ret)->nast;
		

        }
    } else {
        printf("\n Nie znaleziono elementu o kluczu %d\n", k);
	return l;
    };



  return ret;

};

/*
Funkcja: Odszukaj

Wynik: numer elementu z kluczem równym k.


*/




unsigned short odszukaj(lista *l, int k) {

	unsigned short ret = 1;
	lista _l = *l;
	while(_l) {

		if(_l->klucz == k) break;
		_l = _l->nast;
		ret++;
};


	return ret;

};

void WyswietlListe( lista _lista)  { 

	 lista l = _lista;
	 while (l){ 
		 printf ("%d-", l->klucz);
		 l = l->nast;
		 } ;
 printf ("|\n");
 };

/* 
Funkcja: Dodaj Na Poczatek Listy

*/
void DNPL(lista *l, int i)
 { 
	if (l==0) return;
	 lista p = ( lista )malloc(sizeof( elListy ));
	 p->klucz = i;
	 p->nast = *l;
	 *l = p;
 };


/* 
Funkcja: Dodaj Na Koniec Listy

*/

void DNKL(lista *l, int i)  { 
	if(l==0) return;
	 lista p = ( lista )malloc(sizeof( elListy ));
	p->klucz = i;
	 p->nast = 0;	
	 while ((* l )) l = &(*l)->nast;
 *l = p;
 };

/*
Funkcja: Dodaj do Listy

Dodaje element za wskazany element

*/
void DL(lista *l, int k) {
	
	if(l==0) return;
	lista *nast_prev = &(*l)->nast;
	lista p = (lista) malloc(sizeof(lista));
	p->klucz = k;
	p->nast = *nast_prev;
	(*l)->nast = p;
};


/*
Funkcja: Usun Element Listy - k

Usuwa z kolejki element/-y z kluczem równym k.

Opcjonalny argument: Liczba wystąpień k, które mają zostać usunięte.
					 0 oznacza każde wystąpienie

*/

void UEL_k( lista *l, int k, int ilosc_razy) {

  if(!(*l)) {
   printf("\n Lista pusta"); 
   return;
  };
  
  if(ilosc_razy != 0) ilosc_razy++;


  lista p;
  lista *i = l;
	
	do {
		
	
		if((*i)->klucz == k) {
			p = *i;
			(*i) = (*i)->nast;
			free(p); 
			if(ilosc_razy != 0) { 
					ilosc_razy--;
				}
			continue;
		};
		i = &(*i)->nast;
		
	} while((*i) && ilosc_razy != 1);
		
	
};

 /* 
 Funkcja: Usun Pierwszy Element Listy
 
 Usuwa pierwszy element wskazany przez wskaznik ll.
 
 
 */

void UPEL(lista *l) {
	
	lista p;
	if((*l)) {
		p = *l;
		*l = (*l)->nast;
		free(p);
	};
	
};


 /* 
 Funkcja: Usun Ostatni Element Listy
 
 */

void UOEL(lista *l) {
	
	if((*l)) {
			while ((*l) && (*l)->nast) {
				l = &(*l)->nast;
			};
		free(*l);
		*l = 0;
		}

	
};
/*
  Funkcja: Usun wskazany element listy

  Usuwa k-ty element

*/

void U_wsk(lista *l, int k) {
	if(l==0) return;
	int i = 1;
	lista *p = l;
	while(i != k && (*p)) {
		p=&(*p)->nast;
		i++;
	};
	UPEL(p);

};

/* 
 Funkcja: posortuj
 
 Sortuje listę dzieląc ją na dwie: z elementami parzystymi i nieparzystymi.
 
 
 */

//TODO:poprawic kiedy jest pierwszy element parzysty, to nie mozemy go usunac
// jak jest pierwszy i ostatni 
void posortuj(lista *l, lista *l2) {

  // Tworzymy wskaźnik ponieważ nie będziemy modyfikować l, który jest zarówno
  // argumentem tej funkcji, jak i wielu innych funkcji. Będziemy iterować
  // po p.
	lista *p = l;


	int n=0;

	while((*p)) {
	
	

		if((*p)->klucz %2 == 0) {
			DNKL(l2, (*p)->klucz);
			UPEL(p);


		// Po usunięciu wskaźnik p automatycznie wskazuje na następny element,
            // więc nie ma potrzeby przeskakiwania na kolejny element ręcznie.
        } else {
            p = &(*p)->nast;  // Jeśli element nie został usunięty, przechodzimy na nastepny recznie

	};
};


};


