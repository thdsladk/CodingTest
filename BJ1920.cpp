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
    map<int,int> List_Map;
    vector<int> List_Sec(M);
    vector<int> List_Result(M);
    for(int i=0;i<M;i++)
    {
        int a=0;
        cin>>a;
        List_Sec[i] =a;
        List_Map.insert(a,i);
        List_Result[i] = a; 
    }
    sort(List_Sec.begin(),List_Sec.end());

    vector<int>::iterator  A = List.begin();
    vector<int>::iterator B = List_Sec.begin();
    while(A!=List.end() && B!=List_Sec.end())
    {
        if(*A == *B)
        {
            List_Result[List_Map[*B]] =1;
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

    for(int elem : List_Result)
    {
        cout <<elem<<"\n";
    }




    return 0;
}

/*
 이분 탐색 


*/