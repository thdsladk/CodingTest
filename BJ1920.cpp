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

/*
    for(auto elem : List_Sec)
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

            if(Mid ==0 || Mid ==List.size()-1)
            {
                cout << "0\n";
                break;
            }

        }



    }

*/

    for(auto elem : List_Sec)
    {
        if(binary_search(List.begin(),List.end(),elem) ==true)
        {
            cout << "1\n";
        }
        else
        {
            cout <<"0\n";
        }
    }



    return 0;
}

/*
 이분 탐색 
    그냥 깔끔하게 내장함수 쓰자 
    binary_search쓰자 ...

*/