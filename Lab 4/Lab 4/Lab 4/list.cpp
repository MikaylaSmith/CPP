/*************************
* Author: Mikayla Smith
* Filename: list.cpp
* Date Created: 5/6/21
* Modifications:
***************************/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_NODES = 10
#include "list.h"
#include "sales.h"
#include "temp.h"
#include "manager.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

/***********
* Class: List
*
* Purpose:
*	The purpose of this function is to manage the execution of adding, deleting or printing
*	nodes to the linked list.
*
* Manager Functions:
*	List()
*		This is a default constructor.
*	~List()
*		This is the default deconstructor.
*	List(const List& copy)
*		The copy constructor.
*	operator=(const List& rhs)
*
* Methods:
*	AddData(char action, int work, char* lname, char* fname, int birth, int employ)
*		Takes in the information that was read in from the file, then
*	DeleteDate(char action, char* last)
*		Iterates through the list, comparing the last name read from the file to the key value stored in
*		the node. Once the node with the desired key is located, that node is deleted from the list.
*		If there is no node with that same key, an error message is outputted to the output file.
*	ListDisplay()
*		Iterates through the list displaying the WorkID, lastName, firstName, DateOfBirth, DateOfEmployment
*		of each node in the list.
*	Search(char* lname, int row)
*		Look through the designated row for the correct node in the linked list.
*		Prints out to file which node in list and the specified row.
*	GetCount()
*		Returns the total nodes in the linked list (Max of 10).
*	GetHead()
*		Returns the pointer of the head node of the linked list.
*	SetEnd()
*		Sets m_end to the value of the last node in the linked list (node whose next is nullptr).
*	GetEnd()
*		Returns the value of the pointer of the last node in the linked list (m_end)
*
*
***********/

List::List() : m_head(nullptr), m_end(nullptr), m_count(0)
{

}
List::~List()
{
	cout << "List Dtor" << endl;
	Node* temp = nullptr;
	while (m_head != nullptr)
	{
		temp = m_head;
		m_head = m_head->GetNext();
		delete temp;
	}
	m_head = nullptr;
}
List::List(const List& copy)
{
	m_head = copy.m_head;
	m_end = copy.m_end;
	m_count = copy.m_count;
}
List& List::operator=(const List& rhs)
{
	this->m_head = rhs.m_head;
	this->m_end = rhs.m_end;
	this->m_count = rhs.m_count;
	return *this;
}

/* Methods */
void List::AddData(Node* newNode)
{
	/*********
	* Purpose:
	*	Take the new node that was created in the Command Handle and add it to the correct location
	*	within the linked list.
	* Precondition:
	*	New Node was created and action read from the file.
	* Postcondition:
	*	 A new node has been added to the linked list.
	***********/

	//if (m_head == nullptr || strcmp(newNode->GetData()->GetLName(), m_head->GetData()->GetLName()) < 0)
	if(m_head == nullptr || *newNode > *m_head)
	{
		newNode->SetNext(m_head);
		m_head = newNode;
		m_count++;
	}
	else
	{
		Node* current = m_head;
		Node* previous = nullptr;

		//while (current != nullptr && strcmp(current->GetData()->GetLName(), newNode->GetData()->GetLName()) < 0)
		while (current != nullptr && *current > *newNode)
		{
			previous = current;
			current = current->GetNext();
		}
		previous->SetNext(newNode);
		newNode->SetNext(current);

		current = nullptr;
		previous = nullptr;
		delete current;
		delete previous;
		m_count++;
	}
	SetEnd();
}
void List::DeleteData(char* lname)
{
	/*********
	* Purpose:
	*	Take in the last name of a desired last name and delete the correspoding node
		from the linked list.
	* Precondition:
	*	Action and last name read from file.
	* Postcondition:
	*	The node whose last name value corresponds to the value read in from file has been
	*	removed from the linked list or error message has been displayed.
	***********/
	ofstream outFile("Lab 4 Output.txt", ios::app);

	if (outFile.is_open())
	{
		if (m_head == nullptr)
		{
			outFile << "Nothing to Delete." << endl;
		}
		else if (m_head != nullptr)
		{
			Node* current = m_head;
			Node* previous = nullptr;

			if (strcmp(lname, m_head->GetData()->GetLName()) == 0)
			{
				cout << "Deleting " << lname << " Success" << endl;
				previous = m_head;
				m_head = m_head->GetNext();
				delete previous;

				outFile << "Success!" << endl;
				outFile << endl;
				m_count--;
			}
			else
			{
				while (current != nullptr && strcmp(lname, current->GetData()->GetLName()) != 0)
				{
					previous = current;
					current = current->GetNext();
				}
				if (current == nullptr)
				{
					cout << "Deleting " << lname << " Failure" << endl;
					outFile << "Failure!" << endl;
					outFile << endl;
				}
				else
				{
					previous->SetNext(current->GetNext());
					previous = nullptr;

					delete current;
					delete previous;

					cout << "Deleting " << lname << " Success" << endl;
					outFile << "Success!" << endl;
					outFile << endl;
					m_count--;
				}
			}
		}
		outFile.close();
	}
	SetEnd();
}
void List::Search(char* lname, int row)
{
	/*********
	* Purpose:
	*	Search through the list and try to locate the desired name.
	* Precondition:
	*	List holds nodes that hold a value in m_lastName.
	* Postcondition:
	*	The information associated with the last name is printed to output file.
	*	If the last name was not found in the list, error message printed to file.
	***********/
	Node* current = m_head;
	int elementCount = 0;
	ofstream outFile("Lab 4 Output.txt", ios::app);
	if (outFile.is_open())
	{
		while (current != nullptr && strcmp(lname, current->GetData()->GetLName()) != 0)
		{
			current = current->GetNext();
			elementCount++;
		}

		if (current == nullptr)
		{
			outFile << "Unable to find \"" << lname << "\"..." << endl;
		}
		else
		{
			outFile << "Found at: Element " << elementCount << " of Row " << row << endl;
			current->GetData()->Display();
		}
		outFile << endl;
		outFile.close();
	}
	else
	{
		cout << "Error Opening File." << endl;
	}

	current = nullptr;
	delete current;
}
void List::ListDisplay()
{
	/*********
	* Purpose:
	*	Iterate through the whole linked list and display the following from each node in the
		linked list:
	*	- WorkID
	*	- Last Name
	*	- First Name
	*	- Birthdate
	*	- Employment Date
	* Precondition:
	*	Object from class "List" exists.
	* Postcondition:
	*	Output file contains ordered list with all nodes.
	***********/

	Node* current = m_head;
	if (m_head == nullptr)
	{
		ofstream outFile("Lab 4 Output.txt", ios::app);
		if (outFile.is_open())
		{
			outFile << "List is Empty." << endl;
			outFile.close();
		}
	}
	else if (m_head != nullptr)
	{
		while (current != nullptr)
		{
			current->GetData()->Display();
			current = current->GetNext();
		}
	}
	delete current;
}
int List::GetCount()
{
	/*********
	* Purpose:
	*	Return the number of nodes in a linked list.
	* Precondition:
	*	m_count holds a value representing the number of nodes in the list (max of 10) or is 0.
	* Postcondition:
	*	The value of m_count is returned.
	***********/
	return m_count;
}
Node* List::GetHead()
{
	/*********
	* Purpose:
	*	Return the pointer to the head of the list.
	* Precondition:
	*	m_head holds a value of the first node in the list or is nullptr.
	* Postcondition:
	*	The pointer of m_head is returned.
	***********/
	return m_head;
}
void List::SetEnd()
{
	/*********
	* Purpose:
	*	Set the pointer to the last node in the linked list to m_end.
	* Precondition:
	*	The list has nodes or is empty.
	* Postcondition:
	*	A pointer for the last node has been assigned to m_end.
	***********/
	if (m_head == nullptr || m_head->GetNext() == nullptr)
	{
		m_end = nullptr;
	}
	else
	{
		Node* current = m_head;
		while (current->GetNext() != nullptr)
		{
			current = current->GetNext();
		}
		current->SetNext(nullptr);
		m_end = current;
		current = nullptr;
		delete current;
	}

}
Node* List::GetEnd()
{
	/*********
	* Purpose:
	*	Return pointer to the last node in the linked list.
	* Precondition:
	*	m_end holds a pointer to the last node in the linked list or is nullptr.
	* Postcondition:
	*	The value of m_count is returned.
	***********/
	return m_end;
}
void List::RemoveEnd()
{
	/*********
	* Purpose:
	*	Iterate through the list and remove the last node, setting the second to last node as the last
	*	node.
	* Precondition:
	*	The last node needs to be removed from the list because m_count = 10.
	* Postcondition:
	*	m_end has been removed and m_end is now set to the value of the previously second to last node.
	*	Since a node has been deleted, m_count is now m_count - 1.
	***********/
	Node* current = m_head;
	while (current->GetNext()->GetNext() != nullptr)
	{
		current = current->GetNext();
	}
	current->SetNext(nullptr);
	m_end = current;
	current = nullptr;
	delete current;
	m_count--;
}

void List::Pay()
{
	/*********
	* Purpose:
	*	Iterate through the list and calculate how much each person gets paid.
	* Precondition:
	*	The values regarding pay in Sales, Temp and Manager are all set.
	* Postcondition:
	*	The value for each indivdual has been calculated and written to the output file.
	***********/
	ofstream outFile("Lab 4 Output.txt", ios::app);
	if (outFile.is_open())
	{
		outFile << endl;
		outFile << "****** Printing Paychecks ******" << endl;
		outFile.close();
	}
	else
	{
		cout << "Error Openning File." << endl;
	}

	Node* current = m_head;
	if (m_head == nullptr)
	{
		ofstream outFile("Lab 4 Output.txt", ios::app);
		if (outFile.is_open())
		{
			outFile << "List is Empty." << endl;
			outFile.close();
		}
	}
	else if (m_head != nullptr)
	{
		while (current != nullptr)
		{
			current->GetData()->Pay();
			current = current->GetNext();
		}
	}
	delete current;
}

void List::Cast()
{
	/*********
	* Purpose:
	*	Iterate through the list and downcast each m_Person, writing it to the output file.
	* Precondition:
	*	The m_Person holds a Sales, Temp or Manager object.
	* Postcondition:
	*	The object type of each node in the list has been written to the output file.
	***********/
	ofstream outFile("Lab 4 Output.txt", ios::app);

	if (outFile.is_open())
	{
		outFile << endl;
		outFile << "****** Printing Type ******" << endl;
		Node* current = m_head;

		while (current != nullptr)
		{
			if (dynamic_cast<Sales*>(current->GetData()))
			{
				outFile << current->GetData()->GetLName() << ": " << typeid(*current->GetData()).name() << endl;
			}
			else if (dynamic_cast<Temp*>(current->GetData()))
			{
				outFile << current->GetData()->GetLName() << ": " << typeid(*current->GetData()).name() << endl;
			}
			else if (dynamic_cast<Manager*>(current->GetData()))
			{
				outFile << current->GetData()->GetLName() << ": " << typeid(*current->GetData()).name() << endl;
			}
			current = current->GetNext();
		}
		outFile << endl;
		outFile.close();
		delete current;
	}
	else
	{
		cout << "Error Openning File." << endl;
	}

}

