//O³owniuk Julia 
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
struct wezel   // struktura wezla 
 {
    bool dane;
    int indeks;
    wezel *nast;
};
 
struct list    // struktura listy 
{
    wezel *pierwszy;
    wezel *ostatni;
    int rozmiar ;
};
 
void sprawdzWskaznik(void *wsk)  // sprawdzam wskaznik 
{
    if(wsk == NULL) {exit(EXIT_FAILURE);}
}
 
list zrobListe()  // stworzenie listy 
{
    list nowaLista;
    nowaLista.pierwszy = NULL;
    nowaLista.ostatni = NULL;
    nowaLista.rozmiar=0;      //Ustaw rozmiar na 0
    return nowaLista;
}
 
void dodDoOgona(list &list, int wartosc, int indeks) // dodaje do ogona
{
    wezel *nowyWezel = (wezel*)calloc(1, sizeof(wezel)); //Przydziel pamiec dla nowej wartosci
    sprawdzWskaznik(nowyWezel);
    nowyWezel->dane = wartosc; //Zmien dane w wartosc
    nowyWezel->indeks = indeks;
    nowyWezel->nast = NULL; // To ostattnia wartosc (NULL)
 
    if(list.pierwszy==NULL)
      {                       //Jeœli jest to pierwsza wartoœæ - zapisz adres zarówno w nag³ówku, jak i ogonie
        list.pierwszy=nowyWezel;
        list.ostatni=nowyWezel;}
    else {
        list.ostatni->nast = nowyWezel;
        list.ostatni=nowyWezel;
    }
    list.rozmiar++; //Inkrementacja rozmiaru listy
}
 
void wypelnijListe(list &in, int n) // wypelnienie listy 
{
    for(int i=0;i<n;i++)
      {
        dodDoOgona(in, false, i); // za pomoca dodawania kolejnych liczb do ogona 
    }
}
 
 
int main()
{
    unsigned int n, a, b, c, bb, cc, d, i=0; // zmienne pomocnicze do rownania kwadratowego, bb kwadrat wartosci b , cc kwadrat wartosci c 
    list lista = zrobListe();
    cout<<"Podaj liczbe:"<<endl;  //uzytkownik podaje liczbe do ktorej chce wyswietlic liczby pierwsze z przedzialu 2 do n (podanej liczby)
    cin >> n;
    
    if(n<1)
      {
    cout<<"n poza przedzialem"<<endl;
    return 0;
    }
    if(n<=2)    // wypisuje za pomoca cout liczby pierwsze jakie wyswietla sie do podanej liczby, aczkolwiek sa niezalezne od dzialania algorytmu 
      {
    cout<<endl;
   return 0;
    }
    if(n==3)   // wypisuje za pomoca cout liczby pierwsze jakie wyswietla sie do podanej liczby, aczkolwiek sa niezalezne od dzialania algorytmu 
      {
    cout<<"2"<<endl;    
    return 0;
    }

    if(n<6)   // wypisuje za pomoca cout liczby pierwsze jakie wyswietla sie do podanej liczby, aczkolwiek sa niezalezne od dzialania algorytmu 
      {
    cout<<"2 3 "<<endl;
return 0;
    }
 
    wypelnijListe(lista, n);
    a = ceil( sqrt ( n ) ); //
    for( b = 1; b <= a; b++ )
    {
  bb = b * b; // bb=b^2
for( c = 1; c <= a; c++ )
    {

cc = c * c; //cc=c^2
d = ( bb << 2 ) + cc;
wezel *wsk = lista.pierwszy;
 if( ( d <= n ) && ( ( d % 12 == 1 ) || ( d % 12 == 5 ) ) ) // instrukcja warunkowa zgodna z dzialaniem algorytmu
 {
    while(wsk!=NULL)
      {
    if(wsk->indeks==d)
      {
    wsk->dane = !wsk->dane;
    break;
   }
  wsk=wsk->nast;
 }
}
d -= bb;
wsk = lista.pierwszy;
if( ( d <= n ) && ( d % 12 == 7 ) )   // instrukcja warunkowa zgodna z dzialaniem algorytmu
 {
    while(wsk!=NULL)
      {
 if(wsk->indeks==d)
 {
wsk->dane = !wsk->dane;
    break;
}
wsk=wsk->nast;
}
    }
    if( b > c )
    {
d -= cc << 1;
wsk = lista.pierwszy;
if( ( d <= n ) && ( d % 12 == 11 ) ) // instrukcja warunkowa zgodna z dzialaniem algorytmu
{
    while(wsk!=NULL)
      {
    if(wsk->indeks==d)
      {
    wsk->dane = !wsk->dane;
 break;
   }
   wsk=wsk->nast;
   }
    }
    }
    }
      
    }
    wezel *wsk = lista.pierwszy;
    while(wsk->indeks<5 && wsk!=NULL) wsk=wsk->nast;
    i=5;
    while(wsk!=NULL && i<a)
      {
     if(wsk->dane)
    {
bb = i * i;
d = bb;
while( d <= n )
{
wezel *wsk2 = wsk;
   while(wsk2!=NULL)
    {
    if(wsk2->indeks==d)
      {
wsk2->dane = false;
   break;
   }
wsk2=wsk2->nast;
    }
d += bb;
    }
    }
    wsk=wsk->nast;
    i++;
    }
    cout << 2 << " " << 3 << " " ; // wypisuje za pomoca cout liczby pierwsze jakie wyswietla sie do podanej liczby, aczkolwiek sa niezalezne od dzialania algorytmu 
    wsk = lista.pierwszy;          // pierwsza piatka jako liczba pierwsza wyswietli sie ale to wynika z funkcji
    while(wsk!=NULL)
      {
    if(wsk->dane)
      {
   cout<<wsk->indeks<<" ";
   }
wsk=wsk->nast;
    }
    return 0;
}
