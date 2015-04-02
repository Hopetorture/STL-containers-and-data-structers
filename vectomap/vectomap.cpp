// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include<iostream>
#include<map>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

class Vectomap
{
	vector< string > data;
	vector<int>key;
public:
	Vectomap() : key(0), data(0)
	{}
	~Vectomap(){}
	void pushback(int k, string d);
	int find(int k);
	string find(string d);
	void remove(int k);
	void remove(string d);


};

void Vectomap::pushback(int k, string d)
{
	data.push_back(d);
	key.push_back(k);
}
int Vectomap::find(int k)
{
	//int size = key.size();
	for (int i = 0; i<key.size(); ++i)
	{
		if (key[i] == k)
			return key[i];
	}
}
string Vectomap::find(string d)
{
	//int size = data.size();
	for (int i = 0; i<data.size(); ++i)
	{
		if (data[i] == d)
			return data[i];
	}

}
void Vectomap::remove(int k)
{
	
	for (int i = 0; i<key.size(); ++i)
	{
		if (key[i] == k)
		{
			data.erase(data.begin() + (i - 1));
			key.erase(key.begin() + (i - 1));
		}

	}
}
void Vectomap::remove(string d)
{
	int size = data.size();
	for (int i = 0; i<data.size(); ++i)
	{
		if (data[i] == d)
		{
			data.erase(data.begin() + (i - 1));
			key.erase(key.begin() + (i - 1));
		}

	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	clock_t start;
	double duration;
	Vectomap  obj1;
	start = clock();
	for (int i = 0; i < 10000; ++i)
	{
		string pb=i;
		int rnd = rand() % 10000;
		obj1.pushback(rnd, pb);
	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "vectomap insert time is:" << duration << endl;

	map<string, int> testmap;
	start = clock();
	for (int i = 0; i < 10000; ++i)
	{
		string s = "qwe";
		testmap.insert({ s, i });
	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "map insert time is:" << duration << endl;

	start = clock();
	for (int i = 0; i < 10000; ++i)
	{
		int rnd = rand() % 10000;
		obj1.find(rnd);
	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Vectomap find time is:" << duration << endl;

	map<int, string> testmap2;
	for (int i = 0; i < 10000; ++i)
	{
		string s = "a";
		testmap2.insert({ i, s });
		
	}
	map<string, int>::iterator it;
	it = testmap.begin();
	start = clock();
	for (int i = 0; i < 10000; ++i)
	{
		string pb = "qwe";
		it = testmap.find(pb);	

	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "map find time is:" << duration << endl;

	start = clock();
	for (int i = 0; i < 10000; ++i)
	{
		obj1.remove(i);
	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Vectomap remove time is:" << duration << endl;

	start = clock();
	for (int i = 0; i < 10000; ++i)
	{
		testmap2.erase(i);
	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Map remove time is:" << duration << endl;
	
	system("pause");

	return 0;
}

