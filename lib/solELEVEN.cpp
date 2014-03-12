#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include "../include/solutions.h"
using namespace std;

#define NUM_COL 20
#define NUM_ROW 20
#define CONSEC_NUM 4

void createArr(int **tarArr, string line, int pos);
int* lineToInt(string line);
void printArr(int **tarArr);
int prodEast(int **tarArr);
int prodEastHelper(int *row);
int prodSouth(int **tarArr);
int prodWest(int **tarArr);
int prodWestHelper(int *row);
int prodNorth(int **tarArr);
int prodSouthEast(int **tarArr);
int prodSouthWest(int **tarArr);
int prodNorthEast(int **tarArr);
int prodNorthWest(int **tarArr);

int problemEleven(char *filePath) {
	ifstream inFile;
	string line;
	int **arr = new int*[NUM_ROW];
	int rowPos = 0;
	/*
 	* ---------IMPORTANT---------
 	* Constraint on the input array is that each number must be a double digit and separated by whitespace
	*/
	inFile.open(filePath, ios::in);
	
	//Check if file is open for input
	if(inFile.is_open()){
		while(getline(inFile, line)) {	//Read a line from the file
			//Add the line to the array arr
			createArr(arr, line, rowPos);
			rowPos++;
		}
	}

	//Close the file
	inFile.close();

	//Print the array
	printArr(arr);

	/*Compute largest product in all possible directions
	* maxProdEast --> left to right
	* maxProdWest --> right to left
	* maxProdSouth --> top to bottom
	* maxProdNorth --> bottom to top
	* maxProdSouthEast --> diagonal, top to bottom right
	* maxProdSouthWest --> diagonal, top to bottom left
	* maxProdNorthEast --> diagonal, bottom to top right
	* maxProdNorthWest --> diagonal, bottom to top left
	*/
	int maxProdEast = prodEast(arr);
	int maxProdSouth = prodSouth(arr);
	int maxProdWest = prodWest(arr);
	int maxProdNorth = prodNorth(arr);
	int maxProdSouthEast = prodSouthEast(arr);
	int maxProdSouthWest = prodSouthWest(arr);
	int maxProdNorthEast = prodNorthEast(arr);
	int maxProdNorthWest = prodNorthWest(arr);

	//Determine the largest product from all directions
	int maxProdEW = maxProdEast > maxProdWest ? maxProdEast : maxProdWest;
	int maxProdNS = maxProdNorth > maxProdSouth ? maxProdNorth : maxProdSouth;
	int maxProdHorizontalVertical = maxProdEW > maxProdNS ? maxProdEW : maxProdNS;
	int maxProdSEW = maxProdSouthEast > maxProdSouthWest ? maxProdSouthEast : maxProdSouthWest;
	int maxProdNEW = maxProdNorthEast > maxProdNorthWest ? maxProdNorthEast : maxProdNorthWest;
	int maxProdDiagonal = maxProdSEW > maxProdNEW ? maxProdSEW : maxProdNEW;
	int maxProd = maxProdHorizontalVertical > maxProdDiagonal ? maxProdHorizontalVertical : maxProdDiagonal;

	return maxProd;
}

//Returns the larget product of 4 consecutive numbers, going from left to right, of a 2D array tarArr
int prodEast(int **tarArr) {
	int maxProd = 0;
	for(int i=0; i<NUM_ROW; i++) {
		int *row = tarArr[i];
		int prod = prodEastHelper(row);
		maxProd = prod > maxProd ? prod : maxProd;
	}
	return maxProd;
}

int prodEastHelper(int *row) {
	int maxProd = 0;	//variable to hold the maximum product of 4 consecutive numbers of the row
	int prod;
	int limitEl = NUM_COL-CONSEC_NUM; //last element of the array to act as the first of the 4 consecutive numbers for product calculation
	for(int i=0; i<=limitEl;) {
		prod = row[i];
		int j=i+1;
		int j_limit = i+CONSEC_NUM;
		for(j; j<j_limit; j++) {
			prod *= row[j];
		}
		maxProd = prod > maxProd ? prod : maxProd;
		i=i+CONSEC_NUM;
	}
	return maxProd;
}

//Returns the largest product of 4 consecutive numbers, going from right to left, of a 2D array tarArr
int prodWest(int **tarArr) {
	int maxProd = 0;
	for(int i=0; i<NUM_ROW; i++) {
		int *row = tarArr[i];
		int prod = prodWestHelper(row);
		maxProd = prod > maxProd ? prod : maxProd;
	}
	return maxProd;
}

int prodWestHelper(int *row) {
	int maxProd = 0;
	int prod;
	int limitEl = CONSEC_NUM-1;
	for(int i=NUM_COL-1; i>=limitEl;) {
		prod = row[i];
		int j=i-1;
		int j_limit=i-CONSEC_NUM;
		for(j; j>j_limit; j--) {
			prod *= row[j];
		}
		maxProd = prod > maxProd ? prod : maxProd;
		i=i-CONSEC_NUM;
	}
	return maxProd;
}

//Returns the largest product of 4 consecutive numbers, going from top to bottom, of a 2D array tarArr
int prodSouth(int **tarArr) {
	int maxProd = 0;
	for(int i=0; i<NUM_COL; i++) {
		int limitEl = NUM_ROW-CONSEC_NUM;
		for (int j=0; j<=limitEl;) {
			int prod = tarArr[j][i];
			int k = j+1;
			int k_limit = j+CONSEC_NUM;
			for(k; k<k_limit; k++) {
				prod *= tarArr[k][i];
			}
			maxProd = prod > maxProd ? prod : maxProd;
			j=j+CONSEC_NUM;
		}
	}
	return maxProd;
}

//Returns the largest product of 4 consecutive numbers, going from bottom to top, of a 2D array tarArr
int prodNorth(int **tarArr) {
	int maxProd = 0;
	for(int i=0; i<NUM_COL; i++) {
		int limitEl = CONSEC_NUM-1;
		for(int j=NUM_ROW-1; j>=limitEl;) {
			int prod = tarArr[j][i];
			int k = j-1;
			int k_limit = j-CONSEC_NUM;
			for(k; k>k_limit; k--) {
				prod *= tarArr[k][i];
			}
			maxProd = prod > maxProd ? prod : maxProd;
			j=j-CONSEC_NUM;
		}

	}
	return maxProd;
}

//Returns the largest product of 4 consecutive numbers, going from top to bottom right, of a 2D array tarArr
int prodSouthEast(int **tarArr) {
	int maxProd=0;
	for(int i=0; i<NUM_ROW; i++) {
		for(int j=0; j<NUM_COL; j++) {
			int prod = tarArr[i][j];
			if((i+CONSEC_NUM)<=NUM_ROW && (j+CONSEC_NUM)<=NUM_COL) {	//Continue to calculate product only there are 3 more elements diagonally
				int count=1;
				while(count<CONSEC_NUM) {
					prod *= tarArr[i+count][j+count];
					count++;
				}
			}
			maxProd = prod > maxProd ? prod : maxProd;
		}
	}
	return maxProd;
}

//Returns the largest product of 4 consecutive numbers, going from top to bottom left, of a 2D array tarArr
int prodSouthWest(int **tarArr) {
	int maxProd = 0;
	for(int i=0; i<NUM_ROW; i++) {
		for(int j=(NUM_COL-1); j>=0; j--) {
			int prod = tarArr[i][j];
			int r_limit = NUM_ROW-CONSEC_NUM;
			int c_limit = CONSEC_NUM-1;
			if(i<=r_limit && j>=c_limit) {	//Continue only if there are 3 valid elements in the diagonal direction
				int count=1;
				while(count<CONSEC_NUM) {
					prod *= tarArr[i+count][j-count];
					count++;
				}
			}
			maxProd = prod > maxProd ? prod : maxProd;
		}
	}
	return maxProd;
}

//Returns the largest product of 4 consecutive numbers, going from bottom to top right, of a 2D array tarArr
int prodNorthEast(int **tarArr){
	int maxProd=0;
	for(int i=NUM_ROW-1; i>=0; i--)	{
		for(int j=0; j<NUM_COL; j++) {
			int prod = tarArr[i][j];
			int r_limit = CONSEC_NUM-1;
			int c_limit = NUM_COL-CONSEC_NUM;
			if(i>=r_limit && j<=c_limit) {	//Continue only if there are 3 other valid elements for computation
				int count=1;
				while(count<CONSEC_NUM) {
					prod *= tarArr[i-count][j+count];
					count++;
				}
			}
			maxProd = prod > maxProd ? prod : maxProd;
		}
	}
	return maxProd;
}

//Returns the largest product of 4 consecutive numbers, going from bottom to top left, of a 2D array tarArr
int prodNorthWest(int **tarArr){
	int maxProd=0;
	for(int i=NUM_ROW-1; i>=0; i--) {
		for(int j=NUM_COL-1; j>=0; j--) {
			int prod = tarArr[i][j];
			int r_limit = CONSEC_NUM-1;
			int c_limit = CONSEC_NUM-1;
			if(i>=r_limit && j>=c_limit) {	//Continue only if there are 3 other valid elements for computation
				int count=1;
				while(count<CONSEC_NUM) {
					prod *= tarArr[i-count][j-count];
					count++;
				}
			}
			maxProd = prod > maxProd ? prod : maxProd;
		}
	}
	return maxProd;
}

//Print elements of the 2D array tarArr
void printArr(int **tarArr) {
	cout << "\n-------------------------Grid-------------------------\n";
	for(int i=0; i<NUM_ROW; i++) {
		for(int j=0; j<NUM_COL; j++) {
			cout << tarArr[i][j] << " ";
		}
		cout << "\n";
	}	
	cout << "----------------------------------------------------------\n\n";
	return;
}

//Function: add 'line' to the double array tarArr
void createArr(int **tarArr, string line, int pos) {
	tarArr[pos] = lineToInt(line);
	return;
}

//Function: parse 'line', convert each element from char to int and return result in an array
int* lineToInt(string line) {
	size_t strLen = line.size();
	int i=0;
	int* row = new int[NUM_COL];
	int col_count = 0;
	while(i<strLen)
	{
		//Splice number from the string and convert it into an integer
		int num = atoi((line.substr(i,2)).c_str());
		//Add num to the integer array
		row[col_count] = num;
		//Icrement counters
		col_count++;
		i=i+3;
	}
	return row;
}
