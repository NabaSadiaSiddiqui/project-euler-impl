#include<iostream>
#include "../include/solutions.h"
using namespace std;

//Function declarations
unsigned long int smallestPrime(unsigned long int n);
bool isPrime(unsigned long int n);
void addElement(unsigned long int *arrTmp, unsigned long int element);
unsigned long int getArrSize(unsigned long int *arrTmp);
void printArr(unsigned long int *arrTmp);

int problemThree()
{
	unsigned long int targetNum = 600851475143;
	unsigned long int *arrFactors = new unsigned long int;	//Array to hold all prime factors of targetNum

	unsigned long int firstFactor = smallestPrime(targetNum); 	//Smallest prime factor of targetNum
	unsigned long int nextFactor = targetNum/firstFactor;	//targetNum = nextFactor x firstFactor
	
	//Append firstFactor to arrFactors
	addElement(arrFactors, firstFactor);	

	while(!isPrime(nextFactor))	//Prime factorization of nextFactor
	{
		firstFactor = smallestPrime(nextFactor);
		nextFactor = nextFactor/firstFactor;
		
		addElement(arrFactors, firstFactor);
	}

	//Append nextFactor (last factor) to arrFactors
	addElement(arrFactors, nextFactor);
	
	//Get largest prime factor of targetNum
	unsigned long int arrSize = getArrSize(arrFactors);
	unsigned long int largestPrime = arrFactors[arrSize-1];

	return largestPrime;
}

//Find smallest prime factor of n
unsigned long int smallestPrime(unsigned long int n)
{
	unsigned long int i;

	for(i=2; i<n; i++)
	{
		if(n%i==0 && isPrime(i))	//i is the smallest prime factor of targetNum
		{
			break;
		}
	}

	return i;
}

//Append element to arrTmp
void addElement(unsigned long int *arrTmp, unsigned long int element)
{
	unsigned long int arrSize = getArrSize(arrTmp);
	arrTmp[arrSize] = element;

	return;
}

//Get size of arrTmp
unsigned long int getArrSize(unsigned long int *arrTmp)
{
	unsigned long int i=0;
	while(arrTmp[i]!=0)
	{
		i++;
	}

	return i;
}

//Determine if n is a prime number
bool isPrime(unsigned long int n)
{
	unsigned long int j;

	for(j=2; j<n; j++)
	{
		if(n%j==0)	//currElement is not a prime number
		{
			return false;
		}
	}
	
	return true;
}

//Print array elements
void printArr(unsigned long int *arrTmp)
{
	unsigned long int arrSize = getArrSize(arrTmp);
	unsigned long int i;

	for(i=0; i<arrSize; i++)
	{
		cout << arrTmp[i] << "\n";
	}

	return;
}
