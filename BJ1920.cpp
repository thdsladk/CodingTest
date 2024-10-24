#include <iostream>

#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M =0;

    cin>>N;
    priority_queue<int> List_Temp;
    vector<int> List(N); 
    for(int i=0;i<N;i++)
    {
        int a=0;
        cin >>a;
        List_Temp.push(a);

    }
    for(int i=0;i<N;i++)
    {
        List[i] = List_Temp.top();
        List_Temp.pop();
    }

    cin >>M;
    vector<int> List_Sec(M);
    for(int i=0;i<M;i++)
    {
        cin>>List_Sec[i]; 
    }


    for(auto elem : List_Sec)
    {
        int Result =0;
        for(int i=0;i<N;i++)
        {
            if(elem == List[i])
            {
                Result = 1;
            }
            else if(elem <List[i])
            {
                break;
            }
        }
        cout <<Result<<"\n";
    }






    return 0;
}

/*
 이분 탐색 


*/