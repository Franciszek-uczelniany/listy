#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


void  Wczytaj(lista *l) {
    // Zwolnij listę
    ZL(l);
    
   
    FILE *file = fopen("lista.txt", "r");
    if (file == NULL) {
        printf("Nie mozna otworzyc pliku lista.txt\n");
       
    }

    int value;
    while (fscanf(file, "%d", &value) == 1) {
        DNKL(l, value);
    }

    fclose(file);
    
    
}

void Zapisz(lista *l) {
  
    FILE *file = fopen("lista.txt", "w");
    if (file == NULL) {
        printf("Nie można otworzyc pliku lista.txt do zapisu\n");
        return;
    }


	lista i = *l;


    while (i) {
        fprintf(file, "%d\n", i->klucz);
        i = i->nast; 
    }

    
    fclose(file);
}


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


lista odwroc_r(lista l, lista prev, lista next) {
    if (l) {
        next = l->nast;
        l->nast = prev;
        return odwroc_r(next, l, NULL);
    } else {
        return prev;
    }
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

// Funkcja: wyświetl listę w odwrotnej kolejności
void WyswietlOdTylu(lista l) {
    if (l == NULL) {
        return;  
    }
    
    WyswietlOdTylu(l->nast);  // rekurencyjnie przechodzimy do końca listy
    
    // Po powrocie z rekurencji wyświetlamy wartości w odwrotnej kolejności
    printf("%d-", l->klucz);
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

1 - za element
0 - przed

*/
void DL(lista *l, int szukany, int nowy, int side) {

	if(*l==0) return;

	lista p = *l;
	while(p && p->nast && p->nast->klucz != szukany) p = p->nast;

 // Nie znaleziono
	if(!(p->nast) || p->nast->klucz != szukany) return; 

	lista k = (lista) malloc(sizeof(lista));
	k->klucz = nowy;

	if (side == 1) {
		p = p->nast;
		k->nast = p->nast;
		p->nast = k;
	} else if (side == 0) {
		k->nast = p->nast;
		p->nast = k;
	};
};





/*
Funkcja: Usun Element Listy - k

Usuwa z kolejki element/-y z kluczem równym k.

Opcjonalny argument: Liczba wystąpień k, które mają zostać usunięte.
					 0 oznacza każde wystąpienie


Wersja iteracyjna

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
Funkcja: Usun Element Listy - k

Usuwa z kolejki element/-y z kluczem równym k.

Opcjonalny argument: Liczba wystąpień k, które mają zostać usunięte.
					 -1 oznacza każde wystąpienie


Wersja rekurencyjna

*/

void UELR_k( lista *l, int k, int ilosc_razy) {

  if(!(*l)) {
   return;
  };  

if(ilosc_razy == 0) return;

	if( (*l)-> klucz == k) {
		UPEL(l);
		if (ilosc_razy != -1) ilosc_razy--;
		UELR_k(l, k, ilosc_razy);
	}

	else {

	 l = &(*l)->nast;
	 UELR_k(l, k, ilosc_razy);
	

	};


};

 /* 
 Funkcja: Usun Pierwszy Element Listy
 
 Usuwa pierwszy element wskazany przez wskaznik l.
 
 
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
		while ((*l) && (*l)->nast) l = &(*l)->nast;
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





