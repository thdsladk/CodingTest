#include <iostream>

#include <vector>

using namespace std; 



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int Bullet =1;
    int N,Count=0;
    int dp[300001]{};
    cin>> N;
    dp[1] = 1;

    int i =2;

    while((N>=dp[i-1]))
    {
        Bullet +=i;
        dp[i]=dp[i-1] + Bullet;
        i++;
    }
    i--;    

    for(;N > 0 ;i--)
    {
        if(N <= dp[i])
        {
            Count+= N / dp[i];
            N = N % dp[i]; 
        }    
    }

    



    return 0;
}