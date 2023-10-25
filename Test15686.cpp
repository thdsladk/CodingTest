#include "Test15686.h"
//#include <vector>
#include <map>

#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;
/*

문제 풀이 아이디어 

치킨집 M 개만 남겼을때 가장 가까운 치킨거리 구하기 .

 노드 (집, 치킨거리)     도시 치킨 거리  

 풀이 :

 1. 집 좌표 , 치킨집 좌표 , 치킨거리 를 가진 노드들을 구성한다 .  
 총 집수 총 치킨집수 구한다. 

 2. 치킨집을 폐업시킨다 

*/
Test15686::Test15686()
{
	// 0: 빈  1: 집  2: 치킨집  

	int N, M = 0;

	cin >> N >> M;


	vector<vector<int>> Map(N, vector<int>(N));
	
	// 지도 작성 
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> Map[y][x];

			if (Map[y][x] == 2)
			{
				ChickenRestaurant.emplace_back(Pos{ y,x });
			}
			else if(Map[y][x] == 1)
			{
				Home.emplace_back(Pos{ y,x });
			}
			

		}
	}

	if (Home.size() <= M)
	{
		int Result = 0;
		for (auto elem : CalculateDistance(ChickenRestaurant))
		{
			Result += elem;
			cout << elem << endl;
		}
		cout << Result;
	}
	else
	{
		if ((Home.size() / 2) <= M)
		{
			cout << ReExecute(ChickenRestaurant, ChickenRestaurant.size() - M);
		}
		else
		{
			cout << ReExecute(vector<Pos>(ChickenRestaurant.size(), Pos{ -1,-1 }), -M);
		}
	}

}

Test15686::~Test15686()
{

}

int Test15686::ReExecute(vector<Pos> a,int Cnt)
{
	int Result = 10000;

	if (Cnt == 0) 
	{
		Result = 0;
		for (auto elem : CalculateDistance(a))
		{
			Result += elem;
		}
		return Result;
	}
	else if (Cnt < 0) // 리스트를 채워가는 방식
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == Pos{ -1,-1 })
			{
				a[i] = ChickenRestaurant[i];
				int Temp1 = ReExecute(a, Cnt + 1);

				if (Temp1 < Result)
				{
					Result = Temp1;
				}
				a = vector<Pos>( a.size(), Pos{ -1,-1 } );
			}

		}
		return Result;

	}
	else if (Cnt > 0) // 리스트를 지워가는 방식
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != Pos{ -1,-1 })
			{
				vector<Pos> Temp = a;
				Temp[i] = Pos{ -1,-1 };
				int Temp1 = ReExecute(Temp, Cnt - 1);

				if (Temp1 < Result)
				{
					Result = Temp1;
				}
			}



		}
		return Result;

	}
	
}

int Test15686::Distance(Pos a, Pos b)
{
	int X, Y = 0;

	X = a.x - b.x;
	Y = a.y - b.y;

	if (X < 0)
		X = -X;
	if (Y < 0)
		Y = -Y;


	return (X + Y);
}

std::vector<int> Test15686::CalculateDistance(std::vector<Pos> a)
{
	vector<int> DistanceList(Home.size());

	// 거리계산 
	int i = 0;
	for (auto Iter = Home.begin(); Iter != Home.end(); Iter++)
	{
		for (auto Iter2 = a.begin(); Iter2 != a.end(); Iter2++)
		{
			if (*Iter2 == Pos{ -1,-1 })continue;
			int Temp = 0;
			Temp = Distance(*Iter, *Iter2);

			if (DistanceList[i] == 0 ||		// 거리가 0 인경우는 없어서 그냥 대입가능 
				DistanceList[i] > Temp)		// 거리가 더작으면 대체
			{
				DistanceList[i] = Temp;
			}
		}

		i++;

	}
	return DistanceList;
}
