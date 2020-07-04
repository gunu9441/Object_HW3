#include <iostream>
#include <string>

#include "Queue.h"

using namespace std;

int main()
{
	kw::Queue  Queue;

	int Select_num, Input_num;
	while (1)
	{
		Input_num = Queue.Input_Size();
		if (Input_num >= 53)
			cout << "Limit of the number of cards are 52." << endl << "Please input a correct number." << endl << endl;
		else
			break;
	}
	while (1)
	{
		cout << "-----------------------------" << endl << endl;
		cout << "Queue Size : " << Input_num << endl;
		cout << "1.Generate Card" << endl;
		cout << "2.Delete Card" << endl;
		cout << "3.Show all card" << endl;
		cout << "4.End" << endl;
		cout << "-----------------------------" << endl << endl;
		cout << "Select menu: ";
		cin >> Select_num;
		cout << endl;
		if (Select_num == 1)//If Select_num is 1.
			Queue.Push();
		else if (Select_num == 2)//If Select_num is 2.
			Queue.Pop();
		else if (Select_num == 3)//If Select_num is 3.
			cout << Queue << endl;
		else if (Select_num == 4)//If Select_num is 4.
		{
			cout << "The End." << endl;
			break;
		}
		else//else
			cout << "Input the correct number of Input size";
	}
	return 0;
}

