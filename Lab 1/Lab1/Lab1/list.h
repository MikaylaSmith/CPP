/*************************
* Author: Mikayla Smith
* Filename: list.h
* Date Created: 4/6/21
* Modifications:
***************************/
#pragma once
#include "node.h"
#include "personnel.h"
class List
{
public:
	List();
	~List();
	List(const List& copy);
	List& operator=(const List& rhs);

	void AddData(Personnel newPerson);
	void DeleteData(char* lname);
	void Display();
private:
	Node* m_head;
};

