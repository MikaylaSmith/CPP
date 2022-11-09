/*************************
* Author: Mikayla Smith
* Filename: node.h
* Date Created: 5/6/21
* Modifications:
***************************/
#pragma once
#include "personnel.h"

class Node
{
public:
	Node(Personnel* person, Node* pointer);
	~Node();
	Node(const Node& copy);
	Node& operator= (const Node& rhs);

	bool operator <(const Node& rv);
	bool operator >(const Node& rv);

	void SetNext(Node* pointer);

	Personnel* GetData();
	Node* GetNext();
private:
	Personnel* m_Person;
	Node* m_next;
};

