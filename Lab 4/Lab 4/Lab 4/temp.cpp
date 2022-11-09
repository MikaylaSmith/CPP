/*************************
* Author: Mikayla Smith
* Filename: temp.h
* Date Created: 5/6/21
* Modifications:
***************************/
#include "temp.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Temp::Temp() : Personnel(), m_hourRate(0), m_hours(0)
{
}

Temp::Temp(int ID, char lname[11], char fname[11], int birth, int employ, double hRate, int hour)
	: Personnel(ID, lname, fname, birth, employ), m_hourRate(hRate), m_hours(hour)
{
}

Temp::~Temp()
{
	cout << "Temp Dtor" << endl;
	m_hourRate = 0;
	m_hours = 0;
}

Temp::Temp(const Temp& copy) : Personnel(copy), m_hourRate(copy.m_hourRate), m_hours(copy.m_hours)
{
}

Temp& Temp::operator=(const Temp& rhs)
{
	if (this != &rhs)
	{
		this->m_hourRate = rhs.m_hourRate;
		this->m_hours = rhs.m_hours;

	}
	return *this;
}

void Temp::Display()
{
	ofstream outFile("Lab 4 Output.txt", ios::app);

	if (outFile.is_open())
	{
		Personnel::Display();
		outFile << m_hourRate << " " << m_hours << endl;
		outFile.close();
	}
	else
	{
		cout << "Error Opening File." << endl;
	}
}

void Temp::Pay()
{
	ofstream outFile("Lab 4 Output.txt", ios::app);

	if (outFile.is_open())
	{
		outFile << GetLName() << ": $" << (m_hours * m_hourRate) << endl;
		outFile.close();
	}
	else
	{
		cout << "Error Opening File." << endl;
	}
}