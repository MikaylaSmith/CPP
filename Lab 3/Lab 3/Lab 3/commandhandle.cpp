/*************************
* Author: Mikayla Smith
* Filename: commandhandle.cpp
* Date Created: 5/6/21
* Modifications:
***************************/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "commandhandle.h"
#include "isam.h"
#include "sales.h"
#include "temp.h"
#include "manager.h"
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

	char action;
	bool echo = true;
	int tempID;
	char tempLast[11];
	char tempFirst[11];
	int tempBirth;
	int tempEmploy;
	char type;
	int param1;
	int param2;

	//ifstream inFile("Lab 1 Personnel Linked List Input.txt");

	ifstream inFile("Lab 3 Input.txt");

	if (inFile.is_open())
	{
		ofstream outFile("Lab 3 Output.txt", ios::app);

		if (outFile.is_open())
		{
			inFile >> action;
			switch (action)
			{
				case 'I':
				{
					inFile >> tempID >> tempLast >> tempFirst >> tempBirth >> tempEmploy >> type;
					if (type == 'S')
					{
						double tempSales;
						double tempCom;
						inFile >> tempSales >> tempCom;
						Sales* newPerson = new Sales(tempID, tempLast, tempFirst, tempBirth, tempEmploy, tempSales, tempCom);
						Node* node = new Node(newPerson, nullptr);
						outFile << "Inserting: " << tempID << " " << tempLast << " " << tempFirst
							<< " " << setfill('0') << setw(6) << tempBirth
							<< " " << setfill('0') << setw(6) << tempEmploy << endl;
						outFile.close();
						isam.LinkedListInsert(node);
					}
					else if (type == 'T')
					{
						double tempHRate;
						int tempHrs;
						inFile >> tempHRate >> tempHrs;
						Temp* newPerson = new Temp(tempID, tempLast, tempFirst, tempBirth, tempEmploy, tempHRate, tempHrs);
						Node* node = new Node(newPerson, nullptr);
						outFile << "Inserting: " << tempID << " " << tempLast << " " << tempFirst
							<< " " << setfill('0') << setw(6) << tempBirth
							<< " " << setfill('0') << setw(6) << tempEmploy << endl;
						outFile.close();
						isam.LinkedListInsert(node);
					}
					else if (type == 'M')
					{
						double tempSalary;
						int tempBonus;
						inFile >> tempSalary >> tempBonus;
						Manager* newPerson = new Manager(tempID, tempLast, tempFirst, tempBirth, tempEmploy, tempSalary, tempBonus);
						Node* node = new Node(newPerson, nullptr);
						outFile << "Inserting: " << tempID << " " << tempLast << " " << tempFirst
							<< " " << setfill('0') << setw(6) << tempBirth
							<< " " << setfill('0') << setw(6) << tempEmploy << endl;
						outFile.close();
						isam.LinkedListInsert(node);
					}
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
				case '$':
					inFile >> param1 >> param2;
					isam.ISAMPay(param1, param2);
					break;
				case 'C':
					inFile >> param1;
					isam.ISAMCast(param1);
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
			ofstream outFile("Lab 3 Output.txt", ios::app);

			if (outFile.is_open())
			{
				inFile >> action;
				switch (action)
				{
					case 'I':
					{
						inFile >> tempID >> tempLast >> tempFirst >> tempBirth >> tempEmploy >> type;
						if (type == 'S')
						{
							double tempSales;
							double tempCom;
							inFile >> tempSales >> tempCom;
							Sales* newPerson = new Sales(tempID, tempLast, tempFirst, tempBirth, tempEmploy, tempSales, tempCom);
							Node* node = new Node(newPerson, nullptr);
							outFile << "Inserting: " << tempID << " " << tempLast << " " << tempFirst
								<< " " << setfill('0') << setw(6) << tempBirth
								<< " " << setfill('0') << setw(6) << tempEmploy << endl;
							outFile.close();
							isam.LinkedListInsert(node);
						}
						else if (type == 'T')
						{
							double tempHRate;
							int tempHrs;
							inFile >> tempHRate >> tempHrs;
							Temp* newPerson = new Temp(tempID, tempLast, tempFirst, tempBirth, tempEmploy, tempHRate, tempHrs);
							Node* node = new Node(newPerson, nullptr);
							outFile << "Inserting: " << tempID << " " << tempLast << " " << tempFirst
								<< " " << setfill('0') << setw(6) << tempBirth
								<< " " << setfill('0') << setw(6) << tempEmploy << endl;
							outFile.close();
							isam.LinkedListInsert(node);
						}
						else if (type == 'M')
						{
							double tempSalary;
							int tempBonus;
							inFile >> tempSalary >> tempBonus;
							Manager* newPerson = new Manager(tempID, tempLast, tempFirst, tempBirth, tempEmploy, tempSalary, tempBonus);
							Node* node = new Node(newPerson, nullptr);
							outFile << "Inserting: " << tempID << " " << tempLast << " " << tempFirst
								<< " " << setfill('0') << setw(6) << tempBirth
								<< " " << setfill('0') << setw(6) << tempEmploy << endl;
							outFile.close();
							isam.LinkedListInsert(node);
						}
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
					case '$':
						inFile >> param1 >> param2;
						isam.ISAMPay(param1, param2);
						break;
					case 'C':
						inFile >> param1;
						isam.ISAMCast(param1);
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
	}
	else
	{
		cout << "Error: File Couldn't be Opened" << endl;
	}
}