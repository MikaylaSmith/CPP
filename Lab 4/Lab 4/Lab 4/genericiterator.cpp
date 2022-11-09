#include "genericiterator.h"

GenericIterator::GenericIterator()
{
	
}

GenericIterator::GenericIterator(List* list): BaseIterator(list)
{

}

GenericIterator::~GenericIterator()
{

}

void GenericIterator::First()
{
	m_cursor = m_list->GetHead();
}

void GenericIterator::MoveNext()
{
	m_cursor = m_cursor->GetNext();
}

bool GenericIterator::IsDone()
{
	//State:
	//False: Isn't Done
	//True: Is Done
	bool state = false;

	if (m_cursor == nullptr)
	{
		//For empty list or at the end of the list
		state = true;
	}
	return state;
}

Node& GenericIterator::GetCurrent()
{
	return *m_cursor;
}
