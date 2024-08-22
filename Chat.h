#pragma once
#include<iostream>
using namespace std;

#define veryBigNumber 10000
#define arraySize 20

class Chat
{
	struct user
	{
		string name;
		int hash;
	};
	int size = arraySize;
	user* usArray = new user [size];
public:
	Chat();
	~Chat();
	void reg(string name, string password);
	void del(string name);
	bool login(string name, string password);
	int hash_function(const string& name, int index);
};
