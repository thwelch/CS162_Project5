#include "Subject_List.h"

int main()
{
	Subject_List sublist;
	int selection = 0; //variable holding user selection
	
	
	while (selection != 5)
	{
		cout << endl;
		cout << "Welcome to the CS162 Practice Program" << endl;
		cout << "Here are your options: " << endl;
		cout << "1 - Add a new subject" << endl;
		cout << "2 - Display all subjects entered" << endl;
		cout << "3 - Search entries entered" << endl;
		cout << "4 - Remove an entry" << endl;
		cout << "5 - Quit this program" << endl;
		cout << endl;
		cout << "Make your selection: ";
		selection = sublist.getSelection(1, 5);
		cout << endl;
		if (selection == 1)
			sublist.read(); 
 		if (selection == 2)
			sublist.display_sorted();
		if (selection == 3)
			sublist.search();
		if (selection == 4)
			sublist.remove();
	}
	cout << "Goodbye!" << endl;
}
