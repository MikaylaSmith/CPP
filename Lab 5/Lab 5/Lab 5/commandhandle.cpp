/*************************
* Author: Mikayla Smith
* Filename: commandhandle.cpp
* Date Created: 5/24/21
* Modifications:
***************************/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "commandHandle.h"
#include "list.h"
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

	List<Personnel> list;
	char action;
	bool echo = true;
	int tempID;
	char tempLast[11];
	char tempFirst[11];
	int tempBirth;
	int tempEmploy;

	ifstream inFile("Lab 5 Input.txt");

	if (inFile.is_open())
	{
		inFile >> action;

		ofstream outFile("Lab 5 Output.txt");
		if (outFile.is_open())
		{
			switch (action)
			{
				case 'I':
				{
					inFile >> tempID >> tempLast >> tempFirst >> tempBirth >> tempEmploy;
					Personnel newPerson(tempID, tempLast, tempFirst, tempBirth, tempEmploy);
					Node<Personnel>* newNode = new Node<Personnel>(newPerson, nullptr);
					if (echo == true)
					{
						outFile << action << " " << tempID << " " << tempLast << " " << tempFirst
							<< " " << setfill('0') << setw(6) << tempBirth
							<< " " << setfill('0') << setw(6) << tempEmploy << endl;
						outFile.close();
					}
					list.AddData(newNode);
					break;
				}
				case 'D':
					inFile >> tempLast;
					if (echo == true)
					{
						outFile << action << " " << tempLast << endl;

						outFile.close();
					}
					list.DeleteData(tempLast);
					break;
				case 'P':
					if (echo == true)
					{
						outFile << action << endl;

						outFile.close();
					}
					list.Display();
					break;
				case 'T':
					if (echo == true)
					{
						outFile << action << endl;
						echo = false;
					}
					else if (echo == false)
					{
						echo = true;
					}
					break;
				case 'E':
					inFile.close();
					list.GetCount();
					outFile << action << endl;
					outFile.close();
					break;
				default:
					cout << "Action Not Read." << endl;
			}
		}

		do
		{
			ofstream outFile("Lab 5 Output.txt", ios::app);

			if (outFile.is_open())
			{
				inFile >> action;
				switch (action)
				{
					case 'I':
					{
						inFile >> tempID >> tempLast >> tempFirst >> tempBirth >> tempEmploy;
						Personnel newPerson(tempID, tempLast, tempFirst, tempBirth, tempEmploy);
						Node<Personnel>* newNode = new Node<Personnel>(newPerson, nullptr);
						if (echo == true)
						{
							outFile << action << " " << tempID << " " << tempLast << " " << tempFirst
								<< " " << setfill('0') << setw(6) << tempBirth
								<< " " << setfill('0') << setw(6) << tempEmploy << endl;
							outFile.close();
						}
						list.AddData(newNode);
						break;
					}
					case 'D':
						inFile >> tempLast;
						if (echo == true)
						{
							outFile << action << " " << tempLast << endl;
							outFile.close();
						}
						list.DeleteData(tempLast);
						break;
					case 'P':
						if (echo == true)
						{
							outFile << action << endl;
						}
						list.Display();
						break;
					case 'T':
						if (echo == true)
						{
							outFile << action << endl;
							echo = false;
						}
						else if (echo == false)
						{
							echo = true;
						}
						break;
					case 'E':
						inFile.close();
						outFile << "Program Ending..." << endl;
						list.GetCount();
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