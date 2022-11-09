/*************************
* Author: Mikayla Smith
* Filename: sales.h
* Date Created: 5/6/21
* Modifications:
***************************/
/***********
* Class: Sales
*
* Purpose:
*	Store information relating to a Sales Personnel.
*
* Manager Functions:
*	Sales()
*		This is a default constructor.
*	Sales(int ID, char lname[11], char fname[11], int birth, int employ, double sale, double comm)
*		This is a 7 arg constructor.
*	~Sales()
*		This is the default deconstructor.
*	Sales(const Sales& copy)
*		The copy constructor.
*	operator=(const Sales& rhs)
*		The op equals.
*
* Methods:
*	Display()
*		Print out to the output file all of the information pertaining to that
		particular Sales Personnel.
*
*
***********/
#pragma once
#include "personnel.h"

class Sales : public Personnel
{
public:
	Sales();
	Sales(int ID, char lname[11], char fname[11], int birth, int employ, double sale, double comm);
	virtual ~Sales();
	Sales(const Sales& copy);
	Sales& operator=(const Sales& rhs);

	void Display();
	void Pay();

private:
	double m_sales;
	double m_commission;
};