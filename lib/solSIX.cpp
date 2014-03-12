#include<iostream>
#include<cmath>
#include "../include/solutions.h"
using namespace std;

#define NUM 100

int problemSix()
{
	int num1 = 0;
	int num2 = 0;
	int diff = 0;
	int i;

	for(i=1; i<=NUM; i++)
	{
		num1 += pow(i, 2);
		num2 += i;
	}

	diff = pow(num2, 2) - num1;

	return diff;
}
