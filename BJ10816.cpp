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
    map<int,int> List2;
    for(int i=0;i<N;i++)
    {
        cin >>List[i];
        if(List2.find(List[i]) != List2.end())
        {
            List2[List[i]] += 1;
        }
        else
        {
            List2[List[i]] =1;
            //List2.insert(List[i],1);
        }
    }
    sort(List.begin(),List.end());


    cin >>M;
    vector<int> List_Sec(M);
    vector<int> Result(M);
    for(int i=0;i<M;i++)
    {
        cin>>List_Sec[i];
    }

    for(auto elem : List_Sec)
    {
        if(binary_search(List.begin(),List.end(),elem) ==true)
        {
            cout <<List2[elem]<<" ";
        }
        else
        {
            cout <<"0 ";
        }
    }
    



    return 0;
}


/* 수동식 으로 구현하기 ( 시간 초과 해결해야함)

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
    vector<int> Result(M);
    for(int i=0;i<M;i++)
    {
        cin>>List_Sec[i];
    }

    for(int i=0;i<M;i++)
    {
        int Start,Mid,End =0;
        Start =0;
        End = List.size()-1;
        while(true)
        {

            Mid = (Start + End) / 2;

            if(List[Mid]  == List_Sec[i])
            {
                Result[i] += 1;
            
                for(int L = Mid-1;L>=0;L--)
                {
                    if(List[L] == List_Sec[i])
                        Result[i] += 1;
                }
                for(int R = Mid+1;R<N;R++)
                {
                    if(List[R] == List_Sec[i])
                        Result[i] +=1;
                }
                break;
            }
            else if(List[Mid]  > List_Sec[i])
            {
                End = Mid-1;
            }
            else
            {
                Start = Mid+1;
            }

            if(Mid ==0 || Mid ==List.size()-1 || Start >= End)
            {
                break;
            }

        }



    }

    for(auto elem: Result)
    {
        cout << elem << " ";
    }


    return 0;
}
*/