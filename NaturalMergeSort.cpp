// Julia O�owniuk  


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

int i;
int j;
// Zmienna globalna, kt�ra przechowuje nazw� pliku
char nazwaPliku[25];

// Zmienna globalna, kt�ra przechowuje wska�nik do pliku
FILE *plikWe = NULL;

// Zmienna globalna, kt�ra okre�la, czy jest to pierwsze uruchomienie sortowania
bool pierwszeU = false;

// Funkcja, kt�ra wy�wietla zawarto�� pliku
void wyswietlPlik()
{
	int x,n=0;
	plikWe= fopen(nazwaPliku,"r");
	
	// Wczytanie kolejnych liczb z pliku i wy�wietlenie ich na ekranie
	while(fscanf(plikWe,"%d",&x)!=EOF)
	{
		printf("%d ",x);
		n++;
		if(n%10 == 0)
			printf("\n");
	}
	
	printf("\n");
}

// Funkcja, kt�ra sprawdza, czy plik jest posortowany
bool sprawdzPosort() 
{
	plikWe = fopen(nazwaPliku,"r");
	int x,y; 
	if(plikWe) 
	{
		rewind(plikWe); 
		fscanf(plikWe,"%d",&x); 
		while(fscanf(plikWe,"%d",&y)!=EOF) 
		{
			if(y<x)
			{
				fclose(plikWe);
				return false; 
			}
			
			x = y;
		}
		fclose(plikWe);
		return true; 
		
	}
	fclose(plikWe);
	return false; 
}

// Funkcja, kt�ra przesuwa bufor o jedno miejsce
void przesunBuffor(int buffor[]) 
{
	buffor[0]= buffor[1];
	buffor[1]= buffor[2];
}
// Funkcja sortuj�ca plik
void sort(FILE* plikWe) 
{
plikWe = fopen(nazwaPliku,"r");
FILE *plik_1 = NULL;
FILE *plik_2 = NULL;
FILE *curr_plik;
int x,y;
int buffor[3] = {0,0,0};
bool pierwszeU = false;
plik_1 = fopen("dat1.txt","w"); 
plik_2 = fopen("dat2.txt","w");
curr_plik = plik_1; 

rewind(plikWe); 
// Je�li to pierwsze uruchomienie sortowania, nale�y wczyta� pierwsze trzy liczby
if(!pierwszeU) 
    {
    fscanf(plikWe,"%d",&x);
    buffor[1]=x;
    fscanf(plikWe,"%d",&x);
    buffor[2]=x;
    pierwszeU= true;        
    }
// P�tla, kt�ra przetwarza kolejne liczby z pliku
while(fscanf(plikWe,"%d",&x)!=EOF) 
{
	// Sprawdzenie, kt�ra liczba z bufora jest najwi�ksza
    if(buffor[1]>=buffor[0]) 
    {
        fprintf(curr_plik,"%d ",buffor[1]);    
    }
    else if(buffor[1]<=buffor[2]) 
    {
        fprintf(curr_plik,"%d ",buffor[1]);
    }
    else if(buffor[1]>buffor[2]) 
    {
        fprintf(curr_plik,"%d ",buffor[2]);
    }
    // Przesuni�cie bufora o jedno miejsce
    przesunBuffor(buffor);
    buffor[2] = x;
}
// Sprawdzenie, czy trzeba zmieni� plik do zapisu
if(curr_plik == plik_1)
{
    curr_plik = plik_2;
}
else
{
    curr_plik = plik_1;
}
// Zapisanie pozosta�ych liczb z bufora
if(buffor[1] >= buffor[0])
{
    fprintf(curr_plik,"%d ",buffor[1]);
}
else
{
    fprintf(curr_plik,"%d ",buffor[0]);
}

if(buffor[2] >= buffor[1])
{
    fprintf(curr_plik,"%d ",buffor[2]);
}
else
{
    fprintf(curr_plik,"%d ",buffor[1]);
}
// zamykaja sie pliki
fclose(plik_1);
fclose(plik_2);
fclose(plikWe);
}
int main()
{
	bool if_sorted;
	
	printf("Nazwa pliku : ");
	scanf("%s",nazwaPliku);

	printf("Przed sortowaniem:\n");
	wyswietlPlik();
		
	while(!sprawdzPosort())
		sort(plikWe);
					
	printf("Po sortowaniu:\n");
	wyswietlPlik();
	
	printf("Zapisano w posortowanym pliku %s.",nazwaPliku);
	
	return 0;
}
