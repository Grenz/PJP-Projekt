#include "Header.h"
void przesuwanie(kamienie kamienietab[8][8],bool* sprawdzanieplanszy,bool* przesuwanie,int* wiersz)
{
		for (int j = 0; j < 8; j++)
		{
			if (kamienietab[j][*wiersz].wartosc == 4&&*wiersz!=0)
			{
				kamienietab[j][*wiersz].wartosc = kamienietab[j][*wiersz-1].wartosc;
				kamienietab[j][*wiersz].bitmapax = kamienietab[j][*wiersz - 1].docelowabitmapax;
				kamienietab[j][*wiersz].bitmapay = kamienietab[j][*wiersz - 1].docelowabitmapay;
				kamienietab[j][*wiersz-1].wartosc = 4;
			}
		}
		if (*wiersz == 0)
		{
			*przesuwanie = false;
			*sprawdzanieplanszy = true;
			for (int i = 0; i < 8; i++)
			{
				if (kamienietab[i][*wiersz].wartosc == 4)
				{
					*sprawdzanieplanszy = false;
					*przesuwanie = true;
					kamienietab[i][*wiersz].wartosc = rand() % 4;
				}
			}
			*wiersz = 8;
		}
		*wiersz = *wiersz - 1;
}