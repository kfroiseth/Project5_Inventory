#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include "inventoryHeader.h"

using namespace std;


/*******Inventory Member Functions*******/

/*Destructor*/
Inventory::~Inventory()
{
	ListNode *nodePtr = head;
	while (nodePtr != NULL)
	{
		ListNode *garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}

/*Function to determine if item is already in the list*/
bool Inventory::unique(string i)
{
	bool unique = true;															//initialize bool variable unique to true, assuming item is unique

	ListNode *nodePtr = head;													//initialize nodePtr to the head of the list
	while (nodePtr != NULL)														//traverse through list
	{
		if (nodePtr->inventoryItem == i)										//if item is found in one of the nodes, change bool flag to false
			unique = false;
		nodePtr = nodePtr->next;
	}
	return unique;																//return unique
}

/*Function to add an item to the end of the list*/
void Inventory::add_End(string item)
{

	if (head == NULL)																				//if list is empty, add new item to start of the list
	{
		head = new ListNode(item);
		cout << endl << item << " added to the end of the inventory list." << endl;					//notify user of update and prompt to return to main menu.
		cout << "Press Enter to return to the menu. ";
		cin.get();
		//cin.get();
	}

	else if (unique(item))																			 //else, set nodePtr to head and work through nodes until the end of the list is reached (nodePtr->next==NULL)
	{
		ListNode *nodePtr = head;
		while (nodePtr->next != NULL)
			nodePtr = nodePtr->next;																//NodePtr now points to last node in the list

		nodePtr->next = new ListNode(item);															//create a new node and put it after the last node in the list

		cout << endl << item << " added to the end of the inventory list." << endl;						//notify user of update and prompt to return to main menu.
		cout << "Press Enter to return to the menu. ";
		cin.get();
		//cin.get();
	}
	else if (!unique(item))
	{
		cout << endl << "Item is already in inventory list. Please enter a unique item." << endl;
		cout << "Press Enter to return to the menu. ";
		cin.get();
		//cin.get();
	}
}

/*Function to add an item to the beginning of the list*/
void Inventory::add_Begin(string item)
{
	if (head == NULL)																				//if list is empty, add new item to start of the list
	{
		head = new ListNode(item);
		cout << endl << item << " added to the end of the inventory list." << endl;					//notify user of update and prompt to return to main menu.
		cout << "Press Enter to return to the menu. ";
		cin.get();
	}
	else if (unique(item))																			//else, create a new node, set head of list to new item and set its pointer to the previous head
	{
		ListNode *nodePtr = new ListNode(item);
		nodePtr->inventoryItem = item;
		nodePtr->next = head;
		head = nodePtr;

		cout << endl << item << " added to the beginning of the inventory list." << endl;			//notify user of update and prompt to return to main menu.
		cout << "Press Enter to return to the menu. ";
		cin.get();
		//cin.get();
	}
	else if (!unique(item))
	{
		cout << endl << "Item is already in inventory list. Please enter a unique item." << endl;
		cout << "Press Enter to return to the menu. ";
		cin.get();
		//cin.get();
	}

}

/*Function to remove an item from the beginning of the list*/
void Inventory::remove_Begin()
{
	ListNode *nodePtr;																	//List node pointer

	if (!head)																			//if there is no head, list is empty, notify user and return to main menu
	{
		cout << endl << "List is empty. Nothing to remove." << endl;
		cout << "Press Enter to return to the menu.";
		cin.get();
		cin.get();
		return;
	}

	else
	{
		nodePtr = head;																	//else, initialize nodePtr to the head of the list
		head = head->next; 																//set the head to the next node in the list
		delete nodePtr;																	//delete nodePtr (which points to head )

		cout << endl << "Item removed from the beginning of the list." << endl;				//notify user and return to main menu
		cout << "Press Enter to return to the menu. ";
		cin.get();
		cin.get();
	}
}

/*Function to remove an item from the end of the list*/
void Inventory::remove_End()
{
	//ListNode *nodePtr;																//List node pointer
	if (!head)																			//if there is no head, list is empty, notify user and return to main menu
	{
		cout << endl << "List is empty. Nothing to remove." << endl;
		cout << "Press Enter to return to the menu.";
		cin.get();
		cin.get();
		return;
	}


	if (head->next == NULL)																//if list is not empty and head is also last item in the list, delete the head and set it back to NULL
	{
		delete head;
		head = NULL;
	}
	else {																				//else, set previousPtr to head of list and nodePtr to next item in list 
		ListNode *previousPtr = head;
		ListNode *nodePtr = head->next;
		while (nodePtr->next != NULL) {													//traverse the list to the end until nodePtr == NULL					
			previousPtr = nodePtr;
			nodePtr = nodePtr->next;
		}
		delete nodePtr;																	//delete the last item (nodePtr)
		previousPtr->next = NULL;														//previousPtr is now the last item, set it's pointer to NULL
	}
	cout << endl << "Item removed from the end of the list." << endl;					//notify user and return to the main menu
	cout << "Press Enter to return to the menu. ";
	cin.get();
	cin.get();

}

/*Function to remove an item from the list by name*/
void Inventory::remove_Name(string item)
{
	ListNode *nodePtr;																	//set list node pointer

	if (!head)																			//if there is no head, list is empty, notify user and return to main menu
	{
		cout << endl << "Nothing in list to remove." << endl;
		cout << "Press Enter to return to the menu. ";
		cin.get();
		//cin.get();
		return;
	}


	if (head->inventoryItem == item)													//if the first item in the list is the item to remove
	{
		nodePtr = head;																	//initialize nodePtr to the head of the list
		head = head->next;																//make the next item in the list the new head
		delete nodePtr;																	//delete nodePtr holding original head
		cout << endl << item << " removed from the list." << endl;						//notify user and return to menu
		cout << "Press Enter to return to the menu. ";
		cin.get();
		//cin.get();
	}
	else
	{
		nodePtr = head;																	//else, initialize nodePtr to the head of the list
		ListNode *previousNodePtr = nodePtr;
		while (nodePtr != NULL && nodePtr->inventoryItem != item)						//skip items whose value is not our item or until end is reached
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr)
		{
			previousNodePtr->next = nodePtr->next;										//if item is found, link the previous node to the node after our item
			delete nodePtr;																//delete the item
			cout << endl << item << " removed from the list." << endl;					//notify user and return to the menu
			cout << "Press Enter to return to the menu. ";
			cin.get();
			//cin.get();
		}
		else																			//else, item is not in list; notify user
		{
			cout << endl << item << " not found in the list." << endl;
			cout << "Press Enter to return to the menu. ";
			cin.get();
			//	cin.get();
		}
	}

}

/*Function to display the current list*/
void Inventory::displayList() const
{
	ListNode * nodePtr = head;															//initialize nodePtr to the head of the list
	if (nodePtr == NULL)																//if NULL, list is empty, notify user
	{
		cout << "List is empty" << endl;
	}
	else																				//else, print the value of the current node and continue while there is a next item
	{
		cout << endl;
		cout << "****Current Inventory Listing****" << endl << endl;
		while (nodePtr)
		{
			cout << nodePtr->inventoryItem << endl;
			nodePtr = nodePtr->next;
		}
	}
	cout << endl;
	cout << "Press Enter to return to the menu. ";
	cin.get();
	cin.get();
}