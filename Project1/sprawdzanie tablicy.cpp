void sprawdzanie_tablicy(int tab[8][8])
{
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
		if (tab[i][j-2] == tab[i][j -1] && tab[i][j-2] == tab[i][j])
		{
			for (int k = 0; k < 3; k++)
			{
				tab[i][j + k-2] = 4;
			}
		}
		else if (tab[i-2][j] == tab[i - 1][j] && tab[i-2][j] == tab[i][j])
		{
			for (int k = 0; k < 3; k++)
			{
				tab[i+k-2][j] = 4;
			}
		}
			}

}
