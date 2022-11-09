//#pragma once
//#include "personnel.h"
//#include "list.h"
//
//template <typename T>
//class Node
//{
//	public:
//	Node();
//	Node(Personnel person, Node* pointer);
//	~Node();
//	Node(const Node& copy);
//	Node& operator=(const Node& rhs);
//
//	friend class List;
//
//	void SetNext(Node* pointer);
//	Node<T>* GetNext();
//
//	private:
//	Node<T>* m_next;
//	Personnel m_Person;
//};
//
//template<typename T>
//inline Node<T>::Node(): m_next(nullptr)
//{
//
//}
//
//template<typename T>
//inline Node<T>::Node(Personnel person, Node* pointer): m_Person(person), m_next(nullptr)
//{
//
//}
//
//template<typename T>
//inline Node<T>::~Node()
//{
//	delete m_Person;
//	m_next = nullptr;
//}
//
//template<typename T>
//inline Node<T>::Node(const Node& copy)
//{
//	m_Person = copy.m_Person;
//	m_next = copy.m_next;
//}
//
//template<typename T>
//inline Node<T>& Node<T>::operator=(const Node<T>& rhs)
//{
//	if (this != &rhs)
//	{
//		this->m_Person = rhs.m_Person;
//		m_next = rhs.m_next;
//	}
//	return *this;
//}
//
//template<typename T>
//inline void Node<T>::SetNext(Node<T>* pointer)
//{
//	m_next = pointer;
//}
//
//template<typename T>
//inline Node<T>* Node<T>::GetNext()
//{
//	return m_next;
//}
