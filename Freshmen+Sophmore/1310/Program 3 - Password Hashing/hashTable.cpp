/*
        NAME:       Mason Lauderdale
        CLASS:      CSC-1310-001, Program 3
        DUE DATE:   Nov 7, 2022
*/
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"
using std::string;
using std::cout;

// Constructor, creates and fills hash table with NULL
hashTable::hashTable(int size)
{
	//you need to add everything else that belongs in the constructor--------------------------------------
	srand (time(0));	//this needs to be in the constructor, otherwise every user gets the same salt

	tableSize = size;
	hashArray = new entry*[tableSize];

	for(int i = 0; i < tableSize; i++)
	{
		hashArray[i] = NULL;
	}
}

// Destructor, deletes all values inside of hash table
hashTable::~hashTable()
{
	for(int i = 0; i < tableSize; i++)
	{
		if(hashArray[i] != NULL)
		{
			entry* prev = NULL;
			entry* cur = hashArray[i];

			while(cur != NULL)
			{
				prev = cur;
				cur = cur->next;
				delete prev;
			}
		}
	}

	delete [] hashArray;
}

//don't touch this!
string hashTable::generateSalt()
{
	string s = "";
	
	for(int i = 0; i < tableSize; i++)
		s = s + char('!' + (rand() % 93));
	return s;
}

// Calls getEntry to see if user is in hash table, if so then will return their salt by calling entry's getSalt getter function
string hashTable::getSalt(string user)
{
	entry* userEntry = getEntry(user);

	if(userEntry != NULL)
	{
		return userEntry->getSalt();
	}
	else // else If user not in table, tell user they dont exist, return impossible fake salt so the login doesn't work
	{
		cout <<"\nThis user does not exist, ";
		return "fakeSalt";
	}
}


// Dynamically creates a new hash entry, finds its correct index, then place it there and check if its a duplicate username or not
void hashTable::addEntry(string username, string userSalt, string userHashedpwd)
{
	entry* newEntry = new entry(username, userSalt, userHashedpwd);
	newEntry->next = NULL;

	int bucketIndex = hash(username); // call hash function to find the correct index in the hash table

	if(hashArray[bucketIndex] == NULL)
	{
		hashArray[bucketIndex] = newEntry;
	}
	else // Collision has occured
	{
		entry* entryPtr = hashArray[bucketIndex]; // Since chaining, set to first node in that index. traverse till we can add into that index
		while(entryPtr->next != NULL)
		{
			if (entryPtr->getUsername() == username) // if username's (keys) are the same, we can add it since username must be unique, break out of loop
			{
				break;
			}
			entryPtr = entryPtr->next;
		}
		if(entryPtr->getUsername() == username) // Handle case when the username's were the same as a already existing accounts
		{
			cout << "\n\nSorry! This username is already registered to an account. Please use it to login or create an account with a different username." << std::endl;
			delete newEntry; 
		}
		else // If it was unique, add to the end of the linked list in that bucket
		{
			entryPtr->next = newEntry;
		}


	}
}

// Checks if username is in the hash table, returns true or false.
bool hashTable::validateLogin(string username, string hashedpwd)
{
	entry* loginNode = getEntry(username);


	if(loginNode != NULL) // If node isnt empty, then we found the user.
	{
		if(loginNode->getHashedpwd() == hashedpwd) // if that user's hashed password is the same, valid login
		{
			return true;
		}
		else // if hashed password was incorrect, invalid login
		{
			return false;
		}
	}
	else // else if user's username was not found, invalid login
	{ 
		return false;
	}
}

//  removes user after they have a correct username and password to login with. 
bool hashTable::removeUser(string username, string hashedpwd)
{
	entry* entryPtr;
	entry* prevPtr;
	int bucketIndex = hash(username); // Get correct index location

	if(hashArray[bucketIndex] != NULL) // If location isnt empty
	{
		prevPtr = NULL;
		entryPtr = hashArray[bucketIndex]; 

		while(entryPtr->next != NULL && entryPtr->getUsername() != username) // while we are not at the end of the index's chained linked list, and username are not the same keeping moving forward one
		{
			prevPtr = entryPtr;
			entryPtr = entryPtr->next;
		}
		if(entryPtr->getUsername() == username && entryPtr->getHashedpwd() == hashedpwd) // if the username and hashed password match up
		{	
			if(prevPtr == NULL) // If there is only one node in the linked list (or its the first one)
			{
				entry* nextPtr = entryPtr->next;   
				delete entryPtr;
				hashArray[bucketIndex] = nextPtr;
				return true;
			} 
			else // else if not, swap the entry and prev pointer and delete the correct node, do this so linked list stays intact
			{
				entry* otherNextPtr = entryPtr->next;
				delete entryPtr;
				prevPtr->next = otherNextPtr;
				return true;
			}
		}
		else
		{
			return false; // passworrd incorrect
		}
	}
	else
	{
		return false; // Username not found in hash table
	}
}

//don't touch this!
int hashTable::hash(string key)
{
	int sum = 0;
	for(int i = 0; i < key.size(); i++)
		sum += key[i];
	
	return sum % tableSize;
}

// takes in a username and will check if they are in the hash table or not
hashTable::entry* hashTable::getEntry(string username)
{
	int bucketIndex = hash(username); // get correct index for the username key

	if(hashArray[bucketIndex] == NULL) // if location is null, not in hash table
	{
		return NULL;
	}
	else // if location has nodes in it, traverse until ptr isnt null and usernames match up 
	{
		entry* entryPtr = hashArray[bucketIndex];
		while(entryPtr != NULL && entryPtr->getUsername() != username)
		{
			entryPtr = entryPtr->next;
		}
		if(entryPtr == NULL) // If it goes through all the linked list and still not correct username, its not in hash table
		{
			return NULL;
		}
		else // other wise, return the correct node ptr
		{
			return entryPtr;
		}
	}
}

// Constructor, initializes entry attributes 
hashTable::entry::entry(string username, string userSalt, string hashedPwd)
{
	uname = username;
	salt = userSalt;
	passHash = hashedPwd;

	next = NULL;
}

// getter function that returns username
string hashTable::entry::getUsername()
{
	return uname;
}

// getter function that returns salt
string hashTable::entry::getSalt()
{
	return salt;
}

// getter function that returns hashed password
string hashTable::entry::getHashedpwd()
{
	return passHash;
}