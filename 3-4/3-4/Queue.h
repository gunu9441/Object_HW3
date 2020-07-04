#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;
using std::ostream;

namespace kw
{
	class Node
	{
	public:
		string			card_shape;//Card's shape.
		int             card_num;//Card's number.
		Node*			mNextNode;//Nextnode.

		Node(string& data1, int& data2)
			:
			card_shape(data1),
			card_num(data2),
			mNextNode(NULL)
		{
		}

		Node(string& data1, int& data2, Node* nextNode) :
			card_shape(data1),
			card_num(data2),
			mNextNode(nextNode)
		{
		}

		Node() :
			card_shape(NULL),
			card_num(NULL),
			mNextNode(NULL)
		{
		}
	};

	class  Queue
	{

	private:
		Node*				mHead;//mHead.
		unsigned int		mSize;//Limit of the number of cards.
		unsigned int		current_Size;//The number of current cards.

	public:
		Queue();
		~Queue();

		virtual	unsigned int		Input_Size();
		virtual bool				makeQueue(string shape, int num);//Make the first card.

		virtual bool				IsEmpty();//Check the space of card.
		virtual bool				IsFull();//Check the space of card.

		virtual string				get_shape(const int index)const;//Get the card's shape.
		virtual int					get_num(const int index)const;//Get the card's number.
		virtual bool				Add_Card();//Add card.
		virtual bool				Push();//Generate a card.
		virtual bool				Pop();//Delete the first card.
		virtual string				Shape_generater();//Determine the card's shape.
		virtual unsigned int		num_generater();//Determine the card's number.
		unsigned int				get_current_Size();

		friend ostream& operator<<(ostream& os, const Queue& data)//Output the LinkedList.
		{
			if (data.mHead == NULL)
				os << "Queue is empty." << endl;
			else
				for (int count = 0;count < data.current_Size;count++)
				{
					if (count >= 1)
						os << "/ ";
					os << data.get_shape(count) << data.get_num(count);
				}

			return os;
		}
	};

	inline Queue::Queue()
	{
		mHead = NULL;
		mSize = 0;
		current_Size = 0;
	}
	inline  Queue::~Queue()
	{

	}
	inline unsigned int  Queue::Input_Size()
	{
		cout << "Size : ";
		cin >> mSize;
		cout << endl;

		return mSize;
	}
	inline bool Queue::makeQueue(string shape, int num)//Make the first card.
	{
		Node *newHead = new Node(shape, num, NULL);
		mHead = newHead;
		current_Size++;
		return true;
	}
	inline bool  Queue::IsEmpty()//Check the space of card.
	{
		if (current_Size == 0)
			return true;
		else
			return false;
	}
	inline bool  Queue::IsFull()//Check the space of card.
	{
		if (IsEmpty())
			return false;
		else
		{
			if (current_Size == mSize)//if the current_Size is equal to limit of the number of card, implement.
				return true;
			else
				return false;
		}
	}
	inline string  Queue::get_shape(const int index) const//Get the shape of card.
	{
		Node*temp = mHead;
		for (int count = 0;count < index;count++)
			temp = temp->mNextNode;
		return temp->card_shape;
	}
	inline int  Queue::get_num(const int index) const//Get card's number.
	{
		Node*temp = mHead;
		for (int count = 0;count < index;count++)
			temp = temp->mNextNode;

		return temp->card_num;
	}
	inline bool  Queue::Add_Card()//Add card.
	{
		srand(time(NULL));
		int test_num = 1;
		Node* temp = mHead;
		Node* test_temp = mHead;
		string shape;
		int num;

		shape = Shape_generater();
		num = num_generater();
		while (1)
		{
			if (test_temp->card_shape == shape&&test_temp->card_num == num)//If input data is equal to previous datas. 
			{
				shape = Shape_generater();
				num = num_generater();
				test_temp = mHead;
				continue;
			}
			if (test_temp->mNextNode == NULL)
				break;

			test_temp = test_temp->mNextNode;
		}

		test_temp->mNextNode = new Node(shape, num, NULL);//Make new card.
		current_Size++;
		
		return true;
	}


	inline bool  Queue::Push()//Generate a card.
	{
		if (IsFull())//There is no space.
		{
			cout << "There is no space to generate card!" << endl;
			return false;
		}
		else//There is space to generate a card.
		{
			if (IsEmpty())
				makeQueue(Shape_generater(), num_generater());
			else
				Add_Card();
			


			return true;
		}

		return true;
	}
	inline bool  Queue::Pop()//Delete a first card.
	{
		if (current_Size == 0)//There is no card.
		{
			cout << "There is no card." << endl;//Exception handling.
			return false;
		}
		else if (current_Size == 1)//There is one card.
		{
			string shape = mHead->card_shape;
			int num = mHead->card_num;
			cout << shape << num << "is popped." << endl;
			mHead = NULL;
			current_Size = 0;
			return true;
		}
		else //There are at least 2 card.
		{
			Node*temp = mHead;
			string shape = mHead->card_shape;
			int num = mHead->card_num;
			cout << shape << num << "is popped." << endl;
			temp = temp->mNextNode;
			mHead = temp;
			current_Size--;
			return true;
		}
	}
	inline string  Queue::Shape_generater()//Determine a shape of card.
	{
		int Rand_shape;
		string shape;

		Rand_shape = rand() % 4;//Determine random number in "Rand_shape".
		if (Rand_shape == 0)
			shape = "¢¾";
		else if (Rand_shape == 1)
			shape = "¢¼";
		else if (Rand_shape == 2)
			shape = "¢À";
		else
			shape = "¡ß";

		return shape;

	}
	inline unsigned int  Queue::num_generater()//Determine card's number.
	{
		int num, Rand_num;

		Rand_num = rand() % 13;//Determine random number in "Rand_num".
		num = Rand_num + 1;

		return num;
	}
	unsigned int  Queue::get_current_Size()//Get the size of cards.
	{
		return current_Size;
	}

}
