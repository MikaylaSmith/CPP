/*************************
* Author: Mikayla Smith
* Filename: node.h
* Date Created: 4/6/21
* Modifications:
***************************/
#pragma once
#include "personnel.h"

class Node
{
public:
	Node(Personnel person, Node* pointer);
	~Node();
	Node(const Node& copy);
	Node& operator= (const Node& rhs);

	void NewPerson(Personnel newPerson, Node* pointer);
	void SetNext(Node* pointer);

	Personnel GetData();
	Node* GetNext();
private:
	Personnel m_Person;
	Node* m_next;
};

