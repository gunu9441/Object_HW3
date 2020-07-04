#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using std::ostream;

namespace kw
{
	class wordNode //Word class node.
	{
	public:
		string          mData;
		wordNode*		mNextNode;

		wordNode(string& data)
			:
			mData(data),
			mNextNode(NULL)
		{
		}

		wordNode(string& data, wordNode* nextNode)
			:
			mData(data),
			mNextNode(nextNode)
		{
		}

		wordNode()
			:
			mData(NULL),
			mNextNode(NULL)
		{
		}
	};

	class alphabetNode //Alphabet class node.
	{
	public:
		alphabetNode*		alphabet_mNextNode;
		char				mData;
		wordNode*			word_mNextNode;

		alphabetNode(char data)
			:
			alphabet_mNextNode(NULL),
			mData(data),
			word_mNextNode(NULL)
		{
		}

		alphabetNode(alphabetNode* alphabet_nextNode,char data, wordNode* word_nextNode)
			:
			alphabet_mNextNode(alphabet_nextNode),
			mData(data),
			word_mNextNode(word_nextNode)
		{
		}

		alphabetNode()
			:
			alphabet_mNextNode(NULL),
			mData(NULL),
			word_mNextNode(NULL)
		{
		}
	};

	


	class LinkedList
	{

	private:
		alphabetNode*		pHead;//The head of alphabetNode.
		unsigned int		mSize;//The current size of words.
		unsigned int		alphabet;//A value of alphabetNode.

	public:
		LinkedList();
		~LinkedList();

		virtual bool				insert_alphabet_head();//Make the start point.
		virtual bool				Rocate_alphabet();//Place the alphabet.

		virtual char				get_alphabet(int index);//Get an alphabet.

		virtual bool				Rocate_word(string data);//Place a word that ignore the dictionary order.
		virtual bool				show_result();//Output the words.
		virtual bool				sort();//Sorting.

		virtual void				loadTxt(ifstream& inFile);//Recieve input file.
	};

	inline LinkedList::LinkedList()
	{
		pHead = NULL;
		mSize = 0;
		alphabet = 97;
	}
	inline LinkedList::~LinkedList()
	{

	}
	inline bool LinkedList::insert_alphabet_head()//Make the start point.
	{
		alphabetNode* newHead = new alphabetNode(NULL,char(alphabet),NULL);
		pHead = newHead;
		alphabet++;
		return true;
	}
	inline bool LinkedList::Rocate_alphabet()//Place the alphabet.
	{
		while (1)
		{
			if (alphabet < 123)//Alphabet z's unicode value is 122.
			{
				alphabetNode* temp = pHead;
				while (temp->alphabet_mNextNode != NULL)
					temp = temp->alphabet_mNextNode;
				temp->alphabet_mNextNode = new alphabetNode(NULL, char(alphabet), NULL);
				alphabet++;
			}
			else
			{
				alphabet--;
				break;
			}
		}
		return true;
	}
	inline char LinkedList::get_alphabet(int index)//Get an alphabet.
	{
		alphabetNode* temp = pHead;
		for (int count = 0; count < index; count++)
			temp = temp->alphabet_mNextNode;
		return temp->mData;
	}
	inline bool LinkedList::Rocate_word(string data)//Place a word that ignore the dictionary order.
	{
		alphabetNode* temp = pHead;
		for (int i = 0; i < 26; i++)
		{
			if (data.at(0) == char(97 + i))//Check the first alphabet of word.
			{
				if (temp->word_mNextNode == NULL)
				{
					temp->word_mNextNode = new wordNode(data, NULL);
					temp = pHead;
					break;
				}
				else
				{
					wordNode* temp_1 = temp->word_mNextNode;
					while (temp_1->mNextNode != NULL)
						temp_1 = temp_1->mNextNode;

					temp_1->mNextNode = new wordNode(data, NULL);
					temp = pHead;
					break;
				}
			}
			else
				temp = temp->alphabet_mNextNode;
		}
		return true;
	}
	inline bool LinkedList::show_result()//Output the words.
	{
		cout << "Output result" << endl << endl << endl << endl;
		if (pHead == NULL)
		{
			cout << "This linked list is empty." << endl;
			return false;
		}
		else
		{
			alphabetNode* temp = pHead;//Create the temp.
			for (int count = 0;count < 26;count++)
			{
				cout << get_alphabet(count);
				if (temp->word_mNextNode == NULL)
				{
					temp = temp->alphabet_mNextNode;//Move the temp.
					cout << endl << endl;
					continue;
				}
				else
				{
					wordNode*temp_1 = temp->word_mNextNode;
					while (temp_1->mNextNode != NULL)
					{
						cout << "->" << temp_1->mData;
						temp_1 = temp_1->mNextNode;
					}
					cout << "->" << temp_1->mData;
					cout << endl << endl;
					temp = temp->alphabet_mNextNode;
				}
			}
		}
		return true;
	}
	inline bool LinkedList::sort()//Sorting.
	{
		alphabetNode* temp = pHead;
		wordNode* temp_1 = temp->word_mNextNode;

		string value_temp;
		for (int k = 0;k < 26;k++)//The number of alphabet is 26.
		{
			temp_1 = temp->word_mNextNode;
			wordNode* count = temp->word_mNextNode;
			if (count != NULL)//Count the mSize.
			{
				while (count->mNextNode != NULL)
				{
					if (temp->word_mNextNode == NULL)
					{
						mSize = 0;
						break;
					}
					else
					{
						count = count->mNextNode;
						mSize++;
					}
				}
			}
			else
				mSize = 0;

			if (mSize > 0)
				mSize++;
			
			if (mSize > 0) {
				for (int i = 0; i < mSize - 1;i++)//Using basic principal of bubble sort.
				{
					wordNode* re_temp = temp_1;
					for (int j = i;j < mSize - 1;j++)
					{
						re_temp = re_temp->mNextNode;
						if ((temp_1->mData).compare(re_temp->mData) > 0)//Swap.
						{
							value_temp = temp_1->mData;
							temp_1->mData = re_temp->mData;
							re_temp->mData = value_temp;
						}
					}
					temp_1 = temp_1->mNextNode;
				}
			}
			temp = temp->alphabet_mNextNode;
			mSize = 0;
		}
		return true;
	}
	inline void LinkedList::loadTxt(ifstream& inFile)//Recieve input file.
	{
		if (!inFile.is_open())return;

		string input;

		while (!inFile.eof())//Until an EOF
		{
			getline(inFile, input);
			if (input!="")//There is no letter.
				Rocate_word(input);
			else
				break;
		}
	}
	
}
