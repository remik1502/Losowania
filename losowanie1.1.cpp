#include<iostream>
#include<locale>
using namespace std;
const int Total = 49;
int * lotto(int, int);

int main()
{
	int yourchoice = 0;
	cout << "Podaj ile liczb chcesz wylosowaæ z " << Total << "  :";
	cin >> yourchoice;
	int * wsk = lotto(Total, yourchoice);
	if (wsk != NULL)
	{
		for (int i = 0; i < yourchoice; i++)
			cout << "Liczba " << i + 1 << " = " << wsk[i] << endl;
		delete[]wsk;
	}
	else
		cout << "podales liczbe wieksza od " << Total;
	system("pause");
	return 0;
}

int * lotto(int Total_balls, int random_ball)
{
	if (random_ball > Total_balls)
		return NULL;

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