//Krista Froiseth
//
//Linked Lists: This program manages a list of inventory items using a linked list. 
//Operations include adding a new inventory item at the end of the list, adding a new inventory item at the beginning of the list,
//removing an inventory item from the beginning of the list, removing an inventory item from the end of the list, removing an inventory item by name, 
//and displaying the current list of inventory items. User has option to quit.

#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include "inventoryHeader.h"

using namespace std;


/**********Main Function Prototypes************/
void welcome();
void displayMenu();
int getChoice();
string getItem();


/****MAIN****/
int main()
{
	Inventory inv;																	//create Inventory object
	string itemName;																//variable for name of item to be added to list
	int choice;																		//variable for menu choices

	welcome();																		//display message about the program
	cout << endl << "Press Enter to begin.";
	cin.get();
	do																				//start loop to display the menu and perform chosen fucntions as long as quit option is not selected
	{
		displayMenu();
		choice = getChoice();
		if (choice != 7)
		{
			switch (choice)
			{
			case 1: itemName = getItem();											//get item name
				inv.add_End(itemName);												//call function to add it to the end of the lst
				break;
			case 2: itemName = getItem();											//get item name
				inv.add_Begin(itemName);											//call function to add it to the beginning of the lst
				break;
			case 3: inv.remove_Begin();												//call function to remove the first item of the list
				break;
			case 4: inv.remove_End();												//call function to remove the last item of the list
				break;
			case 5: itemName = getItem();											//get item name
				inv.remove_Name(itemName);											//call function to remove the item chosen from the list
				break;
			case 6: inv.displayList();												//call function to display current contents of the list
				break;

			}
		}
	} while (choice != 7);															//continue loop until 7 is chosen; program ends
	cout << "Quitting..." << endl;
	return 0;
}

/*******************Functions********************/
void welcome()
{
	cout << "Welcome. This program will allow you to utilize a linked list\nto add and remove items to and from a list and display the current list." << endl;
}

/*Displays menu options for user*/
void displayMenu()
{
	system("cls");															//clear screen before redisplaying menu each time
	cout << "List Options\n";
	cout << "1.  Add item to the end of the list\n";
	cout << "2.  Add item to the beginning of the list\n";
	cout << "3.  Remove item from the beginning of the list\n";
	cout << "4.  Remove item from the end of the list\n";
	cout << "5.  Remove item from list by name\n";
	cout << "6.  Display current inventory list\n";
	cout << "7.  Quit\n\n";
}

/*Get valid menu choice from user*/
int getChoice()
{
	int choice;																				//create variable for user choice
	bool valid = false;																		//create bool variable and set it to false

	while (!valid)																			//start loop for user input
	{
		valid = true;																		//change bool to true, assuming input is correct/valid
		cout << "Please enter your choice: ";												//prompt user
		cin >> choice;																		//get input

		if (cin.fail())																		//if input is not an int
		{
			cin.clear();																	//clear buffer
			cin.ignore(20, '\n');															//ignore/discard input in buffer up tp 20 characters or until a new line is reached - this is incase user input a string
			cout << "Please enter an integer value." << endl;								//notify user input was not valid
			valid = false;																	//set bool flag to false and restart loop
		}
		else if (choice < 1 || choice > 7)													//if input is integer but not within the range
		{
			cin.clear();																	//clear buffer
			cin.ignore();																	//ignore input in buffer
			cout << "Invalid input. Options are 1-7. Please re-enter: ";					//notify user input was not valid
			valid = false;																	//set bool flag to false and restart loop
		}
	}
	return choice;																			//return validated choice to main
}

/*Get name of item*/
string getItem()
{
	string itemName;																		//create variable for item 
	cout << "Please enter an item: ";														//prompt user
	cin.ignore();																			//clear buffer for user input
	getline(cin, itemName);																	//get user input
	while (itemName.length() == 0)																//if empty, prompt for input
	{

		cout << "Please enter an item: ";
		getline(cin, itemName);
	}

	transform(itemName.begin(), itemName.end(), itemName.begin(), ::tolower);				//make input all lower case to avoid issues when adding or removing items i.e. "Bottle" vs "bottle"

	return itemName;																		//return item name to main
}