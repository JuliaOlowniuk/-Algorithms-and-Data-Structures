// Julia O�owniuk

#include  <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void combSort(int x[], int n) 
{
    // zmienna luka jest gapem
    int luka = n;
    // zmienna zamienione jest u�ywana do sprawdzenia czy by�a wykonana jakakolwiek zamiana
    bool zamienione = true;
  
    //p�tla dzia�a dop�ki gap jest wi�kszy od 1 lub ostatnie przej�cie spowodowa�o zamian�
    while (luka != 1 ||zamienione == true) 
	{
       // obliczanie kolejnego gapu
       luka = (luka * 10) / 13;
        if (luka < 1)
		 {
           luka = 1;
        }
       zamienione = false;
  
        // por�wnanie element�w z aktualnym gapem
        for (int i = 0; i < n - luka; i++) 
		{
            if (x[i] > x[i + luka])
			 {
                // zamiana element�w przy u�yciu pomocniczej zmiennej obecny
                int obecny = x[i];
                x[i] = x[i + luka];
                x[i + luka] = obecny;
                zamienione = true;
            }
        }
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
combSort(tab, iloscLiczb);
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
