// Julia O�owniuk 


#include  <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void radixSort(int tab[], int n) {
    // znajdowanie najwi�kszej warto�ci w tablicy
    int max = tab[0];
    for (int i = 1; i < n; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }

    int e = 1; // zmienna e jest potrzebna do przesuwania si� po cyfrach
    int wyjscie [n]; // tablica wyj�ciowa
    while (max/e> 0) {
        int licz[10] = {0}; // tablica licznik�w
        for (int i = 0; i < n; i++) {
            licz [(tab[i]/e)%10]++;
        }

        // akumulacja licznik�w
        for (int i = 1; i < 10; i++) {
            licz[i] += licz[i-1];
        }

        // tworzenie wyj�ciowej tablicy
        for (int i = n-1; i >= 0; i--) {
            wyjscie [licz[(tab[i]/e)%10]-1] = tab[i];
            licz[(tab[i]/e)%10]--;
        }

        // przepisanie wyj�ciowej tablicy do tablicy wej�ciowej
        for (int i = 0; i < n; i++) {
            tab[i] = wyjscie[i];
        }

        e *= 10; // przesuni�cie do nast�pnej cyfry
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
