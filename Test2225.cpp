#include "Test2225.h"



Test2225::Test2225()
{
	int N, K = 0;
	cin >> N >> K;

	
	vector<vector<int>> dp(K+1, vector<int>(N+1));


	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int i = 1; i <= K; i++) // °í¸£´Â °¹¼ö 
	{
		for (int j = 0; j <= N; j++) 
		{
			for (int l = 0; l <= j; l++) 
			{
				dp[i][j] += dp[i - 1][j - l];
			}

		}

	}

	cout << dp.back().back();


}
