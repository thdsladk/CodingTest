#include <iostream>

#include <vector>

using namespace std; 
using start = 0;
using end = 1;
using dist = 2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,D =0;
    cin>> N >>D;

    vector<vector<int>> Dist;
    for(int i=0;i<N;i++)
    {
        int Start,End,Distance =0;
        cin>>Start>>End>>Distance;

        if(End - (Start+Distance) > 0)
        {
            Dist.push_back(vector<int>{Start,End,Distance});
        }
    }

    vector<int> Temp();
    for(int i=0;i<Dist.size()-1;i++)
    {
        for(int j=i+1;j<Dist.size();j++)
        {
            if(Dist[i][start] <= Dist[j][start] && Dist[i][end] > Dist[j][start])
            {
                if(Dist[i][end] - (Dist[i][start]+Dist[i][dist]) > Dist[j][end] - (Dist[j][start]+Dist[j][dist]))     
                {
                    continue;
                }
                else
                {
                    Temp = Dist[i];
                    continue;
                }
            
            }
            else
            {
                
            }

        }
    }






    return 0;

}

/*

지름길의 갯수 N , 고속도로의 길이 D 
N <= 12   D <= 10000 

지름길의 시작 위치, 도착 위치, 지름길의 길이


*/
