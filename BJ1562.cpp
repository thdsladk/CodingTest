#include <iostream>

#include <vector>

using namespace std; 



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;

    cin >> N;
    vector<vector<long long >> dp(N+1,vector<int>(10));

    for(int i =1; i<10;i++)
    {
        dp[1][i] = 1;
    }


    for(int i=2; i<=N;i++)
    {
        for(int j=0;j<10;j++)
        {
            switch(j)
            {
                case 0 :
                {
                    dp[i][j+1] += dp[i-1][j];
                    break;
                }
                case 9 :
                {
                    dp[i][j-1] += dp[i-1][j];
                    break;
                }
                default :
                {
                    dp[i][j-1] += dp[i-1][j];
                    dp[i][j+1] += dp[i-1][j];
                    break;
                }
            }

        }
    }

    long long Result =0;

    for(int i=0;i<10;i++)
    {
        Result += dp[N][i];
    }

    cout << (Result% 1'000'000'000);


    return 0;
}
0