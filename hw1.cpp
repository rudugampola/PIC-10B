#include "stdafx.h"
#include "hw1.h"

//Other libraries you might need should be placed here:
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

int homeWork = 0;
int myValue = 0;

Score::Score(std::string inputFile, std::string outputFile)
{
	gradesFile = inputFile;
	logFile = outputFile;

	homework = 0;
	tot_homework = 140;
	value = 0;
	midterm1 = 0;
	midterm2 = 0;
	final = 0;
}

Score::~Score()
= default;

int Score::getHomework()
{
	return homework;
}

void Score::setHomework()
{
	homework = homeWork;
}

int Score::getValue()
{
	return value;
}

void Score::setValue()
{
	value = myValue;
}

std::vector<int> Score::getGrade()
{
	return grade;
}

std::vector<int> Score::getScoreVector()
{
	//Score vectorObj(inputFile, outputFile);
	std::ifstream input(gradesFile);
	int test;
	while (input >> test)
	{
		grade.push_back(test);
	}

	input.close();
	return grade;
}


int Score::removeMinHomework()
{
	int min = grade.at(0);
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		//std::cout << grade.at(i);
		if (grade.at(i) < min)
			min = grade.at(i);
	}

	for (int i = 0; i < 8; i++)
	{
		sum += grade.at(i);
	}
	return sum - min;
}

double Score::getScore(int varKey)
{
	switch (varKey)
	{
	case 0:
		{
			homework = removeMinHomework();
			return homework;
		}
	case 1:
		{
			midterm1 = grade.at(8);
			return midterm1;
		}
	case 2:
		{
			midterm2 = grade.at(9);
			return midterm2;
		}
	case 3:
		{
			final = grade.at(10);
			return final;
		}
	default:
		return -1;
	}
}

double Score::scoreSchemeA()
{
	return (25 * (homework / tot_homework)) + (0.20 * midterm1) + (0.20 * midterm2
	) + (0.35 * final);
}

double Score::scoreSchemeB()
{
	return (25 * (homework / tot_homework)) + (0.30 * std::max(midterm1, midterm2)
	) + (0.44 * final);
}

double Score::scoreMax()
{
	return std::max(scoreSchemeA(), scoreSchemeB());
}

/*
Function that you are required to implement (stub).
*/

void compute_overall_score(std::string inputFile, std::string outputFile)
{
	Score computeScore(inputFile, outputFile);
	computeScore.getScoreVector();

	computeScore.getScore(0);
	computeScore.getScore(1);
	computeScore.getScore(2);
	computeScore.getScore(3);

	std::ofstream output(outputFile);
	output << "Score A: " << computeScore.scoreSchemeA() << "% \n" << "Score B: "
		<< computeScore.scoreSchemeB() << "% \n" << "Overall score: " << std::
		setprecision(2) << std::fixed << computeScore.scoreMax() << "% \n";
	output.close();

	std::cout << "Score A: " << computeScore.scoreSchemeA() << "% \n" <<
		"Score B: " << computeScore.scoreSchemeB() << "% \n" << "Overall score: " <<
		std::setprecision(2) << std::fixed << computeScore.scoreMax() << "% \n";
}

/**
The implementation of other functions/classes should be placed below
*/

