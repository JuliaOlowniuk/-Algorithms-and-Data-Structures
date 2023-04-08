// Julia O³owniuk 


#include  <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void radixSort(int tab[], int n) {
    // znajdowanie najwiêkszej wartoœci w tablicy
    int max = tab[0];
    for (int i = 1; i < n; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }

    int e = 1; // zmienna e jest potrzebna do przesuwania siê po cyfrach
    int wyjscie [n]; // tablica wyjœciowa
    while (max/e> 0) {
        int licz[10] = {0}; // tablica liczników
        for (int i = 0; i < n; i++) {
            licz [(tab[i]/e)%10]++;
        }

        // akumulacja liczników
        for (int i = 1; i < 10; i++) {
            licz[i] += licz[i-1];
        }

        // tworzenie wyjœciowej tablicy
        for (int i = n-1; i >= 0; i--) {
            wyjscie [licz[(tab[i]/e)%10]-1] = tab[i];
            licz[(tab[i]/e)%10]--;
        }

        // przepisanie wyjœciowej tablicy do tablicy wejœciowej
        for (int i = 0; i < n; i++) {
            tab[i] = wyjscie[i];
        }

        e *= 10; // przesuniêcie do nastêpnej cyfry
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
radixSort(tab, iloscLiczb);
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
