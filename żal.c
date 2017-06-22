//śmiechu warte 

#include <stdio.h>
#include <stdlib.h>

struct struktura {
	int id;
	char nazwa[20];
};

FILE* init(struct struktura []);
void dodaj_element(struct struktura [], int, int);
void wyswietl(struct struktura []);
void usun(struct struktura []);
void edytuj(struct struktura []);

//tablica struktur
//mozliwosc dodawania kolejnych elementow do tablicy struktur
//wyswietlanie elementow
//ma 4 mozwliwosc usuwania
//na 5 mozliwosc edycji istniejacych elementow

int main(void)
{
    FILE* plik;
	struct struktura tab[20];

	plik = init(tab);
	dodaj_element(tab, -1, 0);
	wyswietl(tab);
	usun(tab);
	edytuj(tab);
	wyswietl(tab);
	fclose(plik);
	return 0;
}

FILE* init(struct struktura tab[])
{
	int i;
	FILE* plik = fopen("baza.txt", "a+");
	if(!plik)
    {
        printf("ERROR\n\n");
    }
    else
    {
        for(i = 0; i < 20; ++i)
        {
            tab[i].id = 0;
        }
    }
}

void dodaj_element(struct struktura tab[], int ktory, int flag)
{
	int i = 0;

	if(flag)
    {
        printf("EDYCJA\n\n");
        i = ktory;
	}
    else if(i == 19) return;
    else if(i == -1)
    {
        while(tab[i].id){++i;};
    }

	printf("podaj id: ");
	scanf("%d", &tab[i].id);
	fflush(stdin);
	printf("\npodaj nazwe: ");
	scanf("%s", tab[i].nazwa);
	fflush(stdin);
}

void wyswietl(struct struktura tab[])
{
	int i;
	for(i = 0; i < 20; ++i)
	{
		if(tab[i].id) printf("id: %d\nnazwa: %s\n\n", tab[i].id, tab[i].nazwa);
	}
}

void usun(struct struktura tab[])
{
	int numer;
	printf("podaj element ktory chcesz usunac [numerujemy od 1] : ");
	scanf("%d", &numer);
	if(numer > 0 && numer < 20)
	{
	    if(tab[numer-1].id == 0) //nic nie rob
            return;
		tab[numer-1].id = 0;
	}
}

void edytuj(struct struktura tab[])
{
    int ktory;

    printf("Ktory element chcesz edytowac?\n");
    scanf("%d", &ktory);
    dodaj_element(tab, ktory-1, 1);
}
