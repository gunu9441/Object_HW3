#include <iostream>
#include <fstream>
#include <string>

#include "Header.h"


using namespace std;

int main()
{
	kw::LinkedList linkedList;

	string strFileName = "input.txt";
	ifstream inFile(strFileName);
	

	if (!inFile.is_open())
	{
		cout << "file is not opened" << endl;
	}


	linkedList.insert_alphabet_head();
	linkedList.Rocate_alphabet();

	linkedList.loadTxt(inFile);

	linkedList.sort();

	linkedList.show_result();

}