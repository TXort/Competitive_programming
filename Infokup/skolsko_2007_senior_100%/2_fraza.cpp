
/*
  Skolsko natjecanje 2007
  Srednjoskolska skupina - 2. podskupina
  Zadatak FRAZA
  Programski jezik C/C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

#define MAXPAPIRICA   50
#define MAXPOZICIJA   10
#define MAXDULJINA   10
#define MAXFRAZA   10

char rijec[MAXPAPIRICA][MAXDULJINA + 1];
int kojaRijec[MAXPAPIRICA * MAXPOZICIJA];
int fraza[MAXFRAZA];

int main ( void )
{
   int brojPapirica, brojRijeciSkrivenogTexta = 0;

   // ucitaj rijeci, spremi ih u polje rijec
   // u kojaRijec[i] zapamti redni broj rijeci koja se nalazi na poziciji i
   scanf ("%d", &brojPapirica);
   for (int papiric = 0; papiric < brojPapirica; papiric++)
   {
      int brojRijeciNaPapiricu;
      scanf ("%s %d", rijec[papiric], &brojRijeciNaPapiricu);

      for (int i = 0; i < brojRijeciNaPapiricu; i++)
      {
         int pozicija;
         scanf ("%d", &pozicija);

         if (brojRijeciSkrivenogTexta < pozicija)
            brojRijeciSkrivenogTexta = pozicija;

         kojaRijec[pozicija-1] = papiric;
      }
   }

   // ucitaj frazu, otkrij na kojem papiricu je koja rijec iz fraze
   // -> redni broj papirica zapisi u polje fraza
   int brojRijeciUFrazi = 0;
   char rijecUFrazi[MAXDULJINA + 1];
   while (scanf ("%s", rijecUFrazi) == 1)
   {
      int i;
      for (i = 0; i < brojPapirica; i++)
         if (strcmp (rijec[i], rijecUFrazi) == 0)
            break;

      fraza[brojRijeciUFrazi] = i;
      brojRijeciUFrazi++;
   }

   // prebroji koliko ima podnizova
   int brojPojavljivanja = 0;
   for (int pocetak = 0; pocetak <= brojRijeciSkrivenogTexta - brojRijeciUFrazi; pocetak++)
   {
      int dobroJe = 1;
      for (int i = 0; i < brojRijeciUFrazi && dobroJe; i++)
         if (fraza[i] != kojaRijec[pocetak + i])
            dobroJe = 0;

      if (dobroJe) brojPojavljivanja++;
   }

   printf ("%d\n", brojPojavljivanja);

   return 0;
}
