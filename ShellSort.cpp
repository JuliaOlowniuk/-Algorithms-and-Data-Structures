//O�owniuk Julia 


#include  <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int sortowanieShell(int tablica[], int n)
{
// Ustaw pocz�tkowy rozmiar podlisty na po�ow� d�ugo�ci tablicy
int a = n / 2;
// Dop�ki rozmiar podlisty jest wi�kszy od 0, iteruj przez nie
while (a > 0)
    {
// Iteruj przez elementy podlisty
for (int i = a; i < n; i++)
{
// Zapisz obecny element do zmiennej tymczasowej
int obecny = tablica[i];
// Ustaw indeks j na obecny indeks elementu
int j = i;
// Dop�ki j jest wi�ksze lub r�wne rozmiarowi podlisty i element podlisty jest wi�kszy od obecnego elementu:
while (j >= a && tablica[j - a] > obecny)
{
// Przenie� element podlisty o indeksie j - a do pozycji j
tablica[j] = tablica[j - a];
// Zmniejsz indeks j o rozmiar podlisty
j -= a;
}
// Wstaw obecny element na pozycj� j
tablica[j] = obecny;
}
 // Zmniejsz rozmiar podlisty o po�ow�
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
if (tab == NULL) // sprawd�, czy alokacja powiod�a si�
{
    cout << "Alokacja pami�ci nie powiod�a si�!" << endl;
    exit(1); // zako�cz z b��dem
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
