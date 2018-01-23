#include<iostream>
#include<locale>
using namespace std;

int * lotto(int, int);

int main()
{
	int * wsk = lotto(49, 6);
	if (wsk != NULL)
	{
		for (int i = 0; i < 6; i++)
			cout << "Liczba " << i + 1 << " = " << wsk[i] << endl;
		delete[]wsk;
	}
	system("pause");
	return 0;
}

int * lotto(int Total_balls, int random_ball)
{
	srand(time(NULL));

	int *tab = new int[random_ball];

	for (int i = 0; i < random_ball; i++)
	{
		tab[i] = rand() % Total_balls + 1;

		for (int j = 0; j < i + 1; j++)
		{
			if (tab[i] == tab[j] && i != j)
			{
				i--;
				break;
			}
		}
	}
return tab;
}