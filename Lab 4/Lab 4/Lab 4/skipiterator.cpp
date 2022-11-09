#include "skipiterator.h"

SkipIterator::SkipIterator()
{
}

SkipIterator::SkipIterator(List* list): GenericIterator(list)
{
}

SkipIterator::~SkipIterator()
{
}

void SkipIterator::First()
{
	m_cursor = m_list->GetHead();
}

void SkipIterator::MoveNext()
{
	if (m_cursor->GetNext() == nullptr)
	{
		//If next is the end of the list. In two nodes, it would be a nullptr
		m_cursor = nullptr;
	}
	else
	{
		GenericIterator::MoveNext();
		GenericIterator::MoveNext();
	}
}

bool SkipIterator::IsDone()
{
	//State:
	//False: Isn't Done
	//True: Is Done
	bool state = false;

	if (m_cursor == nullptr)
	{
		//For empty list or End of list
		state = true;
	}
	return state;
}

Node& SkipIterator::GetCurrent()
{
	return *m_cursor;
}
