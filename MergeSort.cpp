// Julia O³owniuk


#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void scalanie(int *tab, int poczatek, int srodek, int koniec)
{
// zmienna pomocnicza 'i' jest u¿ywana do przegl¹dania lewej tablicy
int i = 0;
// zmienna pomocnicza 'j' jest u¿ywana do przegl¹dania prawej tablicy
int j = 0;
// zmienna 'indeks' jest u¿ywana do okreœlenia pozycji elementu w tablicy 'tab'
int indeks = poczatek;
// 'rozmiar_lewej' to iloœæ elementów w lewej tablicy
int rozmiar_lewej = srodek - poczatek + 1;
// 'rozmiar_prawej' to iloœæ elementów w prawej tablicy
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

// dopóki 'i' jest mniejsze od rozmiaru lewej tablicy i 'j' jest mniejsze od rozmiaru prawej tablicy
while (i < rozmiar_lewej && j < rozmiar_prawej)
{
    // jeœli element lewej tablicy jest mniejszy lub równy elementowi prawej tablicy
    if (lewaTab[i] <= prawaTab[j])
        // kopiujemy element lewej tablicy do tablicy 'tab'
        tab[indeks++] = lewaTab[i++];
    else
        // w przeciwnym razie kopiujemy element prawej tablicy do tablicy 'tab'
        tab[indeks++] = prawaTab[j++];
}

// kopiujemy pozosta³e elementy z lewej tablicy do tablicy 'tab'
while (i < rozmiar_lewej)
tab[indeks++] = lewaTab[i++];
// kopiujemy pozosta³e elementy z prawej tablicy do tablicy 'tab'
while (j < rozmiar_prawej)
tab[indeks++] = prawaTab[j++];
}

void sortowanie_przez_scalanie(int *tab, int poczatek, int koniec)
{
// jeœli pocz¹tek jest mniejszy od koñca
if (poczatek < koniec)
{
// obliczamy œrodek ci¹gu
int srodek = (poczatek + koniec) / 2;
// wywo³ujemy rekurencyjnie sortowanie dla lewej czêœci ci¹gu
sortowanie_przez_scalanie(tab, poczatek, srodek);
// wywo³ujemy rekurencyjnie sortowanie dla prawej czêœci ci¹gu
sortowanie_przez_scalanie(tab, srodek + 1, koniec);
// scalamy posortowane czêœci ci¹gu
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
