#include "Subject_List.h"


//constructs the subject list, setting head to null and count to zero
Subject_List::Subject_List()
{
	count = 0;
	head = NULL;
	
}

//destroys the entirety of the list, ensuring no memory leaks
Subject_List::~Subject_List()
{
	if (!head)
		return;
	node * temp = head; //node to keep track of what to remove now
	node * curr = head; //node to keep track of what to remove next
	while (temp)
	{
		curr = temp->next;
		delete [] temp->data->name;
		delete [] temp->data->description;
		delete [] temp->data->improve;
		delete temp->data;
		delete temp;
		temp = curr;
	}
	head = NULL;
	
}

//reads data in from the user and creates a Subject object for that structure
void Subject_List::read()
{	
		char temp[1000];//arbitrary size to read into
		cout << "Enter the subject's name: ";
		cin.get(temp, 1000, '\n');
		cin.ignore(1000, '\n');
		char * name1 = new char[strlen(temp) +1];
		strcpy(name1, temp);
		cout << endl;
		cout << "What have you learned about this subject: ";
		cin.get(temp, 1000, '\n');
		cin.ignore(1000, '\n');
		char * description1 = new char[strlen(temp) +1];
		strcpy(description1, temp);
		cout << endl;
		cout << "How confident do you feel about this topic(1- not comfortable, 10 - I know it all): ";
		int rating1 = getSelection(1, 10);
		cout << endl;
		cout << "What can you do to improve: ";
		cin.get(temp, 1000, '\n');
		cin.ignore(1000,'\n');
		char * improve1 = new char[strlen(temp) +1];
		strcpy(improve1, temp);
		++count;
		Subject * newS = new Subject;
		newS->name = name1;
		newS->description = description1;
		newS->rating = rating1;
		newS->improve = improve1;
		node * newnode = new node;
		newnode->data = newS;
		newnode->next = NULL;
		insert(newnode);
}

//inserts a new node into the list, sorted alphabetically,maintaing the integrity of the list
void Subject_List::insert(node * newnode)
{
	if (!head) //if the list is empty, insert at head
	{
		head = newnode;
		return;
	}
	node * temp = head; //keep track of location to insert before
	node * prev = head; //keep track of location to insert after
	
	
	if (strcmp(temp->data->name, newnode->data->name) > 0) //if the new node is to be inserted before the first node
	{
		newnode->next = head;
		head = newnode;
		return;
	} 
	while (temp && (!strcmp(temp->data->name, newnode->data->name) <= 0)) //if the new node is to be inserted somewhere in the middle or end, find the location
	{
		prev = temp;
		temp = temp->next;
	}
	if(!temp) //if the node is to be inserted at the very end of the list
	{
		prev->next = newnode;
	}
	else //else the node is inserted between prev and temp
	{
		prev->next = newnode;
		newnode->next = temp;
	}
	
}

int Subject_List::getSelection(int min, int max)
{
	int selection; //selection to make sure it is in range
	cin >> selection;
	while (!cin)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "You did not enter an integer!!" << endl;
		cout << "Try again!: ";
		cin >> selection;
		cout << endl;
	}
	cin.ignore(1000, '\n');
	
	while (selection > max || selection < min) //repeat until selection is in range
	{
		cout << "Selection out of range!" << endl;
		cout << "Try again: ";
		cin >> selection;
		cin.ignore(1000 ,'\n');
	}
	return selection;
}


void Subject_List::display_sorted()
{
	if (!head)
		return;
	
	node * temp = head; //node to traverse
	cout << "DISPLAYING SUBJECTS SORTED ALPHABETICALLY" << endl;
	while (temp)
	{
		cout << "Subject: " << temp->data->name << endl;
		cout << "Description: " << temp->data->description << endl;
		cout << "Rating: " << temp->data->rating << endl;
		cout << "Improve: " << temp->data->improve << endl;
		cout << endl;
		temp = temp->next;
	}
	
}

void Subject_List::search()
{
	char input[500]; //temp array for input
	cout << "what subject would you like to search for: ";
	cin.get(input, 200, '\n');
	cin.ignore(200, '\n');
	cout << endl;
	bool status = false; //status determines if the subject is even in the list, set to false by default, true if found
	node * temp = head;
	while (temp)
	{
		if (strcmp(temp->data->name, input) == 0)
			{
				cout << "This matches your inquiry" << endl;
				cout << "Subject: " << temp->data->name << endl;
				cout << "Descripton: " << temp->data->description << endl;
				cout << "Rating: " << temp->data->rating << endl;
				cout << "Ways to improve: " << temp->data->improve << endl;
				status = true;
			}
		temp = temp->next;
	}
	if (status == false)
		cout << "This subject was not found in the list!" << endl;
}

void Subject_List::remove()
{
	cout << "List of current subjects" << endl;
	
	node * temp = head; //node to keep track of where to insert before
	while (temp)
	{
		cout << temp->data->name << endl;
		temp = temp->next;
	}
	temp = head;
	node * prev = head; //node to keep track of where to insert after
	if (!temp)
	{
		cout << "EMPTY LIST" << endl;
		return;
	}
	
	char input[200]; //temp array for input
	cout << "what subject would you like to delete:";
	cin.get(input, 200,'\n');
	cin.ignore(200, '\n');
	cout << endl;
	bool status = false; //bool to keep track of when node to remove is found, false by default
	
	if (strcmp(temp->data->name, input) == 0)
	{
		temp = head->next;
		delete [] head->data->name;
		delete [] head->data->description;
		delete [] head->data->improve;
		delete head->data;
		delete head;
		head = temp;
		--count;
		return;
	}
	
	while(temp && !status) //while end of list is not reached and node to remove is not found
	{
			if(strcmp(temp->data->name,input) == 0)
			{
				status = true; //if node is found, status set to true
			}
			else
			{
				prev = temp;
				temp = temp->next;
			}
	}
	
	if (!temp)
	{
		cout << "Could not find that entry" << endl;
	}
	if (status)
	{
		cout << "Removing: " << temp->data->name << endl;
		prev->next = temp->next;
		delete [] temp->data->name;
		delete [] temp->data->description;
		delete [] temp->data->improve;
		delete temp->data;
		delete temp;
		--count;

	}
	
}


