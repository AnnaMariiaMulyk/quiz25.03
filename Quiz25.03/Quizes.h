#pragma once
#include <iostream>
#include <string>
using namespace std;
struct quetions
{
	string quetion;
	string answer;
};
struct quiz
{
	string name;
	quetions* quetion;
	string* marks;
	
};
int menu(int choiseMenu);
void addQuiz();
void playQuize();
