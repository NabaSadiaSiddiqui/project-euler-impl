#include<iostream>
#include "../include/solutions.h"
using namespace std;

#define LIMIT 2000000

bool isPrime(long n);
bool isOdd(long n);

int problemTen()
{
	long i;
	long sum=0;

	for(i=2; i<LIMIT; i++)
	{
		if(i==2 || i==3 || i==5)
			sum +=i;
		else if(isOdd(i))	//i is not divisible by 2
		{
			if(i%3!=0)	//i is not divisible by 3
			{
				if(i%5!=0)	//i is not divisible by 5
				{
					if(isPrime(i))
						sum += i;
				}
			}
		}
	}
	
	return sum;
}

bool isOdd(long n)
{
	if(n%2==0)
		return false;
	else
		return true;
}

bool isPrime(long n)
{
	long i;

	for(i=2; i<n; i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
