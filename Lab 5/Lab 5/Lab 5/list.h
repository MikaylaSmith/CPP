/*************************
* Author: Mikayla Smith
* Filename: list.h
* Date Created: 5/24/21
* Modifications:
***************************/
/***********
* Class: List
*
* Purpose:
*	The purpose of this class is to manage the reading data from the file,
*	determining which action should be taken, and executing the necessary list
*	method.
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
*	AddData(Node* newNode)
*		Add new node to the correct location in the linked list.
*	DeleteData(char* lname)
*		Search through the linked list and when encounters lname, delete the node from the list.
*		Display error if its not in the linked list. 
*	Display()
*		Iterate through the list and display the data from the node
*	GetCount()
*		Display the total number of Personnel objects created during execution
*
*
***********/
#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "node.h"
#include "personnel.h"
using namespace std;

template <class T>
class List
{
public:
	List();
	~List();
	List(const List& copy);
	List& operator=(const List& rhs);

	void AddData(Node<T>* newNode);
	void DeleteData(char* lname);
	void Display();

	void GetCount();
private:
	Node<T>* m_head;
};

template<typename T>
inline List<T>::List() : m_head(nullptr)
{

}

template<typename T>
inline List<T>::~List()
{
	Node<T>* temp = nullptr;
	while (m_head != nullptr)
	{
		temp = m_head;
		m_head = m_head->GetNext();
		delete temp;
	}
	m_head = nullptr;
}

template<typename T>
inline List<T>::List(const List& copy)
{
	m_head = copy.m_head;
}

template<typename T>
inline List<T>& List<T>::operator=(const List& rhs)
{
	this->m_head = rhs.m_head;
	return *this;
}

/* Methods */
template<typename T>
inline void List<T>::AddData(Node<T>* newNode)
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

	if (m_head == nullptr || strcmp(newNode->GetData().GetLName(), m_head->GetData().GetLName()) < 0)
	{
		newNode->SetNext(m_head);
		m_head = newNode;
	}
	else
	{
		Node<T>* current = m_head;
		Node<T>* previous = nullptr;

		while (current != nullptr && strcmp(current->GetData().GetLName(), newNode->GetData().GetLName()) < 0)
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
	}
}

template<typename T>
inline void List<T>::DeleteData(char* lname)
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
	ofstream outFile("Lab 5 Output.txt", ios::app);

	if (outFile.is_open())
	{
		if (m_head == nullptr)
		{
			outFile << "Nothing to Delete." << endl;
		}
		else if (m_head != nullptr)
		{
			Node<T>* current = m_head;
			Node<T>* previous = nullptr;

			if (strcmp(lname, m_head->GetData().GetLName()) == 0)
			{
				previous = m_head;
				m_head = m_head->GetNext();
				delete previous;
			}
			else
			{
				while (current != nullptr && strcmp(lname, current->GetData().GetLName()) != 0)
				{
					previous = current;
					current = current->GetNext();
				}
				if (current == nullptr)
				{
					outFile << "Error " << lname << " not in list." << endl;
				}
				else
				{
					previous->SetNext(current->GetNext());
					previous = nullptr;

					delete current;
					delete previous;
				}
			}
		}
		outFile.close();
	}
}

template<typename T>
inline void List<T>::Display()
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

	Node<T>* current = m_head;
	if (m_head == nullptr)
	{
		ofstream outFile("Lab 5 Output.txt", ios::app);
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
			current->GetData().Display();
			current = current->GetNext();
		}
	}
	delete current;
}

template<typename T>
inline void List<T>::GetCount()
{
	/*********
	* Purpose:
	*	Display the Total Number of Personnel Objects made in the process of the execution of 
	*	program.
	* Precondition:
	*	Object from class "Personnel" Created.
	* Postcondition:
	*	Output file contains total number of Personnel objects created.
	***********/
	ofstream outFile; outFile.open("Lab 5 Output.txt", ios::app);
	if (outFile.is_open())
	{
		outFile << "Total Personnel Objects Made:" << Personnel::GetCount() << endl;
		outFile.close();
	}
	else
	{
		cout << "Error Openning File." << endl;
	}
}
