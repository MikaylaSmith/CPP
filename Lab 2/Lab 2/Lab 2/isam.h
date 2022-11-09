/*************************
* Author: Mikayla Smith
* Filename: isam.h
* Date Created: 4/13/21
* Modifications:
***************************/
#pragma once
#include "node.h"
#include "list.h"
class ISAM
{
public:
	ISAM();
	~ISAM();
	ISAM(const ISAM& copy);
	ISAM& operator=(const ISAM& rhs);

	void ISAM_Display(int param1, int param2);
	void LinkedListInsert(Node* newNode);
	void DeleteListNode(char* lname);
	
	void ElementLinearSearch(char* lname);
private:
	List* m_Isam[15];
};