/*
        NAME:       Mason Lauderdale
        CLASS:      CSC-1310-001, Program 4
        DUE DATE:   Nov 27, 2022
*/
#ifndef MARKOVLIST_H
#define MARKOVLIST_H

#include<map>
#include<ctime>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
using namespace std;

class markovList
{
	private:
		struct edge
		{
			float weight; // holds weight to travel to this node
			string value; // The word it holds / Destination 
			edge* next; // points to next node in list
		};
		map<string, edge*> corpus;
		int corpusSize; // The number of Vertices
	public:
		markovList(const char*);
		~markovList();
		void addEdge(string, string, float); // Function to add an edge to the list, added to simplify and clean up code
		string generate(int);
};

// Constructor, goes through corpus file and parses through data and puts in map
markovList::markovList(const char* filename)
{
	ifstream file(filename);
	stringstream parser, splitter;
	string line, index, word;
	float weight;
	//edge* newEdge;
	int i = 0;
	srand(time(0));
	
	if(file.good()) {
	file >> corpusSize;
	file.ignore(1, '\n');
	
	while(getline(file, line, '\n')) //map every word to a position in the matrix, keep the line in an array of buffers for later
	{
		parser.clear();
		parser << line;
		getline(parser, index,',');	//pulls the first word of the line, which is the node for which we're making a list of neighbors
		//initialize an empty list at the index---
		corpus[index] = NULL; // Set the head of list to NULL
		while(getline(parser, word, ','))
		{
			//allocate a new node in the edge list---
				// addEdge handles this
			splitter.clear();
			splitter.str(word);
			splitter >> word >> weight;
			//stick word and weight on the node you've just allocated---
				// addEdge handles this
			//make sure your new node is attached to the list---
			addEdge(index, word, weight); // call addEdge to add the new node to the list 
		}
	}}
}

// Destructor, loops through the entire map to delete all list for every index
markovList::~markovList()
{
	// Loop through each element in the map
	for(map<string, edge*>::iterator i = corpus.begin(); i != corpus.end(); i++)
	{
		string index = i->first; // current index word
		if(corpus[index] != NULL) // As long as it isnt an empty list
		{
			edge* prev = NULL;
			edge* cur = corpus[index];

			while(cur != NULL) // while not at end of lst
			{
				prev = cur;		// Swap and Delete node
				cur = cur->next;
				delete prev;
			}
		}
	}
	corpus.clear(); // clear the map
}

// Function will generate a passed argument number of words by randomly starting somewhere in the corpus and randomly selection a value in its list
string markovList::generate(int length)
{
	map<string, edge*>::iterator it = corpus.begin();	//initialize an iterator to find a random node in the next line
	advance(it,rand() % corpusSize);	//this grabs a random node from your corpus as a starting point
	//write the rest of this
	int counter = 0; // keeps track of how many words have been generated
	string generatedText; // string to save all the words generated
	string index; // corpus index for the word selected
	index = it->second->value; 

	while(counter != length) // While we havent generated 100 words
	{
		edge* nodePtr = corpus[index]; // set pointer to the correct position in map
		float weightSum = 0; // adds all weights from previous nodes to see if we can traverse to that node in list or not
		float randNum = (float) rand() / RAND_MAX; // generate random number to compare against weights sum 

		while(weightSum <= randNum && nodePtr->next != NULL) // while weightSum is less than are random number and not at the end of the list
		{
			weightSum += nodePtr->weight; // update weight
			nodePtr = nodePtr->next; // go to next value
		}

		index = nodePtr->value; // assign the new index for the word we were last able to traverse too
		generatedText = generatedText + " " + nodePtr->value; // add to string 
		counter++; // update counter 
	}
	return generatedText;
}

// Adds edge to the map
void markovList::addEdge(string index, string word, float weight)
{
	// Allocate the new Edge and assign its values
	edge* newEdge = new edge;
	newEdge->value = word;
	newEdge->weight = weight;
	newEdge->next = NULL;

	// If list is empty, assign it as the head
	if(corpus[index] == NULL)
	{
		corpus[index] = newEdge;
	}
	else // else, go through the list until you can put it at the end
	{
		edge* nodePtr = corpus[index];

		while(nodePtr->next != NULL)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newEdge;
	}
}

#endif