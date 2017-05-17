/*

    1.zapytac uzytkownika o liczbe
    2.zaalokowac pamiec na tablice typu char o rozmiarze podanym przez uzytkownika (chodzi o u�ycie calloc())
    3.wypelnic tablice losowymi malymi literami
    4.napisac funkcje ktora zamieni male samogloski na duze
    5.zwolnic pamiec

*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define min 97
#define max 123

void podaj_liczbe(int*);
char* allokuj(int);
void wypelnij(char*, int);
void zamien_na_duze(char*, int);
void wyswietl(char*);

int main(void){
    int liczba;
    char *tablica;

    podaj_liczbe(&liczba);
    if(liczba < 1){
        printf("zly zakres\n");
        system("PAUSE");
        return 2;
    }
    tablica = allokuj(liczba);
    if(tablica == NULL){
        printf("Ups.. Cos poszlo nie tak\n");
        system("PAUSE");
        return 1;
    }
    //wypelnij(allokuj(liczba), liczba);
    wypelnij(tablica, liczba);
    printf("\n\n");
    zamien_na_duze(tablica, liczba);
    free(tablica);

    return 0;
}

void podaj_liczbe(int *liczba){
    printf("Podaj liczbe:   ");
    scanf("%d", liczba);

    return;
}

char* allokuj(int liczba){
    char *p;
    p = (char*)calloc(liczba, sizeof(char));
    return p;
}

void wypelnij(char *tablica, int liczba){
    int i=0;
    while(i < liczba){
        *(tablica+i) = (max - min) * rand() / RAND_MAX + min;
        wyswietl(tablica+i);
        ++i;
    }
    return;
}

void wyswietl(char *tablica){
    printf("  %c   adres: %d\n", *(tablica), (tablica));
    return;
}

void zamien_na_duze(char *tablica, int liczba){
    int i=0;
    char znak;
    while(i<liczba){
        znak = *(tablica+i);
        if(znak == 'a' || znak == 'e' || znak == 'i' || znak == 'o' || znak == 'u' || znak == 'y'){
          *(tablica+i) -= ' ';
        }
        wyswietl(tablica+i);
        ++i;
    }
    return;
}
