#pragma once
#include "stdafx.h" 
#include "MyListNode.h"

template<typename T>
class CListIterator : public std::iterator<std::input_iterator_tag, T>
{
	friend class CStringList;
public:
	CListIterator(ListNode<T>* node, bool isReverse)
		: m_node(node)
		, m_isReverse(isReverse)
	{
	}

	bool operator==(CListIterator const& rhs) const
	{
		return m_node == rhs.m_node;
	}

	bool operator!=(CListIterator const& rhs) const
	{
		return m_node != rhs.m_node;
	}

	CListIterator& operator++()
	{
		if (m_node != nullptr)
		{
			m_node = (m_isReverse) ? m_node->prev : m_node = m_node->next.get();
		}
		return *this;
	}
	CListIterator& operator--()
	{
		if (m_node != nullptr)
		{
			m_node = (m_isReverse) ? m_node->next.get() : m_node = m_node->prev;
		}
		return *this;
	}

	T & operator*() const
	{
		return m_node->data;
	}

private:
	ListNode<T>* m_node = nullptr;
	bool m_isReverse = false;

	ListNode<T>* operator->() const
	{
		return m_node;
	}
};