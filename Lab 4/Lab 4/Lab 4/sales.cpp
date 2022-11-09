/*************************
* Author: Mikayla Smith
* Filename: sales.cpp
* Date Created: 5/6/21
* Modifications:
***************************/
#include "sales.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Sales::Sales() : Personnel(), m_sales(0), m_commission(0)
{
}

Sales::Sales(int ID, char lname[11], char fname[11], int birth, int employ, double sale, double comm)
	: Personnel(ID, lname, fname, birth, employ), m_sales(sale), m_commission(comm)
{
}

Sales::~Sales()
{
	cout << "Sales Dtor" << endl;
	m_sales = 0;
	m_commission = 0;
}

Sales::Sales(const Sales& copy)
	: Personnel(copy), m_sales(copy.m_sales), m_commission(copy.m_commission)
{
}

Sales& Sales::operator=(const Sales& rhs)
{
	if (this != &rhs)
	{
		this->m_sales = rhs.m_sales;
		this->m_commission = rhs.m_commission;
	}
	return *this;
}

void Sales::Display()
{
	ofstream outFile("Lab 4 Output.txt", ios::app);

	if (outFile.is_open())
	{
		Personnel::Display();
		outFile << m_sales << " " << m_commission << endl;
		outFile.close();
	}
	else
	{
		cout << "Error Opening File." << endl;
	}
}

void Sales::Pay()
{
	ofstream outFile("Lab 4 Output.txt", ios::app);

	if (outFile.is_open())
	{
		outFile << GetLName() << ": $" << (m_sales * m_commission) << endl;
		outFile.close();
	}
	else
	{
		cout << "Error Opening File." << endl;
	}
}
