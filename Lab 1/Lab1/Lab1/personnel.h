/*************************
* Author: Mikayla Smith
* Filename: personnel.h
* Date Created: 4/6/21
* Modifications:
***************************/
#pragma once
class Personnel
{
public:
	Personnel();
	Personnel(int ID, char lname[11], char fname[11], int birth, int employ);
	~Personnel();
	Personnel(const Personnel& copy);
	Personnel& operator=(const Personnel& rhs);

	void SetData(int ID, char lname[11], char fname[11], int birth, int employ);
	void Display();
	const char* GetLName();
private:
	int m_WorkID;
	char m_lastName[11];
	char m_firstName[11];
	int m_DateOfBirth;
	int m_DateOfEmployment;
};

