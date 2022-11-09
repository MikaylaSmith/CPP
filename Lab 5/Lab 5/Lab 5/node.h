/*************************
* Author: Mikayla Smith
* Filename: node.h
* Date Created: 5/24/21
* Modifications:
***************************/
#pragma once
#include "personnel.h"

template <class T>
class Node
{
public:
	Node(T person, Node* pointer);
	~Node();
	Node(const Node& copy);
	Node& operator= (const Node& rhs);

	void SetNext(Node* pointer);

	T GetData();
	Node* GetNext();
private:
	T m_Person;
	Node* m_next;
};

template<class T>
inline Node<T>::Node(T person, Node* pointer) : m_Person(person), m_next(pointer)
{

}
template<class T>
inline Node<T>::~Node()
{
	m_next = nullptr;
	delete m_next;
}

template<class T>
inline Node<T>::Node(const Node& copy)
{
	m_next = copy.m_next;
}

template<class T>
inline Node<T>& Node<T>::operator=(const Node& rhs)
{
	this->m_Person = rhs.m_Person;
	this->m_next = rhs.m_next;
	return *this;
}

/****** Setter ********/
template<class T>
inline void Node<T>::SetNext(Node* pointer)
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
template<class T>
inline T Node<T>::GetData()
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
template<class T>
inline Node<T>* Node<T>::GetNext()
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
