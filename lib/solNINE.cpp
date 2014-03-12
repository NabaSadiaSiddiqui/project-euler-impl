#include<iostream>
#include<cmath>
#include "../include/solutions.h"
using namespace std;

#define MAXNUM 1000
#define SUM 1000

bool isPythagorean(int a, int b, int c);
bool checkSum(int a, int b, int c);

int problemNine()
{
	int i, j, k, product;

	for(i=0; i<=MAXNUM; i++)
	{
		for(j=i+1; j<=(MAXNUM-i); j++)
		{
			for(k=j+1; k<=(MAXNUM-i-j); k++)
			{
				if(isPythagorean(i,j,k) && checkSum(i,j,k))
				{
					product=i*j*k;
					break;
				}
			}
		}
	}

	return product;
}

bool isPythagorean(int a, int b, int c)
{
	int leftSide = pow(a,2)+pow(b,2);
	int rightSide = pow(c,2);

	if(leftSide==rightSide)
		return true;

	return false;
}

bool checkSum(int a, int b, int c)
{
	if(a+b+c == SUM)
		return true;
	
	return false;
}
