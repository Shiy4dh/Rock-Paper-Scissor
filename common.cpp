#include "common.h"
#include <iostream>
#include <random>
#include <string>

namespace ascii
{
	
	std::string paper{ R"(
	  ______    ______    ______    ______    ______  
	 /      \  |      \  /      \  /      \  /      \ 
	|  $$$$$$\  \$$$$$$\|  $$$$$$\|  $$$$$$\|  $$$$$$\
	| $$  | $$ /      $$| $$  | $$| $$    $$| $$   \$$
	| $$__/ $$|  $$$$$$$| $$__/ $$| $$$$$$$$| $$      
	| $$    $$ \$$    $$| $$    $$ \$$     \| $$      
	| $$$$$$$   \$$$$$$$| $$$$$$$   \$$$$$$$ \$$      
	| $$                | $$                          
	| $$                | $$                          
	\$$                 \$$    

)" };

	//-----------------------------------

	std::string rock{ R"(
 _______                       __       
|       \                     |  \      
| $$$$$$$\  ______    _______ | $$   __ 
| $$__| $$ /      \  /       \| $$  /  \
| $$    $$|  $$$$$$\|  $$$$$$$| $$_/  $$
| $$$$$$$\| $$  | $$| $$      | $$   $$ 
| $$  | $$| $$__/ $$| $$_____ | $$$$$$\ 
| $$  | $$ \$$    $$ \$$     \| $$  \$$\
 \$$   \$$  \$$$$$$   \$$$$$$$ \$$   \  

)" };

	std::string scissor{ R"(
  ______             __                                         
 /      \           |  \                                        
|  $$$$$$\  _______  \$$  _______   _______   ______    ______  
| $$___\$$ /       \|  \ /       \ /       \ /      \  /      \ 
 \$$    \ |  $$$$$$$| $$|  $$$$$$$|  $$$$$$$|  $$$$$$\|  $$$$$$\
 _\$$$$$$\| $$      | $$ \$$    \  \$$    \ | $$  | $$| $$   \$$
|  \__| $$| $$_____ | $$ _\$$$$$$\ _\$$$$$$\| $$__/ $$| $$      
 \$$    $$ \$$     \| $$|       $$|       $$ \$$    $$| $$      
  \$$$$$$   \$$$$$$$ \$$ \$$$$$$$  \$$$$$$$   \$$$$$$  \$$    
)" };

	std::string draw{ R"(
//   ___    ____    ____  __    __      __ 
//  |   \  |    \  /    ||  |__|  |    |  |
//  |    \ |  D  )|  o  ||  |  |  |    |  |
//  |  D  ||    / |     ||  |  |  |    |__|
//  |     ||    \ |  _  ||  `  '  |     __ 
//  |     ||  .  \|  |  | \      /     |  |
//  |_____||__|\_||__|__|  \_/\_/      |__|
//                                         
)" };

	std::string goodbye{ R"(
//     ____                 _ _                
//    / ___| ___   ___   __| | |__  _   _  ___ 
//   | |  _ / _ \ / _ \ / _` | '_ \| | | |/ _ \
//   | |_| | (_) | (_) | (_| | |_) | |_| |  __/
//    \____|\___/ \___/ \__,_|_.__/ \__, |\___|
//                                  |___/    
)" };

}

int generateRand()
{
	std::random_device rd{};		// initialize the rd for using it as seed.
	std::seed_seq ss{ rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd(), };

	std::mt19937 mt{ ss };			// intialize the mersene twister with seed values.

	std::uniform_int_distribution<> roll{ 1,3 };

	int systemChoice{ 0 };				// stores a random int that the system chose.

	for (int count{ 1 }; count <= 1; ++count)
	{
		systemChoice += roll(mt);
		//std::cout << roll(mt) << '\n';

	}

	return systemChoice;				// return the systemChoice random number.
}

int getUserChoice()
{
	std::cout << "Choose your options...\n";
	std::cout << "1.Rock\n";
	std::cout << "2.Scissor\n";
	std::cout << "3.Paper\n";

	int userChoice{};
	std::cin >> userChoice;

	return userChoice;

}

void checkWhoWon(int userChoice, int systemChoice)
{
	// checking if it is draw
	if (userChoice == systemChoice)
	{
		std::cout << "Draw!\n";

		// R is a raw string literal.
		std::cout << ascii::draw << '\n';

	}
	// check if rock won
	else if ((userChoice == 1 && systemChoice == 2) || (userChoice == 2 && systemChoice == 1))
	{
		std::cout << "Rock has won!\n";
		std::cout << ascii::rock << '\n';
	}
	// check if paper won
	else if ((userChoice == 1 && systemChoice == 3) || (userChoice == 3 && systemChoice == 1))
	{
		std::cout << "Paper has won!\n";
		std::cout << ascii::paper << '\n';
	}

	// check if scissor won
	else if ((userChoice == 3 && systemChoice == 2) || (userChoice == 2 && systemChoice == 3))
	{
		std::cout << "Scissor has won!\n";
		std::cout << ascii::scissor << '\n';
	}
	else
	{
		std::cout << "Enter a valid choice!\n";
	}
}

char wantToExit()
{
	std::cout << "--------------------------------------------------------\n";
	std::cout << "Continue playing? y/n: ";
	char choice{};
	std::cin >> choice;

	return choice;
}


