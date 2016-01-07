#include "Header.h"
void sprawdzanie_tablicy(kamienie kamienietab[8][8],int *score,bool* sprawdzanieplanszy)
{
	kamienie kamienietab2[8][8];
	int k, b;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			kamienietab2[i][j].wartosc = kamienietab[i][j].wartosc;


	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 6; j++)
		{
			if (kamienietab[i][j].wartosc == kamienietab[i][j + 1].wartosc && kamienietab[i][j].wartosc == kamienietab[i][j + 2].wartosc)
			{
				k = 0;
				b = kamienietab[i][j].wartosc;
				while (b == kamienietab[i][j + k].wartosc && j + k <= 7)
				{
					kamienietab2[i][j + k].wartosc = 4;
					k++;
				}
			}

			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 8; j++)
				{
					if (kamienietab[i][j].wartosc == kamienietab[i + 1][j].wartosc && kamienietab[i][j].wartosc == kamienietab[i + 2][j].wartosc)
					{
						k = 0;
						b = kamienietab[i][j].wartosc;
						while (b == kamienietab[i + k][j].wartosc && i + k <= 7)
						{
							kamienietab2[i + k][j].wartosc = 4;
							k++;
						}
					}
				}
		}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (kamienietab2[i][j].wartosc==4)
		{
				kamienietab[i][j].wartosc = 4;
				*score = *score + 10;
		}
		}
	bool powtorzenie = false;
	*sprawdzanieplanszy = false;
start:
	powtorzenie = false;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
		if (kamienietab[i][j].wartosc == 4 && j == 0)
		{
			kamienietab[i][j].wartosc = rand() % 4;
			*sprawdzanieplanszy = true;
		}
		else if (kamienietab[i][j].wartosc == 4 && j>0)
		{
			kamienietab[i][j].wartosc = kamienietab[i][j - 1].wartosc;
			kamienietab[i][j - 1].wartosc = 4;
			powtorzenie = true;
		}
		}
	if (powtorzenie == true)
		goto start;
}