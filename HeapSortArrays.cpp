//Julia O�owniuk 


#include  <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void heapify(int tab[], int n, int i)
{
    int najwiekszy = i; // indeks najwi�kszego elementu
    int l = 2*i + 1; // indeks lewego dziecka
    int r = 2*i + 2; // indeks prawego dziecka
 
    // sprawdzanie czy lewy lub prawy element jest wi�kszy od aktualnego
    if (l < n && tab[l] > tab[najwiekszy])
        najwiekszy = l;
 
    if (r < n && tab[r] > tab[najwiekszy])
        najwiekszy = r;
 
    // zamiana miejscami je�li znaleziony element jest wi�kszy od aktualnego
    if (najwiekszy != i)
    {
        int obecny = tab[i];
        tab[i] = tab[najwiekszy];
        tab[najwiekszy] = obecny;
 
        heapify(tab, n, najwiekszy); // rekurencyjne dostosowanie kopca
    }
}

void heapSort(int tab[], int n)
{
    // Tworzenie kopca
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(tab, n, i);
 
    // Przesuwanie najwi�kszego elementu na koniec tablicy
    for (int i=n-1; i>=0; i--)
    {
        int obecny= tab[0];
        tab[0] = tab[i];
        tab[i] = obecny;
 
        heapify(tab, i, 0); // dostosowanie kopca po przesuni�ciu elementu
    }
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
heapSort(tab, iloscLiczb);
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
