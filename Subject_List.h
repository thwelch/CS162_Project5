/*
* Author: Thomas Welch
* Date: 11/27/2016
* Program #5
* Purpose: This program maintains a way to keep track of what we have learned in CS this year, maintained using a linear linked list, with functions
* designed to search, add subjects, remove subjects, and display them all in a sorted alphabetical manner
*/



#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


struct Subject
{
	  char *name; //holds the name of a subject 
	  char *description; //holds the descrition of a subject
	  int rating; //holds the rating of a subject
	  char *improve; //holds the ways to improve
};

struct node
{
	Subject * data; //holds the data for the subject
	node * next; //holds next node
};

class Subject_List
{
public:
	Subject_List(); //constructor, sets size to 10, count to zero and creates a dynamic array of that size
	~Subject_List(); //destructor, destroys all the dynamically sized arrays then deletes them when done
	void read(); //reads in a new input and stores it
	void display_sorted(); //displays all the entries
	void search(); //searces for a given input
	void remove(); //removes a selected entry, deletes the dynamically assigned memory and then sets the bool exists to false so it wont be read in again
	void insert(node * newnode);
	int getSelection(int, int); // a helper function for getting selections within a certain min-max value
private:
	node * head; //pointer the an array of Subject strurues
	int count; //current count of array filled up
};

