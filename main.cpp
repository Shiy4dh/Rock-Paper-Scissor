#include <iostream>
#include <random>
#include "common.h"



int main()
{

	bool quit{ false };
	
	while (!quit)
	{

		// generate a random number:

		int systemChoice{ generateRand() };

		// ask user for their choice.
		int userChoice{ getUserChoice() };

		checkWhoWon(userChoice, systemChoice);

		char exit{ wantToExit() };
		
		if (exit == 'n')
		{
			std::cout << ascii::goodbye << '\n';
		
			quit = true;
		}
	}
	
	return 0;
}
