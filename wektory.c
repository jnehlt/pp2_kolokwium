#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct wspolrzedne wsp_t;
typedef struct wektor wektor_t;

struct wspolrzedne
{
  float X;
  float Y;
};

struct wektor
{
  wsp_t poczatek;
  wsp_t koniec;
  float dlugosc;
};

char zapisz_do_pliku(const wektor_t* wektor);    // spróbuj później z zapytaniem o nazwę pliku
wektor_t* odczytaj_z_pliku(const wektor_t* wektor);   // tu też: char* nazwa_pliku
wektor_t* oblicz_dlugosc_wektora(const wektor_t* wektor);
wektor_t* stworz_wektory(wektor_t* wektor, float, float, float, float);

int main(void)
{
  srand(time(NULL));
  wektor_t* wektor = NULL;
  wektor = stworz_wektory(wektor, (20 + 14) * ((float)rand() / RAND_MAX) - 14, (20 + 14) * ((float)rand() / RAND_MAX) - 14, (20 + 14) * ((float)rand() / RAND_MAX) - 14, (20 + 14) * ((float)rand() / RAND_MAX) - 14);
  if(!zapisz_do_pliku(wektor))
  {
    printf("Problem z zapisem do pliku. Konczenie programu...\n\n");
    return 1;
  }

  return 0;
}

char zapisz_do_pliku(const wektor_t* wektor)
{
  if (!wektor)
  {
    return 0; //pusty wektor
  }
  FILE* plik;
  if (!(plik = fopen("wektory.txt", "r")))
  {
    printf("Plik nie istnieje...\nTworzenie nowego.\n\n");
    plik = fopen("wektory.txt", "w");
    fprintf(plik, "%f ", wektor->poczatek.X);
    fprintf(plik, " %f\n", wektor->poczatek.Y);
    fprintf(plik, "%f ", wektor->koniec.X);
    fprintf(plik, "%f)\n", wektor->koniec.Y);
  }
  else
  {
    fclose(plik);
    plik = fopen("wektory.txt", "a+");
    fseek(plik, 0, 2);
    fprintf(plik, "%f ", wektor->poczatek.X);
    fprintf(plik, " %f\n", wektor->poczatek.Y);
    fprintf(plik, "%f ", wektor->koniec.X);
    fprintf(plik, "%f\n", wektor->koniec.Y);
  }


  if(plik) return 1;
  fclose(plik);
  return 0;
}

wektor_t* stworz_wektory(wektor_t* wektor, float Px, float Py, float Kx, float Ky)
{
  if(wektor = (wektor_t*)malloc(sizeof(wektor_t)))
  {
    printf("%f   %f   %f   %f\n\n",   wektor->poczatek.X = Px, wektor->poczatek.Y = Py, wektor->koniec.X = Kx, wektor->koniec.Y = Ky);
  }
  return wektor;
}
