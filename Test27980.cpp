#include "Test27980.h"

Test27980::Test27980()
{
	cin >> N >> M;

	cin >> Board;
	cin >> String;

	

	cout<<Search(String);

	cout << endl << "ī��Ʈ ���� :  " << Count;

}

int Test27980::Search(string Str, int Index, int LR, int Score)
{
	Count++;
	if (Str.empty() == true)
	{
		return Score;
	}


	if (LR == 0)
	{
		for (auto elem : Board)
		{
			int Score_Temp = Score;
			if (elem == Str.front())
			{
				Score_Temp++;
			}

			Str.erase(Str.begin());

			if(Index != 0)
				MaxScore = max(Search(Str, Index - 1, -1, Score_Temp),MaxScore);
			if(Index < Board.size()-1)
				MaxScore = max(Search(Str, Index + 1, +1, Score_Temp), MaxScore);

			
		}
	}
	else
	{
		if (MaxScore > Score + Str.size())
		{
			return 0; // ���� ��� ���� �������� �ְ� ���������� ���Ƽ� Ż�� 
		}


		if (Board[Index] == Str.front())
		{
			Score++;
		}

		Str.erase(Str.begin());

		if (Index != 0)
			MaxScore = max(Search(Str, Index - 1, -1, Score), MaxScore);
		if (Index < Board.size() - 1)
			MaxScore = max(Search(Str, Index + 1, +1, Score), MaxScore);



	}


	return MaxScore;
}
