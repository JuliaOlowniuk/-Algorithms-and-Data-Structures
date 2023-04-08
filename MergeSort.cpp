// Julia O�owniuk


#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void scalanie(int *tab, int poczatek, int srodek, int koniec)
{
// zmienna pomocnicza 'i' jest u�ywana do przegl�dania lewej tablicy
int i = 0;
// zmienna pomocnicza 'j' jest u�ywana do przegl�dania prawej tablicy
int j = 0;
// zmienna 'indeks' jest u�ywana do okre�lenia pozycji elementu w tablicy 'tab'
int indeks = poczatek;
// 'rozmiar_lewej' to ilo�� element�w w lewej tablicy
int rozmiar_lewej = srodek - poczatek + 1;
// 'rozmiar_prawej' to ilo�� element�w w prawej tablicy
int rozmiar_prawej = koniec - srodek;
// tworzymy dwie pomocnicze tablice 'lewaTab' i 'prawaTab'
int lewaTab[rozmiar_lewej], prawaTab[rozmiar_prawej];
// kopiujemy elementy z pierwotnej tablicy 'tab' do lewej tablicy 'lewaTab'
for (i = 0; i < rozmiar_lewej; i++)
    lewaTab[i] = tab[poczatek + i];
// kopiujemy elementy z pierwotnej tablicy 'tab' do prawej tablicy 'prawaTab'
for (j = 0; j < rozmiar_prawej; j++)
    prawaTab[j] = tab[srodek + 1 + j];

// ustawiamy indeksy 'i' i 'j' na 0
i = 0; j = 0;

// dop�ki 'i' jest mniejsze od rozmiaru lewej tablicy i 'j' jest mniejsze od rozmiaru prawej tablicy
while (i < rozmiar_lewej && j < rozmiar_prawej)
{
    // je�li element lewej tablicy jest mniejszy lub r�wny elementowi prawej tablicy
    if (lewaTab[i] <= prawaTab[j])
        // kopiujemy element lewej tablicy do tablicy 'tab'
        tab[indeks++] = lewaTab[i++];
    else
        // w przeciwnym razie kopiujemy element prawej tablicy do tablicy 'tab'
        tab[indeks++] = prawaTab[j++];
}

// kopiujemy pozosta�e elementy z lewej tablicy do tablicy 'tab'
while (i < rozmiar_lewej)
tab[indeks++] = lewaTab[i++];
// kopiujemy pozosta�e elementy z prawej tablicy do tablicy 'tab'
while (j < rozmiar_prawej)
tab[indeks++] = prawaTab[j++];
}

void sortowanie_przez_scalanie(int *tab, int poczatek, int koniec)
{
// je�li pocz�tek jest mniejszy od ko�ca
if (poczatek < koniec)
{
// obliczamy �rodek ci�gu
int srodek = (poczatek + koniec) / 2;
// wywo�ujemy rekurencyjnie sortowanie dla lewej cz�ci ci�gu
sortowanie_przez_scalanie(tab, poczatek, srodek);
// wywo�ujemy rekurencyjnie sortowanie dla prawej cz�ci ci�gu
sortowanie_przez_scalanie(tab, srodek + 1, koniec);
// scalamy posortowane cz�ci ci�gu
scalanie(tab, poczatek, srodek, koniec);
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
    sortowanie_przez_scalanie(tab,0,iloscLiczb-1);
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
