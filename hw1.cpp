#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "hw1.h"
#include <vector>

//Other libraries you might need should be placed here:
 

/*
Function that you are required to implement (stub).
*/

void compute_overall_score(std::string inputFile, std::string outputFile) {
	
	Score computeScore(inputFile, outputFile);
	computeScore.getScoreVector();

	computeScore.getScore(0);
	computeScore.getScore(1);
	computeScore.getScore(2);
	computeScore.getScore(3);

	std::ofstream output(outputFile);
	output << "Score A: " << computeScore.scoreSchemeA() << "% \n" << "Score B: " << computeScore.scoreSchemeB() << "% \n" << "Overall score: " << std::setprecision(2) << std::fixed << computeScore.scoreMax() << "% \n";
	output.close();

	std::cout << "Score A: " << computeScore.scoreSchemeA() << "% \n" << "Score B: " << computeScore.scoreSchemeB() << "% \n" << "Overall score: " << std::setprecision(2) << std::fixed << computeScore.scoreMax() << "% \n";

}

/**
The implementation of other functions/classes should be placed below
*/
