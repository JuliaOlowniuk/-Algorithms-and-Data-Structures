
//O³owniuk Julia 

#include<iostream>
#include <cstdlib>
#include<cstring>
#include <ctime>
#include <algorithm>

using namespace std;

// Funkcja sortuj¹ca tablicê liczb ca³kowitych przy u¿yciu algorytmu sortowania przez wstawianie
//
// tab - tablica liczb ca³kowitych do posortowania
// n - liczba elementów w tablicy
void sortowanieBiblioteczne(int *tab, int n) 
{
// Zmienne pomocnicze
int lib_size, index_pos, *gaps, *library[2];
bool target_lib, *numbered;
// Alokacja pamiêci dla dwóch bibliotek
library[0] = (int*)malloc(n * sizeof(int));
library[1] = (int*)malloc(n * sizeof(int));

// Alokacja pamiêci dla tablicy gapów i zaznaczaj¹cej, które elementy s¹ gapami
gaps = (int*)malloc((n + 1) * sizeof(int));
numbered = (bool*)malloc((n + 1) * sizeof(bool));
memset(numbered, 0, (n + 1) * sizeof(bool));
// Inicjalizacja zmiennych
lib_size = 1;
index_pos = 1;
target_lib = 0;
library[target_lib][0] = tab[0];

// Pêtla g³ówna sortowania
while (index_pos < n) {
    // Wyszukaj pozycjê do wstawienia nowego elementu za pomoc¹ wyszukiwania binarnego
   int insert = distance(library[target_lib], lower_bound(library[target_lib], library[target_lib] + lib_size, tab[index_pos]));

    // Jeœli na pozycji insert jest ju¿ gap, to przenieœ bibliotekê do drugiej tablicy i wyczyœæ gapy
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
// W przeciwnym wypadku oznacz pozycjê insert jako gap i dodaj na ni¹ nowy element
else {
numbered[insert] = true;
gaps[insert] = tab[index_pos];
index_pos++;
}
}
// Przenieœ wszystkie elementy z obu bibliotek do tablicy wyjœciowej
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

// Zwolnij pamiêæ zaalokowan¹ dla bibliotek i tablicy gapów
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
if (tab == NULL) // sprawdŸ, czy alokacja powiod³a siê
{
cout << "Alokacja pamiêci nie powiod³a siê!" << endl;
exit(1); // zakoñcz z b³êdem
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
// Wywo³anie funkcji sortowanieBiblioteczne
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
// Zwolnienie pamiêci zaalokowanej dla tablicy
free(tab);
return 0;
}
