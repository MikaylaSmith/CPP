/*************************
* Author: Mikayla Smith
* Filename: skipiterator.h
* Date Created: 5/17/21
* Modifications:
***************************/
/***********
* Class: SkipIterator
*
* Purpose:
*	Manage the searching and addition of list pointers to the elements of the array.
*
* SkipIterator Functions:
*	SkipIterator()
*		This is a default constructor.
*	SkipIterator(List* list)
*		This is a 1 arg constructor.
*	~SkipIterator()
*		This is the default deconstructor.
* Methods:
*	First()
*		Sets m_cursor to the head of the current linked list.
*	MoveNext()
*		Calls GenericIterator's MoveNext twice, skipping every other node in the linked list.
*	IsDone()
*		Tests to see if all iterations through the list have been completed. Returns false if 
*		iterations aren't complete and true if they are.
*	GetCurrent()
*		Returns the values of m_Person for m_cursor, giving the iterator access to that data.
*
***********/
#pragma once
#include "genericiterator.h"

class SkipIterator : public GenericIterator
{
	public:
		SkipIterator();
		SkipIterator(List* list);
		~SkipIterator();
		void First();
		void MoveNext();
		bool IsDone();
		Node& GetCurrent();
};