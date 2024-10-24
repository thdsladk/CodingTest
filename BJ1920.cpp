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
    vector<int> List_Sec(M);
    for(int i=0;i<M;i++)
    {
        cin>>List_Sec[i];
    }

    for(auto elem : List_Sec)
    {
        int Start,Mid,End =0;
        Start =0;
        End = List.size()-1;
        while(true)
        {

            Mid = (Start + End) / 2;

            if(List[Mid]  == elem)
            {
                cout<<"1\n";
                break;
            }
            else if(List[Mid]  > elem)
            {
                End = Mid;
            }
            else
            {
                Start = Mid;
            }

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