#include "baseiterator.h"

BaseIterator::BaseIterator() : m_cursor(nullptr), m_list(nullptr)
{

}

BaseIterator::~BaseIterator()
{
	m_cursor = nullptr;
	m_list = nullptr;
}

BaseIterator::BaseIterator(List* list): m_cursor(nullptr), m_list(list)
{
	
}
