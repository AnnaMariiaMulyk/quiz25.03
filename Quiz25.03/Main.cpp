#include <iostream>
#include <fstream>
#include <string>
#include "Quizes.h"
using namespace std;

int main()
{
	int choiseMenu = 0;
	do {
		choiseMenu = menu(choiseMenu);
		switch (choiseMenu)
		{
		case 1:
			playQuize();
			break;
		case 2:
			addQuiz();
			break;
		case 3:
			myTotalScores();
			break;
		case 4:
			cout << "Goodbye!" << endl;
		default:
			break;
		}
		cout << endl;
	} while (choiseMenu != 4);

	system("pause");
	return 0;
}