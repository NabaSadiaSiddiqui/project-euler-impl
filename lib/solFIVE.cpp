#include<iostream>
#include "../include/solutions.h"
using namespace std;

#define MAX_NUM 20

bool isDivisible(int target, int num);

int problemFive()
{
	bool nextNum = true;
	int target = 1;
	
	while(nextNum)
	{
		int i;
		for(i=1; i<=MAX_NUM; i++)
		{
			if(isDivisible(target, i)==false)
			{
				break;
			}
		}

		if(i==MAX_NUM+1)
			nextNum = false;		
		else
			target++;
	}

	return target;
}

bool isDivisible(int target, int num)
{
	if(target%num==0)
		return true;
	else
		return false;
}
