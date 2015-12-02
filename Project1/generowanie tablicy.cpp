#include "Header.h"
void generowanie_tablicy(int tab[8][8])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			tab[i][j] = rand() % 4;
		}
	}
}