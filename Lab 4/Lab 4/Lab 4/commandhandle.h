/*************************
* Author: Mikayla Smith
* Filename: commandhandle.h
* Date Created: 5/6/21
* Modifications:
***************************/
#pragma once
#include "isam.h"
#include "list.h"
class CommandHandle
{
public:
	CommandHandle();
	~CommandHandle();
	CommandHandle(const CommandHandle& copy);
	CommandHandle& operator=(const CommandHandle& rhs);

	void Read();
private:
	ISAM isam;
};

