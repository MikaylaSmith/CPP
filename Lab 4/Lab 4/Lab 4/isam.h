/*************************
* Author: Mikayla Smith
* Filename: isam.h
* Date Created: 5/6/21
* Modifications:
***************************/
#pragma once
#include "list.h"

class ISAM
{
public:
	ISAM();
	~ISAM();
	ISAM(const ISAM& copy);
	ISAM& operator=(const ISAM& rhs);

	friend class I_Iterator;

	void ISAM_Display(int param1, int param2);
	void LinkedListInsert(Node* newNode);
	void DeleteListNode(char* lname);

	void ElementLinearSearch(char* lname);
	void ISAMPay(int param1, int param2);
	void ISAMCast(int param1);
	void Iterate();
private:
	List* m_Isam[15];
};