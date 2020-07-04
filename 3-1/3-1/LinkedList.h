#pragma once

#include <iostream>

using std::ostream;

namespace kw
{
	template<typename T>

	class Node
	{
	public:
		T               mData;
		Node<T>*	mNextNode;

		Node(const T& data)
			:
			mData(data),
			mNextNode(NULL)
		{
		}

		Node(const T& data, Node<T>* nextNode)
			:
			mData(data),
			mNextNode(nextNode)
		{
		}

		Node()
			:
			mData(NULL),
			mNextNode(NULL)
		{
		}
	};

	template <typename T>
	class LinkedList
	{

	private:
		Node<T>*            mHead;
		unsigned int		mSize;

	public:
		LinkedList();
		~LinkedList();

		virtual T               get(const int index) const;
		virtual bool			set(const int index, const T& data);

		virtual bool			insert(const T& data);
		virtual bool			insert(const int index, const T& data);

		virtual bool			insertHead(const T& data);

		virtual bool			pop();
		virtual bool			pop(const int index);

		virtual unsigned int	size()	const;
		virtual bool			empty() const;

		virtual void			clear();

		friend ostream& operator<<(ostream& os, const LinkedList<T>& data)//Output the LinkedList.
		{
			if (data.mHead == NULL)
			{
				os << "This linked list is empty." << endl;
			}
			else
			{
				os << "------------------------------------" << endl;
				for (int count = 0;count < data.mSize;count++)
				{
					os << "idx: " << count << ", data: " << data.get(count) << endl;
				}
				os << "------------------------------------" << endl;
			}

			return os;
		}
	};
	template<typename T>
	inline LinkedList<T>::LinkedList()
	{
		mHead = NULL;
		mSize = 0;
	}
	template<typename T>
	inline LinkedList<T>::~LinkedList()
	{

	}
	template<typename T>
	inline T LinkedList<T>::get(const int index) const//Bring the mdata in index node.
	{
		Node<T>*temp = mHead;
		for (int count = 0;count < index;count++)
			temp = temp->mNextNode;

		return T(temp->mData);
	}
	template<typename T>
	inline bool LinkedList<T>::set(const int index, const T & data)//Input the other input in index node.
	{
		Node<T>*temp = mHead;
		for (int count = 0;count < index;count++)
			temp = temp->mNextNode;
		temp->mData = data;
		return true;
	}
	template<typename T>
	inline bool LinkedList<T>::insert(const T & data)//Insert the node.
	{
		if (empty())//If mHead exist.
			insertHead(data);

		else//If mHead does not exist.
		{
			Node<T>*temp = mHead;
			while (temp->mNextNode != NULL)//Move the temp;
				temp = temp->mNextNode;
			temp->mNextNode=new Node<T>(data, NULL);
			mSize++;
		} 
		return true;
	}
	template<typename T>
	inline bool LinkedList<T>::insert(const int index, const T & data)//Insert the node.
	{
		Node<T>*temp = mHead;
		for (int count = 0;count < index-1 ;count++)//Move the temp.
			temp = temp->mNextNode;
		Node<T>*add_temp = new Node<T>(data,temp->mNextNode);
		temp->mNextNode = add_temp;
		mSize++;//Increase the size of node.
		return true;
	}
	template<typename T>
	inline bool LinkedList<T>::insertHead(const T & data)//Insert the first node 'mHead'.
	{
		Node<T>*newHead = new Node<T>(data, NULL);
		mHead = newHead;
		mSize++;//Increase the size of node.
		return true;
	}
	template<typename T>
	inline bool LinkedList<T>::pop()//Remove the lastest node.
	{
		Node<T>*temp = mHead;
		for (int count = 0;count < mSize-2;count++)//Move the temp.
			temp = temp->mNextNode;
		temp->mNextNode = NULL;//temp->mNextNode do not dicated other node.
		mSize--;//Reduce the size of node.
		return true;
	}
	template<typename T>
	inline bool LinkedList<T>::pop(const int index)
	{
		if (empty())
			return false;
		else 
		{
			Node<T>*temp = mHead;
			for (int count = 0;count < index;count++)//Move the temp.
				temp = temp->mNextNode;
			Node<T>*temp1 = temp->mNextNode;
			if (mHead == temp)//If mHead is equal to temp, Implement.
				mHead = temp1;
			else
				temp->mNextNode = temp1;
			mSize--;//Reduce the size of node.
		}

		return true;
	}
	template<typename T>
	inline unsigned int LinkedList<T>::size() const//Size of LinkedList.
	{
		return mSize;
	}
	template<typename T>
	inline bool LinkedList<T>::empty() const//Check the existance of LinkedList.
	{
		if (mSize == 0)
			return true;
		else
			return false;
	}
	template<typename T>
	inline void LinkedList<T>::clear()//Remove all nodes.(Remove LinkedList.)
	{
		mHead = NULL;
		mSize = 0;
	}
}
