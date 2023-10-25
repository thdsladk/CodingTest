#include "Test15686.h"
//#include <vector>
#include <map>

#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;
/*

���� Ǯ�� ���̵�� 

ġŲ�� M ���� �������� ���� ����� ġŲ�Ÿ� ���ϱ� .

 ��� (��, ġŲ�Ÿ�)     ���� ġŲ �Ÿ�  

 Ǯ�� :

 1. �� ��ǥ , ġŲ�� ��ǥ , ġŲ�Ÿ� �� ���� ������ �����Ѵ� .  
 �� ���� �� ġŲ���� ���Ѵ�. 

 2. ġŲ���� �����Ų�� 

*/
Test15686::Test15686()
{
	// 0: ��  1: ��  2: ġŲ��  

	int N, M = 0;

	cin >> N >> M;


	vector<vector<int>> Map(N, vector<int>(N));
	
	// ���� �ۼ� 
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
	else if (Cnt < 0) // ����Ʈ�� ä������ ���
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
	else if (Cnt > 0) // ����Ʈ�� �������� ���
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

	// �Ÿ���� 
	int i = 0;
	for (auto Iter = Home.begin(); Iter != Home.end(); Iter++)
	{
		for (auto Iter2 = a.begin(); Iter2 != a.end(); Iter2++)
		{
			if (*Iter2 == Pos{ -1,-1 })continue;
			int Temp = 0;
			Temp = Distance(*Iter, *Iter2);

			if (DistanceList[i] == 0 ||		// �Ÿ��� 0 �ΰ��� ��� �׳� ���԰��� 
				DistanceList[i] > Temp)		// �Ÿ��� �������� ��ü
			{
				DistanceList[i] = Temp;
			}
		}

		i++;

	}
	return DistanceList;
}
