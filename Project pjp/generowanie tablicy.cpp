#include "Header.h"
void generowanie_tablicy(kamienie kamienietab[8][8],int plansza_x,int plansza_y)
{
	bool powtozenie = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			kamienietab[i][j].wartosc = rand() % 4;
			kamienietab[i][j].x = i;
			kamienietab[i][j].y = j;
			kamienietab[i][j].bitmapax = i*50+plansza_x;
			kamienietab[i][j].bitmapay =  j*50+plansza_y;
			kamienietab[i][j].docelowabitmapax = i * 50+plansza_x;
			kamienietab[i][j].docelowabitmapay = j * 50+plansza_y;
		}
	}
	start:
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
			if (kamienietab[i][j - 2].wartosc == kamienietab[i][j - 1].wartosc &&kamienietab[i][j - 2].wartosc == kamienietab[i][j].wartosc)
			{
				for (int k = 0; k < 3; k++)
				{
					kamienietab[i][j + k - 2].wartosc = 4;

				}
			}
			else if (kamienietab[i - 2][j].wartosc == kamienietab[i - 1][j].wartosc && kamienietab[i - 2][j].wartosc == kamienietab[i][j].wartosc)
			{
				for (int k = 0; k < 3; k++)
				{
					kamienietab[i + k - 2][j].wartosc = 4;
				}
			}
			}
		powtozenie = false;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (kamienietab[i][j].wartosc==4)
			{
				kamienietab[i][j].wartosc = rand() % 4;
				powtozenie = true;
			}
	if (powtozenie == true)
		goto start;

}