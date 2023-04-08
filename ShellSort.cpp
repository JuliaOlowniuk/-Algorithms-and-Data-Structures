//O³owniuk Julia 


#include  <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int sortowanieShell(int tablica[], int n)
{
// Ustaw pocz¹tkowy rozmiar podlisty na po³owê d³ugoœci tablicy
int a = n / 2;
// Dopóki rozmiar podlisty jest wiêkszy od 0, iteruj przez nie
while (a > 0)
    {
// Iteruj przez elementy podlisty
for (int i = a; i < n; i++)
{
// Zapisz obecny element do zmiennej tymczasowej
int obecny = tablica[i];
// Ustaw indeks j na obecny indeks elementu
int j = i;
// Dopóki j jest wiêksze lub równe rozmiarowi podlisty i element podlisty jest wiêkszy od obecnego elementu:
while (j >= a && tablica[j - a] > obecny)
{
// Przenieœ element podlisty o indeksie j - a do pozycji j
tablica[j] = tablica[j - a];
// Zmniejsz indeks j o rozmiar podlisty
j -= a;
}
// Wstaw obecny element na pozycjê j
tablica[j] = obecny;
}
 // Zmniejsz rozmiar podlisty o po³owê
 a /= 2;
}
return 0;
}
int main()
{    
srand( time( NULL ) );//losowanie
int iloscLiczb, i,max,min,zakres;
cout << "Podaj liczbe elementow do posortowania:"<<endl;
cin >> iloscLiczb;
cout<<"Podaj dolna granice zakresu losowania:"<<endl;
cin>>min;
cout<<"Podaj gorna granice zakresu losowania:"<<endl;
cin>>max;
zakres=max-min+1;
int* tab = (int*)malloc(iloscLiczb * sizeof(int));// utworzenie dynamicznej tablicy elementow
if (tab == NULL) // sprawdŸ, czy alokacja powiod³a siê
{
    cout << "Alokacja pamiêci nie powiod³a siê!" << endl;
    exit(1); // zakoñcz z b³êdem
}
for (i = 0; i < iloscLiczb; i++) // wczytywanie liczb do tablicy
{
tab[i]=((rand()% zakres) + min);
}
cout<<"Nieposortowana tablica:"<<endl;
for (i = 0; i < iloscLiczb; i++) // wypisanie nieposortowanej tablicy
{
  cout <<tab[i] <<"  ";
if((i+1) % 10 == 0)
{
cout<<endl;
}
    }
sortowanieShell(tab, iloscLiczb);
cout<<endl;
cout<<"Posortowana tablica:"<<endl;
    for (i = 0; i < iloscLiczb; i++) // wypisanie posortowanej tablicy
    {
cout <<tab[i] <<"  ";
if((i+1) % 10 == 0)
{
cout<<endl;
}
    }
    delete [] tab;
    return 0;
}
