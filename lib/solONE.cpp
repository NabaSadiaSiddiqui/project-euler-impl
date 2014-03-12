#include<iostream>
#include "../include/solutions.h"
using namespace std;

int problemOne()
{
	int sum=0;
	int i;
	for(i=1; i<1000; i++)
	{
		if(i%3==0 || i%5==0)
		{
			sum+=i;
		}
	}

	return sum;
}
