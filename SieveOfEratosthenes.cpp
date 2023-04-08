//O³owniuk Julia 
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
struct wezel // struktura wezla
{
    bool dane;
    int indeks;
    wezel *nast;
};
 
struct list   // struktura listy   
{
    wezel *pierwszy;
    wezel *ostatni;
    int rozmiar;
};
 
void sprawdzWskaznik(void *wsk)  // sprawdzono wskaznik
 {
    if(wsk == NULL) {exit(EXIT_FAILURE);}
}
 
list zrobListe()  // funkcja tworzaca nowa liste
{
    list nowaLista;
    nowaLista.pierwszy = NULL;
    nowaLista.ostatni = NULL;
    nowaLista.rozmiar=0;         //Ustaw rozmiar na 0 
    return nowaLista;
}
 
void dodajDoOgona(list &list, bool wartosc, int indeks) // dodano wartosc na koniec
{
    wezel *nowyWezel = (wezel*)calloc(1, sizeof(wezel));         //Przydziel pamiec dla nowej wartosci
    sprawdzWskaznik(nowyWezel);
    nowyWezel->dane = wartosc;                            //Zmien dane w wartosc
    nowyWezel->indeks = indeks;
    nowyWezel->nast = NULL;         //To jest ostatniwa wartosc(NULL)
 
    if(list.pierwszy==NULL)
   {                          //Jeœli jest to pierwsza wartoœæ - zapisz adres zarówno w nag³ówku na pierwszym, jak i ogonie (ostatnim)
    list.pierwszy=nowyWezel;
    list.ostatni=nowyWezel;
   }
    else
 {
    	
    list.ostatni->nast = nowyWezel;
    list.ostatni=nowyWezel;
    }
    list.rozmiar++;           //Inkrementacja rozmiaru listy
    return;
}
 
void uzupListe(list &in, int n) // wypelniono liste
{
    for(int i=0;i<n;i++)
	{
        dodajDoOgona(in, true, i); // w petli dodajemy do ogona
    }
}
 
void drukListe(list &list)   
{                                  //Drukuj Liste
    sprawdzWskaznik(&list);
    wezel *wsk=list.pierwszy->nast->nast; // Algorytm zaczyna sie od 3 elementu (od 2 )
 
    for(int i=0;wsk!=NULL;i++)  
    {                            //Przejdz po liscie krok po kroku
    if(wsk->dane==1) 
	cout<<wsk->indeks<<" ";
    wsk = wsk->nast;
    }
}
 
 
int main()
{
 
    list lista = zrobListe(); //tworze liste 
    cout<<"Podaj liczbe:"<<endl; // Uzytkownik podaje liczbe do ktorej maja zostac wyswietlone 
                                 //liczby pierwsze (zgodnie z algorytmem) z zadanego przedzialu
    int x;
    cin>>x;
    int sqrtX = ceil(sqrt(x));
 
    uzupListe(lista, x);  //uzupelniam liste
 
    wezel *wsk = lista.pierwszy->nast->nast;
 
    for(int i=2;i<sqrtX; i++)
	{
if( wsk->dane)
{
wezel *wsk2 = wsk;
for(int j=0, y=2, z=i+1; j<x;y++)
{
    j=y*i;
while(wsk2 != NULL)
{
 if(z==j+1)
  {
   wsk2->dane=false;
   break;
    }
   z++;
   wsk2 = wsk2->nast;
    }
   }
    }
   wsk=wsk->nast;
    }
    drukListe(lista);  //drukuje liste na konsole
 
    return 0;
}
