#include "Header.h"
void sprawdzanie_tablicy(int tab[8][8], int *score, bool* sprawdzanieplanszy)
{
	int tab2[8][8];
	int k, b;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			tab2[i][j] = tab[i][j];


	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 6; j++)
		{
			if (tab[i][j] == tab[i][j + 1] && tab[i][j] == tab[i][j + 2])
			{
				k = 0;
				b = tab[i][j];
				while (b == tab[i][j + k] && j + k <= 7)
				{
					tab2[i][j + k] = 4;
					k++;
				}
			}

			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 8; j++)
				{
					if (tab[i][j] == tab[i + 1][j] && tab[i][j] == tab[i + 2][j])
					{
						k = 0;
						b = tab[i][j];
						while (b == tab[i + k][j] && i + k <= 7)
						{
							tab2[i + k][j] = 4;
							k++;
						}
					}
				}
		}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (tab2[i][j] == 4)
			{
				tab[i][j] = 4;
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
			if (tab[i][j] == 4 && j == 0)
			{
				tab[i][j] = rand() % 4;
				*sprawdzanieplanszy = true;
			}
			else if (tab[i][j] == 4 && j>0)
			{
				tab[i][j] = tab[i][j - 1];
				tab[i][j - 1] = 4;
				powtorzenie = true;
			}
		}
	if (powtorzenie == true)
		goto start;
}