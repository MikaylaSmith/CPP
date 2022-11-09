/*************************
* Author: Mikayla Smith
* Filename: list.h
* Date Created: 5/6/21
* Modifications:
***************************/
#pragma once
#include "node.h"
#include "personnel.h"
class List
{
public:
	List();
	~List();
	List(const List& copy);
	List& operator=(const List& rhs);

	void AddData(Node* newNode);
	void DeleteData(char* lname);
	void ListDisplay();
	void Search(char* lname, int row);
	void RemoveEnd();

	void Pay();
	void Cast();

	Node* GetHead();
	void SetEnd();
	Node* GetEnd();
	int GetCount();
private:
	Node* m_head;
	Node* m_end;
	int m_count;
};

