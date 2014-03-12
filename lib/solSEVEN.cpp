#include<iostream>
#include "../include/solutions.h"
using namespace std;

#define TARGETNUM 10001

bool isPrime(int n);

int problemSeven()
{
	int curr=0;	//Counter to keep track of nth prime number
	int i=2;	//Variable to hold incrementing values

	while(curr<TARGETNUM)
	{
		if(isPrime(i))
		{
			curr++;
		}
		i++;
	}
	i--;

	return i;
}

bool isPrime(int n)
{
	int i;
	for(i=2; i<n; i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
