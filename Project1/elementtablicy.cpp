#include "Header.h"
void elementtablicy(int posofmouseX, int posofmouseY, int* X, int *Y, int plansza_x, int plansza_y)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (posofmouseX >= i * 50 + plansza_x && posofmouseX < (i + 1) * 50 + plansza_x && posofmouseY >= j * 50 + plansza_y && posofmouseY < (j + 1) * 50 + plansza_y)
			{
				*X = i;
				*Y = j;
			}
}