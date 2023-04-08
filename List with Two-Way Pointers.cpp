//O³owniuk Julia 
#include <iostream>
#include <fstream>

using namespace std;

struct wizytowka  // struktura wizytowki 
{
    string Nazwisko;
    string Imie;
    int telefon;
};

struct lista // truktura listy
{
    lista *prev;
    wizytowka W;
    lista *next;
};

void uzupDane(lista &L) // uzupelnianie danych
{
    cout<<"Nazwisko: ";
    cin>>L.W.Nazwisko;
    cout<<"Imie: ";
    cin>>L.W.Imie;
    cout<<"Numer telefonu: ";
    cin>>L.W.telefon;

}
void dod(lista **pierwszy) //Dodnie elementow
{
    lista *obecny=*pierwszy;
    if(*pierwszy==NULL)
	{
        *pierwszy=new lista;
        uzupDane(**pierwszy);
        (*pierwszy)->next=NULL;
        (*pierwszy)->prev=NULL;
    }
    else{
        lista *nowaLista=new lista;
        uzupDane(*nowaLista);
        while(obecny->next!=NULL)
		{
            obecny=obecny->next;
        }
        nowaLista->next=NULL;
        nowaLista->prev=obecny;
        obecny->next=nowaLista;
    }
}

void szukaj(lista *pierwszy)  // Wyszukiwanie wedlug nazwiska
{
    string Nazwisko;
    cout<<"Podaj nazwisko osoby ktora chcesz wyszukac: ";
    cin>>Nazwisko;
    lista *obecny=pierwszy;
    while(obecny!=NULL)
	{
        if(obecny->W.Nazwisko==Nazwisko)
		{
                cout<<"Nazwisko: "<<obecny->W.Nazwisko<<endl;
                cout<<"Imie: "<<obecny->W.Imie<<endl;
                cout<<"Numer telefonu: "<<obecny->W.telefon<<endl;
               
        }
        obecny=obecny->next;
    }
}

void sortuj(lista *pierwszy)  // Sortowanie w kolejnosci alfabetycznej
 {
     lista *i, *j, *obecny;
     string tmp_nazwisko;
     string tmp_imie;
     int tmp_nr;
     
     for(i=pierwszy; i->next!=NULL; i=i->next)
	 {
         for(j=i->next; j!=NULL; j=j->next)
		 {
             if(i->W.Nazwisko>j->W.Nazwisko)
			 {
      	
                 tmp_nazwisko = j->W.Nazwisko;
                 tmp_imie = j->W.Imie;
                 tmp_nr = j->W.telefon;
                 
                 j->W.Nazwisko = i->W.Nazwisko;
                 j->W.Imie = i->W.Imie;
                 j->W.telefon= i->W.telefon;
                 
                 
                 i->W.Nazwisko = tmp_nazwisko;
                 i->W.Imie = tmp_imie;
                 i->W.telefon = tmp_nr;     
             }
         }
     }
 }


void wypisz_liste_A_Z(lista* pierwszy) // wypisz od a do z 
{ 
    lista *obecny=pierwszy;
    while(obecny!=NULL)
	{
        
        cout<<"Nazwisko: "<<obecny->W.Nazwisko<<endl;
        cout<<"Imie: "<<obecny->W.Imie<<endl;
        cout<<"Numer telefonu: "<<obecny->W.telefon<<endl;
       
        obecny=obecny->next;
    }
}

void wypisz_liste_Z_A(lista* pierwszy)  //  wypisanie listy od z do a
{
    lista *obecny=pierwszy;
    while(obecny->next!=NULL)
	{		
        obecny=obecny->next;  // wskaznik na koniec listy
    }
    while(obecny!=NULL)
	{
    
        cout<<"Nazwisko: "<<obecny->W.Nazwisko<<endl;
        cout<<"Imie: "<<obecny->W.Imie<<endl;
        cout<<"Numer telefonu: "<<obecny->W.telefon<<endl;
        
        obecny=obecny->prev;
    }
}


void usun(lista** pierwszy)
{ // usuwanie elementu wedle nazwiska
	string tmp_nazwisko;
	cout<<"Podaj nazwisko osoby, ktorej wizytowke chcesz usunac:"<<endl;
	cin>>tmp_nazwisko;
    lista *obecny =*pierwszy;      //przechowanie poczatku listy
    lista *prev;

    if (obecny!=NULL&&obecny->W.Nazwisko==tmp_nazwisko) 
	{                                                    //Przypadek gdy wartosc do usuniecia jest na poczatku listy
        *pierwszy=obecny->next;
        obecny->prev=NULL;
        return;
    }

    
    while (obecny!=NULL&&obecny->W.Nazwisko!=tmp_nazwisko)  //Poszukiwaniie wartosci do usuniecia, zapamietujac wskaznik na poprzedni element
	{
        prev=obecny;
        obecny=obecny->next;
    }                              
    if (obecny == NULL)  //Wyjscie z funkcji gdy nie znajduje sie w niej szukana wartosc
	{
        return;
    }                          
    prev->next=obecny->next;    //Odlaczenie elementu listy od listy
    obecny->next->prev=prev;
}

  
void zapisz_do_pliku(lista* pierwszy)     // Zapis do pliku 
{
	
	fstream plik;
	plik.open("rekordy.txt", ios::out);		//stworzenie b¹dŸ nadpisanie pliku rekordy.txt
	
    lista *obecny=pierwszy;

    //Wypisanie listy od A do Z
    while(obecny!=NULL)
	{
        	
      
        plik<<"Nazwisko: "<<obecny->W.Nazwisko<<endl;
        plik<<"Imie: "<<obecny->W.Imie<<endl;
        plik<<"Numer telefonu: "<<obecny->W.telefon<<endl;
       
        obecny=obecny->next;
    }
    plik.close();
}

 int main()
 {
 	
   lista *lista_wizytowek=NULL;
   setlocale(LC_CTYPE, "Polish");
   int petla=1, data, powrot, ktory;
   while (petla) 
   {
   	   printf("Menu listy: \n");
   	   printf("\t0. Zakoñcz\n");
	   printf("\t1. Dodaj element:\n"); 
	   printf("\t2. Usun element:\n");
	   printf("\t3. Szukaj wizytowki:\n");
	   printf("\t4. Posortuj elementy listy od A do Z \n");
		printf("\t5. Posortuj elementy listy od Z do A \n");
		printf("\t6. Zapisz rekordy do pliku \n");
	   printf("Wybierz operacjê podajac jej numer (0-1): ");
	   scanf("%d",&petla);
	   fflush(stdin);                                           // Czyszczenie buforów 
	   
  switch(petla) 
	   {
		case 0: printf("\n\t Koniec \n\n"); 
				break;
		case 1: printf("\n\t Dodaj element\n \t  podaj dane : \n");
				dod(&lista_wizytowek);	
				//sort(lista_wizytowek);										//po kazdym dodaniu elementu do listy lista zostaje posortowana alfabetycznie
				break;
		case 2: printf("\n\t Usun element\n"); 							
				usun(&lista_wizytowek);
				break;
		case 3: printf("\n\t Znajdz element\n \t   podaj element : \n"); 
				szukaj(lista_wizytowek);
				break;
		case 4: printf("\n\t Lista elementów od A do Z:\n"); 
				wypisz_liste_A_Z(lista_wizytowek);
				break;
				
		case 5: printf("\n\t Lista elementów od A do Z:\n"); 
				wypisz_liste_Z_A(lista_wizytowek);
				break;
				
		case 6: printf("\n\t Zapis do pliku\n"); 
				zapisz_do_pliku(lista_wizytowek);
				break;
				
				
   };
 
   return 0;
 }
}
