#include <allegro5/allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\bitmap.h>
#include <allegro5\bitmap_draw.h>
#include <allegro5\allegro_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

struct kamienie
{
	int x;
	int y;
	int bitmapax;
	int bitmapay;
	int docelowabitmapax;
	int docelowabitmapay;
	int wartosc;
};
void generowanie_tablicy(kamienie kamienietab[8][8],int plansza_x,int plansza_y);
void elementtablicy(int posofmouseX, int posofmouseY, int* X, int *Y,int plansza_x,int plansza_y);
void sprawdzanie_tablicy(kamienie kamienietab[8][8],int *score,bool *sprawdzanieplanszy,bool* przesuwanie);
void rysowanietablicy(kamienie kamienietab[8][8], int plansza_x, int plansza_y, ALLEGRO_BITMAP* pierwszy, ALLEGRO_BITMAP* drugi, ALLEGRO_BITMAP* trzeci, ALLEGRO_BITMAP* czwarty, ALLEGRO_BITMAP* piaty);
void przesuwanie(kamienie kamienietab[8][8], bool* sprawdzanieplanszy, bool* przesuwanie, int* wiersz);
