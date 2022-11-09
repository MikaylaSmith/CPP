/*************************
* Author: Mikayla Smith
* Filename: baseiterator.h
* Date Created: 5/17/21
* Modifications:
***************************/
/***********
* Class: BaseIterator
*
* Purpose:
*	Manage the searching and addition of list pointers to the elements of the array.
*
* BaseIterator Functions:
*	BaseIterator()
*		This is a default constructor.
*	BaseIterator(List* list)
*		This is a 1 arg constructor.
*	~BaseIterator()
*		This is the default deconstructor.
*	BaseIterator(const BaseIterator& copy)
*		The copy constructor.
*	operator=(const BaseIterator& rhs)
*		The op equals.
* Methods:
*	None
*
***********/
#pragma once
#include "i_iterator.h"
#include "node.h"
#include "list.h"

class BaseIterator : public I_Iterator
{
public:
	BaseIterator();
	~BaseIterator();

	BaseIterator(List* list);
protected:
	Node* m_cursor;
	List* m_list;
};