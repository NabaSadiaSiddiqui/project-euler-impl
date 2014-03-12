#include<iostream>
#include<cstdlib>
#include "../include/solutions.h"
using namespace std;

void printProblemDefinition(int usrOption);
void printAnswer(int ans);

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		cout << "ERROR: Incorrect program syntax\n";
		cout << "\t$./main <problem number>\n";
		exit(EXIT_FAILURE);
	}

	int usrOption=atoi(argv[1]);
	char *inputGridPath=argv[2];
	
	switch(usrOption) {
		case 1:
			printProblemDefinition(usrOption);
			printAnswer(problemOne());
			break;
		case 2:
			printProblemDefinition(usrOption);
			printAnswer(problemTwo());
			break;
		case 3:
			printProblemDefinition(usrOption);
			printAnswer(problemThree());
			break;
		case 4:
			printProblemDefinition(usrOption);
			printAnswer(problemFour());
			break;
		case 5:
			printProblemDefinition(usrOption);
			printAnswer(problemFive());
			break;
		case 6:
			printProblemDefinition(usrOption);
			printAnswer(problemSix());
			break;
		case 7:
			printProblemDefinition(usrOption);
			printAnswer(problemSeven());
			break;
		case 8:
			printProblemDefinition(usrOption);
			printAnswer(problemEight());
			break;
		case 9:
			printProblemDefinition(usrOption);
			printAnswer(problemNine());
			break;
		case 10:
			printProblemDefinition(usrOption);
			printAnswer(problemTen());
			break;
		case 11:
			printProblemDefinition(usrOption);
			if(inputGridPath==NULL){
				cout << "ERROR: You did not pass in the aboslute path of the text file with the 20x20 grid as the 2nd argument\n";
				exit(EXIT_FAILURE);
			}
			else {
				printAnswer(problemEleven(inputGridPath));
				break;
			}
		default:
			printProblemDefinition(usrOption);
			printAnswer(-1);
			break;
	}

	return 0;


}

void printProblemDefinition(int probNum)
{
	switch(probNum) {
		case 1:
			cout << "Problem: the sum of all the multiples of 3 or 5 below 1000.\n";
			break;
		case 2:
			cout << "Problem: the sum of the even-valued terms in the Fibonacci sequence whose values do not exceed four million.\n";
			break;
		case 3:
			cout << "Problem: the largest prime factor of the number 600851475143.\n";
			break;
		case 4:
			cout << "Problem: the largest palindrome made from the product of two 3-digit numbers.\n";
			break;
		case 5:
			cout << "Problem: the smallest positive number that is evenly divisible by all of the numbers from 1 to 20.\n";
			break;
		case 6:
			cout << "Problem: the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n";
			break;
		case 7:
			cout << "Problem: the 10 001st prime number.\n";
			break;
		case 8:
			cout << "Problem: the greatest product of five consecutive digits in the 1000-digit number defined in the code.\n";
			break;
		case 9:
			cout << "Problem: the product abc of the Pythagorean triplet for which a+b+c = 1000.\n";
			break;
		case 10:
			cout << "Problem: the sum of all the primes below two million.\n";
			break;
		case 11:
			cout << "Problem: the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid defined in /res/inputGridProblemEleven.txt\n";
			break;
		default:
			cout << "Problem: not yet solved.\n";
			break;
	}

	return;
}

void printAnswer(int ans)
{
	if(ans!=-1)
		cout << "Answer: " << ans << "\n";
	else
		cout << "Answer: invalid\n";

	return;
}
