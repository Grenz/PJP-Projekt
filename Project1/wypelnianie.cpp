#include "Header.h"
void wypelnianie(int tab[8][8],bool *sprawdzanieplanszy)
{
	bool powtorzenie = false;
	*sprawdzanieplanszy = false;
start:
	powtorzenie = false;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
		if (tab[i][j]==4&&j==0)
		{
			tab[i][j] = rand() % 4;
			*sprawdzanieplanszy = true;
		}
		else if (tab[i][j]==4&&j>0)
		{
			tab[i][j] = tab[i][j-1];
			tab[i][j - 1] = 4;
			powtorzenie = true;
		}
		}
	if (powtorzenie == true)
		goto start;
}