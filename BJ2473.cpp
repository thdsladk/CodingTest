#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    constexpr long long INF = 0x3f3f3f3f3f3f3f3fll;
    int N=0;
    vector<long long> Result(3);
    cin>>N;
    vector<long long> List(N); 
    for(int i=0;i<N;i++)
    {
        cin >>List[i];
    }
    sort(List.begin(),List.end());


    // two pointer
    long long Temp = INF;
    int Start = 0;
    int End = N-1;

    while(Start <End)
    {
        int L = Start;
        int R = End;
        for(int Mid= (L+R) /2;Mid>L && Mid <R;)
        {
            Mid = (L+R)/2;
            if(abs(Temp)  > abs(List[L] + List[Mid] + List[R]))
            {
                Temp  = List[L] + List[Mid] + List[R];
                Result[0] = List[L];
                Result[1] = List[Mid];
                Result[2] = List[R];
            }
            if(Temp<0){L =Mid+1;}
            else if(Temp>0){R = Mid-1;}
            else{break;}
        }
        
        if(Temp < 0){Start++;}
        else if(Temp >0) {End--;}
        else {break;}
    }
    

    cout<< Result[0]<<" "<<Result[1]<<" "<<Result[2]<<" ";

    return 0;
}


/* 이분탐색 없이 완전 탐색으로 찾았을때 

    while(Start <End)
    {
        for(int Mid=Start+1;Mid<End;Mid++)
        {
            if(abs(Temp)  > abs(List[Start] + List[Mid] + List[End]))
            {
                Temp  = List[Start] + List[Mid] + List[End];
                Result[0] = List[Start];
                Result[1] = List[Mid];
                Result[2] = List[End];
            }
        }
        if(Temp < 0){Start++;}
        else if(Temp >0) {End--;}
        else {break;}
    }
    
    */