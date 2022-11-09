/*************************
* Author: Mikayla Smith
* Filename: personnel.h
* Date Created: 5/6/21
* Modifications:
***************************/
/***********
* Class: Manager
*
* Purpose:
*	Manage the searching and addition of list pointers to the elements of the array.
*
* Manager Functions:
*	Manager()
*		This is a default constructor.
*	Manager(int ID, char lname[11], char fname[11], int birth, int employ, double salary, int bonus)
*		This is a 7 arg constructor.
*	~Manager()
*		This is the default deconstructor.
*	Manager(const Manager& copy)
*		The copy constructor.
*	operator=(const Manager& rhs)
*		The op equals.
*
* Methods:
*	Display()
*		Print out to the output file all of the information pertaining to that
		particular Manager Personnel.
*
*
***********/
#pragma once
#include "personnel.h"

class Manager : public Personnel
{
public:
	Manager();
	Manager(int ID, char lname[11], char fname[11], int birth, int employ, double salary, int bonus);
	virtual ~Manager();
	Manager(const Manager& copy);
	Manager& operator=(const Manager& rhs);

	void Display();
	void Pay();

private:
	double m_salary;
	int m_bonus;
};