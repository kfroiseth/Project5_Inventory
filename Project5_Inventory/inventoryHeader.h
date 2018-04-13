//Krista Froiseth
//
//Linked Lists: This program manages a list of inventory items using a linked list. 
//Operations include adding a new inventory item at the end of the list, adding a new inventory item at the beginning of the list,
//removing an inventory item from the beginning of the list, removing an inventory item from the end of the list, removing an inventory item by name, 
//and displaying the current list of inventory items. User has option to quit.

#pragma once
#ifndef inventoryHead_H
#define inventoryHead_H 

using namespace std;

class Inventory
{
	//declare a class for the list node		
protected:
	struct ListNode
	{
		string inventoryItem;
		ListNode *next;
		ListNode(string inventoryItem1, ListNode *next1 = NULL)
		{
			inventoryItem = inventoryItem1;
			next = next1;
		}
	};
	ListNode *head;								//list head pointer
												//class member functions
public:
	Inventory() { head = NULL; }				//constructor 
	~Inventory();								//desctructor
	bool unique(string item);
	void add_End(string item);					//add item at end
	void add_Begin(string item);				//add item at beginning
	void remove_Begin();						//remove item from beginning
	void remove_End();							//remove item from end
	void remove_Name(string item);				//remove item by name
	void displayList() const;					//display current list contents
};

#endif 
