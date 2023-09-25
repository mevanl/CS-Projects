/*
        NAME:       Mason Lauderdale
        CLASS:      CSC-1310-001, Program 4
        DUE DATE:   Nov 27, 2022
*/
#include<iostream>
//#include "markovMat.h"
#include "markovList.h"
using namespace std;

int main()
{
	//markovMat* chain = new markovMat("corpus.txt");
	markovList* chain = new markovList("corpus.txt");
	
	cout << chain->generate(100) << endl;
	delete chain;
	return 0;
}