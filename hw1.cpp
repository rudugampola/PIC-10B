#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "hw1.h"

//Other libraries you might need should be placed here:

using namespace std;

/*
Function that you are required to implement (stub).
*/

void compute_overall_score(std::string inputFile, std::string outputFile) {

	std::ifstream input(inputFile);
	std::vector<int> grade(11);
	int value;

	while (input >> value)
	{
		grade.push_back(value);
	}

	input.close();

	/* Iterate the vector
	int iter;
	for (vector<int>::const_iterator iter = grade.begin(); iter != grade.end(); ++ iter) {
		std::cout << *iter << std::endl;
	}
	*/

	double tot_homework = 160;

	double homework = grade.at(0) + grade.at(1) + grade.at(2) + grade.at(3) +  grade.at(4) + grade.at(5) + grade.at(6) + grade.at(7);
	double midterm1 = grade.at(8);
	double midterm2 = grade.at(9);
	double final = grade.at(10);

	double score_a = (25*(homework/tot_homework)) + (0.20*midterm1) + (0.20*midterm2) + (0.35*final);

	double score_b1 = (25 * (homework / tot_homework)) + (0.30*midterm1) + (0.44*final);
	double score_b2 = (25 * (homework / tot_homework)) + (0.30*midterm2) + (0.44*final);
	double score_b = std::max(score_b1, score_b2);
	double highest = std::max(score_a, score_b);

	/* Print scores
	std::cout.precision(4);
	cout << homework << endl << midterm1 << endl << midterm2 << endl << final << endl << score_a << endl << score_b  << endl;
	*/

	std::ofstream output(outputFile);
	output << "Score A: " << std::setprecision(2) << fixed << score_a << "\n" << "Score B: " << score_b << "\n" << "Overall score: " << highest;
	output.close();

	return;
}

/**
The implementation of other functions/classes should be placed below
*/
Score::Score(std::string inputFile, std::string outputFile) : grades(inputFile), log(outputFile){}
Score::~Score() {}
