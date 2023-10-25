#pragma once

#include <vector>

class Test15686
{
public:
	struct Pos
	{
	public:
		bool operator==(const Pos& a) {
			return (a.x == x && a.y == y);
		}
		bool operator!=(const Pos& a) {
			return (a.x != x || a.y != y);
		}
		int y{};
		int x{};
	};
	struct Node
	{
		Pos HomePos{};
		Pos ChickenPos{};
		int Distance{};

	};
	Test15686();
	~Test15686();


	int ReExecute(std::vector<Pos> a,int Cnt);

private:

	std::vector<Pos> Home;
	std::vector<Pos> ChickenRestaurant;

private:

	int Distance(Pos a, Pos b);
	std::vector<int> CalculateDistance(std::vector<Pos> a);

};

