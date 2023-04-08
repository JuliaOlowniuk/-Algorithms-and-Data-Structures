// O³owniuk Julia 


#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
 // Funkcja podziel s³u¿y do podzia³u tablicy na dwie czêœci
int podziel(int tab[], int x, int z) 
{
    // y to element bêd¹cy punktem podzia³u
    int y = tab[x]; 
    int i = x, j = z;

    while (true)
    {
        // Przeszukujemy od koñca tablicy, szukaj¹c elementów mniejszych ni¿ y
        while (tab[j] > y) // dopoki elementy sa wieksze od x
            j--;
        // Przeszukujemy od pocz¹tku tablicy, szukaj¹c elementów wiêkszych ni¿ y
        while (tab[i] < y) // dopoki elementy sa mniejsze od x
            i++;

        // Jeœli indeksy i, j siê nie przecinaj¹ to zamieniamy elementy tablicy
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
            // Jeœli przecinaj¹ siê, zwracamy indeks punktu podzia³u
            return j;
        }
    }
}

// Funkcja quickSort s³u¿y do sortowania tablicy
void quickSort(int tab[], int p, int r) 
{
    int a;
    if (p < r)
    {  
        // Dzielimy tablicê na dwie czêœci i sortujemy ka¿d¹ z nich rekurencyjnie
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

