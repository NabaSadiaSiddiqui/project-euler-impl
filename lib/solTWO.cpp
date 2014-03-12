#include<iostream>
#include "../include/solutions.h"
using namespace std;

//Find the next fibonacci term
int findNext(int tmpArr [], int n)
{
	return (tmpArr[n]+tmpArr[n-1]);
}

int problemTwo()
{
	int *fibSeq=new int[2];
	int i=1;
	int maxTerm=4000000;
	int sum=0;
	int arrSize=2;

	//Initialize array with first 2 values
	fibSeq[0]=1;
	fibSeq[1]=2;
		
	//Set latest fibonacci term
	int currTerm=fibSeq[i];

	//Expand fibSeq according to maximum limit set by maxTerm
	while(currTerm<=maxTerm) 
	{
		int nextTerm=findNext(fibSeq, i);

		if(nextTerm<=maxTerm)
		{
			arrSize++;
			fibSeq[i+1]=nextTerm;
		}
		
		currTerm=nextTerm;
		i++;
	}

	//Calculate sum of even terms of the sequence
	for(i=0; i<arrSize; i++)
	{
		//If even
		if(fibSeq[i]%2==0)
		{
			sum+=fibSeq[i];
		}
	}

	return sum;
}
