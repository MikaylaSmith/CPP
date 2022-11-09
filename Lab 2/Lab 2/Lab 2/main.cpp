/*************************
* Author: Mikayla Smith
* Filename: main.cpp
* Date Created: 4/12/21
* Modifications:
***************************/
/*************************
* Lab/Assignment:
*	Lab2 - Sparse Matrix
* Overview:
*	The purpose of this program is to read information from a text file and then perform
*	certain actions based on the information read with a linked list.
*	Possible options include Adding a new Node to the linked list, Deleting a node from the
*	linked list, printing out the whole linked list to an output file, starting or stopping
*	the echoing of the commands performed in the output file, or ending program execution.
* Input:
*	All inputs originate from the .txt file "Lab 2 Sparse Matrix Input.txt"
* Output:
*	All ouputs written to Console (Error messages)
	or to the output file "Lab 2 Sparse Matrix Output.txt"
***************************/
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "commandHandle.h"
#include "isam.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CommandHandle command;
	command.Read();

	return 0;
}