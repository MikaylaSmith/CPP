/*************************
* Author: Mikayla Smith
* Filename: personnel.h
* Date Created: 5/6/21
* Modifications:
***************************/
/***********
* Class: Temp
*
* Purpose:
*	Manage the searching and addition of list pointers to the elements of the array.
*
* Manager Functions:
*	Temp()
*		This is a default constructor.
*	Temp(int ID, char lname[11], char fname[11], int birth, int employ, double hRate, int hour)
*		This is a 7 arg constructor.
*	~Temp()
*		This is the default deconstructor.
*	Temp(const Temp& copy)
*		The copy constructor.
*	operator=(const Temp& rhs)
*		The op equals.
*
* Methods:
*	Display()
*		Print out to the output file all of the information pertaining to that
		particular Temp Personnel.
*
*
***********/
#pragma once
#include "personnel.h"

class Temp : public Personnel
{
public:
	Temp();
	Temp(int ID, char lname[11], char fname[11], int birth, int employ, double hRate, int hour);
	virtual ~Temp();
	Temp(const Temp& copy);
	Temp& operator=(const Temp& rhs);

	void Display();
	void Pay();

private:
	double m_hourRate;
	int m_hours;
};