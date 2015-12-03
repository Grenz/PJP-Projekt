#include "Header.h"
void elementtablicy(int posofmouseX , int posofmouseY,int* X,int *Y)
{
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (posofmouseX >= i * 50 && posofmouseX < (i + 1) * 50 && posofmouseY >= j * 50 && posofmouseY < (j + 1) * 50)
				{
			*X = i;
			*Y = j;
				}
}