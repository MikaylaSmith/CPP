///*************************
//* Author: Mikayla Smith
//* Filename: list.cpp
//* Date Created: 5/24/21
//* Modifications:
//***************************/
//#define _CRT_SECURE_NO_WARNINGS
//#include "list.h"
//#include <iostream>
//#include <fstream>
//#include <cstring>
//#include <iomanip>
//using namespace std;
//
///***********
//* Class: List
//*
//* Purpose:
//*	The purpose of this function is to manage the execution of adding, deleting or printing
//*	nodes to the linked list.
//*
//* Manager Functions:
//*	List()
//*		This is a default constructor.
//*	~List()
//*		This is the default deconstructor.
//*	List(const List& copy)
//*		The copy constructor.
//*	operator=(const List& rhs)
//*
//* Methods:
//*	AddData(char action, int work, char* lname, char* fname, int birth, int employ)
//*		Takes in the information that was read in from the file, then
//*	DeleteDate(char action, char* last)
//*		Iterates through the list, comparing the last name read from the file to the key value stored in
//*		the node. Once the node with the desired key is located, that node is deleted from the list.
//*		If there is no node with that same key, an error message is outputted to the output file.
//*	Display()
//*		Iterates through the list displaying the WorkID, lastName, firstName, DateOfBirth, DateOfEmployment
//*		of each node in the list.
//*
//*
//***********/
//template<typename T>
//inline List<T>::List() : m_head(nullptr)
//{
//	
//}
//
//template<typename T>
//inline List<T>::~List()
//{
//	Node<Personnel>* temp = nullptr;
//	while (m_head != nullptr)
//	{
//		temp = m_head;
//		m_head = m_head->GetNext();
//		delete temp;
//	}
//	m_head = nullptr;
//}
//
//template<typename T>
//inline List<T>::List(const List& copy)
//{
//	m_head = copy.m_head;
//}
//
//template<typename T>
//inline List<T>& List<T>::operator=(const List& rhs)
//{
//	this->m_head = rhs.m_head;
//	return *this;
//}
//
///* Methods */
//template<typename T>
//inline void List<T>::AddData(Node<T> newNode)
//{
//	/*********
//	* Purpose:
//	*	Take the new node that was created in the Command Handle and add it to the correct location
//	*	within the linked list.
//	* Precondition:
//	*	New Node was created and action read from the file.
//	* Postcondition:
//	*	 A new node has been added to the linked list.
//	***********/
//
//	if (m_head == nullptr || strcmp(newNode.GetData().GetLName(), m_head->GetData().GetLName()) < 0)
//	{
//		newNode.SetNext(m_head);
//		m_head = &newNode;
//	}
//	else
//	{
//		Node<T>* current = m_head;
//		Node<T>* previous = nullptr;
//
//		while (current != nullptr && strcmp(current->GetData().GetLName(), newNode.GetData().GetLName()) < 0)
//		{
//			previous = current;
//			current = current->GetNext();
//		}
//		previous->SetNext(&newNode);
//		newNode.SetNext(current);
//
//		current = nullptr;
//		previous = nullptr;
//		delete current;
//		delete previous;
//	}
//}
//
//template<typename T>
//inline void List<T>::DeleteData(char* lname)
//{
//	/*********
//	* Purpose:
//	*	Take in the last name of a desired last name and delete the correspoding node
//		from the linked list.
//	* Precondition:
//	*	Action and last name read from file.
//	* Postcondition:
//	*	The node whose last name value corresponds to the value read in from file has been
//	*	removed from the linked list or error message has been displayed.
//	***********/
//	ofstream outFile("Lab 5 Output.txt", ios::app);
//
//	if (outFile.is_open())
//	{
//		if (m_head == nullptr)
//		{
//			outFile << "Nothing to Delete." << endl;
//		}
//		else if (m_head != nullptr)
//		{
//			Node<T>* current = m_head;
//			Node<T>* previous = nullptr;
//
//			if (strcmp(lname, m_head->GetData().GetLName()) == 0)
//			{
//				previous = m_head;
//				m_head = m_head->GetNext();
//				delete previous;
//			}
//			else
//			{
//				while (current != nullptr && strcmp(lname, current->GetData().GetLName()) != 0)
//				{
//					previous = current;
//					current = current->GetNext();
//				}
//				if (current == nullptr)
//				{
//					outFile << "Error " << lname << " not in list." << endl;
//				}
//				else
//				{
//					previous->SetNext(current->GetNext());
//					previous = nullptr;
//
//					delete current;
//					delete previous;
//				}
//			}
//		}
//		outFile.close();
//	}
//}
//
//template<typename T>
//inline void List<T>::Display()
//{
//	/*********
//	* Purpose:
//	*	Iterate through the whole linked list and display the following from each node in the
//		linked list:
//	*	- WorkID
//	*	- Last Name
//	*	- First Name
//	*	- Birthdate
//	*	- Employment Date
//	* Precondition:
//	*	Object from class "List" exists.
//	* Postcondition:
//	*	Output file contains ordered list with all nodes.
//	***********/
//
//	Node<T>* current = m_head;
//	if (m_head == nullptr)
//	{
//		ofstream outFile("Lab 5 Output.txt", ios::app);
//		if (outFile.is_open())
//		{
//			outFile << "List is Empty." << endl;
//			outFile.close();
//		}
//	}
//	else if (m_head != nullptr)
//	{
//		while (current != nullptr)
//		{
//			current->GetData().Display();
//			current = current->GetNext();
//		}
//	}
//	delete current;
//}
//
//template<typename T>
//inline void List<T>::GetCount()
//{
//	ofstream outFile("Lab 5 Output.txt", ios::app);
//	if (outFile.is_open())
//	{
//		outFile << "Total Personnel Objects Made:" << Personnel::GetCount() << endl;
//		outFile.close();
//	}
//	else
//	{
//		cout << "Error Openning File." << endl;
//	}
//}
