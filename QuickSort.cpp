// O�owniuk Julia 


#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
 // Funkcja podziel s�u�y do podzia�u tablicy na dwie cz�ci
int podziel(int tab[], int x, int z) 
{
    // y to element b�d�cy punktem podzia�u
    int y = tab[x]; 
    int i = x, j = z;

    while (true)
    {
        // Przeszukujemy od ko�ca tablicy, szukaj�c element�w mniejszych ni� y
        while (tab[j] > y) // dopoki elementy sa wieksze od x
            j--;
        // Przeszukujemy od pocz�tku tablicy, szukaj�c element�w wi�kszych ni� y
        while (tab[i] < y) // dopoki elementy sa mniejsze od x
            i++;

        // Je�li indeksy i, j si� nie przecinaj� to zamieniamy elementy tablicy
        if (i < j) 
        {
            int w = tab[i];
            tab[i] = tab[j];
            tab[j] = w;
            i++;
            j--;
        }
        else 
        {
            // Je�li przecinaj� si�, zwracamy indeks punktu podzia�u
            return j;
        }
    }
}

// Funkcja quickSort s�u�y do sortowania tablicy
void quickSort(int tab[], int p, int r) 
{
    int a;
    if (p < r)
    {  
        // Dzielimy tablic� na dwie cz�ci i sortujemy ka�d� z nich rekurencyjnie
        a = podziel(tab,p,r); 
        quickSort(tab, p, a); 
        quickSort(tab, a+1, r);
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
quickSort(tab,0, iloscLiczb-1);
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

