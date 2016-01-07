#include "Header.h"
void rysowanietablicy(kamienie kamienietab[8][8], int plansza_x, int plansza_y, ALLEGRO_BITMAP* pierwszy, ALLEGRO_BITMAP* drugi, ALLEGRO_BITMAP* trzeci, ALLEGRO_BITMAP* czwarty, ALLEGRO_BITMAP* piaty)
{
	int pomoc=10;
	for (int j = 0; j < 8; j++)
		for (int i = 0; i < 8; i++)
			switch (kamienietab[i][j].wartosc)
		{
			case 0:
				if (!(kamienietab[i][j].bitmapax==kamienietab[i][j].docelowabitmapax))
				{
					if ((kamienietab[i][j].docelowabitmapax-kamienietab[i][j].bitmapax)>0)
					{
						kamienietab[i][j].bitmapax = kamienietab[i][j].bitmapax  + pomoc;
					}
					else if ((kamienietab[i][j].docelowabitmapax - kamienietab[i][j].bitmapax)<0)
					{
						kamienietab[i][j].bitmapax = kamienietab[i][j].bitmapax -pomoc;
					}
				}
				if (!(kamienietab[i][j].bitmapay == kamienietab[i][j].docelowabitmapay))
				{
					if ((kamienietab[i][j].docelowabitmapay - kamienietab[i][j].bitmapay)>0)
					{
						kamienietab[i][j].bitmapay = kamienietab[i][j].bitmapay + pomoc;
					}
					else if ((kamienietab[i][j].docelowabitmapay - kamienietab[i][j].bitmapay)<0)
					{
						kamienietab[i][j].bitmapay = kamienietab[i][j].bitmapay - pomoc;
					}
				}
				al_draw_bitmap(pierwszy, kamienietab[i][j].bitmapax, kamienietab[i][j].bitmapay, NULL);
				break;
			case 1:
				if (!(kamienietab[i][j].bitmapax == kamienietab[i][j].docelowabitmapax))
				{
					if ((kamienietab[i][j].docelowabitmapax - kamienietab[i][j].bitmapax)>0)
					{
						kamienietab[i][j].bitmapax = kamienietab[i][j].bitmapax + pomoc;
					}
					else if ((kamienietab[i][j].docelowabitmapax - kamienietab[i][j].bitmapax)<0)
					{
						kamienietab[i][j].bitmapax = kamienietab[i][j].bitmapax - pomoc;
					}
				}
				if (!(kamienietab[i][j].bitmapay == kamienietab[i][j].docelowabitmapay))
				{
					if ((kamienietab[i][j].docelowabitmapay - kamienietab[i][j].bitmapay)>0)
					{
						kamienietab[i][j].bitmapay = kamienietab[i][j].bitmapay + pomoc;
					}
					else if ((kamienietab[i][j].docelowabitmapay - kamienietab[i][j].bitmapay)<0)
					{
						kamienietab[i][j].bitmapay = kamienietab[i][j].bitmapay - pomoc;
					}
				}
				al_draw_bitmap(drugi, kamienietab[i][j].bitmapax, kamienietab[i][j].bitmapay, NULL);
				break;
			case 2:
				if (!(kamienietab[i][j].bitmapax == kamienietab[i][j].docelowabitmapax))
				{
					if ((kamienietab[i][j].docelowabitmapax - kamienietab[i][j].bitmapax)>0)
					{
						kamienietab[i][j].bitmapax = kamienietab[i][j].bitmapax + pomoc;
					}
					else if ((kamienietab[i][j].docelowabitmapax - kamienietab[i][j].bitmapax)<0)
					{
						kamienietab[i][j].bitmapax = kamienietab[i][j].bitmapax - pomoc;
					}
				}
				if (!(kamienietab[i][j].bitmapay == kamienietab[i][j].docelowabitmapay))
				{
					if ((kamienietab[i][j].docelowabitmapay - kamienietab[i][j].bitmapay)>0)
					{
						kamienietab[i][j].bitmapay = kamienietab[i][j].bitmapay + pomoc;
					}
					else if ((kamienietab[i][j].docelowabitmapay - kamienietab[i][j].bitmapay)<0)
					{
						kamienietab[i][j].bitmapay = kamienietab[i][j].bitmapay - pomoc;
					}
				}
				al_draw_bitmap(trzeci, kamienietab[i][j].bitmapax,kamienietab[i][j].bitmapay, NULL);
				break;
			case 3:
				if (!(kamienietab[i][j].bitmapax == kamienietab[i][j].docelowabitmapax))
				{
					if ((kamienietab[i][j].docelowabitmapax - kamienietab[i][j].bitmapax)>0)
					{
						kamienietab[i][j].bitmapax = kamienietab[i][j].bitmapax + pomoc;
					}
					else if ((kamienietab[i][j].docelowabitmapax - kamienietab[i][j].bitmapax)<0)
					{
						kamienietab[i][j].bitmapax = kamienietab[i][j].bitmapax - pomoc;
					}
				}
				if (!(kamienietab[i][j].bitmapay == kamienietab[i][j].docelowabitmapay))
				{
					if ((kamienietab[i][j].docelowabitmapay - kamienietab[i][j].bitmapay)>0)
					{
						kamienietab[i][j].bitmapay = kamienietab[i][j].bitmapay + pomoc;
					}
					else if ((kamienietab[i][j].docelowabitmapay - kamienietab[i][j].bitmapay)<0)
					{
						kamienietab[i][j].bitmapay = kamienietab[i][j].bitmapay - pomoc;
					}
				}
				al_draw_bitmap(czwarty,kamienietab[i][j].bitmapax,kamienietab[i][j].bitmapay, NULL);
				break;
			case 4:
				if (!(kamienietab[i][j].bitmapax == kamienietab[i][j].docelowabitmapax))
				{
					if ((kamienietab[i][j].docelowabitmapax - kamienietab[i][j].bitmapax)>0)
					{
						kamienietab[i][j].bitmapax = kamienietab[i][j].bitmapax + pomoc;
					}
					else if ((kamienietab[i][j].docelowabitmapax - kamienietab[i][j].bitmapax)<0)
					{
						kamienietab[i][j].bitmapax = kamienietab[i][j].bitmapax - pomoc;
					}
				}
				if (!(kamienietab[i][j].bitmapay == kamienietab[i][j].docelowabitmapay))
				{
					if ((kamienietab[i][j].docelowabitmapay - kamienietab[i][j].bitmapay)>0)
					{
						kamienietab[i][j].bitmapay = kamienietab[i][j].bitmapay + pomoc;
					}
					else if ((kamienietab[i][j].docelowabitmapay - kamienietab[i][j].bitmapay)<0)
					{
						kamienietab[i][j].bitmapay = kamienietab[i][j].bitmapay - pomoc;
					}
				}
				al_draw_bitmap(piaty, kamienietab[i][j].bitmapax,kamienietab[i][j].bitmapay, NULL);
				break;
		}
}
