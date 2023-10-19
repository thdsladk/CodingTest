#include "Test1374.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Class
{
	Class() = default;
	Class operator+(const Class& a)
	{	
		Class Temp;
		Temp.Num = Num + a.Num;
		Temp.StartTime = StartTime + a.StartTime;
		Temp.EndTime = EndTime + a.EndTime;
		return Temp;
	}

	Class(const Class& rhs)
	{
		Num = rhs.Num;
		StartTime = rhs.StartTime;
		EndTime = rhs.EndTime;
	}

	int Num = 0;
	int StartTime = 0;
	int EndTime = 0;
};

Test1374::Test1374()
{
	int N = 1;
	cin >> N;

	vector<pair<int, int>> Schedule;
	priority_queue<int, vector<int>, greater<int>> lastTime;
	int Answer = 1;

	for (int i = 0; i < N; i++)
	{
		int Room, Start, End =1;
		cin >> Room >> Start >> End;
		Schedule.push_back({ Start,End });
	}

	sort(Schedule.begin(), Schedule.end());
	

	for (int i = 0; i < Schedule.size(); i++) {
		int StartTime = Schedule[i].first;
		int EndTime = Schedule[i].second;

		if (lastTime.empty()) {
			lastTime.push(EndTime);
		}
		else 
		{
			if (lastTime.top() > StartTime) 
			{ // ���� �� ���� ��� ȸ�ǽ��� ����.
				Answer++;
			}
			else 
			{ // �� ȸ�ǽǷ� ���� �ȴ�.
				lastTime.pop(); // ���� ���Ǵ� �����ش�.
			}

			lastTime.push(EndTime);
			// � ��쿡������ ���Ӱ� ������ ���� ������ �����Ѵ�.
		}
	}
	cout << Answer;
	



}

Test1374::~Test1374()
{
}
