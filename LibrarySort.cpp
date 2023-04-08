
//O�owniuk Julia 

#include<iostream>
#include <cstdlib>
#include<cstring>
#include <ctime>
#include <algorithm>

using namespace std;

// Funkcja sortuj�ca tablic� liczb ca�kowitych przy u�yciu algorytmu sortowania przez wstawianie
//
// tab - tablica liczb ca�kowitych do posortowania
// n - liczba element�w w tablicy
void sortowanieBiblioteczne(int *tab, int n) 
{
// Zmienne pomocnicze
int lib_size, index_pos, *gaps, *library[2];
bool target_lib, *numbered;
// Alokacja pami�ci dla dw�ch bibliotek
library[0] = (int*)malloc(n * sizeof(int));
library[1] = (int*)malloc(n * sizeof(int));

// Alokacja pami�ci dla tablicy gap�w i zaznaczaj�cej, kt�re elementy s� gapami
gaps = (int*)malloc((n + 1) * sizeof(int));
numbered = (bool*)malloc((n + 1) * sizeof(bool));
memset(numbered, 0, (n + 1) * sizeof(bool));
// Inicjalizacja zmiennych
lib_size = 1;
index_pos = 1;
target_lib = 0;
library[target_lib][0] = tab[0];

// P�tla g��wna sortowania
while (index_pos < n) {
    // Wyszukaj pozycj� do wstawienia nowego elementu za pomoc� wyszukiwania binarnego
   int insert = distance(library[target_lib], lower_bound(library[target_lib], library[target_lib] + lib_size, tab[index_pos]));

    // Je�li na pozycji insert jest ju� gap, to przenie� bibliotek� do drugiej tablicy i wyczy�� gapy
    if (numbered[insert] == true) {
        int prov_size = 0, next_target_lib = !target_lib;

        for (int i = 0; i <= n; i++) {
            if (numbered[i] == true) {
                library[next_target_lib][prov_size] = gaps[i];
                prov_size++;
                numbered[i] = false;
            }

            if (i <= lib_size) {
                library[next_target_lib][prov_size] = library[target_lib][i];
                prov_size++;
            }
        }

        target_lib = next_target_lib;
        lib_size = prov_size - 1;
        }
// W przeciwnym wypadku oznacz pozycj� insert jako gap i dodaj na ni� nowy element
else {
numbered[insert] = true;
gaps[insert] = tab[index_pos];
index_pos++;
}
}
// Przenie� wszystkie elementy z obu bibliotek do tablicy wyj�ciowej
int index_pos_for_output = 0;
for (int i = 0; index_pos_for_output < n; i++) {
    if (numbered[i] == true) {
        tab[index_pos_for_output] = gaps[i];
        index_pos_for_output++;
    }

    if (i < lib_size) {
        tab[index_pos_for_output] = library[target_lib][i];
        index_pos_for_output++;
    }
}

// Zwolnij pami�� zaalokowan� dla bibliotek i tablicy gap�w
free(library[0]);
free(library[1]);
free(gaps);
free(numbered);
}
int main()
{
srand(time(NULL)); //losowanie
int iloscLiczb, i, min, max, zakres;
cout << "Podaj liczbe elementow do posortowania:" << endl;
cin >> iloscLiczb;
cout << "Podaj dolna granice zakresu losowania:" << endl;
cin >> min;
cout << "Podaj gorna granice zakresu losowania:" << endl;
cin >> max;
zakres = max - min + 1;
int* tab = (int*)malloc(iloscLiczb * sizeof(int)); // utworzenie dynamicznej tablicy elementow
if (tab == NULL) // sprawd�, czy alokacja powiod�a si�
{
cout << "Alokacja pami�ci nie powiod�a si�!" << endl;
exit(1); // zako�cz z b��dem
}
for (i = 0; i < iloscLiczb; i++) // wczytywanie liczb do tablicy
{
tab[i] = ((rand() % zakres) + min);
}
cout << "Nieposortowana tablica:" << endl;
for (i = 0; i < iloscLiczb; i++) // wypisanie nieposortowanej tablicy
{
cout << tab[i] << " ";
if ((i + 1) % 10 == 0)
{
cout << endl;
}
}
cout << endl;
// Wywo�anie funkcji sortowanieBiblioteczne
sortowanieBiblioteczne(tab, iloscLiczb);
cout << "Posortowana tablica:" << endl;
for (i = 0; i < iloscLiczb; i++) // wypisanie posortowanej tablicy
{
cout << tab[i] << " ";
if ((i + 1) % 10 == 0)
{
cout << endl;
}
}
cout << endl;
// Zwolnienie pami�ci zaalokowanej dla tablicy
free(tab);
return 0;
}
