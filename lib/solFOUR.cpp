#include <iostream>
#include <string>
#include "../include/solutions.h"
#include "../include/helperFunc.h"
using namespace std;

#define MIN3DIGIT 100
#define MAX3DIGIT 999

bool isPalindrome(int n);

int problemFour()
{
	int i, j;
	int *arrPalindrome = new int;
	int largestPalindrome = 0;

	for(i=MIN3DIGIT; i<=MAX3DIGIT; i++)
	{
		for(j=MIN3DIGIT; j<=MAX3DIGIT; j++)
		{
			int product = i*j;
	
			if(isPalindrome(product))
				largestPalindrome = product>largestPalindrome ? product : largestPalindrome;
		}
	}

	return largestPalindrome;
}

bool isPalindrome(int n)
{
	int i;

	string strN = to_string(n);
	int strSize = getStrSize(strN);
	int limit = strSize/2;

	for(i=0; i<limit; i++)
	{
		if(strN[i]!=strN[strSize-1-i])
			return false;
	}
	return true;
}
