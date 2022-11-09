/*************************
* Author: Mikayla Smith
* Filename: manager.cpp
* Date Created: 5/6/21
* Modifications:
***************************/
#include "manager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Manager::Manager() : Personnel(), m_salary(0), m_bonus(0)
{
}

Manager::Manager(int ID, char lname[11], char fname[11], int birth, int employ, double salary, int bonus)
	: Personnel(ID, lname, fname, birth, employ), m_salary(salary), m_bonus(bonus)
{
}

Manager::~Manager()
{
	cout << "Manager Dtor" << endl;
	m_salary = 0;
	m_bonus = 0;
}

Manager::Manager(const Manager& copy)
	: Personnel(copy), m_salary(copy.m_salary), m_bonus(copy.m_bonus)
{
}

Manager& Manager::operator=(const Manager& rhs)
{
	if (this != &rhs)
	{
		this->m_salary = rhs.m_salary;
		this->m_bonus = rhs.m_bonus;

	}
	return *this;
}

void Manager::Display()
{
	ofstream outFile("Lab 4 Output.txt", ios::app);

	if (outFile.is_open())
	{
		Personnel::Display();
		outFile << m_salary << " " << m_bonus << endl;
		outFile.close();
	}
	else
	{
		cout << "Error Opening File." << endl;
	}
}

void Manager::Pay()
{
	ofstream outFile("Lab 4 Output.txt", ios::app);

	if (outFile.is_open())
	{
		outFile << GetLName() << ": $" << (m_salary + m_bonus) << endl;
		outFile.close();
	}
	else
	{
		cout << "Error Opening File." << endl;
	}
}