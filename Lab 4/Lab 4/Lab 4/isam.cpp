/*************************
* Author: Mikayla Smith
* Filename: isam.cpp
* Date Created: 5/6/21
* Modifications:
***************************/
#define _CRT_SECURE_NO_WARNINGS
#include "isam.h"
#include "i_iterator.h"
#include "baseiterator.h"
#include "genericiterator.h"
#include "skipiterator.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
/***********
* Class: ISAM
*
* Purpose:
*	Manage the searching and addition of list pointers to the elements of the array.
*
* Manager Functions:
*	ISAM()
*		This is a default constructor.
*	~ISAM()
*		This is the default deconstructor.
*	ISAM(const ISAM& copy)
*		The copy constructor.
*	operator=(const ISAM& rhs)
*		The op equals.
*
* Methods:
*	LinkedListInsert(Node* newNode)
*		After performing a linear search to locate the location of the row into which the node
*		will go, insert it. If the list is full, see if the next list has space for the last node.
		If no space, shift all rows of m_Isam down one and insert into the new empty list space.
*	DeleteListNode(char* lname)
*		Use linear search to locate row that may contain the desired name. If found, delete.
*		If after deletion the list is empty, shift all rows up one.
*	ElementLinearSearch(char* lname)
*		Use linear search to locate the row that may contain the desired name. Pass along to
*		ListSearch to finish finding.
*	ISAM_Display(int param1, int param2)
*		For the lists stored in row param1 to row param2, run the list.Display() function
*		to print out all of the nodes in the lists between those points
*
*
***********/

ISAM::ISAM()
{
	for (int i = 0; i < 15; i++)
	{
		List* newList = new List;
		m_Isam[i] = newList;
	}
}
ISAM::~ISAM()
{
	cout << "ISAM Dtor" << endl;
	for (int i = 0; i != 15; i++)
	{
		delete m_Isam[i];
		//m_Isam[i]->~List();
		//m_Isam[i] = nullptr;
	}
}
ISAM::ISAM(const ISAM& copy)
{
	*m_Isam = *copy.m_Isam;
}
ISAM& ISAM::operator=(const ISAM& rhs)
{
	*this->m_Isam = *rhs.m_Isam;
	return *this;
}

/* Methods */
void ISAM::LinkedListInsert(Node* newNode)
{
	/*********
	* Purpose:
	*	Take the new node that was created in the Command Handle and add it to the correct location
	*	within the linked list. If the list has 10 nodes at the location where it needs to
	*	be inserted, test the next list to see if it has space for the last node in the row
	*	where the insertion needs to happen has space. If there's space, insert the end node to
	*	row + 1 and newNode to row. If no space, shift all rows of m_Isam down and create a new
	*	linked list and insert end to there.
	* Precondition:
	*	New Node was created and action read from the file.
	* Postcondition:
	*	 A new node has been added to the linked list in the proper location.
	***********/
	char tempName[11];
	int row = 0;
	//int result = 0;
	bool found = false;

	//strcpy(tempName, newNode->GetData()->GetLName());

	while (found != true && row < 14)
	{
		if (m_Isam[row]->GetHead() == nullptr)
		{
			//If the list is empty, insert newNode
			m_Isam[row]->AddData(newNode);
			found = true;
		}
		else
		{
			//Testing to See if in a certain list
			//result = strcmp(tempName, m_Isam[row]->GetHead()->GetData()->GetLName());
			//if (result < 0)
			if (*newNode > *m_Isam[row]->GetHead())
			{
				//Comes before the head node of list
				if (m_Isam[row]->GetCount() == 10)
				{
					//If the List is full
					//Pull out the last node in the list
					Node* end = m_Isam[row]->GetEnd();
					m_Isam[row]->RemoveEnd();

					//Relocate the previous last node
					if (m_Isam[row + 1]->GetCount() != 10)
					{
						//If there is space in the next list for the node
						//Insert old end of list to the next list
						//Add the new node to original list

						m_Isam[row + 1]->AddData(end);
						m_Isam[row]->AddData(newNode);
						found = true;
					}
					else if (m_Isam[row + 1]->GetCount() == 10)
					{
						//Shifts all lists down one row
						delete m_Isam[14];
						for (int i = 14; i > row; i--)
						{
							m_Isam[i] = m_Isam[i - 1];
						}
						m_Isam[row + 1] = nullptr;
						m_Isam[row + 1] = new List;

						//Add the new node
						m_Isam[row + 1]->AddData(end);
						m_Isam[row]->AddData(newNode);
						found = true;
					}
					end = nullptr;
					delete end;
				}
				if (m_Isam[row]->GetCount() != 10)
				{
					//If the list has space
					m_Isam[row]->AddData(newNode);
					found = true;
				}
			}
			//If not before head, test if before end
			//else if (result > 0)
			else if (m_Isam[row]->GetEnd() != nullptr)
			{
				//This is to make sure that there is an end to the list
				//If there is only the head node, end will be nullptr
				//This test shouldn't ever need to be skipped but is here in case
				//if (m_Isam[row]->GetEnd() != nullptr)
				//{
					//result = strcmp(tempName, m_Isam[row]->GetEnd()->GetData()->GetLName());
					//if (result < 0)
					if (*newNode > *m_Isam[row]->GetEnd())
					{
						//If before the end of the list
						if (m_Isam[row]->GetCount() == 10)
						{
							//If the List is full
							//Pull out the last node in the list
							Node* end = m_Isam[row]->GetEnd();
							m_Isam[row]->RemoveEnd();

							//Process to relocate the previous last node
							if (m_Isam[row + 1]->GetCount() != 10)
							{
								//If there is space in the next list for the node
								//Insert old end of list to the next list
								//Add the new node to original list
								m_Isam[row + 1]->AddData(end);
								m_Isam[row]->AddData(newNode);
								found = true;
							}
							else if (m_Isam[row + 1]->GetCount() == 10)
							{
								//If the next list is also full, make a new list
								//Shifts all lists down one row
								delete m_Isam[14];
								for (int i = 14; i > row; i--)
								{
									m_Isam[i] = m_Isam[i - 1];
								}
								m_Isam[row + 1] = nullptr;
								m_Isam[row + 1] = new List;

								//Add the new node
								m_Isam[row + 1]->AddData(end);
								m_Isam[row]->AddData(newNode);
								found = true;
							}
							end = nullptr;
							delete end;
						}
						else if (m_Isam[row]->GetCount() != 10)
						{
							//If the list has space
							m_Isam[row]->AddData(newNode);
							found = true;
						}
						else
						{
							//If Comes after the end of the list and no space in list, Repeat Search Process
							row++;
						}
					}
					//else if (result > 0)
					else if (*newNode < *m_Isam[row]->GetEnd())
					{
						//If comes after the end, see if there is space in current list
						if (m_Isam[row]->GetCount() != 10)
						{
							//Test against the head of the next list, see if comes after it
							if (m_Isam[row + 1]->GetHead() == nullptr)
							{
								//If next list is empty and space in current, insert in current
								m_Isam[row]->AddData(newNode);
								found = true;
							}
							else if (m_Isam[row + 1]->GetHead() != nullptr)
							{
								//If the next list isn't empty, see if new node will be after the next node
								//result = strcmp(tempName, m_Isam[row + 1]->GetHead()->GetData()->GetLName());
								//if (result < 0)
								if (newNode > m_Isam[row + 1]->GetHead())
								{
									//If comes before head of next list, insert in current list
									m_Isam[row]->AddData(newNode);
									found = true;
								}
								//if (result > 0)
								if (newNode < m_Isam[row + 1]->GetHead())
								{
									//If after head of next list, increment up
									row++;
								}
							}
						}
						else if (m_Isam[row]->GetCount() == 10)
						{
							//If the current list is full and comes after end
							//Increment up
							row++;
						}
						else
						{
							//If the next list is empty, add to this current list
							m_Isam[row]->AddData(newNode);
							found = true;
						}

					}
					else
					{
						//In the off chance something doesn't meet one of the prior conditions
						row++;
					}
				//}
				//else
				//{
					//Should the first condition fail, increment row up
					//May end up simply traversing through the whole list
					//row++;
				//}
			}
			else
			{
				row++;
			}

		}
	}
}
void ISAM::DeleteListNode(char* lname)
{
	/*********
	* Purpose:
	*	Take the new node that was created in the Command Handle and search through the correct
	*	linked list and remove that node, if it exists. If the list is empty after the node is deleted,
	*	delete the empty list and shift all of the subsequent rows up one.
	* Precondition:
	*	The last name of the node to be deleted was read in from the file.
	* Postcondition:
	*	 The corresponding node has been deleted. Shifting of rows may have occured.
	***********/
	int row = 0;
	int result = 0;
	bool found = false;

	while (found != true && row < 14)
	{
		if (m_Isam[row]->GetHead() == nullptr)
		{
			//If the list is empty, nothing to delete, so increment up
			row++;
		}
		else
		{
			result = strcmp(lname, m_Isam[row]->GetHead()->GetData()->GetLName());
			//Testing to See if in a certain list
			if (result == 0)
			{
				//If it is the same as the head node
				m_Isam[row]->DeleteData(lname);
				found = true;
				//Test if now an empty list, if yes, shift all rows up
				if (m_Isam[row]->GetCount() == 0)
				{
					delete m_Isam[row];

					for (int i = row; i < 14; i++)
					{
						m_Isam[i] = m_Isam[i + 1];
					}
					m_Isam[14] = nullptr;
				}
			}
			//If first condition fails, tests if comes before end
			else
			{
				//This is to make sure that there is an end to the list
				//If there is only the head node, end will be nullptr
				//This test shouldn't ever need to be skipped but is here in case
				if (m_Isam[row]->GetEnd() != nullptr)
				{
					result = strcmp(lname, m_Isam[row]->GetEnd()->GetData()->GetLName());
					if (result == 0)
					{
						//Same as end
						m_Isam[row]->DeleteData(lname);
						found = true;
						//Test if now an empty list, if yes, shift all rows up
						if (m_Isam[row]->GetCount() == 0)
						{
							//delete m_Isam[14];
							for (int i = row; i < 14; i++)
							{
								m_Isam[i] = m_Isam[i + 1];
							}
							m_Isam[14] = nullptr;
						}
					}
					else if (result < 0)
					{
						//Comes after head and before end, so if in list, is here
						m_Isam[row]->DeleteData(lname);
						found = true;
					}
					else
					{
						//It comes after the end of the list, Repeat Search Process
						row++;
					}
				}
				else
				{
					//Should the first condition fail, increment row up
					//May end up simply traversing through the whole list
					row++;
				}
			}
		}
	}
}
void ISAM::ElementLinearSearch(char* lname)
{
	/*********
	* Purpose:
	*	Preform a linear search to locate which row the desired last name may be located.
	*	When that row is located, search through the list to find the exact element, if it exists.
	* Precondition:
	*	Last name to be found was read in from file.
	* Postcondition:
	*	 The node has been located or message "Unable to find" was displayed to the output file.
	***********/
	int row = 0;
	int result = 0;
	bool found = false;

	while (found != true && row < 14)
	{
		if (m_Isam[row]->GetHead() == nullptr)
		{
			//If the list is empty then move to the next list
			//Will likely end up traversing the whole array
			row++;
		}
		else
		{
			result = strcmp(lname, m_Isam[row]->GetHead()->GetData()->GetLName());
			if (result == 0)
			{
				//Is the same as the head node
				m_Isam[row]->Search(lname, row);
				found = true;
			}
			else if (result < 0 && m_Isam[row]->GetCount() == 1)
			{
				row--;
				m_Isam[row]->Search(lname, row);
				found = true;
			}
			else if (result > 0)
			{
				//Would come after head node
				if (m_Isam[row]->GetEnd() != nullptr)
				{
					result = strcmp(lname, m_Isam[row]->GetEnd()->GetData()->GetLName());
					if (result == 0)
					{
						//Same as end
						m_Isam[row]->Search(lname, row);
						found = true;
					}
					else if (result < 0)
					{
						//Before End so If in list, it's here
						m_Isam[row]->Search(lname, row);
						found = true;
					}
					else
					{
						//After the end of the list, move to next row
						row++;
					}
				}
				else
				{
					//If fails to belong in the list at row
					row++;
				}
			}
		}
	}
}
void ISAM::ISAMPay(int param1, int param2)
{
	for (int i = param1; i <= param2; i++)
	{
		m_Isam[i]->Pay();
	}
}
void ISAM::ISAMCast(int param1)
{
	m_Isam[param1]->Cast();
}
void ISAM::ISAM_Display(int param1, int param2)
{
	/*********
	* Purpose:
	*	Based on the parameters read in from the file, display the corresponding rows of the
	*	m_Isam member.
	* Precondition:
	*	Row parameters are read were read in from file.
	* Postcondition:
	*	 Rows displayed to output file.
	***********/
	ofstream outFile("Lab 4 Output.txt", ios::app);
	if (outFile.is_open())
	{
		for (int i = param1; i <= param2; i++)
		{
			outFile << endl;
			outFile << "========== Displaying Row: " << i << " ==========" << endl;
			outFile << "Row " << i << " contains: " << m_Isam[i]->GetCount() << " items" << endl;
			m_Isam[i]->ListDisplay();
			outFile << endl;
			outFile << "======================================" << endl;
			outFile << endl;
		}
		outFile.close();
	}
	else
	{
		cout << "Error Opening File." << endl;
	}

}
void ISAM::Iterate()
{
	ofstream outFile ("Lab 4 Output.txt", ios::app);

	if (outFile.is_open())
	{
		int row = 0;
		outFile << endl;
		outFile << "****** Iterate ******" << endl;
		for (row = 0; row < 14; row++)
		{
			I_Iterator* iterator = new GenericIterator(m_Isam[row]);

			for (iterator->First(); !iterator->IsDone(); iterator->MoveNext())
			{
				iterator->GetCurrent().GetData()->Display();
			}
			delete iterator;
		}
		outFile << endl;

		outFile << "****** Skip Iterate ******" << endl;
		for (row = 0; row < 14; row++)
		{
			I_Iterator* iter = new SkipIterator(m_Isam[row]);

			for (iter->First(); !iter->IsDone(); iter->MoveNext())
			{
				iter->GetCurrent().GetData()->Display();
			}
			delete iter;
		}
		outFile << endl;

		outFile.close();
	}
	else
	{
		cout << "Error Opening File." << endl;
	}
}