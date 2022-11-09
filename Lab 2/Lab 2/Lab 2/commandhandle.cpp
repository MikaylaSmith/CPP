/*************************
* Author: Mikayla Smith
* Filename: commandhandle.cpp
* Date Created: 4/6/21
* Modifications:
***************************/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "commandhandle.h"
#include "isam.h"
/***********
* Class: CommandHandle
*
* Purpose:
*	The purpose of this class is to manage the reading data from the file,
*	determining which action should be taken, and executing the necessary list
*	method.
*
* Manager Functions:
*	CommandHandle()
*		This is a default constructor.
*	~CommandHandle()
*		This is the default deconstructor.
*	CommandHandle(const CommandHandle& copy)
*		The copy constructor.
*	operator=(const CommandHandle& rhs)
*
* Methods:
*	Read(List& list)
*		Executes the reading of data from the file,
*		determining which action should be taken, and executing the necessary list
*		method through the use of a switch statement.
*
*
***********/
CommandHandle::CommandHandle()
{

}
CommandHandle::~CommandHandle()
{	
	cout << "\n\n*****************************" << endl;
	cout << "Command Handle Dtor" << endl;
}
CommandHandle::CommandHandle(const CommandHandle& copy)
{

}
CommandHandle& CommandHandle::operator=(const CommandHandle& rhs)
{
	return *this;
}

void CommandHandle::Read()
{
	/*********
	* Purpose:
	*	Read information from file, insert data into proper temporary variables, and based
	*	on the action read from the file, either insert a new node, delete an existing node,
	*	print out the entire linked list, toggle whether commands are echoed out to the output
	*	file or end program execution.
	* Precondition:
	*	Object from class "List" exists and input file attached to program.
	* Postcondition:
	*	The end of the file has been reached, the output file contains all echoed commands, the linked
		list has been printed, and both input and output files have been closed. End of program
		execution.
	***********/

	char action;
	bool echo = true;
	int tempID;
	char tempLast[11];
	char tempFirst[11];
	int tempBirth;
	int tempEmploy;
	int param1;
	int param2;

	//ifstream inFile("Lab 1 Personnel Linked List Input.txt");

	ifstream inFile("tempSource.txt");

	if (inFile.is_open())
	{
		inFile >> action;

		ofstream outFile("tempOutput.txt");
		if (outFile.is_open())
		{
			switch (action)
			{
				case 'I':
				{
					inFile >> tempID >> tempLast >> tempFirst >> tempBirth >> tempEmploy;
					Personnel newPerson(tempID, tempLast, tempFirst, tempBirth, tempEmploy);
					Node* node = new Node(newPerson, nullptr);
					outFile << "Inserting: " << tempID << " " << tempLast << " " << tempFirst
							<< " " << setfill('0') << setw(6) << tempBirth
							<< " " << setfill('0') << setw(6) << tempEmploy << endl;
					outFile.close();
					isam.LinkedListInsert(node);
					break;
				}
				case 'D':
					inFile >> tempLast;
					outFile << "Deleting: \"" << tempLast << "\"" << endl;
					outFile.close();
					isam.DeleteListNode(tempLast);
					break;
				case 'R':
					inFile >> param1 >> param2;
					isam.ISAM_Display(param1, param2);
					break;
				case 'S':
					inFile >> tempLast;
					outFile << "Searching for: \"" << tempLast << "\"" << endl;
					isam.ElementLinearSearch(tempLast);
					break;
				case 'E':
					inFile.close();
					outFile << "Program Ending..." << endl;
					outFile.close();
					break;
				default:
					cout << "Action Not Read." << endl;
			}
		}

		do
		{
			ofstream outFile("tempOutput.txt", ios::app);

			if (outFile.is_open())
			{
				inFile >> action;
				switch (action)
				{
					case 'I':
					{
						inFile >> tempID >> tempLast >> tempFirst >> tempBirth >> tempEmploy;
						Personnel newPerson(tempID, tempLast, tempFirst, tempBirth, tempEmploy);
						Node* node = new Node(newPerson, nullptr);
						outFile << "Inserting: " << tempID << " " << tempLast << " " << tempFirst
							<< " " << setfill('0') << setw(6) << tempBirth
							<< " " << setfill('0') << setw(6) << tempEmploy << endl;
						outFile.close();
						isam.LinkedListInsert(node);
						break;
					}
					case 'D':
						inFile >> tempLast;
						outFile << "Deleting: \"" << tempLast << "\"" << endl;
						outFile.close();
						isam.DeleteListNode(tempLast);
						break;
					case 'R':
						inFile >> param1 >> param2;
						isam.ISAM_Display(param1, param2);
						break;
					case 'S':
						inFile >> tempLast;
						outFile << "Searching for: \"" << tempLast << "\"" << endl;
						isam.ElementLinearSearch(tempLast);
						break;
					case 'E':
						inFile.close();
						outFile << "Program Ending..." << endl;
						outFile.close();
						break;
					default:
						cout << "Action Not Read." << endl;
				}
			}
		}
		while (action != 'E');

		if (inFile.is_open())
		{
			inFile.close();
		}
		if (outFile.is_open())
		{
			outFile.close();
		}
	}
	else
	{
		cout << "Error: File Couldn't be Opened" << endl;
	}
}