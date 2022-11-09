/*************************
* Author: Mikayla Smith
* Filename: i_iterator.h
* Date Created: 5/17/21
* Modifications:
***************************/
/***********
* Class: I_Iterator
*
* Purpose:
*	Manage the searching and addition of list pointers to the elements of the array.
*
* I_Iterator Functions:
*	I_Iterator()
*		This is a default constructor.
*	I_Iterator(int ID, char lname[11], char fname[11], int birth, int employ, double salary, int bonus)
*		This is a 7 arg constructor.
*	~I_Iterator()
*		This is the default deconstructor.
*	I_Iterator(const I_Iterator& copy)
*		The copy constructor.
*	operator=(const I_Iterator& rhs)
*		The op equals.
* Methods:
*	First()
*		Pure virtual.
*	MoveNext()
*		Pure virtual.
*	IsDone()
*		Pure virtual.
*	GetCurrent()
*		Pure virtual.
*
***********/
#pragma once
#include "node.h"
class I_Iterator
{
public:
	I_Iterator();
	virtual ~I_Iterator();

	virtual void First() = 0;
	virtual void MoveNext() = 0;
	virtual bool IsDone() = 0;
	virtual Node& GetCurrent() = 0;
};