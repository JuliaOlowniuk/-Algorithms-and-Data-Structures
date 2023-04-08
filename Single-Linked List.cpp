//O³owniuk Julia 
#include <iostream>
#include <stdlib.h>>
using namespace std; 
typedef struct Node // struktura wezla
{
    int num;
    struct Node* nast; // wskaznik na nastepny element 
} Lista;


 wypelnij(Lista *&pierwszy,int wartosc)
{
	Lista *wskaznik;
	Lista *Node1;
wskaznik= (Lista*)malloc (sizeof(Lista));
Node1=(Lista*)malloc (sizeof(Lista));
	Node1->nast=NULL;
	Node1->num=wartosc;
	wskaznik=pierwszy;
    if (wskaznik)
    {
    	while (wskaznik->nast) wskaznik = wskaznik->nast;
    	wskaznik->nast = Node1;
	}
	else pierwszy = Node1;
}

void pokaz(Lista * pierwszy) // Wyswietl zawartosc listy
{
	if (pierwszy == NULL) 
	{
	cout<< "Lista pusta";
    } 
	else{
	
		Lista* obecny = pierwszy;
		do{
			cout << obecny->num<< ", ";
			obecny = obecny->nast;
		}while (obecny != NULL);

	}
	cout << endl;
}

void liczSrednia(Lista * pierwszy)  // Srednia
{
	double suma = 0;
	if (pierwszy == NULL) 
	cout<< "Lista pusta, srednia to 0";
	else{
		Lista* obecny = pierwszy;
		do{
			suma = suma + (obecny->num);
			obecny = obecny->nast;
		}while (obecny != NULL); // procedura przejscia 
	
	}
	cout <<"Srednia w tej liscie: " << suma/100 << endl;;
}
void liczSrednia1(Lista * pierwszy)  // Srednia
{
	double suma = 0;
	if (pierwszy == NULL) 
	cout<< "Lista pusta, srednia to 0";
	else{
		Lista* obecny = pierwszy;
		do{
			suma = suma + (obecny->num);
			obecny = obecny->nast;
		}while (obecny != NULL); // procedura przejscia 
	
	}
	cout <<"Srednia w tej liscie: " << suma/50 << endl;;
}

void usun_el (Lista **pierwszy, int z) //Usun element
{
	Lista *y;
    Lista *usun= *pierwszy;
    if (z == 1)
    {
    	Lista *obecny = *pierwszy;
    	
    	if (obecny)
    	{
    		*pierwszy = obecny->nast; //  w tym wywolaniu funkcji nastepuje procedura powstawania nowego wezla glowa 
    		delete obecny; 
		}
	}
    if(z == usun->num)
      {
          y = usun ;
          usun = usun->nast;
      }
    else
    {
        Lista *obecny = *pierwszy;
        while(obecny->nast != NULL) // null bo go nie ma
        {
            if(z == obecny-> nast->num)
            {
                y = obecny->nast;
                obecny->nast = obecny->nast->nast;
                break;
            }
            else
            {
            obecny = obecny->nast;
            }
          }
      }
}

int main()
{
	Lista *pierwszy = NULL; // Zawiera adres poczatku listy
	
	int z;
	
	for (int i = 1; i<=  100; i++) //Petla pozwalajaca wypelnc listy kolejnymi wartosciami
	{
		wypelnij(pierwszy, i);
	}

	pokaz(pierwszy);    // na terminalu wyswietlaja sie wszystkie elementy 
	
	liczSrednia(pierwszy); // liczona jest srednia
	
	for (int i = 1; i <= 100; i++)
	{
		if (i%2 == 1) // petla usuwajaca nieparzyste elementy 
		usun_el(&pierwszy, i);  // tutaj jeszcze dodatkowo wywolana jest funkcja usuwajaca pierwszy element z listy 
	}
	pokaz(pierwszy); // ponownie wyswietla sie lista 
	
	liczSrednia1(pierwszy);// oraz liczona jest srednia z tych obecnych elementow
	
return 0;
}


