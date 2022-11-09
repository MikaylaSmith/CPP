/*************************
* Author: Mikayla Smith
* Filename: genericiterator.h
* Date Created: 5/17/21
* Modifications:
***************************/
/***********
* Class: GenericIterator
*
* Purpose:
*	Manage the searching and addition of list pointers to the elements of the array.
*
* GenericIterator Functions:
*	GenericIterator()
*		This is a default constructor.
*	GenericIterator(List* list)
*		This is a 1 arg constructor.
*	~GenericIterator()
*		This is the default deconstructor.
* Methods:
*	First()
*		Sets m_cursor to the head of the current linked list.
*	MoveNext()
*		Calls GetNext() for m_cursor, and sets m_cursor to the value returned by GetNext().
*	IsDone()
*		Tests to see if all iterations through the list have been completed. Returns false if 
*		iterations aren't complete and true if they are.
*	GetCurrent()
*		Returns the values of m_Person for m_cursor, giving the iterator access to that data.
*
***********/
#pragma once
#include "baseiterator.h"
#include "list.h"

class GenericIterator : public BaseIterator
{
	public:
		GenericIterator();
		GenericIterator(List* list);
		~GenericIterator();
		void First();
		void MoveNext();
		bool IsDone();
		Node& GetCurrent();


};