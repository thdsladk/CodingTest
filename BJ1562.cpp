#include <iostream>

#include <vector>

#define MOD (int)1e9

using namespace std; 



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;

    cin >> N;
    vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(10,vector<int>(1024)));

    for(int i=1;i<10;i++)
        dp[1][i][1<<i]=1;

    for(int i=2;i<=N;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=1;k<1024;k++)
            {
                if(j==0)
                {
                    dp[i][0][k|(1<<0)]=(dp[i][0][k|(1<<0)]+dp[i-1][1][k])%MOD;
                } 
                else if(j==9)
                {
                    dp[i][9][k|(1<<9)]=(dp[i][9][k|(1<<9)]+dp[i-1][8][k])%MOD;
                }    
                else
                {
                    dp[i][j][k|(1<<j)]=((dp[i][j][k|(1<<j)]+dp[i-1][j+1][k])%MOD+dp[i-1][j-1][k])%MOD;
                } 
            }   
        } 
    }

    int ans=0;
    for(int i=0;i<10;i++) ans=(ans+dp[N][i][1023])%MOD;
    cout << ans << '\n';

    return 0;
}

