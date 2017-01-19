#pragma once
#include "stdafx.h"
#include "MyListNode.h"
#include "MyListIterator.h"

template<typename T>
class CMyList
{
	friend class ListNode<T>;
	friend class CListIterator<T>;
public:
	CMyList() = default;
	CMyList(CMyList & list)
	{
		CMyList MyList;
		for (const T & elem : list)
		{
			MyList.PushBack(elem);
		}
		std::swap(m_firstNode, MyList.m_firstNode);
		std::swap(m_lastNode, MyList.m_lastNode);
		m_size = MyList.m_size;
	}

	~CMyList()
	{
		Clear();
	}

	size_t GetSize() const
	{
		return m_size;
	}

	bool IsEmpty() const
	{
		return m_size == 0;
	}

	void PushBack(T & data)
	{
		try
		{
			std::unique_ptr<ListNode<T>> newNode = std::make_unique<ListNode<T>>(data, m_lastNode, nullptr);
			ListNode<T> *newLastNode = newNode.get();
			if (m_lastNode)
			{
				m_lastNode->next = std::move(newNode);
			}
			else
			{
				m_firstNode = std::move(newNode);
			}
			m_lastNode = newLastNode;
			m_lastNode->next = nullptr;

			++m_size;
		}
		catch (...)
		{
			throw;
		}
	}

	void PushFront(T & data)
	{
		try
		{
			std::unique_ptr<ListNode<T>> newNode = InsertOnTheEdge(data, nullptr, std::move(m_firstNode));
			if (!newNode->next)
			{
				m_lastNode = newNode.get();
			}
			m_firstNode = std::move(newNode);
			m_firstNode->prev = nullptr;

			m_size++;
		}
		catch (...)
		{
			throw;
		}
	}

	void Clear()
	{
		while (m_lastNode)
		{
			m_lastNode->next = nullptr;
			m_lastNode = m_lastNode->prev;
		}
		m_firstNode = nullptr;
		m_size = 0;
	}

	void Insert(const CListIterator<T> & it, T data)
	{
		if (it == begin())
		{
			PushFront(data);
		}
		else if (it == end())
		{
			PushBack(data);
		}
		else
		{
			try
			{
				auto node = std::make_unique<ListNode<T>>(data, it->prev, std::move(it->prev->next));
				it->prev = std::move(node.get());
				node->prev->next = std::move(node);
			}
			catch (...)
			{
				throw;
			}
		}
	}

	void Erase(const CListIterator<T> & it)
	{
		if (m_size == 0)
		{
			throw std::out_of_range("List is empty");
		}
		else if (m_size == 1)
		{
			Clear();
			return;
		}

		auto pEnd = begin();
		for (size_t i = 0; i < m_size - 1; ++i)
		{
			pEnd = ++pEnd;
		}

		if (it == begin())
		{
			m_firstNode = std::move(it->next);
			m_firstNode->prev = nullptr;
		}
		else if (it == pEnd)
		{
			m_lastNode = std::move(it->prev);
			m_lastNode->next = nullptr;
		}
		else
		{
			it->next->prev = std::move(it->prev);
			it->prev->next = std::move(it->next);
		}

		if (m_size > 0)
		{
			m_size--;
		}
	}

	T & GetLastElement() const
	{
		if (m_lastNode != nullptr)
		{
			return m_lastNode->data;
		}
		else
		{
			throw std::runtime_error("List hasn`t last element");
		}
	}

	T & GetFirstElement() const
	{
		if (m_firstNode != nullptr)
		{
			return m_firstNode->data;
		}
		else
		{
			throw std::runtime_error("List hasn`t first element");
		}
	}

	CListIterator<T> begin()
	{
		return CListIterator<T>(m_firstNode.get(), false);
	}

	CListIterator<T> end()
	{
		return (m_lastNode != nullptr)
			? CListIterator<T>(m_lastNode->next.get(), false)
			: CListIterator<T>(m_lastNode, false);
	}

	const CListIterator<T> cbegin() const
	{
		return CListIterator<T>(m_firstNode.get(), false);
	}

	const CListIterator<T>cend() const
	{
		return (m_lastNode != nullptr)
			? CListIterator<T>(m_lastNode->next.get(), false)
			: CListIterator<T>(m_lastNode, false);
	}

	CListIterator<T> rbegin()
	{
		return CListIterator<T>(m_lastNode, true);
	}

	CListIterator<T> rend()
	{
		return (m_firstNode != nullptr)
			? CListIterator<T>(m_firstNode->prev, true)
			: CListIterator<T>(m_firstNode.get(), true);
	}

	const CListIterator<T> crbegin() const
	{
		return CListIterator<T>(m_lastNode, true);
	}

	const CListIterator<T> crend() const
	{
		return (m_firstNode != nullptr)
			? CListIterator<T>(m_firstNode->prev, true)
			: CListIterator<T>(m_firstNode.get(), true);
	}

private:
	std::unique_ptr<ListNode<T>> InsertOnTheEdge(const T & data, ListNode<T> * prev, std::unique_ptr<ListNode<T>> && next)
	{
		try
		{
			std::unique_ptr<ListNode<T>> newNode = std::make_unique<ListNode<T>>(data, prev, std::move(next));

			if (newNode->prev)
			{
				newNode->prev->next = std::move(newNode);
			}
			else if (newNode->next)
			{
				newNode->next->prev = newNode.get();
			}
			return newNode;
		}
		catch (...)
		{
			throw;
		}
	}

	size_t m_size = 0;
	std::unique_ptr<ListNode<T>> m_firstNode = nullptr;
	ListNode<T> * m_lastNode = nullptr;
};