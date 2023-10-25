#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Test27980
{
public:
	Test27980();
	int Search(string Str, int Index=0, int LR=0, int Score=0);
private:
	int N, M = 0;
	string Board;
	string String;
	int MaxScore = 0;
	int Count = 0;
};

