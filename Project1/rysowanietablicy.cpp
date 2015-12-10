#include "Header.h"
void rysowanietablicy(int tab[8][8], int plansza_x, int plansza_y, ALLEGRO_BITMAP* pierwszy, ALLEGRO_BITMAP* drugi, ALLEGRO_BITMAP* trzeci, ALLEGRO_BITMAP* czwarty, ALLEGRO_BITMAP* piaty)
{
	for (int j = 0; j < 8; j++)
		for (int i = 0; i < 8; i++)
			switch (tab[i][j])
		{
			case 0:
				al_draw_bitmap(pierwszy, i * 50 + plansza_x, j * 50 + plansza_y, NULL);
				break;
			case 1:
				al_draw_bitmap(drugi, i * 50 + plansza_x, j * 50 + plansza_y, NULL);
				break;
			case 2:
				al_draw_bitmap(trzeci, i * 50 + plansza_x, j * 50 + plansza_y, NULL);
				break;
			case 3:
				al_draw_bitmap(czwarty, i * 50 + plansza_x, j * 50 + plansza_y, NULL);
				break;
			case 4:
				al_draw_bitmap(piaty, i * 50 + plansza_x, j * 50 + plansza_y, NULL);
				break;
		}
}
