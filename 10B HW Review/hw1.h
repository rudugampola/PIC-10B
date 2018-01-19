#ifndef HW1_H
#define HW1_H

#include <string>
#include <vector>

void compute_overall_score(std::string inputFile, std::string outputFile);

class Score
{
private:
	std::string gradesFile;
	std::string logFile;

	std::vector<int> grade;
	std::vector<int> homeworks;

	int value;
	double homework;
	double midterm1;
	double midterm2;
	double final;
	double tot_homework;

public:
	// Constructor
	Score::Score(std::string inputFile, std::string outputFile);

	// Deconstructor
	Score::~Score();

	// Other accessor functions
	int Score::getHomework();
	void Score::setHomework();
	int Score::getValue();
	void Score::setValue();

	// Other vectors 
	std::vector<int> getScoreVector();
	std::vector<int> getGrade();

	// Other variables initialized 
	int removeMinHomework();
	double getScore(int varKey);
	double scoreSchemeA();
	double scoreSchemeB();
	double scoreMax();
};

#endif
