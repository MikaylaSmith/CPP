/*************************
* Author: Mikayla Smith
* Filename: personnel.cpp
* Date Created: 4/6/21
* Modifications:
***************************/
#define _CRT_SECURE_NO_WARNINGS
#include "personnel.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

/***********
* Class: Personnel
*
* Purpose:
*	The purpose of this class is to mangage the storage of the data relating to the
	individual whose information was read in from the file.
*
* Manager Functions:
*	Personnel()
*		This is a default constructor.
*	Personnel(int ID, char lname[11], char fname[11], int birth, int employ)
*		This is a 5 argument constructor.
*	~Personnel()
*		This is the default deconstructor.
*	Personnel(const Personnel& copy)
*		The copy constructor.
*	operator=(const Personnel& rhs)
*
* Methods:
*	SetData(int ID, char* lname, char* fname, int birth, int employ)
*		Takes the data that was read in from the file and sets the values for all of
*		private members.
*	GetLName()
*		Retrieves the value stored in the m_lastName pointer.
***********/

Personnel::Personnel()
	:m_WorkID(0), m_lastName("\0"), m_firstName("\0"), m_DateOfBirth(0), m_DateOfEmployment(0)
{

}
Personnel::Personnel(int ID, char lname[11], char fname[11], int birth, int employ)
	: m_WorkID(ID), m_DateOfBirth(birth), m_DateOfEmployment(employ)
{
	strcpy(m_lastName, lname);
	strcpy(m_firstName, fname);
}
Personnel::~Personnel()
{
	strcpy(m_lastName, "\0");
	strcpy(m_firstName, "\0");
}
Personnel::Personnel(const Personnel& copy)
{
	m_WorkID = copy.m_WorkID;
	strcpy(m_lastName, copy.m_lastName);
	strcpy(m_firstName, copy.m_firstName);

	m_DateOfBirth = copy.m_DateOfBirth;
	m_DateOfEmployment = copy.m_DateOfEmployment;
}
Personnel& Personnel::operator=(const Personnel& rhs)
{
	if (this != &rhs)
	{
		this->m_WorkID = rhs.m_WorkID;
		this->m_DateOfBirth = rhs.m_DateOfBirth;
		this->m_DateOfEmployment = rhs.m_DateOfEmployment;
		delete[] m_lastName;
		delete[] m_firstName;

		if (strlen(rhs.m_lastName) == 0)
		{
			this->m_lastName[0] = '\0';
		}
		else
		{
			strcpy(this->m_lastName, rhs.m_lastName);
		}
		if (strlen(rhs.m_firstName) == 0)
		{
			this->m_firstName[0] = '\0';
		}
		else
		{
			strcpy(this->m_firstName, rhs.m_firstName);
		}
	}
	return *this;
}

/*********** Setter ***************/
void Personnel::SetData(int ID, char lname[11], char fname[11], int birth, int employ)
{
	/*********
	* Purpose:
	*	Takes the data inputs that were read from the file and sets the correspoding 
	*	data members to that value.
	* Precondition:
	*	An object of type "Personnel" created and values passed to function.
	* Postcondition:
	*	All data members hold the corresponding values.
	***********/

	m_WorkID = ID;

	strcpy(m_lastName, lname);
	strcpy(m_firstName, fname);

	m_DateOfBirth = birth;

	m_DateOfEmployment = employ;
}
void Personnel::Display()
{
	/*********
	* Purpose:
	*	Iterate through the whole linked list and display the following from each node in the
		linked list to the output file:
	*	- WorkID
	*	- Last Name
	*	- First Name
	*	- Birthdate
	*	- Employment Date
	* Precondition:
	*	All data members hold values.
	* Postcondition:
	*	Output file contains values of all data members for specific node.
	***********/
	ofstream outFile("Lab 1 Personnel Linked List Output.txt", ios::app);
	if (outFile.is_open())
	{
		outFile << m_WorkID << " " << m_lastName << " " << m_firstName
			<< " " << setfill('0') << setw(6) << m_DateOfBirth
			<< " " << setfill('0') << setw(6) << m_DateOfEmployment << endl;
		outFile.close();
	}
	else
	{
		cout << "Error Opening File" << endl;
	}
}
const char* Personnel::GetLName()
{
	/*********
	* Purpose:
	*	Return the value stored in m_lastName. 
	* Precondition:
	*	m_lastName holds a value.
	* Postcondition:
	*	Value stored in m_lastName returned.
	***********/

	return m_lastName;
}