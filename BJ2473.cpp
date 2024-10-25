#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    constexpr int INF = 0x3f3f3f3f;
    int N=0;
    vector<int> Result(3);
    cin>>N;
    vector<int> List(N); 
    for(int i=0;i<N;i++)
    {
        cin >>List[i];
    }
    sort(List.begin(),List.end());


    // two pointer
    int Temp = INF;
    int Start = 0;
    int End = N-1;

    for(int i=0;Start <End;)
    {
        if(i%2 == 0){Start++;}
        else {End--;}

        for(int Mid=Start+1;Mid<End;Mid++)
        {
            if(Temp  > List[Start] + List[Mid] + List[End])
            {
                Temp  = List[Start] + List[Mid] + List[End];
                Result[0] = List[Start];
                Result[1] = List[Mid];
                Result[2] = List[End];
            }
        }
        
       

    }
    

    cout<< Result[0]<<" "<<Result[1]<<" "<<Result[2]<<" ";

    return 0;
}