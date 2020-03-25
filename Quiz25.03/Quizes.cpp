#include "Quizes.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

quiz* quizes;
int countQuiz;
const int sizeQuize = 5;
int totalScores = 0;


int menu(int choiseMenu)
{
	cout << "\tQUIZ" << endl;
	cout << "1. Start quize" << endl;
	cout << "2. Add quiz" << endl;
	cout << "3. My total scores" << endl;
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
		cin.ignore();
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
	string userAnswer;
	int gamescores = 0;
	cout << "\tQUIZ" << endl;
	cout << "Quiz list: " << endl;
	for (int i = 0; i < countQuiz; i++)
	{
		cout << i + 1 <<". " << quizes[i].name << endl;
	}
	for (int i = 0; i < countQuiz; i++)
	{
		cout << "Enter name of quize to play: ";
		cin.ignore();
		getline(cin, name);

		if (quizes[i].name == name)
		{
			for (int j = 0; j < sizeQuize; j++)
		{
		userAnswer = " ";
		cout << "1. " << quizes[i].quetion[j].quetion << endl;
		cout << "Enter answer: ";
		getline(cin, userAnswer);
		if (userAnswer == quizes[i].quetion[j].answer)
		{
			cout << "Correct answer!" << endl;
			cout << "+ 10" << endl;
			gamescores += 10;
		}
		else
		{
			cout << "Wrong answer!" << endl;
		}
		}
		cout << "YOUR SCORES: " << gamescores << endl;
		totalScores += gamescores;					}
		else
		{
			cout << "Can not find quize with this name!" << endl;
		}
	}
}
void myTotalScores()
{
	cout << "MY TOTAL SCORES" << endl;
	cout << "My scores: " << totalScores << endl;

}
