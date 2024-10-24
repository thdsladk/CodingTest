#include <iostream>

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M =0;

    cin>>N;
    vector<int> List(N); 
    for(int i=0;i<N;i++)
    {
        cin >>List[i];
    }
    sort(List.begin(),List.end());


    cin >>M;
    map<int,int> Map;
    vector<int> List_Sec(M);
    vector<int> Result(M);
    for(int i=0;i<M;i++)
    {
        cin>>List_Sec[i];
        Map.insert(List_Sec[i],i);
        Result[i] = List_Sec[i]; 
    }
    sort(List_Sec.begin(),List_Sec.end());

    auto A = List.begin();
    auto B = List_Sec.begin();
    while(A!=List.end() && B!=List_Sec.end())
    {
        if(*A == *B)
        {
            Result[Map[*B]] =1;
            A++;
            B++;
        }
        else if(*A < *B)
        {            
            A++;
        }
        else if(*A > *B)
        {
            B++;
        }
    }

    for(auto elem : Result)
    {
        cout <<elem<<"\n";
    }




    return 0;
}

/*
 이분 탐색 


*/