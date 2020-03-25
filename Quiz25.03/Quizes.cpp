#include "Quizes.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

quiz* quizes;
int countQuiz;
const int sizeQuize = 5;


int menu(int choiseMenu)
{
	cout << "\tQUIZ" << endl;
	cout << "1. Start quize" << endl;
	cout << "2. Add quiz" << endl;
	cout << "3. My scores" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter action: ";
	cin >> choiseMenu;
	return choiseMenu;
}

void addQuiz()
{
	ofstream fout;
	fout.open("quizes.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == false)
	{
		cout << "Error!!! Program can not open file!" << endl;
	}
	else
	{
		quiz* temp = new quiz[countQuiz + 1];
		for (int i = 0; i < countQuiz; i++)
		{
			temp[i] = quizes[i];
		}
		cout << "Enter quize name: ";
		getline(cin, temp[countQuiz].name);
		temp[countQuiz].quetion = new quetions[sizeQuize];
		for (int i = 0; i < sizeQuize; i++)
		{
			cout << "Enter quetion: ";
			getline(cin, temp[countQuiz].quetion[i].quetion);
			cout << "Enter answer: ";
			getline(cin, temp[countQuiz].quetion[i].answer);
		}
		fout << temp[countQuiz].name << endl;
		for (int i = 0; i  < sizeQuize; i++)
		{
			fout << temp[countQuiz].quetion[i].quetion << endl;
			fout << temp[countQuiz].quetion[i].answer << endl;
		}
		fout.close();
		countQuiz++;
		delete quizes;
		quizes = temp;
	}
}

void playQuize()
{
	string name;
	cout << "\tQUIZ" << endl;
	for (int i = 0; i < countQuiz; i++)
	{
		cout << quizes[i].name << endl;
	}

do {

	cout << "Enter name of quize to play: ";
	getline(cin, name);

		for (int i = 0; i < countQuiz; i++)
		{
			if (quizes[i].name == name)
			{
				int index = i;
				ifstream fin;
				fin.open("quizes.txt");
				bool isOpen = fin.is_open();
				if (isOpen == false)
				{
					cout << "Error!!! Program can not open file!" << endl;
				}
				else
				{
						
				}
				fin.close();
			}
			else
			{
				cout << "Can not find quize with this name!" << endl;
			}
		}
	} while (name != quizes[countQuiz].name);
}
