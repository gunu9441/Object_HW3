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
		virtual bool			empty() const;

		virtual bool			insert(const T& data);
		virtual bool			insertHead(const T& data);
		virtual unsigned int	size()	const;
		virtual bool			reverse();
		virtual bool			sort();

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
	inline bool LinkedList<T>::empty() const//Check the existance of LinkedList.
	{
		if (mSize == 0)
			return true;
		else
			return false;
	}

	template<typename T>
	inline bool LinkedList<T>::insert(const T & data)//Insert the node.
	{
		if (empty())//If mHead exist.
			insertHead(data);

		else//If mHead does not exist.
		{
			Node<T>*temp = mHead;
			while (temp->mNextNode != NULL)//Move the temp.
				temp = temp->mNextNode;
			temp->mNextNode = new Node<T>(data, NULL);
			mSize++;
		}
		return true;
	}
	
	template<typename T>
	inline bool LinkedList<T>::insertHead(const T & data)//Insert the first node 'mHead'.
	{
		Node<T>*newHead = new Node<T>(data, mHead);
		mHead = newHead;
		mSize++;//Increase the size of node.
		return true;
	}

	template<typename T> 
	inline unsigned int LinkedList<T>::size() const//Size of LinkedList.
	{
		return mSize;
	}

	template<typename T>
	inline bool LinkedList<T>::reverse()//reverse the order of value.
	{
		if (mSize % 2 == 1)//mSize is odd number.
		{
			Node<T>* temp = mHead;
			Node<T>* re_temp = mHead;
			int value_temp = 0;

			value_temp = temp->mData;//Swap.
			for (int i = 0;i < mSize - 1;i++)
				re_temp = re_temp->mNextNode;
			temp->mData = re_temp->mData;
			re_temp->mData = value_temp;
			
			re_temp = mHead;//Redefine a re_temp.
			
			for (int count = 0;count < ((mSize-1) / 2) - 1;count++)
			{

				temp = temp->mNextNode;
				for (int i = 0; i < mSize - count -2;i++)//Move re_temp.
					re_temp = re_temp->mNextNode;

				value_temp = temp->mData;//Swap.
				temp->mData = re_temp->mData;
				re_temp->mData = value_temp;
			}
			re_temp = mHead;//Redefine a re_temp.
		}
		else//mSize is even number.
		{
			Node<T>* temp = mHead;
			Node<T>* re_temp = mHead;
			int value_temp = 0;

			value_temp = temp->mData;//Swap.
			for (int i = 0;i < mSize - 1;i++)
				re_temp = re_temp->mNextNode;
			temp->mData = re_temp->mData;
			re_temp->mData = value_temp;
			
			re_temp = mHead;//Redefine a re_temp.

			for (int count = 0;count < (mSize / 2) - 1;count++)
			{

				temp = temp->mNextNode;
				for (int i = 0; i < mSize - count - 2;i++)//Move re_temp.
					re_temp = re_temp->mNextNode;

				value_temp = temp->mData;//Swap.
				temp->mData = re_temp->mData;
				re_temp->mData = value_temp;
			}
			re_temp = mHead;//Redefine a re_temp.
		}
		return true;
	}

	template<typename T>
	inline bool LinkedList<T>::sort()//Place the value that the biggest one is the lastest and the smallest one is the first.
	{
		Node<T>* temp = mHead;
		int value_temp = 0;

		for (int i = 0; i < mSize - 1;i++)//Using basic principal of bubble sort.
		{
			Node<T>* re_temp = temp;
			for (int j = i;j < mSize - 1;j++)
			{
				re_temp = re_temp->mNextNode;
				if (temp->mData > re_temp->mData)//Swap.
				{
					value_temp = temp->mData;
					temp->mData = re_temp->mData;
					re_temp->mData = value_temp;
				}
			}
			temp = temp->mNextNode;
		}
		return true;

	}
	
}
