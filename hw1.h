#ifndef HW1_H
#define HW1_H

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
/*
Forward declaration of auxiliary functions. At the very least, you need to
implement a function with the signature:
void compute_overall_score(std::string, std::string);
*/
void compute_overall_score(std::string inputFile, std::string outputFile);

// Other functions you need should be placed here:

class Score{
private:
	std::string gradesFile;
	std::string logFile;
	std::vector<int> grade;
	std::vector<int> homeworks;
	int value;

	double homeworkMin;
	double homework;
	double midterm1;
	double midterm2;
	double final;
	double tot_homework;

public:
// Constructor(s)
	Score::Score(std::string inputFile, std::string outputFile) {
		gradesFile = inputFile;
		logFile = outputFile;
		homework = 0;
		tot_homework = 140;
	};

// Deconstructor
	Score::~Score() {};

// Other member functions
	std::vector<int> getScoreVector() {
		std::ifstream input(gradesFile);
		while (input >> value)
		{
			grade.push_back(value);
		}

		input.close();
		return grade;
	}

	int removeMinHomework(std::vector<int>& homework) {
		for (int i = 0; i < 8; i++) {
			homework.push_back(grade.at(i));
		}
		int min_val = *std::min_element(homework.begin(), homework.end());
		return std::accumulate(homework.begin(), homework.end(), 0.0) - min_val;
	}

	double getScore(int var) {
		switch (var) {
		case 0: {
			homework = removeMinHomework(homeworks);
			return homework;
			}
		case 1: {
			midterm1 = grade.at(8);
			return midterm1;
			}
		case 2: {
			midterm2 = grade.at(9);
			return midterm2;
			}
		case 3: {
			final = grade.at(10);
			return final;
			}					
		default:
			return -1;
		}
	}

	double scoreSchemeA() {
		return (25 * (homework / tot_homework)) + (0.20*midterm1) + (0.20*midterm2) + (0.35*final);
	}

	double scoreSchemeB() {
		return (25 * (homework / tot_homework)) + (0.30*std::max(midterm1, midterm2)) + (0.44*final);
	}

	double scoreMax() {
		return std::max(Score::scoreSchemeA(), Score::scoreSchemeB());
	}

};

#endif
