#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Test3132
{
public:
	Test3132();

	void DFS(int Child, int Parent, int MaxIQ);
private:
	vector<int> adj[1001];
	vector<int> IQ;
	vector<pair<int, int>> NewStructure;
};

