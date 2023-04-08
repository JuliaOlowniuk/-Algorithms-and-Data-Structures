// Julia O³owniuk

#include  <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void combSort(int x[], int n) 
{
    // zmienna luka jest gapem
    int luka = n;
    // zmienna zamienione jest u¿ywana do sprawdzenia czy by³a wykonana jakakolwiek zamiana
    bool zamienione = true;
  
    //pêtla dzia³a dopóki gap jest wiêkszy od 1 lub ostatnie przejœcie spowodowa³o zamianê
    while (luka != 1 ||zamienione == true) 
	{
       // obliczanie kolejnego gapu
       luka = (luka * 10) / 13;
        if (luka < 1)
		 {
           luka = 1;
        }
       zamienione = false;
  
        // porównanie elementów z aktualnym gapem
        for (int i = 0; i < n - luka; i++) 
		{
            if (x[i] > x[i + luka])
			 {
                // zamiana elementów przy u¿yciu pomocniczej zmiennej obecny
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
