#ifndef COMMON_H
#define COMMON_H




#include <string>

namespace ascii
{
	// we used extern so that we could access the variables in the namespace from common.cpp
	extern std::string paper;
	extern std::string rock;
	extern std::string scissor;
	extern std::string draw;
	extern std::string goodbye;

}

int generateRand();
int getUserChoice();

void checkWhoWon(int userChoice, int systemChoice);
char wantToExit();

#endif // !COMMON_H
