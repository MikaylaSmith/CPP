/*************************
* Author: Mikayla Smith
* Filename: node.cpp
* Date Created: 3/29/21
* Modifications:
***************************/
#define _CRT_SECURE_NO_WARNINGS
#include "node.h"
#include <iostream>
#include <cstring>
using namespace std;

/***********
* Class: Node
*
* Purpose:
*	The purpose of this class is to manage the storage of the data held in Personnel.
*
* Manager Functions:
*	Node()
*		This is a default constructor.
*	~Node()
*		This is the default deconstructor.
*	Node(const Node& copy)
*		The copy constructor.
*	operator=(const Node& rhs)
*
* Methods:
*	NewPerson(Personnel person, Node* pointer)
*		Takes in the person object and a pointer value and set it to the new node
*		object being created.
*	SetNext(Node* pointer)
*		Alters the value stored in the m_next data member.
*	GetData()
*		Retrieve the values stored in the m_Person object stored in the
*		particular node.
*	GetNext()
*		Retrieves the value of the m_next pointer.
*
*
***********/

Node::Node(Personnel person, Node* pointer) : m_Person(person), m_next(pointer)
{

}
Node::~Node()
{
	m_next = nullptr;
	delete m_next;
}
Node::Node(const Node& copy)
{
	m_next = copy.m_next;
}
Node& Node::operator=(const Node& rhs)
{
	this->m_Person = rhs.m_Person;
	this->m_next = rhs.m_next;
	return *this;
}

/****** Setter ********/
void Node::NewPerson(Personnel newPerson, Node* pointer)
{
	/*********
	* Purpose:
	*	Transfer values that were read in from file into their correct containers within the
	*	"Personnel" class. This takes place as a part of the creation of a new Node.
	* Precondition:
	*	Values read in from file.
	* Postcondition:
	*	The Node holds the desired values that were passed to the function.
	***********/
	m_Person = newPerson;
	m_next = pointer;
}
void Node::SetNext(Node* pointer)
{
	/*********
	* Purpose:
	*	Transfer the value within the pointer passed to the function to
		the m_next data member for a particular node.
	* Precondition:
	*	A value has been passed to the function, either nullptr or a pointer to the next node.
	* Postcondition:
	*	The value of m_next is now equvalent to the passed pointer value.
	***********/

	m_next = pointer;
}

/****** Getter ********/
Personnel Node::GetData()
{
	/*********
	* Purpose:
	*	Transfer the values within the Personnel object for a particular node
	* Precondition:
	*	Values read in from file have already been set into the m_Person member.
	* Postcondition:
	*	The object and all correspoding values are returned.
	***********/

	return m_Person;
}
Node* Node::GetNext()
{
	/*********
	* Purpose:
	*	Transfer the value within the m_next pointer for a particular node.
	* Precondition:
	*	A value has been set, either nullptr or a pointer to the next node.
	* Postcondition:
	*	The pointer's value is returned.
	***********/

	return m_next;
}