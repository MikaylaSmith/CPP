/*************************
* Author: Mikayla Smith
* Filename: isamnode.h
* Date Created: 4/14/21
* Modifications:
***************************/
#pragma once
#include "list.h"

class ISAMNode
{
public:
	ISAMNode();
	~ISAMNode();
	ISAMNode(const ISAMNode& copy);
	ISAMNode& operator=(const ISAMNode& rhs);

	void SetList(List* pointer);
	List* GetList();
	void SetListHead(Node* pointer);
	void SetListEnd(Node* pointer);
	void SetCount(int count);
	int GetCount();

	void InsertNode(Node* newNode);
	void DeleteNode(char* lname);
	void MoveNode(char* lname);
	void Display();
private:
	List* m_list;
	Node* m_list_head;
	Node* m_list_end;
	int m_count;
};