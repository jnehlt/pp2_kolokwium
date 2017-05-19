/* Sterta */

#include <stdlib.h>
#include <stdio.h>

struct ObszarAlokatora;

struct ObszarAlokatora
{
//  Header(){}
//  ~Header(){}
  struct ObszarAlokatora* Poprzedni;
  struct ObszarAlokatora* Nastepny;
  //ObszarAlokatora* KoniecBlokuDanych;
  int SumaKontrolna;
};  // 22bajty - jeśli SumaKontrolna to MD5

struct ObszarGlownegoAlokatora
{
  struct ObszarAlokatora OA;
  int PrzestrzenNaZmienne;
};

int main(void)
{
  int sterta[1024*64];
  struct ObszarGlownegoAlokatora *pstart = (struct ObszarGlownegoAlokatora *)sterta;
  struct ObszarAlokatora *phead = (struct ObszarAlokatora *)(sterta + sizeof(struct ObszarGlownegoAlokatora));
  struct ObszarAlokatora *pend = (struct ObszarAlokatora *)(sterta - sizeof(struct ObszarAlokatora));

  printf("%p\n%p\n", pstart, phead);
/*
  allokacja miejsca dla bloku zarezerwowanego oraz bloku konca sterty
*/

  return 0;
}
