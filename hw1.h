
#ifndef HW1_H
#define HW1_H

#include <string>
#include <fstream>


/*
Forward declaration of auxiliary functions. At the very least, you need to
implement a function with the signature:
void compute_overall_score(std::string, std::string);
*/
void compute_overall_score(std::string inputFile, std::string outputFile);

// Other functions you need should be placed here:

class Score{
public:
// Constructor(s)
	Score(std::string grades, std::string log);
	~Score();

// Other member functions

private:
	std::string grades;
	std::string log;
};

#endif
